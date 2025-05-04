#include <iostream>
#include <string>
#include <cctype>
#include "Lab6_C.h"

using namespace std;

// Function to get a valid infix expression
void getInfix(string& infix) {
    cout << "Enter a valid infix expression: ";
    getline(cin, infix);
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=');
}

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '=') {
        return 0;
    }
    return -1;
}

// Function to convert infix expression to postfix
void convertInfixToPostfix(const string& infix, string& postfix) {
    Stack stack;
    postfix = "";
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch; // If operand, append to result
        } else if (ch == '(') {
            stack.push(ch); // Push '(' to stack
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop(); // Pop and add to result until '(' is found
            }
            stack.pop(); // Pop '(' from stack
        } else if (isOperator(ch)) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += stack.pop(); // Pop operators with higher or equal precedence
            }
            stack.push(ch); // Push the current operator
        }
    }
    // Pop remaining operators from the stack
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
    cout << "Postfix expression: " << postfix << endl;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix) {
    Stack stack;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0'); // Push operand to stack
        } else if (isOperator(ch)) {
            int val2 = stack.pop();
            int val1 = stack.pop();
            int result;
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '=': result = val1; break;
            }
            stack.push(result); // Push result back to stack
        }
    }
    return stack.pop(); // Final result
}

int main() {
    string infix, postfix;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Get Infix\n";
        cout << "2. Convert Infix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character

        switch (choice) {
            case 1:
                getInfix(infix); // Get infix expression
                break;
            case 2:
                convertInfixToPostfix(infix, postfix); // Convert infix to postfix
                break;
            case 3:
                if (!postfix.empty()) {
                    int result = evaluatePostfix(postfix); // Evaluate postfix expression
                    cout << "Postfix evaluation result: " << result << endl;
                } else {
                    cout << "No postfix expression to evaluate.\n";
                }
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
