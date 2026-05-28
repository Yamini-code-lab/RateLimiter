#pragma once
#include <mutex>
#include <unordered_map>
#include <list>
#include <string>

class LRUCache {

private:

    int capacity;

    std::list<std::pair<std::string, int>> cacheList;

    std::unordered_map<
        std::string,
        std::list<std::pair<std::string, int>>::iterator
    > cacheMap;

    std::mutex cacheMutex;

public:

    LRUCache(int cap);

    bool exists(const std::string& key);

    int get(const std::string& key);

    void put(const std::string& key, int value);
};