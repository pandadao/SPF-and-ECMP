#include <stdio.h>


#define INFINITE 9999



int main(int argc, char *argv[]){


		/* open file of the constellation network data.  */
		FILE *pFile;
		pFile = fopen("const36", "r");

		int matrix_range = 0;
		fscan(pFile, "%d\n",&matrix_range);
		
		/* Initial the matrix to save data about the network state.  */
		int N = 0, M = 0, MatrixTable[matrix_range][matrix_range]; 
		for(N = 0; N < matrix_range; N++){
		
				for(M = 0; M < matrix_range; M++){
				
						MatrixTable[M][N] = INFINITE;
				}
		}

		for(N = 0; N < matrix_range; N++){
		
				MatrixTable[N][N] = 0;
		}




}
