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
			printf("There is a match!! %d \n",i);
		}
	}
}

int main(){
	
	uint64_t diff;
	struct timespec start, end;
    FILE *fp = fopen("10000.txt", "r");
    char word[] = "And he looked over at the alarm clock, ticking on the chest of drawers. \"God in Heaven!\" he thought. It was half past six and the hands were quietly moving forwards, it was even later than half past, more like quarter to seven. Had the alarm clock not rung? He could see from the bed that it had been set for four o'clock as it should have been; it certainly must have rung. Yes, but was it possible to quietly sleep through that furniture-rattling noise? True, he had not slept peacefully, but probably all the more deeply because of that. What should he do now? The next train went at seven; if he were to catch that he would have to rush like mad and the collection of samples was still not packed, and he did not at all feel particularly fresh and lively.";
	clock_gettime(CLOCK_MONOTONIC, &start);
	bruteForce(FileToString(fp),word);
    clock_gettime(CLOCK_MONOTONIC, &end);
	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
	
	return 0;
}
