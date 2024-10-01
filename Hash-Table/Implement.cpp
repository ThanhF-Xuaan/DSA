#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
private:
    vector<vector<pair<string, int>>> data;
    int size;

    // Hash function: Generate a hash from the key
    int _hash(const string& key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash = (hash + key[i] * i) % size;
        }
        return hash;
    }

public:
    // Constructor to initialize the hash table with a given size
    HashTable(int size) : size(size) {
        data.resize(size);
    }

    // Function to insert a key-value pair into the hash table
    void set(const string& key, int value) {
        int address = _hash(key);
        for (auto& pair : data[address]) {
            if (pair.first == key) {
                pair.second = value; // Update existing key
                return;
            }
        }
        data[address].emplace_back(key, value); // Insert new key-value pair
    }

    // Function to get the value associated with a given key
    int get(const string& key) {
        int address = _hash(key);
        for (const auto& pair : data[address]) {
            if (pair.first == key) {
                return pair.second; // Return the value if the key is found
            }
        }
        return -1; // Return -1 if the key is not found (could also throw an exception)
    }

    // Display the entire hash table (for debugging purposes)
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            for (const auto& pair : data[i]) {
                cout << "[" << pair.first << ": " << pair.second << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myHashTable(50);  // Create a hash table of size 50
    myHashTable.set("grapes", 10000);  // Insert key "grapes" with value 10000
    myHashTable.set("apples", 9);      // Insert key "apples" with value 9

    cout << "Value for 'grapes': " << myHashTable.get("grapes") << endl;  // Retrieve value for "grapes"
    cout << "Value for 'apples': " << myHashTable.get("apples") << endl;  // Retrieve value for "apples"
    
    myHashTable.display(); // Display the contents of the hash table (optional)
    
    return 0;
}


//Difference between emplace_back and push_back
//Efficiency: emplace_back can be more efficient than push_back because it avoids extra copies or moves by constructing the object in place.
//Object Creation: push_back requires the object to be created beforehand (as an existing object or a temporary), while emplace_back constructs the object inside the container, forwarding the constructor arguments.
//When to use
//Use emplace_back when you need to construct an object in place, especially if constructing the object is costly or involves temporary objects.
//Use push_back when you already have a fully constructed object that you want to add to the container.