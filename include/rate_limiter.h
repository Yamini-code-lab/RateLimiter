#pragma once

#include <string>

#include "token_bucket.h"
#include "lru_cache.h"
#include "mysql_client.h"

class RateLimiter {

private:

    TokenBucket bucket;

    LRUCache cache;

    MySQLClient db;

public:

    RateLimiter(int capacity);

    bool isAllowed(const std::string& user_id);
};