#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& array) {
    int length = array.size();

    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;

        // Di chuyển các phần tử lớn hơn key về phía sau
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key; // Chèn key vào đúng vị trí
    }
}

int main() {
    vector<int> numbers = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    insertionSort(numbers);

    // In mảng sau khi sắp xếp
    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}
