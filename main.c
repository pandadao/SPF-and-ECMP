#include <stdio.h>


#define INFINITE 9999



int main(int argc, char *argv[]){


		/* open file of the constellation network data.  */
		FILE *pFile;
		pFile = fopen("const36", "r");

		int matrix_range = 0;
		fscanf(pFile, "%d",&matrix_range);
		
		
		/* Initial the matrix to save data about the network state.  */
		int N = 0, M = 0;
		int MatrixTable[matrix_range][matrix_range];
		for(N = 0; N < matrix_range; N++){
		
				for(M = 0; M < matrix_range; M++){
				
						MatrixTable[M][N] = INFINITE;
				}
		}   

		for(N = 0; N < matrix_range; N++){
		
				MatrixTable[N][N] = 0;
		}

	
		/* Read end node and link number . */
		int end_node = 0, link_number = 0;
		fscanf(pFile, "%d", &end_node);
		fscanf(pFile, "%d", &link_number);

		
		/* Add link to MatrixTable.  */
		int rowLine = 0, columnLine = 0;
		while(fscanf(pFile, "%d %d", &rowLine, &columnLine) != EOF){
		
				MatrixTable[rowLine][columnLine] = 1;
		}


		/* close the file and free pointer.  */
		fclose(pFile);
		
		
		/* Link become 1, others no change their state.    */
		/* And show the matrix for check symmetry.  */
		int row = 0, columns = 0;
		for(row = 0; row<matrix_range;row++){
		
				for(columns = 0; columns < matrix_range; columns++){
				
						printf("%4d ", MatrixTable[row][columns]);
				}
				printf("\n");
		}
		

		return 0;

}
