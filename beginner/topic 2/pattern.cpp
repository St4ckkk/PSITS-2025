
#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int j = 0;

    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}