#include <iostream>
#include <chrono>

using namespace std;

unsigned long long factorial(int n) {
    if (n < 0) {
        throw invalid_argument("Factorial is not defined for negative numbers.");
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int number;
    cout << "Enter a non-negative integer for factorial: ";
    cin >> number;

    auto start = chrono::high_resolution_clock::now();
    try {
        unsigned long long factorial_result = factorial(number);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        cout << "The factorial of " << number << " is: " << factorial_result << endl;
        cout << "Runtime for factorial calculation: " << duration.count() << " seconds" << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}