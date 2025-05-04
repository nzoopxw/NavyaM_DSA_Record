//Fumction to check whether a given string is balanced or not
#include <iostream>
using namespace std;

class ParenthesesChecker {
private:
    string str;
public:
    ParenthesesChecker() {
        cout << "Enter a string of parentheses: ";
        getline(cin, str);
    }
    
    int isBalancedUsingCounter() {
        int count = 0;
        for (char ch : str) {
            if (ch == '(') {
                count++;
            } else if (ch == ')') {
                count--;
                if (count < 0) return -1; // Indicates unbalanced parentheses
            }
        }
        return (count == 0) ? 1 : -1; // 1 for balanced, -1 for unbalanced
    }
};

int main() {
    int choice;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore newline character after choice input
        
        switch (choice) {
            case 1: {
                ParenthesesChecker checker;
                if (checker.isBalancedUsingCounter() == 1) {
                    cout << "Balanced (Using Counter)\n";
                } else {
                    cout << "Unbalanced (Using Counter)\n";
                }
                break;
            }
            case 2:
                cout << "Exiting program.\n";
                break;
                
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 2);
    
    return 0;
}
