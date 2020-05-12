#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>	/* for uint64 definition */
#include <time.h>	/* for clock_gettime */
#include <windows.h>
#define BILLION 1000000000L
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
   if(!QueryPerformanceFrequency(&li))
    	printf("QueryPerformanceFrequency failed!\n");

    PCFreq = double(li.QuadPart)/1000000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double((li.QuadPart-CounterStart)/PCFreq) ;
}
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
	char *text=FileToString(fp);
	StartCounter();
	bruteForce(text,word);
	float counter = GetCounter();
	printf("QueryPerformanceCounter = %0.10f",counter);
    
	return 0;
}
