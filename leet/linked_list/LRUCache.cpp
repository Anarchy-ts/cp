#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        } else {
            // Move the accessed node to the front of the list
            order.splice(order.begin(), order, it->second.second);
            return it->second.first;
        }
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Update the value
            it->second.first = value;
            // Move the updated node to the front of the list
            order.splice(order.begin(), order, it->second.second);
        } else {
            // Check if we need to evict the least recently used item
            if (cache.size() == capacity) {
                // Remove the LRU item from the cache and list
                int lru = order.back();
                order.pop_back();
                cache.erase(lru);
            }
            // Insert the new item
            order.push_front(key);
            cache[key] = {value, order.begin()};
        }
    }
    
private:
    int capacity;
    list<int> order; // List to keep track of the order of usage
    unordered_map<int, pair<int, list<int>::iterator>> cache; // Hash map to store key-value pairs and list iterators
};

// Example usage:
int main() {
    LRUCache lRUCache(2);
    
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // return -1 (not found)
    cout << lRUCache.get(3) << endl;    // return 3
    cout << lRUCache.get(4) << endl;    // return 4
    
    return 0;
}
