#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "mpi.h"

// Serial code from https://www.olcf.ornl.gov/tutorials/monte-carlo-pi/
// Parallelized by Yuwu Chen for LSU HPC training purpose only
//


int  main(int argc, char ** argv)
{
    uint64_t niter;
    int rank, psize;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &psize);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(argc > 2)
    {
    if (rank==0)
    printf("too many arguements, no need to provide number_points, or just use: %s [num_points]\n", argv[0]);
    return 0;
    }
    else if (argc ==2)
    niter=atol(argv[1]);
    else 
    niter=1000000000000;
    if (rank==0)
    printf("niter=%llu\n",niter);
    long nlocal, n_start,n_end;
    nlocal=niter/psize;
    n_start=rank*nlocal;
    if (rank==psize-1)
    n_end=(rank+1)*nlocal-1+niter%psize;
    else
    n_end=(rank+1)*nlocal-1;
    //printf("n_start and n_end on rank %d are %ld and %ld\n",rank,n_start,n_end);
    
    double x,y;
    long i;
    long count=0,count_glb=0;
    double z;
    double pi;
    srand(time(NULL)+rank);
    //main loop
    for (i=n_start; i<=n_end; ++i)
    {
        //get random points
        x = (double)random()/RAND_MAX;
        y = (double)random()/RAND_MAX;
        z = ((x*x)+(y*y));
   // printf("x=%f,y=%f,z=%f",x,y,z);
        //check to see if point is in unit circle
        if (z<=1)
        {
            ++count;
        }
    }
   printf("rank %d has %ld counts in circle out of %ld\n",rank,count, n_end-n_start+1);
    // collect count from each process
    MPI_Allreduce(&count,&count_glb,1,MPI_LONG,MPI_SUM,MPI_COMM_WORLD);
    // calculate pi
        pi = ((long double)count_glb/(long double)niter)*4.0;          //p = 4(m/n)
    if (rank==0) {
    printf("total counts in circle:%ld\n",count_glb);
    printf("Pi: %f\n", pi);
    }
    MPI_Finalize();
    return 0;
}
