#include<iostream>
using namespace std;

void input();
void sort(long long arr[], int size);
void calculate(int nop, long long stg[], long long temp[]);

int main()
{
    input();
    return 0;
}

void sort(long long arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                long long temp1 = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp1;
            }
        }
    }
}

void calculate(int nop, long long stg[], long long temp[])
{
    sort(temp, nop);

    for (int j = 0; j < nop; j++)
    {
        if (stg[j] < temp[nop - 1])
        {
            cout << stg[j] - temp[nop - 1] << "   ";
        }
        else
        {
            cout << stg[j] - temp[nop - 2] << "   ";
        }
    }
    cout << "\n";
}

void input()
{
    int test;
    cout << "enter the number of test cases\n";
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int nop = 0;
        cout << "enter the number of players\n";
        cin >> nop;

        long long stg[nop];
        long long temp[nop];

        cout << "enter the strengths of the players\n";
        for (int j = 0; j < nop; j++)
        {
            cin >> stg[j];
            temp[j] = stg[j];
        }

        if (nop == 1)
        {
            cout << "0\n";
            continue;
        }

        calculate(nop, stg, temp);
    }
}
