#include <iostream>
using namespace std;

// Iterative version of factorial
int findFactorialIterative(int number) {
    int answer = 1;
    for (int i = 2; i <= number; i++) {
        answer *= i;
    }
    return answer;
}

// Recursive version of factorial with base case for number <= 1
int findFactorialRecursive(int number) {
    if (number <= 1) {  // Base case for number <= 1
        return 1;
    }
    return number * findFactorialRecursive(number - 1);
}

int main() {
    int number = 5;

    cout << "Iterative Factorial of " << number << ": " << findFactorialIterative(number) << endl;
    cout << "Recursive Factorial of " << number << ": " << findFactorialRecursive(number) << endl;

    return 0;
}
