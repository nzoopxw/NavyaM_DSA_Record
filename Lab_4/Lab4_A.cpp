//C++ menu-driven program to implement List ADT using a singly linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    void displayReverseHelper(Node* node) {
        if (!node) return;
        displayReverseHelper(node->next);
        cout << node->data << " ";
    }
public:
    SinglyLinkedList() : head(nullptr) {}
    
    // Time Complexity: O(1)
    void insertBeginning(int val);
    
    // Time Complexity: O(n)
    void insertEnd(int val);
    
    // Time Complexity: O(n)
    void insertPosition(int val, int pos);
    
    // Time Complexity: O(1)
    void deleteBeginning();
    
    // Time Complexity: O(n)
    void deleteEnd();
    
    // Time Complexity: O(n)
    void deletePosition(int pos);
    
    // Time Complexity: O(n)
    bool search(int val);
    
    // Time Complexity: O(n)
    void display();
    
    // Time Complexity: O(n)
    void displayReverse();
    
    // Time Complexity: O(n)
    void reverseLink();
};

int main() {
    SinglyLinkedList list;
    int choice, value, position;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n";
        cout << "6. Delete Position\n7. Search\n8. Display\n9. Display Reverse\n10. Reverse Link\n11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: "; cin >> value;
            list.insertBeginning(value);
            break;
        case 2:
            cout << "Enter value: "; cin >> value;
            list.insertEnd(value);
            break;
        case 3:
            cout << "Enter value and position: "; cin >> value >> position;
            list.insertPosition(value, position);
            break;
        case 4:
            list.deleteBeginning();
            break;
        case 5:
            list.deleteEnd();
            break;
        case 6:
            cout << "Enter position: "; cin >> position;
            list.deletePosition(position);
            break;
        case 7:
            cout << "Enter value to search: "; cin >> value;
            cout << (list.search(value) ? "Found" : "Not Found") << endl;
            break;
        case 8:
            list.display();
            break;
        case 9:
            list.displayReverse();
            break;
        case 10:
            list.reverseLink();
            break;
        case 11:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 11);
    return 0;
}

void SinglyLinkedList::insertBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::insertEnd(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void SinglyLinkedList::insertPosition(int val, int pos) {
    if (pos <= 0) {
        insertBeginning(val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; temp && i < pos; ++i) temp = temp->next;
    if (!temp) {
        insertEnd(val);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void SinglyLinkedList::deleteBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void SinglyLinkedList::deleteEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void SinglyLinkedList::deletePosition(int pos) {
    if (pos <= 0 || !head) {
        deleteBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp->next && i < pos; ++i) temp = temp->next;
    if (!temp->next) return;
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

bool SinglyLinkedList::search(int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

void SinglyLinkedList::display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void SinglyLinkedList::displayReverse() {
    displayReverseHelper(head);
    cout << endl;
}

void SinglyLinkedList::reverseLink() {
    Node* prev = nullptr, * curr = head, * next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
