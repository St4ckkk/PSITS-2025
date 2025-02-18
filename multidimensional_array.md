1. Matrix Diagonal Sum
   #include <iostream>
   using namespace std;

int main() {
int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int n = 3;
int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += matrix[i][i]; // Primary diagonal
        if (i != n - i - 1) {
            sum += matrix[i][n - i - 1]; // Secondary diagonal
        }
    }

    cout << "Diagonal Sum: " << sum << endl;
    return 0;

} 2. Pascal's Triangle
#include <iostream>
using namespace std;

void generatePascal(int numRows) {
int triangle[10][10] = {0};

    for (int i = 0; i < numRows; ++i) {
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
int numRows = 5;
generatePascal(numRows);
return 0;
} 3. Maximum Element in 2D Array
#include <iostream>
using namespace std;

int main() {
int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int maxVal = matrix[0][0];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }

    cout << "Maximum Element: " << maxVal << endl;
    return 0;

} 4. Matrix Transpose
#include <iostream>
using namespace std;

int main() {
int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int transposed[3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

} 5. Matrix Multiplication
#include <iostream>
using namespace std;

int main() {
int A[2][2] = {{1, 2}, {3, 4}};
int B[2][2] = {{5, 6}, {7, 8}};
int result[2][2] = {0};

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

} 6. Diagonal Difference
#include <iostream>
using namespace std;

int main() {
int matrix[3][3] = {{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};
int n = 3;
int primaryDiagonal = 0, secondaryDiagonal = 0;

    for (int i = 0; i < n; ++i) {
        primaryDiagonal += matrix[i][i];
        secondaryDiagonal += matrix[i][n - i - 1];
    }

    cout << "Diagonal Difference: " << abs(primaryDiagonal - secondaryDiagonal) << endl;
    return 0;

} 7. Sum of All Elements
#include <iostream>
using namespace std;

int main() {
int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int sum = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum += matrix[i][j];
        }
    }

    cout << "Sum of All Elements: " << sum << endl;
    return 0;

} 8. Matrix Rotation (90 degrees clockwise)
#include <iostream>
using namespace std;

int main() {
int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int n = 3;
int rotated[3][3];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

} 9. Largest Submatrix with Equal Elements
#include <iostream>
using namespace std;

int main() {
int matrix[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
int n = 3;
int maxSize = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int size = 1;
            while (i + size < n && j + size < n && matrix[i][j] == matrix[i + size][j] && matrix[i][j] == matrix[i][j + size] && matrix[i][j] == matrix[i + size][j + size]) {
                size++;
            }
            if (size > maxSize) {
                maxSize = size;
            }
        }
    }

    cout << "Largest Submatrix with Equal Elements: " << maxSize << endl;
    return 0;

} 10. Maximum Element in Each Row
#include <iostream>
using namespace std;

int main() {
int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int n = 3;

    for (int i = 0; i < n; ++i) {
        int maxVal = matrix[i][0];
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
        cout << "Maximum Element in Row " << i + 1 << ": " << maxVal << endl;
    }

    return 0;

}
