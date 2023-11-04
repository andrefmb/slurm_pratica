#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Original code from https://www.olcf.ornl.gov/tutorials/monte-carlo-pi/
// Modified by Yuwu Chen for LSU HPC training purpose only
// May be compiled by icc or gcc
// To compile with gcc, use "-lm" (without quotes) option to link the math library
int  main(int argc, char ** argv)
{
    uint64_t niter;
    if(argc < 2)
    {
    niter=1000000000;
    printf("niter=%llu\n",niter);
    }
    else if (argc ==2)
    {
    niter=atol(argv[1]);
    printf("niter=%llu\n",niter);
    }
    else
    {
    printf("too many arguements, need use: %s [num_points]\n", argv[0]);
    return 0;
    }
    double x,y;
    long i;
    long count=0;
    double z;
    double pi;
    srand(time(NULL));
    //main loop
    for (i=0; i<niter; ++i)
    {
        //get random points
        x = (double)random()/RAND_MAX;
        y = (double)random()/RAND_MAX;
        z = sqrt((x*x)+(y*y));
        //check to see if point is in unit circle
        if (z<=1)
        {
            ++count;
        }
//    }
        pi = ((long double)count/(long double)niter)*4.0;          //p = 4(m/n)
    }
    printf("count in circle:%ld\n",count);
    printf("Pi: %f\n", pi);
    return 0;
}
