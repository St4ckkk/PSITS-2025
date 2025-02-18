````md
## 1. Average of Three Numbers

```cpp
#include <iostream>
using namespace std;

int main() {
    float num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    float average = (num1 + num2 + num3) / 3;
    cout << "Average: " << average << endl;
    return 0;
}
```
````

## 2. Greeting Generator

```cpp
#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    return 0;
}
```

## 3. Area of a Circle

```cpp
#include <iostream>
using namespace std;

int main() {
    float radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    float area = 3.14159 * radius * radius;
    cout << "Area of the circle: " << area << endl;
    return 0;
}
```

## 4. String Uppercase Converter

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Uppercase: " << str << endl;
    return 0;
}
```

## 5. String Lowercase Converter

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "Lowercase: " << str << endl;
    return 0;
}
```

## 6. String Length Function

```cpp
#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "Length of the string: " << str.length() << endl;
    return 0;
}
```

## 7. Count Digits

```cpp
#include <iostream>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of digits: " << countDigits(n) << endl;
    return 0;
}
```

## 8. Positive or Negative

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n > 0) {
        cout << "The number is positive." << endl;
    } else if (n < 0) {
        cout << "The number is negative." << endl;
    } else {
        cout << "The number is zero." << endl;
    }
    return 0;
}
```

## 9. Prime Factors

```cpp
#include <iostream>
using namespace std;

void primeFactors(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 2) {
        cout << n << " ";
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Prime factors: ";
    primeFactors(n);
    cout << endl;
    return 0;
}
```
