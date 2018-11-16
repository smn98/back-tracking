#include<stdio.h>
#include<stdlib.h>
#define D 10

void printSol(int** queen) 
{ 
    for (int i = 0; i < D; i++) 
    { 
        for (int j = 0; j < D; j++) 
            printf(" %d ", queen[i][j]); 
        printf("\n"); 
    }
	printf("\n"); 
} 
  
int isSafe(int** queen,int row, int col){
	
	int i,j;
	//check this row upwards
	for(i=0; i<row;i++)
		if(queen[i][col])
			return false;
	//check upper left diagonal
	for(i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
		if(queen[i][j])
			return false;
	//check upper right diagonal
	for(i=row-1, j=col+1; i>=0 && j<D;i--,j++)
		if(queen[i][j])
			return false;
			
	return true;
}


int nQueens(int** queen,int row){
	
	if(row >= D){
		printSol(queen);
		return true;
	}
	
	int res = false;	
	for(int j=0; j<D; j++){
		if(isSafe(queen,row,j)){
			
			queen[row][j] = 1;
			
			res = nQueens(queen,row+1) || res;
				
			queen[row][j] = 0; 
		}
	}
	return res;
}

int main(){
	int** queen = (int**)calloc(D,sizeof(int*));
	for(int i=0; i<D; i++)
		queen[i] = (int*)calloc(D,sizeof(int));
	nQueens(queen,0);
	return 0;
}
