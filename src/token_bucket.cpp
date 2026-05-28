#include "token_bucket.h"

TokenBucket::TokenBucket(int capacity) {}

bool TokenBucket::allowRequest(
    const std::string& user_id,
    int limit
) {
    std::lock_guard<std::mutex> lock(bucketMutex);

    auto now = std::chrono::steady_clock::now();

    if (buckets.find(user_id) == buckets.end()) {

        buckets[user_id] = {
            limit,
            limit,
            now
        };
    }

    Bucket& bucket = buckets[user_id];

    auto secondsPassed =
        std::chrono::duration_cast<
            std::chrono::seconds
        >(
            now - bucket.lastRefill
        ).count();

    if (secondsPassed >= 1) {

        bucket.tokens = bucket.maxTokens;

        bucket.lastRefill = now;
    }

    if (bucket.tokens > 0) {

        bucket.tokens--;

        return true;
    }

    return false;
}