#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Thư viện cho find và find_if

using namespace std;

int main() {
    vector<string> beasts = {"Centaur", "Godzilla", "Mosura", "Minotaur", "Hydra", "Nessie"};

    // 1. indexOf ("Godzilla")
    auto indexOfGodzilla = find(beasts.begin(), beasts.end(), "Godzilla");
    if (indexOfGodzilla != beasts.end()) {
        cout << "indexOf: " << distance(beasts.begin(), indexOfGodzilla) << endl;
    } else {
        cout << "Godzilla not found" << endl;
    }

    // 2. findIndex với điều kiện
    auto findIndex = find_if(beasts.begin(), beasts.end(), [](const string& item) {
        return item == "Godzilla";
    });
    if (findIndex != beasts.end()) {
        cout << "findIndex: " << distance(beasts.begin(), findIndex) << endl;
    } else {
        cout << "Godzilla not found" << endl;
    }

    // 3. find (Trả về phần tử)
    auto findGodzilla = find_if(beasts.begin(), beasts.end(), [](const string& item) {
        return item == "Godzilla";
    });
    if (findGodzilla != beasts.end()) {
        cout << "find: " << *findGodzilla << endl;
    } else {
        cout << "Godzilla not found" << endl;
    }

    // 4. includes (kiểm tra tồn tại)
    bool includesGodzilla = (find(beasts.begin(), beasts.end(), "Godzilla") != beasts.end());
    cout << "includes: " << (includesGodzilla ? "true" : "false") << endl;

    return 0;
}
