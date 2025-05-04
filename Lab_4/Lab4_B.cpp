//C++ menu-driven program to implement List ADT using a singly linked list using a gethead() 
#include "ListADT.h"

int main() {
    List list1, list2, list3;
    int choice, value;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert into List1\n";
        std::cout << "2. Insert into List2\n";
        std::cout << "3. Merge List1 and List2 into List3\n";
        std::cout << "4. Display Lists\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value for List1: ";
                std::cin >> value;
                list1.insertAscending(value);
                break;

            case 2:
                std::cout << "Enter value for List2: ";
                std::cin >> value;
                list2.insertAscending(value);
                break;

            case 3:
                list3 = List::mergeLists(list1, list2);
                std::cout << "Lists merged into List3.\n";
                break;

            case 4:
                std::cout << "List1: ";
                list1.display();
                std::cout << "List2: ";
                list2.display();
                std::cout << "List3 (Merged): ";
                list3.display();
                break;

            case 5:
                std::cout << "Exiting program...\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
