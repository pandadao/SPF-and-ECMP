#include <stdio.h>
#include <string.h>


int main(){

		//Read file of constellation network link.
		FILE *pFile;
		pFile = fopen("const36", "r");

		int i = 0, j = 0;
		int matrix_t[10];
		fscanf(pFile, "%d\n", &matrix_t[i]);
		i++;

		fscanf(pFile, "%d\n", &matrix_t[i]);
		i++;

		fscanf(pFile, "%d\n", &matrix_t[i]);
		i++;

		for(j = 0; j<4;j++){
				printf("%d\n", matrix_t[j]);
		}

		fclose(pFile);
		return 0;

}
