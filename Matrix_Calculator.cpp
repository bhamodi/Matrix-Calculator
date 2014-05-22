/*******************************************************************************
*   Name: Baraa Hamodi                                                         *
*   Last Update Date: 05/17/2014                                               *
*   Contents: A fully loaded matrix class capable of scalar multiplication,    *
*             matrix addition, matrix multiplication, determinant finder, etc. *
*******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

class Matrix {
    private:
        int row, col, scalar;
        int matrix[10][10];
        int result[10][10];
    
    public:
        // Default Constructor
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
        
        // Constructor
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
        
        // Important hack
        int& operator()(int row, int col) {
            return matrix[row][col];
        }
        
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
        
        void displayMatrix() {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    cout << setw(3) << matrix[i][j];
                }
                cout << endl;
            }
        }
        
        void displayResultMatrix(int rows, int cols) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << setw(3) << result[i][j];
                }
                cout << endl;
            }
        }
        
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
        
        //NEEDS WORK
        void matrixRREF() {
            for (int c = 0; c < col; c++) {
                for (int r = 0; r < row; r++) {
                    if (matrix[c][c] != 1) {
                        for (int i = 0; i < col; i++) {
                            matrix[0][i] *= 1/matrix[0][0];
                        }
                    }
                    if (matrix[r+1][0] != 0) {
                        int num = matrix[r+1][0];
                        for (int k = 0; k < col; k++) {
                            matrix[r+1][k] += -1*num*matrix[0][k];
                        }
                    }
                }
            }
            displayMatrix();
        }
        
        int determinantFinder() {
            if (col == row) {
                //do
            } else {
                cout << "Cannot find the determinant of this matrix. (Must be nxn)\n";
            }
        }
        
        void inverseMatrix() {
            if (col == row) {
                //do
            } else {
                cout << "Cannot invert this matrix. (Must be nxn)\n";
            }
        }
};

int main ()
{
	cout << "Welcome to Matrix Calculator V1.0 By Baraa Hamodi!\n\n"
	     << "Start by making your first matrix!\n";
    Matrix a;
	a.getInput();
	int choice;
	string continueDecision, matrixDecision;
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
    	    //do
    	} else if (choice == 5) {
    	    a.transpose();
    	} else if (choice == 6) {
    	    //do
    	} else if (choice == 7) {
    	    a.matrixRREF();
    	}
    	cout << "Continue? (Enter yes or no) ";
        cin >> continueDecision;
        if (continueDecision == "yes" || continueDecision == "Yes") {
            cout << "Now enter yes to create a new matrix or no to use current matrix.\n";
            cin >> matrixDecision;
            if (matrixDecision == "yes" || matrixDecision == "Yes") {
                a.getInput();
            }
        }
    } while(continueDecision == "yes" || continueDecision == "Yes");
    
	system("PAUSE");
	return EXIT_SUCCESS;
}

/*******************************************************************************
*   Copyright(c) 2014 Baraa Hamodi.  Students, staff, and faculty members at   *
*   the University of Waterloo are granted a non-exclusive right to copy,      *
*   modify, or use this software for non-commercial teaching, learning, and    *
*   research purposes provided the author(s) are acknowledged except for as    *
*   noted below.                                                               *
*******************************************************************************/
