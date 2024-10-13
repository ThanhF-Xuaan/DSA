#include <iostream>
using namespace std;

// Iterative Fibonacci function
int fibonacciIterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev1 = 0, prev2 = 1, current;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return current;
}

// Recursive Fibonacci function 0 1 1 2 3 5 8
int fibonacciRecursive(int n) {
    if (n < 2) {  // Base case
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);  // Recursive call
}

int main() {
    int n = 6;

    // Fibonacci using iterative method
    cout << "Fibonacci Iterative (" << n << "): " << fibonacciIterative(n) << endl;

    // Fibonacci using recursive method
    cout << "Fibonacci Recursive (" << n << "): " << fibonacciRecursive(n) << endl;

    return 0;
}
