### Longest substring without repeating characters

```cpp
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int maxLength = 0;

    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            bool unique = true;

            for (int k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    unique = false;
                    break;
                }
            }

            if (unique) {
                maxLength = max(maxLength, j - i + 1);
            } else {
                break;
            }
        }
    }

    cout << maxLength << endl;
    return 0;
}
```

### Longest palindromic substring

```cpp
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int maxLength = 0, start = 0;

    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            bool isPalindrome = true;

            for (int k = 0; k <= (j - i) / 2; k++) {
                if (s[i + k] != s[j - k]) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome && (j - i + 1) > maxLength) {
                maxLength = j - i + 1;
                start = i;
            }
        }
    }

    cout << s.substr(start, maxLength) << endl;
    return 0;
}
```

### Reverse Comma-Separated String with Capitalization

```cpp
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    string s, result = "";
    cin >> s;

    if (!s.empty()) {
        s[0] = toupper(s[0]);
    }


    for (int i = 0; i < s.length(); i++) {
        result += s[i];
        if (i != s.length() - 1) {
            result += ",";
        }
    }


    reverse(result.begin(), result.end());

    cout << result << endl;
    return 0;
}
```

### Longest Substring with At Least K Repeating Characters

```cpp
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    if (n == 0) {
        cout << "No longest substring found." << endl;
        return 0;
    }

    char longestChar = s[0];
    int maxLen = 1, currentLen = 1;
    bool found = false;


    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            currentLen++;
            found = true;
        } else {
            currentLen = 1;
        }

        if (currentLen > maxLen) {
            maxLen = currentLen;
            longestChar = s[i];
        }
    }


    if (!found) {
        cout << "No longest substring found." << endl;
        return 0;
    }


    int totalCount = 0;
    for (char c : s) {
        if (c == longestChar) totalCount++;
    }

    cout << "The longest substring is \""
         << string(maxLen, longestChar)
         << "\", as '" << longestChar
         << "' is repeated " << totalCount
         << " times." << endl;

    return 0;
}

```

```cpp
#include <iostream>
using namespace std;
/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T.
Your task is to find the longest repetition in the sequence.
 This is a maximum-length substring containing only one type of character.
*/
int main() {
    string s;
    cin >> s;
    int n = s.length();
    int maxLen = 1, currentLen = 1;

    for(int i=1; i<=n; i++) {
        if(s[i] == s[i-1]) {
            currentLen++;
        } else {
            currentLen = 1;
        }
        if(currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    cout << maxLen;
    return 0;
}
```

```cpp
#include <iostream>
using namespace std;
/*
Consider an algorithm that takes as input a positive integer n. If n is even,
the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one.
The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
 */
int main() {
    long long n;
    cin >> n;

    cout << n << " ";

    while(n>1) {
        if(n %2==0) {
            n/=2;
        }else {
            n = (n*3)+1;
        }

        cout << n << " ";
    }

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

/*
You are given all numbers between 1,2,...n except one. Your task is to find the missing number.
*/

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n-1);
    int sumArr = 0;
    for(int i=0; i<n-1; i++) {
        cin >> arr[i];
        sumArr+=arr[i];
    }

    int sum = (n * (n + 1)) / 2;
    int missingNumber = sum - sumArr;

    cout << missingNumber;



    return 0;
}
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Increasing Array

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    long long moves = 0;

    for(int i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) {
            moves += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }

    cout << moves << endl;


    return 0;
}
```

### Sort Strings by Their Suffixes Using Radix Sort

```cpp
#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<string>& arr, int pos) {
    const int ASCII_RANGE = 256;
    vector<string> output(arr.size());
    vector<int> count(ASCII_RANGE, 0);

    for(const string& s : arr) {
        int char_val = (pos < s.length()) ? s[s.length() - 1 - pos] : 0;
        count[char_val]++;
    }

    for(int i=1; i< ASCII_RANGE; i++) {
        count[i] += count[i-1];
    }

    for(int i=arr.size() - 1; i>=0; i--) {
        int char_val = (pos < arr[i].length()) ? arr[i][arr[i].length() - 1 - pos] : 0;
        output[count[char_val] - 1] = arr[i];
        count[char_val]--;
    }

    arr = output;
}

void radixSort(vector<string>&arr) {
    if(arr.empty()) return;

    int max_length = arr[0].length();

    for(int pos=0; pos<max_length; pos++) {
        countSort(arr, pos);

        cout << "Pass " << pos + 1 << " (sorting by position "
        << max_length - pos << "): " ;
        for(const string& s : arr) {
            cout << s << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore();

    vector<string> arr(n);
    cout << "Enter the strings: " << endl;
    for(int i=0; i<n; i++) {
        getline(cin, arr[i]);
    }

    radixSort(arr);


    return 0;
}
```

### Number of Good Pairs

```cpp

#include <iostream>
#include <vector>

using namespace std;

int main() {
int n;
int count = 0;
cout << "Enter size of array: ";
cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements:" << endl;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=i + 1; j<n; j++) {
            if(nums[i] == nums[j]) {
                count++;
            }
        }
    }

    cout << "Number of Good Pairs: " << count;

    return 0;

}
```

### Found all pairs with given number

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cout << "Enter N: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter target sum: ";
    cin >> k;
    bool found = false;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i]+arr[j] == k) {
                cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
                found = true;
            }
        }

    }

    if(!found) {
        return 0;
    }


    return 0;
}
```

### Convert Adjacency Matrix to Adjacency List

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> convertToAdjList(const vector<vector<int>>& adjMatrix, int n) {
    vector<vector<int>> adjList(n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(adjMatrix[i][j] == 1) {
                adjList[i].push_back(j+1);
            }
        }
    }

    return adjList;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the adjacency matrix:" << endl;
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    vector<vector<int>> adjList = convertToAdjList(adjMatrix, n);

    cout << "Adjacency List:" << endl;
    for(int i=0; i<n; i++) {
        cout << (i + 1) << ": ";
        for(size_t j =0; j < adjList[i].size(); j++) {
            cout << adjList[i][j];
            if(j < adjList[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Create and input the adjacency matrix using vectors
    cout << "Enter the adjacency matrix:" << endl;
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0)); // Initialize with zeros

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ": ";
        bool first = true;
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                if (!first) {
                    cout << " ";
                }
                cout << (j + 1);
                first = false;
            }
        }
        cout << endl;
    }

    return 0;
}

```

### Character Case Checker with Calculation

```cpp
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
    char a, b;
    cout << "Enter the first character: ";
    cin >> a;
    cout << "Enter the second character: ";
    cin >> b;

    int result = 0;
    if(isupper(a) && islower(b)) {
        result = pow(2, 17);
    }

     cout << "Result: " << result;


    return 0;
}
```

### Sort Strings Lexicographically Using Selection Sort

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void selectionSort(vector<string>&arr) {
   int n = arr.size();


    int max_length = arr[0].length();

    for(int i=0; i < n - 1; i++) {
       int min_idx = i;
       for(int j=i+1; j<n; j++) {
           if(arr[j] < arr[min_idx]) {
               min_idx = j;
           }
       }


       if(min_idx != i) {
           swap(arr[i], arr[min_idx]);
        }

        cout << "Iteration " << i+1 << ": ";
        for(const string& s : arr) {
            cout << s << " ";
         }

        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore();

    vector<string> arr;
    cout << "Enter the strings: " << endl;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    selectionSort(arr);


    return 0;
}
```

### Hexadecimal color validation

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {

    string input;
    cout << "Enter a hexadecimal color code: ";
    cin >> input;

    bool isValid = true;
    if(input.length() == 0 || input[0] != '#') {
        isValid = false;
    }

    if(input.length() != 7 ){
        isValid = false;
    }

    for(int i=1; i <input.length() && isValid; i++) {
        char c = input[i];
        if(!isxdigit(c)) {
            isValid = false;
        }
    }

    if(isValid) {
        cout << "Valid hexadecimal color code";
    } else {
        cout << "Invalid hexadecimal color code";
    }
    return 0;
}
```

### Discount calculator

```cpp
#include <iostream>
#include <iomanip>
using namespace std;



int main(void) {
    string name;
    double price, discount;
    cout << "Enter your name: ";
    cin >> name;
    cin.ignore();
    cout << "Enter the original price of the product: ";
    cin >> price;
    cout << "Enter the discount percentage: ";
    cin >> discount;
    bool isValid = true;

    if(discount >= 100) {
        isValid = false;
    }

    if(isValid) {
        double finalPrice = price * (1 - discount/100);
        cout << fixed << setprecision(2);
        cout << name << ", the final price is: " << finalPrice;
    } else {
        cout << "Error: Invalid discount percentage.";
    }

   return 0;
}
```

### Find the first non-repeated character in a string

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;



int main(void) {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int str = s.length();
    int charCount[256] = {0};
    for(int i=0; i<str; i++) {
        charCount[(unsigned char)s[i]]++;
    }

     for(int i=0; i<str; i++) {
         if(charCount[(unsigned char)s[i]] == 1) {
              cout << "First non-repeated character is: " << s[i] << endl;
              break;
         }
    }




   return 0;
}
```

### Find All Triplicates in an Array

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers:" << endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

     int count[1001] = {0};
     for(int i=0; i<n; i++) {
         count[arr[i]]++;
     }
     bool found = false;

     for(int i=0; i<1001; i++) {
         if(count[i] == 3) {
             if(!found) {
                 cout << "Elements appearing thrice: ";
             }
             cout << i << " ";
             found = true;
         }
     }

     if(!found) {
         cout << "No triplicates found." ;
     }
     cout << endl;





   return 0;
}
```
