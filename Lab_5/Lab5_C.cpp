#include "Lab5_C.h"

int main() {
    int quantum;
    cout << "Enter fixed time slot (quantum): ";
    cin >> quantum;

    RoundRobin rr(quantum);
    int choice, time;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Process\n";
        cout << "2. Execute\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter time for new process: ";
                cin >> time;
                rr.insertProcess(time);
                break;
            case 2:
                rr.executeProcess();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
