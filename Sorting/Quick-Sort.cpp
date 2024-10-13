#include <iostream>
#include <vector>

using namespace std;

// Hàm hoán đổi (swap) hai phần tử trong mảng
void swap(vector<int>& array, int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

// Hàm phân hoạch (partition)
int partition(vector<int>& array, int pivot, int left, int right) {
    int pivotValue = array[pivot];
    int partitionIndex = left;

    for (int i = left; i < right; i++) {
        if (array[i] < pivotValue) {
            swap(array, i, partitionIndex);
            partitionIndex++;
        }
    }
    swap(array, right, partitionIndex);
    return partitionIndex; 
}

// Hàm quick sort
void quickSort(vector<int>& array, int left, int right) {
    if (left < right) {
        int pivot = right;
        int partitionIndex = partition(array, pivot, left, right);

        // Đệ quy sắp xếp phần bên trái và bên phải
        quickSort(array, left, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, right);
    }
}

int main() {
    vector<int> numbers = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};

    quickSort(numbers, 0, numbers.size() - 1);

    // In mảng sau khi sắp xếp
    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}
