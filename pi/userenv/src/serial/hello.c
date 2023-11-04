#include <stdio.h>
#include <time.h>
#include <math.h>

int main(char *argc, char **argv) {
    double t0, t1, t2, t3, s=0.0;
    // fundamental arithmetic type representing clock tick counts.
    clock_t start, end; 
    int i;
    start = clock();
    for (i=0;i<1000000000;i++){ 
        s=i/2.0*4.9; // doing some floating point operations
    }
    end = clock();
    double time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
    printf("\ntime_computing_in_sec: %e\n", time_elapsed_in_seconds);
    start = clock();
    system ("sleep 5"); // just sleep, does this accumulate CPU time?
    end = clock();
    time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
    printf("\ntime_sleeping_in_sec: %e\n", time_elapsed_in_seconds);
    return 0;
}
