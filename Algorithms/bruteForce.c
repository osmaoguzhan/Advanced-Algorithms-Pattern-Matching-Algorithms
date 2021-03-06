#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>	/* for uint64 definition */
#include <time.h>	/* for clock_gettime */
#define BILLION 1000000000L
char *FileToString(FILE *fp){
    char *buffer;
    long numbytes;
    fseek(fp, 0L, SEEK_END);
    numbytes = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    buffer = (char*)calloc(numbytes, sizeof(char));
    fread(buffer, sizeof(char), numbytes, fp);
    fclose(fp);
    return buffer;
}
void bruteForce(char *text,char *word){
	int m=strlen(word);
	int n=strlen(text);
	int i= 0;
	for(i=0; i< n-m+1; i++){
		int j=0;
		while(j<m && text[i+j]==word[j]){
			j++;
		}
		if(j==m){
			;
		}
	}
}

int main(){
	
	uint64_t diff;
	struct timespec start, end;
    FILE *fp = fopen("char.txt", "r");
    char word[] = "himself";
	char *text = FileToString(fp);
	clock_gettime(CLOCK_MONOTONIC, &start);
	bruteForce(text,word);
    clock_gettime(CLOCK_MONOTONIC, &end);
	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("CLOCK_MONOTONIC = %llu nanoseconds\n", (long long unsigned int) diff);
	
	return 0;
}
