#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hàm đệ quy để thêm các phần tử từ mảng vào mảng đảo ngược
void addToArray(vector<char>& array, vector<char>& reversedArray) {
    if (!array.empty()) {
        reversedArray.push_back(array.back());
        array.pop_back();
        addToArray(array, reversedArray); // Gọi đệ quy chính nó
    }
}

// Hàm đảo ngược chuỗi không đệ quy
string reverseString(const string& str) {
    vector<char> arrayStr(str.begin(), str.end());
    vector<char> reversedArray;
    
    addToArray(arrayStr, reversedArray); // Bắt đầu hàm đệ quy
    return string(reversedArray.begin(), reversedArray.end());
}

// Hàm đảo ngược chuỗi bằng đệ quy
string reverseStringRecursive(const string& str) {
    if (str.empty()) {
        return "";
    } else {
        return reverseStringRecursive(str.substr(1)) + str[0];
    }
}

int main() {
    // Kiểm tra hàm đảo ngược không đệ quy
    cout << "Non-recursive reverse: " << reverseString("yoyo master") << endl;

    // Kiểm tra hàm đảo ngược đệ quy
    cout << "Recursive reverse: " << reverseStringRecursive("yoyo master") << endl;

    return 0;
}
