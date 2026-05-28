cmake_minimum_required(VERSION 3.10)
project(RateLimiter)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
    "C:/msys64/ucrt64/include/mariadb"
    ) 

link_directories(
    "C:/msys64/ucrt64/lib"
)

add_executable(rate_limiter
    src/main.cpp
    src/token_bucket.cpp
    src/rate_limiter.cpp
    src/mysql_client.cpp
    src/logger.cpp
    src/lru_cache.cpp
)

target_link_libraries(rate_limiter  
   mariadb
   ws2_32
   mswsock
)