#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>	
#include <time.h>	
#define BILLION 1000000000L
#define d 256

void search(char pat[], char txt[], uint64_t q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }

            if (j == M)
                ;
        }

        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            if (t < 0)
                t = (t + q);
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
	char word[] = "himself";
	FILE *infile = fopen("char.txt", "r");
   	char *text=FileToString(infile);
	uint64_t q=168191651949749111;
    clock_gettime(CLOCK_MONOTONIC, &start);
    //search(word,text,q);
    clock_gettime(CLOCK_MONOTONIC, &end);
	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	//printf("elapsed time = %lllu nanoseconds\n", (long long unsigned int) diff);
	printf("%d",2521008887&112321);
    return 0;
}

