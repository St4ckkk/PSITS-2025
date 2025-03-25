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
