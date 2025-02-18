````md
## 1. Linear Search

```cpp
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = linearSearch(arr, n, x);
    if (result != -1) cout << "Element is present at index " << result << endl;
    else cout << "Element is not present in array" << endl;
    return 0;
}
```

## 2. Binary Search

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) cout << "Element is present at index " << result << endl;
    else cout << "Element is not present in array" << endl;
    return 0;
}
```

## 3. Recursive Binary Search

```cpp
#include <iostream>
using namespace std;

int recursiveBinarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return recursiveBinarySearch(arr, l, mid - 1, x);
        return recursiveBinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = recursiveBinarySearch(arr, 0, n - 1, x);
    if (result != -1) cout << "Element is present at index " << result << endl;
    else cout << "Element is not present in array" << endl;
    return 0;
}
```

## 4. Jump Search

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n)) return -1;
    }
    if (arr[prev] == x) return prev;
    return -1;
}

int main() {
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 55;
    int result = jumpSearch(arr, n, x);
    if (result != -1) cout << "Element is present at index " << result << endl;
    else cout << "Element is not present in array" << endl;
    return 0;
}
```

## 5. Exponential Search

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x) return 0;
    int i = 1;
    while (i < n && arr[i] <= x) i = i * 2;
    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = exponentialSearch(arr, n, x);
    if (result != -1) cout << "Element is present at index " << result << endl;
    else cout << "Element is not present in array" << endl;
    return 0;
}
```

## 6. Interpolation Search

```cpp
#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int lo = 0, hi = n - 1;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (lo == hi) {
            if (arr[lo] == x) return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) lo = pos + 1;
        else hi = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18;
    int result = interpolationSearch(arr, n, x);
    if (result != -1) cout << "Element is present at index " << result << endl;
    else cout << "Element is not present in array" << endl;
    return 0;
}
```

## 7. Fibonacci Search

```cpp
#include <iostream>
using namespace std;

int min(int x, int y) { return (x <= y) ? x : y; }

int fibonacciSearch(int arr[], int x, int n) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else return i;
    }
    if (fibMMm1 && arr[offset + 1] == x) return offset + 1;
    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 85;
    int result = fibonacciSearch(arr, x, n);
    if (result != -1) cout << "Element is present at index " << result << endl;
    else cout << "Element is not present in array" << endl;
    return 0;
}
```

## 8. Ternary Search

```cpp
#include <iostream>
using namespace std;

int ternarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (arr[mid1] == x) return mid1;
        if (arr[mid2] == x) return mid2;
        if (x < arr[mid1]) return ternarySearch(arr, l, mid1 - 1, x);
        else if (x > arr[mid2]) return ternarySearch(arr, mid2 + 1, r, x);
        else return ternarySearch(arr, mid1 + 1, mid2 - 1, x);
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int result = ternarySearch(arr, 0, n - 1, x);
    if (result != -1) cout << "Element is present at index " << result << endl;
    else cout << "Element is not present in array" << endl;
    return 0;
}
```

## 9. Count Occurrences

```cpp
#include <iostream>
using namespace std;

int countOccurrences(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) count++;
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 2, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    cout << "Number of occurrences of " << x << ": " << countOccurrences(arr, n, x) << endl;
    return 0;
}
```

## 10. First and Last Occurrence

```cpp
#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int lastOccurrence(int arr[], int n, int x) {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 2, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    cout << "First occurrence of " << x << ": " << firstOccurrence(arr, n, x) << endl;
    cout << "Last occurrence of " << x << ": " << lastOccurrence(arr, n, x) << endl;
    return 0;
}
```
````
