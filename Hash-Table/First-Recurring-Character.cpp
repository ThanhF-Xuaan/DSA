#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// First version: Using nested loops (O(n^2) complexity)
int firstRecurringCharacter(const vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = i + 1; j < input.size(); j++) {
            if (input[i] == input[j]) {
                return input[i];
            }
        }
    }
    return -1; // Return -1 to indicate no recurring character found
}

// Second version: Using a hash map (O(n) complexity)
int firstRecurringCharacter2(const vector<int>& input) {
    unordered_map<int, int> map; // To store the frequency of characters
    for (int i = 0; i < input.size(); i++) {
        if (map.find(input[i]) != map.end()) {
            return input[i]; // Return the first recurring character
        } else {
            map[input[i]] = i;
        }
    }
    return -1; // Return -1 if no recurring character is found
}

int main() {
    // Test cases
    vector<int> arr1 = {2, 5, 1, 2, 3, 5, 1, 2, 4};
    vector<int> arr2 = {2, 1, 1, 2, 3, 5, 1, 2, 4};
    vector<int> arr3 = {2, 3, 4, 5};

    // Using the first version
    cout << "First recurring character (O(n^2)): " << firstRecurringCharacter(arr1) << endl;
    cout << "First recurring character (O(n^2)): " << firstRecurringCharacter(arr2) << endl;
    cout << "First recurring character (O(n^2)): " << firstRecurringCharacter(arr3) << endl;

    // Using the second version
    cout << "First recurring character (O(n)): " << firstRecurringCharacter2(arr1) << endl;
    cout << "First recurring character (O(n)): " << firstRecurringCharacter2(arr2) << endl;
    cout << "First recurring character (O(n)): " << firstRecurringCharacter2(arr3) << endl;

    return 0;
}
