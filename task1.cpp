// CALCULATOR CPP PROGRAM
#include <iostream>
using namespace std;

int main() {
    double a, b;
    double output;
    char operation;

    cout << "Enter 1st number: " << endl;
    cin >> a;
    cout << "Enter 2nd number" << endl;
    cin >> b;
    cout << "Choose operation you want to perform from: +, -, /, * " << endl;
    cin >> operation;

    switch (operation) {
        case '+':
            output = a + b;
            cout << "Result: " << output << endl;
            break;
        case '-':
            output = a - b;
            cout << "Result: " << output << endl;
            break;
        case '/':
            if (b != 0) {
                output = a / b;
                cout << "Result: " << output << endl;
            } else {
                cout << "Not defined" << endl;
            }
            break;
        case '*':
            output = a * b;
            cout << "Result: " << output << endl;
            break;
        default:
            cout << "Invalid Operation" << endl;
    }

    return 0;
}
