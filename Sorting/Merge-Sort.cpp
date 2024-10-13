#include <iostream>
#include <vector>

using namespace std;

// Hàm hợp nhất (merge) hai mảng con đã sắp xếp
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    int leftIndex = 0, rightIndex = 0;

    // So sánh các phần tử từ hai mảng con và thêm phần tử nhỏ hơn vào result
    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    // Thêm các phần tử còn lại từ mảng con bên trái (nếu có)
    while (leftIndex < left.size()) {
        result.push_back(left[leftIndex]);
        leftIndex++;
    }

    // Thêm các phần tử còn lại từ mảng con bên phải (nếu có)
    while (rightIndex < right.size()) {
        result.push_back(right[rightIndex]);
        rightIndex++;
    }

    return result;
}

// Hàm merge sort
vector<int> mergeSort(const vector<int>& array) {
    if (array.size() <= 1) {
        return array;
    }

    // Chia mảng thành hai nửa
    int middle = array.size() / 2;
    vector<int> left(array.begin(), array.begin() + middle);
    vector<int> right(array.begin() + middle, array.end());

    // Đệ quy sắp xếp và hợp nhất hai mảng con
    return merge(mergeSort(left), mergeSort(right));
}

int main() {
    vector<int> numbers = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    vector<int> sortedArray = mergeSort(numbers);

    // In mảng sau khi sắp xếp
    cout << "Sorted array: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }

    return 0;
}
