#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define d 256
long int q = 2521008887; //Unique prime number
void search(char **pat, char **txt,long int q,int txtRow,int txtCol,int K)
{
    int p = 0;
    int t;
	int k,z;
    //pattern hashing
	for(int j=0;j<K;j++){
		for (int i = 0; i < K; i++) {
        	p = ((d * p + pat[j][i]) & q);
    	}
    }
    //24-38 displaying random matrix and pattern
    printf("\nUNIVERSITY OF LODZ - ADVANCED ALGORITHMS (2D RABIN-KARP)\n");
    printf("\n--------------2D Array--------------\n");
    for(int j=0;j<txtRow;j++){
		for (int i = 0; i < txtCol; i++) {
      		printf("%c ",txt[j][i]);
	  	}
	  	printf("\n");
    }
    printf("\n--------------Pattern--------------\n");
    for(int j=0;j<K;j++){
		for (int i = 0; i < K; i++) {
      		printf("%c ",pat[j][i]);
	  	} 
	  	printf("\n");
    }
    printf("----------------------------\n");

    // touring inside the matrix
    for (int i = 0; i <=txtRow - K; i++) {
    	for(int j=0;j<=txtCol-K;j++){
            //text hashing
        	t=0;
            for(int m=i;m<i+K;m++){
				for (int n = j; n <j+K; n++) {
        			t = ((d * t + txt[m][n]) & q);
    			}
    		}
            //if the hashes are equal then do brute force
    		if (p == t) {
				for ( k = 0; k<K ; k++){
                	for( z=0; z<K;z++){
                    	if (txt[i+k][j+z] != pat[k][z]){
                        	goto A; //if the chars are not same then go to label
                    	}
                	}
            	}
            	A:
            	if (k == K && z == K)
                	printf("Pattern found at [%d,%d]\n", i,j);
        	}
    	}
	}
}
int main(){
	srand(time(NULL));
	char *alphabet="10";
	int M,N,K;
	printf("Row number:");
	scanf("%d",&M);
	printf("Column number:");
	scanf("%d",&N);
	printf("K: ");
	scanf("%d",&K);
	if(K>M || K>N){
		printf("K should not be greater than M and N!!");
	}else{
		char **tDarray = (char **)malloc(M * sizeof(char *));
    	for (int i=0; i<M; i++)
         	tDarray[i] = (char *)malloc(N * sizeof(char));
		int patRow =(int)ceil(M/3.0);
		int patCol =(int)ceil(N/3.0);
    	char **pattern = (char **)malloc(patRow * sizeof(char *));
    	for (int i=0; i<M; i++)
         	pattern[i] = (char *)malloc(patCol* sizeof(char));
    	//random matrix
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				int random=rand()%2;
				tDarray[i][j]=alphabet[random];
			}
		}
    	//pattern which is equal to top-right of matrix
    	for(int i=0,k=0;i<K;i++,k++){
			for(int j=N-K,l=0;j<N;j++,l++){
				pattern[k][l]=tDarray[i][j];
			}
		}
	search(pattern,tDarray,q,M,N,K);
	}
    return 0;
}
