#include <iostream>
#include <vector>

using namespace std;

class CrazyQueue {
private:
    vector<int> first;
    vector<int> last;

public:
    // Phương thức thêm phần tử vào hàng đợi
    CrazyQueue& enqueue(int value) {
        int length = first.size();
        for (int i = 0; i < length; i++) {
            last.push_back(first.back());
            first.pop_back();
        }
        last.push_back(value);
        return *this; // Trả về đối tượng hàng đợi để tiếp tục chain
    }

    // Phương thức loại bỏ phần tử khỏi hàng đợi
    CrazyQueue& dequeue() {
        int length = last.size();
        for (int i = 0; i < length; i++) {
            first.push_back(last.back());
            last.pop_back();
        }
        if (!first.empty()) {
            first.pop_back();
        }
        return *this;
    }

    // Phương thức trả về phần tử đầu tiên trong hàng đợi
    int peek() {
        if (!first.empty()) {
            return first.back();
        }
        if (!last.empty()) {
            return last.front();
        }
        return -1; // Nếu hàng đợi trống
    }

    // In hàng đợi để kiểm tra trạng thái
    void printQueue() {
        cout << "First: ";
        for (int i = first.size() - 1; i >= 0; i--) {
            cout << first[i] << " ";
        }
        cout << "\nLast: ";
        for (int i = 0; i < last.size(); i++) {
            cout << last[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CrazyQueue myQueue;
    cout << "Peek: " << myQueue.peek() << endl; // Trả về -1 vì hàng đợi rỗng
    myQueue.enqueue(10).enqueue(20).enqueue(30);
    cout << "Peek: " << myQueue.peek() << endl; // Trả về 10
    cout << "========\n";
    myQueue.dequeue();
    cout << "Peek after dequeue: " << myQueue.peek() << endl; // Trả về 20
    myQueue.dequeue();
    cout << "Peek after dequeue: " << myQueue.peek() << endl; // Trả về 30
    myQueue.dequeue();
    cout << "Peek after dequeue: " << myQueue.peek() << endl; // Trả về -1 vì hàng đợi trống
    cout << "========\n";
    myQueue.printQueue(); // In trạng thái của hàng đợi
    return 0;
}
