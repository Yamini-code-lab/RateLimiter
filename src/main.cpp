#define CROW_MAIN
#include "crow/app.h"
#include "crow/json.h"
#include "rate_limiter.h"
#include "logger.h"
#include <iostream>

int main() {

    crow::SimpleApp app;

    RateLimiter limiter(1000);

    CROW_ROUTE(app, "/check").methods("POST"_method)
    ([&limiter](const crow::request& req) {
        auto body = crow::json::load(req.body);

        if (!body || !body.has("user_id")) {
            return crow::response(400, "Invalid request");
        }

        std::string user_id = body["user_id"].s();
        
        bool allowed = limiter.isAllowed(user_id);

        // ✅ Logging (important)
        std::cout << "User: " << user_id 
                  << " -> " << (allowed ? "Allowed" : "Blocked") 
                  << std::endl;

        if (allowed) {
            return crow::response(200, "Request Allowed");
        } else {
            return crow::response(429, "Rate Limit Exceeded");
        }
    });

    app.port(18080).multithreaded().run();
}