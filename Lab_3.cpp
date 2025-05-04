#include <iostream>
#include <algorithm> 
#define MAX_SIZE 5 
using namespace std;

class List {
public:
    int elements[MAX_SIZE];
    int currentSize;

    // Constructor to initialize size to zero  
    List() {
        currentSize = 0;
    }

    // Function prototypes  
    int insertAtBeginning(int);
    int insertAtEnd(int);
    int insertAtPosition(int, int);
    int deleteFromBeginning();
    int deleteFromEnd();
    int deleteFromPosition(int);
    int searchElement(int);
    void displayList();
    void rotate(int);
    void rotateOptimal(int);
    void rotateBruteForce(int);
};

int main() {
    List list;
    int userChoice = 0; 
    int inputValue;
    int position, k;

    while (userChoice != 10) {
        cout << "\n1: Insert at Beginning\n";
        cout << "2: Insert at End\n";
        cout << "3: Insert at Position\n";
        cout << "4: Delete from Beginning\n";
        cout << "5: Delete from End\n";
        cout << "6: Delete from Position\n";
        cout << "7: Search Element\n";
        cout << "8: Display List\n";
        cout << "9: Rotate List\n";
        cout << "10: Exit\n";

        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                cout << "Enter value: ";
                cin >> inputValue;
                cout << list.insertAtBeginning(inputValue) << "\n";
                break;

            case 2:
                cout << "Enter value: ";
                cin >> inputValue;
                cout << list.insertAtEnd(inputValue) << "\n";
                break;

            case 3:
                cout << "Enter value: ";
                cin >> inputValue;
                cout << "Enter the position (index): ";
                cin >> position;
                cout << list.insertAtPosition(inputValue, position) << "\n";
                break;

            case 4:
                cout << list.deleteFromBeginning() << "\n";
                break;

            case 5:
                cout << list.deleteFromEnd() << "\n";
                break;

            case 6:
                cout << "Enter the position to delete: ";
                cin >> position;
                cout << list.deleteFromPosition(position) << "\n";
                break;

            case 7:
                cout << "Enter the value to search: ";
                cin >> inputValue;
                cout << list.searchElement(inputValue) << "\n";
                break;

            case 8:
                cout << "The list is: ";
                list.displayList();
                break;

            case 9:
                cout << "Enter k: ";
                cin >> k;
                list.rotate(k);
                break;

            case 10:
                cout << "Exiting the program\n";
                return 0;
        }
    }
}

// Function to display the elements of the list
void List::displayList() {
    if (currentSize == 0) {
        cout << "List is empty.\n";
        return;
    }
    for (int i = 0; i < currentSize; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

// Function to delete an element from the beginning of the list
int List::deleteFromBeginning() {
    if (currentSize == 0) return 0;
    for (int i = 0; i < currentSize - 1; i++) {
        elements[i] = elements[i + 1];
    }
    currentSize--;
    return 1;
}

// Function to delete an element from the end of the list
int List::deleteFromEnd() {
    if (currentSize == 0) return 0;
    currentSize--;
    return 1;
}

// Function to delete an element from a specific position
int List::deleteFromPosition(int position) {
    if (currentSize == 0 || position < 0 || position >= currentSize) return 0;
    for (int i = position; i < currentSize - 1; i++) {
        elements[i] = elements[i + 1];
    }
    currentSize--;
    return 1;
}

// Function to search for an element in the list
int List::searchElement(int value) {
    for (int i = 0; i < currentSize; i++) {
        if (elements[i] == value) return i;
    }
    return -1;
}

// Function to rotate the list by k positions
void List::rotate(int k) {
    rotateOptimal(k);
}

// 
void List::rotateOptimal(int k) {
    if (currentSize == 0) return;
    k = k % currentSize;
    if (k == 0) return;

    reverse(elements, elements + currentSize);
    reverse(elements, elements + k);
    reverse(elements + k, elements + currentSize);
}

// Rotation
void List::rotateBruteForce(int k) {
    if (currentSize == 0) return;
    k = k % currentSize;
    if (k == 0) return;

    int temp[MAX_SIZE];
    for (int i = 0; i < currentSize; i++) {
        temp[(i + k) % currentSize] = elements[i];
    }
    for (int i = 0; i < currentSize; i++) {
        elements[i] = temp[i];
    }
}

// Function to insert an element at the beginning of the list  
int List::insertAtBeginning(int value) {
    if (currentSize == MAX_SIZE) return 0;
    for (int i = currentSize; i > 0; i--) {
        elements[i] = elements[i - 1];
    }
    elements[0] = value;
    currentSize++;
    return 1;
}

// Function to insert an element at the end of the list  
int List::insertAtEnd(int value) {
    if (currentSize == MAX_SIZE) return 0;
    elements[currentSize] = value;
    currentSize++;
    return 1;
}

// Function to insert an element at a specific position  
int List::insertAtPosition(int value, int position) {
    if (currentSize == MAX_SIZE || position < 0 || position > currentSize) return 0;
    for (int i = currentSize; i > position; i--) {
        elements[i] = elements[i - 1];
    }
    elements[position] = value;
    currentSize++;
    return 1;
}