#include <stdio.h>
#include "mpi.h"
#include <omp.h>

int main(int argc, char *argv[]) {
    int numprocs, nrank, namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int gtd=0, itd=0, gid=0, np = 1;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &nrank);
    MPI_Get_processor_name(processor_name, &namelen);

#pragma omp parallel default(shared) private(itd, np)
    {
        gtd = omp_get_num_threads();
        itd = omp_get_thread_num();
        gid = nrank*gtd + itd;// global id
        printf("Gid %d from thread %d out of %d from process %d out of %d on %s\n",
                gid, itd, gtd, nrank, numprocs, processor_name);
        if (nrank==0 && itd==0) 
        {
            // system("pstree -ap -u $USER");
            //system("for f in `cat $PBS_NODEFILE|uniq`; do ssh $f pstree -ap -u $USER; done;");
            //system("sleep 10");
        }
    }

    if (nrank==0) 
        system("hostname && date && echo rank-pid $$");

    MPI_Finalize();
}
