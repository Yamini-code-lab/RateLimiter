#include "lru_cache.h"

LRUCache::LRUCache(int cap)
    : capacity(cap) {}

bool LRUCache::exists(const std::string& key) {

    std::lock_guard<std::mutex> lock(cacheMutex);

    return cacheMap.find(key) != cacheMap.end();
}

int LRUCache::get(const std::string& key) {

    std::lock_guard<std::mutex> lock(cacheMutex);

    auto it = cacheMap.find(key);

    if (it == cacheMap.end()) {
        return -1;
    }

    cacheList.splice(
        cacheList.begin(),
        cacheList,
        it->second
    );

    return it->second->second;
}

void LRUCache::put(
    const std::string& key,
    int value
) {

    std::lock_guard<std::mutex> lock(cacheMutex);
    
    auto it = cacheMap.find(key);

    if (it != cacheMap.end()) {

        cacheList.erase(it->second);

        cacheMap.erase(it);
    }

    cacheList.push_front({key, value});

    cacheMap[key] = cacheList.begin();

    if (cacheMap.size() > capacity) {

        auto last = cacheList.back();

        cacheMap.erase(last.first);

        cacheList.pop_back();
    }
}