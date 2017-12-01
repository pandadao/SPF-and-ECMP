#include <stdio.h>
#include<string.h>
#include <stdbool.h>

#define INFINITE 9999
#define UNDEFINED -999

int stack[36],m = 1;
int testTable[36][36];

/* Here is the dijkstra algorithm for counting the shortest path.  */
int dijkstra(int source_node, int destination_node, int matrix_range, int MatrixTable[matrix_range][matrix_range]){
		
		int distance[matrix_range], prev_node[matrix_range], i,m, min_dis, start, d,j, pathcount = 0;
		int select[matrix_range];
		char path[matrix_range];

		for(i = 0; i< matrix_range; i++)
				select[i] = 0;
		
		for(i = 0; i<matrix_range;i++){
		
				distance[i] = INFINITE;
				prev_node[i] = -1;
		}
		start = source_node;
		select[start] = 1;
		distance[start] = 0;
		while(select[destination_node] == 0){
				
				min_dis = INFINITE;
				m = 0;
				for(i=0; i < matrix_range; i++){
				
						d = distance[start] + MatrixTable[start][i];
						if(i == destination_node && MatrixTable[start][i] != INFINITE){
						
								distance[i] = d;
								prev_node[i] = start;
								min_dis = distance[i];
								m = i;
								break;
						}

						if(d < distance[i] && select[i] == 0){
						
								distance[i] = d;
								prev_node[i] = start;
						}
						if(min_dis > distance[i] && select[i] == 0){
						
								min_dis = distance[i];
								m = i;
						}
				}
				start = m;
				select[start] = 1;
				//printf("%d ", m);
				//path[pathcount] = m;
				//pathcount++;
		}
		start = destination_node;
		i = 0;
		
		
		while(start != -1){
		
				path[j++] = start;
				start = prev_node[start];
		}
		path[j] = '\0';
		//strrev(path);
		for(i = j-1; i >= 0; i--){
		
				if(path[i] != -1)
						printf("%d ", path[i]);
		}
		

		return distance[destination_node];

}   


/* Implement ecmp algorithm.  */
int ecmp(int matrix_range,int MatrixTable[matrix_range][matrix_range],int source_node, int destination_node,int shortest_cost, FILE *opFILE){
		
		int i = 0,j = 0;
		for(i = 0;i< matrix_range; i++){
				
				if(MatrixTable[source_node][i] == 1){
						
						if(i == destination_node){
						
								for(j = 0; j < m; j++){
								
										printf("%-3d", stack[j]);
										fprintf(opFILE, "%-3d", stack[j]);
								}
								printf("%-3d\n",destination_node);
								fprintf(opFILE, "%-3d\n", destination_node);
						}
						else if(m < shortest_cost){
						
								stack[m] = i;
								m++;
								ecmp(matrix_range, MatrixTable, i, destination_node, shortest_cost, opFILE);
								m--;
						}
				}
		}

}


void link_disjoint(FILE *opFILE){

		printf("Link disjoint find:\n");
		fseek(opFILE, 0, SEEK_SET);
		char buf[10];
		while(fgets(buf, 10, opFILE) != NULL){
				printf("%s", buf);
		}
		printf("\n");
}



int main(int argc, char *argv[]){


		/* open file of the constellation network data.  */
		FILE *pFile;
		pFile = fopen("const36", "r");

		int matrix_range = 0;
		fscanf(pFile, "%d",&matrix_range);
		
		
		/* Initial the matrix to save data about the network state.  */
		int N = 0, M = 0, co;
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
		
		int *matrix_table = MatrixTable[0];



		/* close the file and free pointer.  */
		fclose(pFile);
		
		
		/* Link become 1, others no change their state.    */
		/* And show the matrix for check symmetry.         */
		int row = 0, columns = 0;
		
		
		
		/*   
		 *  Here is function to printf matrix about saving link information.
		 *
		for(row = 0; row<matrix_range;row++){
		
				for(columns = 0; columns < matrix_range; columns++){
				
						printf("%4d ", MatrixTable[row][columns]);
				}
				printf("\n");
		}    */
		

		/* Get the source node and destination node from user. */
		int source_node = 0, destination_node = 0;
		printf("\nEnter the source node number: ");
		scanf("%d", &source_node);
		printf("\nEnter the destination node number: ");
		scanf("%d", &destination_node);
		
		/* Transfer matrix data to dijkstra function.     */
		co = dijkstra(source_node, destination_node, matrix_range, MatrixTable);
		printf("\nThe shortest path cost: %d\n\n\n", co);
		
		FILE *opFILE;
		opFILE = fopen("operate-file", "w+");


		stack[0] = source_node;
		int shortest_cost = co;
		ecmp(matrix_range, MatrixTable, source_node, destination_node, shortest_cost, opFILE);

		link_disjoint(opFILE);
		fclose(opFILE);


		return 0;

}
