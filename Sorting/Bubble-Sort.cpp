#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& array) {
    int length = array.size();
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Hoán đổi hai giá trị
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<int> numbers = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    bubbleSort(numbers);

    // In mảng sau khi sắp xếp
    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}
