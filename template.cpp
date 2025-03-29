#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> count(5, 0);

    for (int i = 0; i < n; i++)
    {
        int groupSize;
        cin >> groupSize;
        count[groupSize]++;
    }

    int taxis = 0;

    taxis += count[4];
    taxis += count[3];
    count[1] = max(0, count[1] - count[3]);

    if (count[1] < 0)
    {
        count[1] = 0;
    }

    taxis += count[2] / 2;

    if (count[2] % 2 == 1)
    {
        taxis += 1;
        count[1] -= 2;
        if (count[1] < 0)
        {
            count[1] = 0;
        }
    }

    taxis += count[1] / 4;
    if (count[1] % 4 != 0)
    {
        taxis += 1;
    }

    cout << taxis;

    return 0;
}
