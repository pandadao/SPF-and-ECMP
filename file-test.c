#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(FILE *pFile){

		char buf[10];
		fseek(pFile, 0, SEEK_SET);
		while(fgets(buf, 10, pFile) != NULL)
				printf("%s", buf);
				printf("\n");
}



int main(){

		FILE *pFile;
		int matrix[10][10];
		int i = 0, j = 0;
		pFile = fopen("test-file", "w+");
		for(i = 0; i<10; i++){
		
				for(j = 0; j< 10; j++){
				
						matrix[i][j] = i+j;
				}
		}


		for(i = 0; i<10; i++){
		
				for(j = 0; j< 10; j++){
				
						fprintf(pFile,"%-3d", matrix[i][j]);
				}
				fprintf(pFile,"\n");
		}

		print(pFile);

		fclose(pFile);


return 0;
}
