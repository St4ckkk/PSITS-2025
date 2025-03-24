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
