#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insertBeginning(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!tail) {
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertEnd(int value) {
        insertBeginning(value);
        tail = tail->next;
    }

    void insertPosition(int pos, int value) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (!tail || pos == 1) {
            insertBeginning(value);
            return;
        }

        Node* temp = tail->next;
        for (int i = 1; i < pos - 1 && temp != tail; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds.\n";
            return;
        }

        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;

        if (temp == tail) {
            tail = newNode;
        }
    }

    void deleteBeginning() {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }

        Node* head = tail->next;
        if (tail == head) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    }

    void deleteEnd() {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }

        Node* head = tail->next;
        if (head == tail) {
            delete tail;
            tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
    }

    void deletePosition(int pos) {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }

        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }

        Node* head = tail->next;
        if (pos == 1) {
            deleteBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head) {
            cout << "Position out of bounds.\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        if (toDelete == tail) {
            tail = temp;
        }

        delete toDelete;
    }

    void search(int value) {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = tail->next;
        int pos = 1;
        do {
            if (temp->data == value) {
                cout << "Value " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != tail->next);

        cout << "Value not found in the list.\n";
    }

    void display() {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = tail->next;
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to start)\n";
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n";
        cout << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cll.insertBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            cll.insertEnd(value);
            break;
        case 3:
            cout << "Enter position and value: ";
            cin >> pos >> value;
            cll.insertPosition(pos, value);
            break;
        case 4:
            cll.deleteBeginning();
            break;
        case 5:
            cll.deleteEnd();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> pos;
            cll.deletePosition(pos);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            cll.search(value);
            break;
        case 8:
            cll.display();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 9);

    return 0;
}
