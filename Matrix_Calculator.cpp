/*******************************************************************************
*   Author: Baraa Hamodi                                                       *
*   Description: A simple matrix class capable of scalar multiplication,       *
*                matrix addition, matrix multiplication, transposing a matrix, *
*                and determining the RREF of a matrix.                         *
*******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

class Matrix {
  private:
    int row, col, scalar;
    int matrix[10][10];
    int result[10][10];

  public:
    // Default Constructor.
    Matrix() {
      row = 0;
      col = 0;
      scalar = 0;
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          matrix[i][j] = 0;
          result[i][j] = 0;
        }
      }
    }

    // Constructor.
    Matrix(int r, int c, int s) {
      row = r;
      col = c;
      scalar = s;
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          matrix[i][j] = 0;
          result[i][j] = 0;
        }
      }
    }

    // Operator overload.
    int& operator()(int row, int col) {
      return matrix[row][col];
    }

    // Get matrix size and populate all matrix elements.
    void getInput() {
      do {
        cout << "Rows = ";
        cin >> row;
        cout << "Columns = ";
        cin >> col;
        if (row < 1 || col < 1 || row > 10 || col > 10) {
          cout << "Invalid entries. Min size = 1x1 and max size = 10x10.\n";
        }
      } while (row < 1 || col < 1 || row > 10 || col > 10);

      cout << "Remember to enter matrix entries from top-left to bottom-right.\n";
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          cout << "Matrix Entry (" << i << "," << j << ") = ";
          cin >> matrix[i][j];
        }
      }
    }

    // Output the full matrix to the screen in matrix representation.
    void displayMatrix() {
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          cout << setw(3) << matrix[i][j];
        }
        cout << endl;
      }
    }

    // Output the full resultant matrix to the screen in matrix representation.
    void displayResultMatrix(int rows, int cols) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          cout << setw(3) << result[i][j];
        }
        cout << endl;
      }
    }

    // Perform scalar multiplication.
    void scalarMultiplication() {
      cout << "Enter a scalar to multiply the matrix by: ";
      cin >> scalar;
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          matrix[i][j] *= scalar;
        }
      }
      displayMatrix();
    }

    // Perform matrix addition.
    void matrixAddition(Matrix m) {
      if (row == m.row && col == m.col) {
        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            matrix[i][j] += m(i,j);
          }
        }
        displayMatrix();
      } else {
        cout << "Cannot complete matrix addition with these matrices.\n";
      }
    }

    // Perform matrix multiplication.
    void matrixMultiplication(Matrix m) {
      if (col == m.row) {
        for (int i = 0; i < row; i++) {
          for (int j = 0; j < m.col; j++) {
            for (int k = 0; k < m.row; k++) {
              result[i][j] += matrix[i][k] * m(k,j);
            }
          }
        }
        displayResultMatrix(row, m.col);
      } else {
        cout << "Cannot complete matrix multiplication with these matrices.\n";
      }
    }

    // Transpose matrix.
    void transpose() {
      int temp = row;
      row = col;
      col = temp;
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          result[i][j] = matrix[j][i];
        }
      }
      displayResultMatrix(row, col);
    }

    // Swaps two rows.
    void swapRows(int row1, int row2) {
      if (row1 < row && row2 < row) {
        int temp[1][col];
        for (int i = 0; i < col; i++) {
          temp[0][i] = matrix[row1][i];
          matrix[row1][i] = matrix[row2][i];
          matrix[row2][i] = temp[0][i];
        }
      } else {
        cout << "Could not access specified row to swap.\n";
      }
    }

    // Compute the reduced row-echelon form of a matrix.
    void matrixRREF() {
      int lead = 0;
      for (int r = 0; r < row; r++) {
        if (lead >= col) {
          return;
        }
        int i = r;
        while (matrix[i][lead] == 0) {
          i += 1;
          if (i == row) {
            i = r;
            lead += 1;
            if (col == lead) {
              return;
            }
          }
        }
        swapRows(i, r);
        int val = matrix[r][lead];
        if (matrix[r][lead] != 0) {
          for (int j = 0; j < col; j++) {
            matrix[r][j] /= val;
          }
        }
        for (int i = 0; i < row; i++) {
          if (i != r) {
            int val = matrix[i][lead];
            for (int j = 0; j < col; j++) {
              matrix[i][j] -= (val * matrix[r][j]);
            }
          }
        }
        lead += 1;
      }
      displayMatrix();
    }

    // TODO: Finds the determinant of a matrix.
    int determinantFinder() {
      if (col == row) {
        int determinant;
        if (row == 1) {
          determinant = matrix[0][0];
        } else if (row == 2) {
          determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        } else {
          for (int p = 0; p < row; p++) {
            int h = 0,
              k = 0;
            for (int i = 1; i < row; i ++) {
              for (int j = 0; j < n; j++) {
                if (j == p) {
                  continue;
                }
                // temp[h][k] = matrix[i][j];
                k++;
                if (k == n - 1) {
                  h++;
                  k = 0;
                }
              }
            }
            //determinant = determinant + matrix[0][p] * pow(-1, p) * determinantFinder(temp, n -1);
          }
          //return determinant;
        }
        cout << "The determinant of this matrix is: " << determinant << endl;
      } else {
        cout << "Cannot find the determinant of this matrix. (Must be nxn)\n";
      }
    }

    // TODO: Inverses a matrix.
    void inverseMatrix() {
      if (col == row) {
        //TODO
      } else {
        cout << "Cannot invert this matrix. (Must be nxn)\n";
      }
    }
};

int main () {
  cout << "Welcome to Matrix Calculator V1.1 By Baraa Hamodi!\n\n"
     << "Start by making your first matrix!\n";
  Matrix a;
  a.getInput();
  int choice;
  string proceed, remakeMatrix;
  cout << "Now that you have this matrix:\n";
  a.displayMatrix();
  cout << "What would you like to do?\n"
     << "Enter 1 for matrix scalar multiplication.\n"
     << "Enter 2 for matrix addition.\n"
     << "Enter 3 for matrix multiplication.\n"
     << "Enter 4 to find the matrix determinant.\n"
     << "Enter 5 to transpose the matrix.\n"
     << "Enter 6 to find the inverse of your matrix.\n"
     << "Enter 7 to put your matrix in RREF.\n";
  do {
    cout << "Please enter your operation choice: ";
    cin >> choice;
    if (choice == 1) {
      a.scalarMultiplication();
    } else if (choice == 2) {
      cout << "This will require a second matrix, please create one now.\n";
      Matrix b;
      b.getInput();
      a.matrixAddition(b);
    } else if (choice == 3) {
      cout << "This will require a second matrix, please create one now.\n";
      Matrix b;
      b.getInput();
      a.matrixMultiplication(b);
    } else if (choice == 4) {
      a.determinantFinder();
    } else if (choice == 5) {
      a.transpose();
    } else if (choice == 6) {
      a.inverseMatrix();
    } else if (choice == 7) {
      a.matrixRREF();
    }
    cout << "Continue? (Enter yes or no) ";
    cin >> proceed;
    transform(proceed.begin(), proceed.end(), proceed.begin(), ::tolower);
    if (proceed == "yes") {
      cout << "Now enter yes to create a new matrix or no to use current matrix.\n";
      cin >> remakeMatrix;
      transform(remakeMatrix.begin(), remakeMatrix.end(), remakeMatrix.begin(), ::tolower);
      if (remakeMatrix == "yes") {
        a.getInput();
      }
    }
  } while(proceed == "yes");

  system("PAUSE");
  return EXIT_SUCCESS;
}

/*******************************************************************************
*   Copyright(c) 2014-Present, Baraa Hamodi. Students, staff, and faculty      *
*   members at the University of Waterloo are granted a non-exclusive right to *
*   copy, modify, or use this software for non-commercial teaching, learning,  *
*   and research purposes provided the author is acknowledged.                 *
*******************************************************************************/
