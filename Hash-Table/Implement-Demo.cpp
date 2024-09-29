#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> data;
    
public:
    // Constructor
    HashTable(int size) {
        data.resize(size);
    }

    // Hash function
    int _hash(const string& key) {
        int hash = 0;
        for (int i = 0; i < key.length(); ++i) {
            hash = (hash + key[i] * i) % data.size();
        }
        return hash;
    }

    // Insert key-value pair into the hash table
    //Vector -> List -> Pair;
    //It is not Linked List 
    //It only address in order to save key and value;
    void set(const string& key, int value) {
        int address = _hash(key);
        auto& bucket = data[address];
        for (auto& kv : bucket) {
            if (kv.first == key) {
                kv.second = value; // Update if key exists
                return;
            }
        }
        bucket.push_back(make_pair(key, value)); // Add new key-value pair
    }

    // Retrieve value by key from the hash table
    int get(const string& key) {
        int address = _hash(key);
        auto& bucket = data[address];
        for (auto& kv : bucket) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        return -1; // If key is not found
    }
};

int main() {
    HashTable myHashTable(50);

    myHashTable.set("grapes", 10000);
    cout << "grapes: " << myHashTable.get("grapes") << endl;

    myHashTable.set("apples", 9);
    cout << "apples: " << myHashTable.get("apples") << endl;

    return 0;
}
