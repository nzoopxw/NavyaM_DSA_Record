// header file

#ifndef LISTADT_H
#define LISTADT_H

#include <iostream>

class List {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

    
    Node* getHead() const {
        return head;
    }

public:
    
    List() : head(nullptr) {}

   
    ~List() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert in ascending order
    void insertAscending(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head || head->data >= value) {  
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data < value) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Merge two sorted lists
    static List mergeLists(const List& list1, const List& list2) {
        List mergedList;
        Node* temp1 = list1.getHead();
        Node* temp2 = list2.getHead();
        Node** tail = &mergedList.head;  

        while (temp1 && temp2) {
            if (temp1->data < temp2->data) {
                *tail = new Node{temp1->data, nullptr};
                temp1 = temp1->next;
            } else {
                *tail = new Node{temp2->data, nullptr};
                temp2 = temp2->next;
            }
            tail = &((*tail)->next);
        }

        // Append remaining nodes
        while (temp1) {
            *tail = new Node{temp1->data, nullptr};
            temp1 = temp1->next;
            tail = &((*tail)->next);
        }
        while (temp2) {
            *tail = new Node{temp2->data, nullptr};
            temp2 = temp2->next;
            tail = &((*tail)->next);
        }

        return mergedList;
    }

    // Display the list
    void display() const {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

#endif 