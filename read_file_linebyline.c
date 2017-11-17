#include <stdio.h>
#include <string.h>


int main(){

		//Read file of constellation network link.
		FILE *pFile;
		pFile = fopen("const36", "r");

		int i = 0, j = 0;
		int matrix_t[10];
		fscanf(pFile, "%d", &matrix_t[i]);
		i++;

		fscanf(pFile, "%d", &matrix_t[i]);
		i++;

		fscanf(pFile, "%d", &matrix_t[i]);
		i++;

		int table[36][36] = {0};
		int n = 0, m = 0, rowLine = 0, columnLine = 0;
		while(fscanf(pFile,"%d %d", &rowLine, &columnLine) != EOF){
				
				printf("%d, %d\n", rowLine, columnLine);
		}

		fclose(pFile);
		return 0;

}
