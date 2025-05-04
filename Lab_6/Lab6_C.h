#ifndef LAB6_C_H
#define LAB6_C_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Node structure to represent each element in the stack
struct Node {
    char data;
    Node* next;
};

// Stack class to represent the stack ADT
class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    // Function to push data onto the stack
    void push(char data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    // Function to pop data from the stack
    char pop() {
        if (top == nullptr) {
            throw runtime_error("Stack underflow");
        }
        Node* temp = top;
        char poppedData = top->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    // Function to peek at the top of the stack
    char peek() {
        if (top == nullptr) {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to destroy the stack
    void destroy() {
        while (top != nullptr) {
            pop();
        }
    }
};

#endif
