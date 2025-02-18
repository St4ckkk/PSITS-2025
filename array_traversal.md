Here are the C++ implementations for each of the array traversal operations using standard libraries:

### 1. **Sum of Array**

```cpp
#include <iostream>
#include <numeric> // For accumulate
#include <vector>

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    std::cout << "Sum of Array: " << sum << std::endl;
    return 0;
}
```

---

### 2. **Maximum Element in Array**

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For max_element

int main() {
    std::vector<int> arr = {10, 50, 30, 20, 40};
    int maxElement = *std::max_element(arr.begin(), arr.end());
    std::cout << "Maximum Element: " << maxElement << std::endl;
    return 0;
}
```

---

### 3. **Minimum Element in Array**

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For min_element

int main() {
    std::vector<int> arr = {10, 50, 30, 20, 40};
    int minElement = *std::min_element(arr.begin(), arr.end());
    std::cout << "Minimum Element: " << minElement << std::endl;
    return 0;
}
```

---

### 4. **Average of Array**

```cpp
#include <iostream>
#include <vector>
#include <numeric> // For accumulate

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    double average = static_cast<double>(std::accumulate(arr.begin(), arr.end(), 0)) / arr.size();
    std::cout << "Average of Array: " << average << std::endl;
    return 0;
}
```

---

### 5. **Array Index of Element**

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For find

int main() {
    std::vector<int> arr = {10, 20, 30, 40, 50};
    int element = 30;
    auto it = std::find(arr.begin(), arr.end(), element);

    if (it != arr.end()) {
        std::cout << "Index of " << element << ": " << std::distance(arr.begin(), it) << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
    return 0;
}
```

---

### 6. **Array Sorting**

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For sort

int main() {
    std::vector<int> arr = {50, 10, 40, 30, 20};
    std::sort(arr.begin(), arr.end());

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
```

---

### 7. **Array Reverse**

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For reverse

int main() {
    std::vector<int> arr = {10, 20, 30, 40, 50};
    std::reverse(arr.begin(), arr.end());

    std::cout << "Reversed Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
```

---

### 8. **Array Concatenation**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr1 = {1, 2, 3};
    std::vector<int> arr2 = {4, 5, 6};
    std::vector<int> result(arr1);

    result.insert(result.end(), arr2.begin(), arr2.end());

    std::cout << "Concatenated Array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}
```

---

### 9. **Array Rotation**

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For rotate

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2; // Number of rotations
    std::rotate(arr.begin(), arr.begin() + k, arr.end());

    std::cout << "Rotated Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
```

---

### 10. **Array Unique Elements**

```cpp
#include <iostream>
#include <vector>
#include <set> // For unique elements

int main() {
    std::vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
    std::set<int> uniqueElements(arr.begin(), arr.end());

    std::cout << "Unique Elements: ";
    for (int num : uniqueElements) {
        std::cout << num << " ";
    }
    return 0;
}
```

These implementations efficiently utilize the **C++ Standard Library** to perform various array operations. Let me know if you need any modifications! 🚀
