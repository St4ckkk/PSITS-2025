#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string colors[] = {
        "Green", "Yellow", "Brown", "Orange", "Indigo", "Red", "Violet"};

    const int numColors = 7;

    int colorIndex = 0;

    cout << string(12, ' ') << colors[0] << endl;
    cout << string(6, ' ') << colors[1];
    cout << string(5, ' ') << colors[2] << endl;
    cout << string(2, ' ') << colors[3];
    cout << string(13, ' ') << colors[4] << endl;
    cout << string(0, ' ') << colors[5];
    cout << string(22, ' ') << colors[6] << endl;

    return 0;
}