#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& array) {
    int length = array.size();

    for (int i = 0; i < length - 1; i++) {
        // Thiết lập chỉ số của phần tử nhỏ nhất
        int minIndex = i;
        int temp = array[i];

        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[minIndex]) {
                // Cập nhật minIndex nếu tìm thấy phần tử nhỏ hơn
                minIndex = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử hiện tại
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main() {
    vector<int> numbers = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    selectionSort(numbers);

    // In mảng sau khi sắp xếp
    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}
