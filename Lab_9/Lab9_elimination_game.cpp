#include<iostream>
using namespace std;

void input(int& nok, int& noq, int skip[], int ply[]);
void process(int nok, int noq, int skip[], int ply[]);
void elemination();

int main()
{
    elemination();
    return 0;
}

void input(int& nok, int& noq, int skip[], int ply[])
{
    cout << "enter the number of positions from which the players are to be deleted\n";
    cin >> nok;
    cout << "enter the number of queries\n";
    cin >> noq;

    for (int j = 0; j < nok; j++)
    {
        cout << "enter the index to be eleminated\n";
        cin >> skip[j];
    }

    for (int j = 0; j < noq; j++)
    {
        cout << "enter the number of players\n";
        cin >> ply[j];
    }
}

void process(int nok, int noq, int skip[], int ply[])
{
    for (int j = 0; j < noq; j++)
    {
        int temp = ply[j];
        int cal = 0;
        while (1)
        {
            for (int k = 0; k < nok; k++)
            {
                if (temp >= skip[k])
                {
                    cal++;
                }
            }
            if (cal == 0)
            {
                cout << temp << "  ";
                break;
            }
            temp = temp - cal;
            cal = 0;
        }
    }
    cout << "\n";
}

void elemination()
{
    int test;
    cout << "enter the number of test cases\n";
    cin >> test;
    if (!(1 <= test && test <= 250))
    {
        cout << "invalid input\n";
        return;
    }

    for (int i = 0; i < test; i++)
    {
        int nok = 0;
        int noq = 0;
        int skip[100];
        int ply[100];

        input(nok, noq, skip, ply);

        if (!(1 <= nok && nok <= 100) || !(1 <= noq && noq <= 100))
        {
            cout << "invalid input\n";
            return;
        }

        process(nok, noq, skip, ply);
    }
}
