//PROGRAM TO IMPLEMENT A GAME AS GIVEN IN THE LAB 10 QUESTION A
#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAX_N = 200000;
const int MAX_T = 10000;
int arr[MAX_N];
int removeResults[MAX_T]; // Store remove count results

// Solution for Problem A: Removing minimum prefix to make all elements distinct
void solveProblemA() {
    int t;
    scanf("%d", &t);
    while (t < 1 || t > MAX_T) {
        printf("Invalid number of test cases. Must be between 1 and %d. Enter again:\n", MAX_T);
        scanf("%d", &t);
    }
    
    for (int test = 0; test < t; test++) {
        int n;
        bool firstAttempt = true;
        do {
            if (!firstAttempt) {
                printf("Entered wrong value: %d. Enter again:\n", n);
            }
            scanf("%d", &n);
            firstAttempt = false;
        } while (n < 1 || n > MAX_N);
        
        int freq[n + 1]; // Dynamically allocate frequency array based on n
        
        // Initialize frequency array to 0
        for (int i = 0; i <= n; i++) {
            freq[i] = 0;
        }
        
        bool valid;
        do {
            valid = true;
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
                if (arr[i] > n) {
                    valid = false;
                }
            }
            if (!valid) {
                printf("Invalid sequence. All values must be <= %d. Enter the sequence again:\n", n);
            }
        } while (!valid);
        
        int removeCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (freq[arr[i]] > 0) {
                removeCount = i + 1;
                break;
            }
            freq[arr[i]]++;
        }
        removeResults[test] = removeCount; // Store the result
    }
    
    // Print all results at the end
    for (int i = 0; i < t; i++) {
        printf("%d\n", removeResults[i]);
    }
}

int main() {
    solveProblemA();
    return 0;
}