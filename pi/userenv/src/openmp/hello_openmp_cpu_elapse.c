// http://stackoverflow.com/questions/5362577/c-gettimeofday-for-computing-time
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(char *argc, char **argv) {
    const long N = 10000000000;
    double t0, t1, t2, t3, sum=0.0; 
    // fundamental arithmetic type representing clock tick counts.
    clock_t start, end; 
    struct timeval r_start, r_end;
    int i;
    gettimeofday(&r_start, NULL);
    start = clock();
    // openmp directives
    #pragma omp parallel for
        for (i=0;i<N;i++) 
            sum = i*sqrt(i/2.0)+ i/3.0*sqrt(i); // doing some floating point operations
            // b = i*2.0; // doing some floating point operations
    end = clock();
    //system("sleep 2");
    gettimeofday(&r_end, NULL);
    double cputime_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
    double realtime_elapsed_in_seconds = ((r_end.tv_sec * 1000000 + r_end.tv_usec)
              - (r_start.tv_sec * 1000000 + r_start.tv_usec))/1000000.0;
    printf("cputime_elapsed_in_sec: %e\n", cputime_elapsed_in_seconds);
    printf("realtime_elapsed_in_sec: %e\n", realtime_elapsed_in_seconds);
    printf("cputime / numcores: %e\n", cputime_elapsed_in_seconds/16);
    printf("cputime / realtime=%.2f\n",cputime_elapsed_in_seconds/realtime_elapsed_in_seconds);
    return 0;
}
