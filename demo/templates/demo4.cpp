#include <iostream>
#include <string>
using namespace std;

// Define states
enum State { q0, q1, q2, q3, q4 };

// Check if the state is accepting
bool isAccepting(State state) {
    return state == q2 || state == q3;
}

// Transition function
State transition(State current, char input) {
    switch (current) {
        case q0:
            return (input == '1') ? q1 : q0;
        case q1:
            return (input == '1') ? q2 : q1;
        case q2:
            return (input == '1') ? q3 : q2;
        case q3:
            return (input == '1') ? q4 : q3;
        case q4:
            return q4;
        default:
            return q4;
    }
}

int main() {
    string input;
    cout << "Enter a binary string (0s and 1s): ";
    cin >> input;

    State current = q0;

    for (char ch : input) {
        if (ch != '0' && ch != '1') {
            cout << "Invalid input. Only 0 and 1 are allowed.\n";
            return 1;
        }
        current = transition(current, ch);
    }

    if (isAccepting(current)) {
        cout << "Accepted: The string has exactly two or three 1's.\n";
    } else {
        cout << "Rejected: The string does not have exactly two or three 1's.\n";
    }

    return 0;
}
