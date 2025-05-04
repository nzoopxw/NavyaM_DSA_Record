#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include <iostream>
using namespace std;

struct Node {
    int time;
    Node* next;
};

class RoundRobin {
private:
    Node* head;
    int timeQuantum;

public:
    RoundRobin(int tq) {
        head = nullptr;
        timeQuantum = tq;
    }

    void insertProcess(int t) {
        Node* newNode = new Node{t, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Process inserted with time: " << t << endl;
        displayQueue();
    }

    void executeProcess() {
        if (!head) {
            cout << "No processes in the queue.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        if (temp->time > timeQuantum) {
            temp->time -= timeQuantum;
            cout << "Process with remaining time: " << temp->time << endl;
            head = temp->next;

            // Move to end
            if (temp->next == temp) return; // Only one node

            Node* tail = head;
            while (tail->next != temp)
                tail = tail->next;

            tail->next = head;
            temp->next = head;
            tail = head;
            while (tail->next != head)
                tail = tail->next;
            tail->next = temp;
        } else {
            cout << "Process completed and removed from the queue\n";
            if (temp->next == temp) {
                delete temp;
                head = nullptr;
            } else {
                Node* last = head;
                while (last->next != head)
                    last = last->next;
                head = temp->next;
                last->next = head;
                delete temp;
            }
        }
        displayQueue();
    }

    void displayQueue() {
        if (!head) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->time << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD\n";
    }
};

#endif
