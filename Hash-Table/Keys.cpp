#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
  vector<vector<pair<string, int>>> data;
  
public:
  HashTable(int size) {
    data.resize(size);
  }

  // Hash function
  int _hash(string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash = (hash + key[i] * i) % data.size();
    }
    return hash;
  }

  // Set key-value pair
  void set(string key, int value) {
    int address = _hash(key);
    data[address].emplace_back(key, value);
  }

  // Get value by key
  int get(string key) {
    int address = _hash(key);
    for (int i = 0; i < data[address].size(); i++) {
      if (data[address][i].first == key) {
        return data[address][i].second;
      }
    }
    return -1;  // If key not found
  }

  // Keys function to return all keys
  vector<string> keys() {
    vector<string> result;

    // Loop through all elements in the hash table
    for (int i = 0; i < data.size(); i++) {
      // Check if the slot contains any data
      if (!data[i].empty()) {
        // Loop through the bucket to handle collisions
        for (int j = 0; j < data[i].size(); j++) {
          result.push_back(data[i][j].first);  // Push only the key
        }
      }
    }
    
    return result;
  }
};

int main() {
  HashTable myHashTable(50);

  myHashTable.set("grapes", 10000);
  myHashTable.set("apples", 9);
  myHashTable.set("bananas", 500);

  vector<string> keys = myHashTable.keys();

  // Output all keys
  cout << "Keys in the hash table:" << endl;
  for (string key : keys) {
    cout << key << endl;
  }

  return 0;
}
