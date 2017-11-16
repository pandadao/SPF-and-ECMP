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

	
		/* Read end node and link number . */
		int end_node = 0; link_number = 0;
		fscanf(pFile, "%d\n", &end_node);
		fscanf(pFile, "%d\n", &link_number);

		
		/* Add link to MatrixTable.  */

		

}
