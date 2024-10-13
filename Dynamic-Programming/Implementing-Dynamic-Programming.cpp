#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int calculations = 0;

// Simple recursive Fibonacci function (O(2^n))
int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Memoized Fibonacci function (O(n))
class FibonacciMaster {
private:
    unordered_map<int, int> cache;

public:
    int fib(int n) {
        calculations++;
        if (cache.find(n) != cache.end()) {
            return cache[n]; // Return from cache if found
        }
        if (n < 2) {
            return n;
        }
        cache[n] = fib(n - 1) + fib(n - 2); // Cache the result
        return cache[n];
    }
};

// Dynamic Programming - Bottom-Up Fibonacci function (O(n))
int fibonacciMaster2(int n) {
    if (n < 2) return n; // Handle base cases
    vector<int> answer = {0, 1};
    for (int i = 2; i <= n; i++) {
        answer.push_back(answer[i - 2] + answer[i - 1]);
    }
    return answer.back(); // Return the last element
}

int main() {
    FibonacciMaster memoizedFib;

    // Simple recursive Fibonacci (inefficient)
    cout << "Slow: " << fibonacci(35) << endl;

    // Memoized Fibonacci
    cout << "DP: " << memoizedFib.fib(100) << endl;

    // Dynamic Programming Fibonacci
    cout << "DP2: " << fibonacciMaster2(100) << endl;

    // Number of calculations made in memoized version
    cout << "We did " << calculations << " calculations" << endl;
    
    return 0;
}
