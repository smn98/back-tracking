#include<stdio.h>
#include<stdlib.h>
#define D 4
//I'll comment later :P
void printSol(int* color){
	printf("Solution Exists:"
            " Following are the assigned colors \n"); 
    for (int i = 0; i < D; i++) 
      printf(" %d ", color[i]); 
    printf("\n"); 
}
int isSafe(int graph[][4], int* color,int c,int v){
	for(int i=0;i<D;i++)
		if(graph[v][i] && color[i] == c)
			return false;
	return true;
}
int graphColor(int graph[][4], int* color, int m, int v){
	if(v==D){
		printSol(color);
		return true;
	}
	int res = false;
	for(int c=1; c<=m;c++){
		if(isSafe(graph,color,c,v)){
			color[v] = c;
			res = graphColor(graph,color,m,v+1) || res;
			color[v] = 0;
		}
	}
	return res;
}

int main(){
	int graph[D][D] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    }; 
		
	int* color = (int*)calloc(D,sizeof(int));
			
	graphColor(graph,color,3,0);
	return 0;
}
