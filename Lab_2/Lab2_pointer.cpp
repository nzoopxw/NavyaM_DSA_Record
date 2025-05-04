// menu-driven program to determine whether a number is a  Palindrome, Armstrong, or Perfect Number

#include <iostream>
#include <cstdio>
using namespace std;

// Function to check if a number is a palindrome
bool isPalindrome(int* number) {
    // Allocate memory for the original number and its reverse
    int* original = (int*)malloc(sizeof(int));
    *original = *number;
    int* reverse = (int*)malloc(sizeof(int));
    int* remainder = (int*)malloc(sizeof(int));

    // Check if memory allocation was successful
    if (reverse == nullptr || remainder == nullptr) {
        printf("Dynamic memory not allocated\n");
        return false;
    }

    // Initialize reverse to 0
    *reverse = 0;

    // Reverse the digits of the number
    while ((*number) != 0) {
        *remainder = *number % 10;
        *reverse = (*reverse) * 10 + (*remainder);
        *number /= 10;
    }

    // Check if the original number is equal to its reverse
    bool* result = (bool*)malloc(sizeof(bool));
    *result = ((*original) == (*reverse));

    // Free allocated memory before returning result
    free(reverse);
    free(remainder);

    return *result;
}

// Function to check if a number is an Armstrong number
bool isArmstrong(int* number) {
    // Allocate memory for the original number, sum, and digit
    int* original = (int*)malloc(sizeof(int));
    *original = *number;
    int* sum = (int*)malloc(sizeof(int));
    *sum = 0;
    int* digit = (int*)malloc(sizeof(int));

    // Calculate the sum of the cubes of each digit
    while (*number != 0) {
        *digit = *number % 10;
        *sum += ((*digit) * (*digit) * (*digit));
        *number /= 10;
    }

    // Check if the sum of cubes equals the original number
    bool* result = (bool*)malloc(sizeof(bool));
    *result = ((*original) == (*sum));

    // Free allocated memory before returning result
    free(original);
    free(sum);
    free(digit);

    return *result;
}

// Function to check if a number is a perfect number
bool isPerfect(int* number) {
    // Allocate memory for the original number, sum, and loop counter
    int* original = (int*)malloc(sizeof(int));
    *original = *number;
    int* sum = (int*)malloc(sizeof(int));
    *sum = 0;
    int* i = (int*)malloc(sizeof(int));

    // Find the sum of divisors of the number
    for ((*i) = 1; (*i) <= ((*original) / 2); (*i)++) {
        if ((*original) % (*i) == 0) {
            *sum += (*i);
        }
    }

    // Check if the sum of divisors equals the original number
    bool* result = (bool*)malloc(sizeof(bool));
    *result = ((*original) == (*sum));

    // Free allocated memory before returning result
    free(sum);
    free(i);

    return *result;
}

int main() {
    int* number;
    number = (int*)malloc(sizeof(int));

    // Prompt user to enter a number
    printf("Enter number: \n");
    scanf("%d", number);

    int* choice = (int*)malloc(sizeof(int));

    do {
        // Menu-driven program
        printf("The menu is: \n");
        printf("1. Palindrome\n");
        printf("2. Armstrong number\n");
        printf("3. Perfect number\n");
        printf("4. Exit\n");
        printf("Enter choice: \n");
        scanf("%d", choice);

        // Switch-case to handle user choices
        switch (*choice) {
        case 1:
            if (isPalindrome(number)) {
                printf("It is a palindrome\n");
            } else {
                printf("It is not a palindrome\n");
            }
            break;

        case 2:
            if (isArmstrong(number)) {
                printf("It is an Armstrong number\n");
            } else {
                printf("It is not an Armstrong number\n");
            }
            break;

        case 3:
            if (isPerfect(number)) {
                printf("It is a perfect number\n");
            } else {
                printf("It is not a perfect number\n");
            }
            break;

        case 4:
            printf("Exiting operation\n");
            break;

        default:
            printf("Invalid input\n");
            break;
        }

    } while (*choice != 4);

    // Free dynamically allocated memory
    free(number);
    free(choice);

    return 0;
}