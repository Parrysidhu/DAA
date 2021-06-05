#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<math.h>
#define v 7

void distance(int E[v][v], int source)
{
	int D[v];
	bool in[v];
	int m, ind;

	for (int i = 0; i < v; i++) {
		D[i] = INT_MAX, in[i] = false;   //Initializing the values
	}

	D[source] = 0; //distance from source will always be 0.

	for (int c = 0; c < v - 1; c++) {
		m = INT_MAX;
		for(int j=0; j<v; j++) {
			if(in[j]==false && D[j]<=m) {
				m=D[j], ind=j;
			}
		}

		int u = ind;
		in[u] = true;
		for (int j = 0; j < v; j++) {
			if ( !in[j] && E[u][j] && D[u] != INT_MAX && D[u] + E[u][j] < D[j] ) {
				D[j] = fmin( D[j], D[u] + E[u][j] ); //Update the distance using the logic given in notes
			}
		}
	}

	printf("The distance from source to each vertex is:\n");
	printf("\nvertex \t distance\n");
	for(int i=0;i<v;i++) {
		printf("%d \t %d\n",i,D[i]);  //print the distance and vertex
	}
}

int main() {
	int source;
	int E[v][v]={{0,8,6,3,6,1000,1000},
				{8,0,12,1000,1000,1000},
				{6,12,0,8,1000,1000,7},
				{3,1000,8,0,4,3,4},     //Enter the matrix for graph in problem1
				{6,1000,1000,4,0,3,1000},
				{1000,1000,1000,3,3,0,2},
				{1000,1000,7,4,1000,2,0},
			};

	printf("\nEnter source no. :");
	scanf("%d", &source);
	distance(E,source);
	return 0;
}
