//PROGRAM TO IMPLEMENT GAME AS DESCRIBED IN LAB 10 QUESTION B
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_N 1000
#define MAX_T 100

bool isValidWord(const char word[]) {
    return (strlen(word) == 3 && word[0] >= 'a' && word[0] <= 'z' &&
            word[1] >= 'a' && word[1] <= 'z' && word[2] >= 'a' && word[2] <= 'z');
}

int main() {
    int t;

    while (true) { 
        scanf("%d", &t); 
        if (t >= 1 && t <= MAX_T) break;
        printf("Invalid number of test cases! Enter a value between 1 and 100:\n");
    }

    int results[MAX_T][3]; // Store results for all test cases

    for (int tc = 0; tc < t; tc++) {
        int n;

        while (true) {
            scanf("%d", &n);
            if (n >= 1 && n <= MAX_N) break;
            printf("Invalid n! Enter a value between 1 and 1000:\n");
        }

        char words[3][MAX_N][4]; 
        int freq[26][26][26] = {0};

        for (int i = 0; i < 3; i++) {
            while (true) { 
                bool valid = true;

                for (int j = 0; j < n; j++) {
                    scanf("%s", words[i][j]);
                    if (!isValidWord(words[i][j])) {
                        valid = false;
                    }
                }

                if (valid) break;
                
                printf("Invalid input! Enter the entire sequence again for player %d:\n", i + 1);
            }

            for (int j = 0; j < n; j++) {
                int x = words[i][j][0] - 'a';
                int y = words[i][j][1] - 'a';
                int z = words[i][j][2] - 'a';
                freq[x][y][z]++;
            }
        }

        int scores[3] = {0};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                int x = words[i][j][0] - 'a';
                int y = words[i][j][1] - 'a';
                int z = words[i][j][2] - 'a';

                if (freq[x][y][z] == 1)
                    scores[i] += 3;
                else if (freq[x][y][z] == 2)
                    scores[i] += 1;
            }
        }

        results[tc][0] = scores[0];
        results[tc][1] = scores[1];
        results[tc][2] = scores[2];
    }


    for (int i = 0; i < t; i++) {
        printf("%d %d %d\n", results[i][0], results[i][1], results[i][2]);
    }

    return 0;
}
