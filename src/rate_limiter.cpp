#include "rate_limiter.h"

#include <iostream>

RateLimiter::RateLimiter(int capacity)
    : bucket(capacity),
      cache(100)
{}

bool RateLimiter::isAllowed(
    const std::string& user_id
) {

    int limit;

    if (cache.exists(user_id)) {

        limit = cache.get(user_id);

        std::cout << "[CACHE HIT] "
                  << user_id
                  << " limit="
                  << limit
                  << std::endl;

    } else {

        limit = db.getUserLimit(user_id);

        cache.put(user_id, limit);

        std::cout << "[MYSQL CONNECTED] "
                  << user_id
                  << " limit="
                  << limit
                  << std::endl;
    }

    return bucket.allowRequest(
    user_id,
    limit
);
}