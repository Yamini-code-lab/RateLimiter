#pragma once
#include <mutex>
#include <unordered_map>
#include <chrono>
#include <string>

class TokenBucket {

private:

    struct Bucket {

        int tokens;

        int maxTokens;

        std::chrono::steady_clock::time_point lastRefill;
    };

    std::unordered_map<std::string, Bucket> buckets;
    std::mutex bucketMutex;

public:

    TokenBucket(int capacity);

    bool allowRequest(
        const std::string& user_id,
        int limit
    );
};