program hello
include 'mpif.h' 

integer rank, proc, ierr, status(MPI_STATUS_SIZE)   

call MPI_Init(ierr)
call MPI_Comm_Size(MPI_COMM_WORLD, proc, ierr)
call MPI_Comm_Rank(MPI_COMM_WORLD, rank, ierr)

 write(6,*) "Hello from", rank, "of", proc
 call MPI_Finalize(ierr)
 end

