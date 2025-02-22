#include <iostream>
#include <chrono>

using namespace std;

//Function to calculate the nth Fibonacci number
unsigned long long fibonacci(int n) {
    if (n < 0) {
        throw invalid_argument("Fibonacci is not defined for negative numbers.");
    } else if (n == 0) {
        return 0; //Fibonacci(0) = 0
    } else if (n == 1) {
        return 1; //Fibonacci(1)= 1
    }

    unsigned long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b; //Calculate the next Fibonacci number
        a = b; //Update a to the previous Fibonacci number
        b = c; //Update b to the current Fibonacci number
    }
    }
    return b; //Return the nth Fibonacci number
}

int main() {
    int number;
    cout << "Enter a non-negative integer for Fibonacci: ";
    cin >> number;

    auto start = chrono::high_resolution_clock::now(); //Start timing
    try {
        unsigned long long fibonacci_result = fibonacci(number); //Calculate Fibonacci
        auto end = chrono::high_resolution_clock::now();  //End timing
        chrono::duration<double> duration = end - start; //Calculate duration


        cout << "The " << number << "th Fibonacci number is: " << fibonacci_result << endl;
        cout << "Runtime for Fibonacci calculation: " << duration.count() << " seconds" << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl; //Handle negative input
    }

    return 0;
}