#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // Thêm thư viện này để sử dụng max_element

using namespace std;

// Hàm đếm và sắp xếp các phần tử theo chữ số hiện tại (được truyền vào dưới dạng digit)
void countingSort(vector<int>& A, int digit, int radix) {
    int n = A.size();
    vector<int> B(n);        // Mảng kết quả tạm thời
    vector<int> C(radix, 0); // Mảng đếm, kích thước là "radix" (ví dụ hệ thập phân radix = 10)

    // Đếm số lần xuất hiện của từng chữ số
    for (int i = 0; i < n; i++) {
        int digit_of_Ai = (A[i] / static_cast<int>(pow(radix, digit))) % radix;
        C[digit_of_Ai]++;
    }

    // Cộng dồn giá trị trong mảng C để xác định vị trí chính xác của mỗi phần tử
    for (int j = 1; j < radix; j++) {
        C[j] += C[j - 1];
    }

    // Sắp xếp các phần tử dựa trên chữ số hiện tại (đi từ cuối mảng lên)
    for (int m = n - 1; m >= 0; m--) {
        int digit_of_Ai = (A[m] / static_cast<int>(pow(radix, digit))) % radix;
        B[--C[digit_of_Ai]] = A[m];
    }

    // Sao chép mảng đã sắp xếp lại vào A
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

// Hàm Radix Sort chính
void radixSort(vector<int>& A, int radix) {
    // Tìm số lớn nhất để biết cần bao nhiêu chữ số
    int k = *max_element(A.begin(), A.end());
    // Tính số lượng chữ số của số lớn nhất
    int digits = floor(log(k) / log(radix)) + 1;

    // Sắp xếp theo từng chữ số (bắt đầu từ chữ số hàng đơn vị đến chữ số cao nhất)
    for (int i = 0; i < digits; i++) {
        countingSort(A, i, radix);
    }
}

int main() {
    vector<int> A = {9, 3, 1, 4, 5, 7, 7, 2, 20, 55};

    cout << "Mang ban dau: ";
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;

    // Gọi hàm Radix Sort với hệ thập phân (radix = 10)
    radixSort(A, 10);

    cout << "Mang sau khi sap xep: ";
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
