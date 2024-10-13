#include <iostream>
#include <vector>

using namespace std;

// Hàm max_heapify giúp duy trì tính chất của max heap
void max_heapify(vector<int>& A, int heap_size, int i) {
    int left = 2 * i + 1;  // con trái
    int right = 2 * i + 2; // con phải
    int largest = i;

    // So sánh node hiện tại với con trái
    if (left < heap_size && A[left] > A[largest]) {
        largest = left;
    }
    // So sánh node lớn nhất hiện tại với con phải
    if (right < heap_size && A[right] > A[largest]) {
        largest = right;
    }
    // Nếu node lớn nhất không phải là i, hoán đổi và tiếp tục heapify
    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify(A, heap_size, largest);
    }
}

// Hàm build_heap để xây dựng max heap từ một mảng
void build_heap(vector<int>& A) {
    int heap_size = A.size();
    // Bắt đầu từ node không phải lá cuối cùng
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        max_heapify(A, heap_size, i);
    }
}

// Hàm heapsort để sắp xếp mảng sử dụng heap
void heapsort(vector<int>& A) {
    int heap_size = A.size();
    build_heap(A);  // Xây dựng max heap

    // Trích xuất phần tử lớn nhất và đặt vào cuối mảng
    for (int i = heap_size - 1; i > 0; i--) {
        swap(A[0], A[i]); // Đưa phần tử lớn nhất về cuối
        heap_size--;  // Giảm kích thước heap
        max_heapify(A, heap_size, 0);  // Duy trì max heap
    }
}

int main() {
    vector<int> A = {2, 8, 1, 4, 14, 7, 16, 10, 9, 3};

    heapsort(A);

    // In mảng đã sắp xếp
    cout << "Sorted array: ";
    for (int num : A) {
        cout << num << " ";
    }
    return 0;
}
