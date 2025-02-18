Here's your README file:

---

# Array Operations in C++

This repository contains multiple C++ programs that perform various operations on arrays, such as sum calculation, finding maximum and minimum values, counting even and odd numbers, and more.

## Programs Included

### 1. Sum of Array Elements

Calculates the sum of all elements in an array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    cout << "Sum of array elements: " << sum << endl;
    return 0;
}
```

### 2. Array Average

Finds the average value of an array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    double average = sum / 10.0;
    cout << "Average of array elements: " << average << endl;
    return 0;
}
```

### 3. Maximum Element in Array

Finds the maximum value in an array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int maxElement = arr[0];
    for(int i = 1; i < 10; i++) {
        if(arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    cout << "Maximum element in array: " << maxElement << endl;
    return 0;
}
```

### 4. Minimum Element in Array

Finds the minimum value in an array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int minElement = arr[0];
    for(int i = 1; i < 10; i++) {
        if(arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    cout << "Minimum element in array: " << minElement << endl;
    return 0;
}
```

### 5. Count Even Numbers in Array

Counts the number of even elements in an array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int countEven = 0;
    for(int i = 0; i < 10; i++) {
        if(arr[i] % 2 == 0) {
            countEven++;
        }
    }
    cout << "Count of even numbers in array: " << countEven << endl;
    return 0;
}
```

### 6. Count Odd Numbers in Array

Counts the number of odd elements in an array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int countOdd = 0;
    for(int i = 0; i < 10; i++) {
        if(arr[i] % 2 != 0) {
            countOdd++;
        }
    }
    cout << "Count of odd numbers in array: " << countOdd << endl;
    return 0;
}
```

### 7. Reverse Array

Prints the elements of the array in reverse order.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Reversed array: ";
    for(int i = 9; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

### 8. Find Duplicate Elements in Array

Finds and prints duplicate elements in an array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    cout << "Duplicate elements in array: ";
    for(int i = 0; i < 10; i++) {
        for(int j = i + 1; j < 10; j++) {
            if(arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
```

### 9. Check if Array is Sorted

Checks if an array is sorted in ascending order.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool isSorted = true;
    for(int i = 0; i < 9; i++) {
        if(arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }
    if(isSorted) {
        cout << "Array is sorted" << endl;
    } else {
        cout << "Array is not sorted" << endl;
    }
    return 0;
}
```

### 10. Find Perfect Square Numbers in Array

Finds and prints all perfect square numbers in an array.

```cpp
#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(int num) {
    int root = sqrt(num);
    return (root * root == num);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Perfect square elements in array: ";
    for(int i = 0; i < 10; i++) {
        if(isPerfectSquare(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
```
