#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class User {
public:
    // Properties
    string name;
    int age;
    bool magic;
    
    // Constructor
    User(string name, int age, bool magic)
        : name(name), age(age), magic(magic) {}

    // Method to simulate scream
    void scream() {
        cout << "aaaaaah!" << endl;
    }

    // Method to add a new spell (simulating adding property dynamically)
    //Using const string& more safety than string&
    void addSpell(const string& spellName, const string& spell) {
        spells[spellName] = spell;
    }

    // Method to print user details
    void print() const {
        cout << "Name: " << name << "\nAge: " << age << "\nMagic: " << (magic ? "true" : "false") << endl;
        cout << "Spells: " << endl;
        for (const auto& spell : spells) {
            cout << spell.first << ": " << spell.second << endl;
        }
    }

private:
    // Using a map to simulate adding dynamic properties
    unordered_map<string, string> spells;
};

int main() {
    // Create a user object
    User user("Kyle", 54, true);

    // Access a property (lookup)
    cout << user.name << endl; // Lookup O(1)

    // Call a method
    user.scream(); // O(1)

    // Insert a new property (simulate adding a spell)
    user.addSpell("spell", "abra kadabra"); // O(1)

    // Print the user details
    user.print();

    return 0;
}
