#include <iostream>
#include <unordered_map>

using namespace std;

class MemoizeAddTo80 {
private:
    unordered_map<int, int> cache; // Cache to store computed results

public:
    int operator()(int n) {
        if (cache.find(n) != cache.end()) {
            return cache[n]; // Return cached result
        } else {
            cout << "long time" << endl;
            int answer = n + 80;
            cache[n] = answer; // Store result in cache
            return answer;
        }
    }
};

int main() {
    MemoizeAddTo80 memoizedAddTo80;

    // First call will calculate and cache
    cout << "Result 1: " << memoizedAddTo80(6) << endl;

    // Second call will retrieve from cache
    cout << "Result 2: " << memoizedAddTo80(6) << endl;

    return 0;
}
