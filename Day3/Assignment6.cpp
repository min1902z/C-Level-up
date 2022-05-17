#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool importData(int** pArr,int szRow,int szCol);
void printMatrix(int** pArr,int szRow,int szCol);
int** addMatrix(int** pArr1,int **pArr2,int szRow,int szCol);
void freeMem(int** pArr,int szRow,int szCol);
int main(int argc, char** argv) {
	int iRow, iCol, szRow, szCol;
	int **pArr1, **pArr2, **Sum;
	
	cout << "Enter Size of Row: ";
	cin >> szRow;
	
	cout << "Enter Size of Column: ";
	cin >> szCol;
	
	pArr1 = new int*[szRow];
	for(iRow = 0; iRow < szRow; iRow++){
		pArr1[iRow] = new int[szCol];
	}
	
	pArr2 = new int*[szRow];
	for(iRow = 0; iRow < szRow; iRow++){
		pArr2[iRow] = new int[szCol];
	}
	
	cout << "\n Enter Matrix 1:";
	importData(pArr1, szRow, szCol);
	cout << "\n Enter Matrix 2:";
	importData(pArr2, szRow, szCol);
	
	Sum = (int**)addMatrix(pArr1, pArr2, szRow, szCol);
	cout << "\nMatrix 1:";
	printMatrix(pArr1, szRow, szCol);
	cout << "\nMatrix 2:";
	printMatrix(pArr2, szRow, szCol);
	cout << "\nMatrix Sum:";
	printMatrix(Sum, szRow, szCol);
	
	freeMem(pArr1, szRow, szCol);
	freeMem(pArr2, szRow, szCol);
	freeMem(Sum, szRow, szCol);
	
	return 0;
}
/******************************
* Function name: importData()
* Description: import data of matrix
* Parameter: 
	int** pArr(I): array pointer of matrix
	int szRow(I): size of row
	int szCol(I): size of column
* Return value: boolean
*******************************/
bool importData(int** pArr,int szRow,int szCol)
{
	int iRow, iCol;
	if(pArr){
		for(iRow = 0; iRow < szRow; iRow++){
			for(iCol = 0; iCol < szCol; iCol++){
				cout << "\nEnter Matrix[" << iRow << "]" << "[" << iCol << "]" << endl;
				cin >> pArr[iRow][iCol];
			}
		}	
		return true;
	}
	return false;
}
/******************************
* Function name: printMatrix()
* Description: print out matrix
* Parameter: 
	int** pArr(I): array pointer of matrix
	int szRow(I): size of row
	int szCol(I): size of column
* Return value: void
*******************************/
void printMatrix(int** pArr,int szRow,int szCol)
{
	int iRow, iCol;
    for(iRow = 0; iRow < szRow; iRow++){
        cout << "\n";
        for (iCol = 0; iCol < szCol; iCol++){
            cout << pArr[iRow][iCol] << " ";
        }
    }
}
/******************************
* Function name: addMatrix()
* Description: calculate sum of 2 matrix
* Parameter: 
	int** pArr1(I): array pointer of matrix 1
	int** pArr2(I): array pointer of matrix 2
	int szRow(I): size of row
	int szCol(I): size of column
* Return value: int, sum of 2 matrix
*******************************/
int** addMatrix(int** pArr1,int** pArr2,int szRow,int szCol)
{
	int iRow, iCol;
	int **Sum;
    Sum = new int*[szRow];
	    for(iRow = 0; iRow < szRow; iRow++){
	        Sum = new int*[szCol];
	    }
	    for(iRow = 0; iRow < szRow; iRow++){
	    	for (iCol = 0; iCol < szCol; iCol++){
	        	Sum[iRow][iCol] = pArr1[iRow][iCol] + pArr2[iRow][iCol];
	    	}
	    }
    return Sum;
}
/******************************
* Function name: freeMem()
* Description: free allocated memory
* Parameter: 
	int** pArr(I): array pointer of matrix
	int szRow(I): size of row
	int szCol(I): size of column
* Return value: void
*******************************/
void freeMem(int** pArr,int szRow,int szCol)
{
	for(int i = 0; i < szRow; i++){
		if(pArr[i]){
			delete[] pArr[i];
			pArr[i] = NULL;
		}
	}
	if(pArr){
		delete[] pArr;
	}
}
