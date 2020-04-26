#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>	
#define BILLION 1000000000L

void sunday(char *P,char *T){
	int m = strlen(P);
    int n = strlen(T);

    int lastoccoff[127];
    for(int j=0; j<127; j++)
    {
        lastoccoff[j]=-1;
    }
    for(int j=0; j<m; j++)
    {
        lastoccoff[P[j]]=j;
    }
    int i;
    for(i=0; i<n-m; i+=m-lastoccoff[T[i+m]])
    {
        int j=0;
        while (j<m && T[i+j]==P[j])
        {
            j++;
        }
        if(j==m){
        	printf("Ann occ at %d\n",i);
        }
    }
    if(i==n-m){
        int j=0;
        while (j<m && T[i+j]==P[j])
        {
            j++;
        }
        if(j==m){
        	int a=0;
            printf("Ann occ at %d\n",i);
        }
    }
	
}
char *FileToString(FILE *infile){
    char *buffer;
    long numbytes;
    fseek(infile, 0L, SEEK_END);
    numbytes = ftell(infile);
    fseek(infile, 0L, SEEK_SET);
    buffer = (char*)calloc(numbytes, sizeof(char));
    fread(buffer, sizeof(char), numbytes, infile);
    fclose(infile);
    return buffer;
}
int main()
{
	uint64_t diff;
	struct timespec start, end;
	FILE *infile = fopen("10000.txt", "r");
	char P[] = "he";
	clock_gettime(CLOCK_MONOTONIC, &start);
	sunday(P,FileToString(infile));
    clock_gettime(CLOCK_MONOTONIC, &end);
	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %11u nanoseconds\n", (long long unsigned int) diff); 
    return 0;
}

