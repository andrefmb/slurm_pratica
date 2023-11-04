program hello_mpi
    include 'mpif.h'
    character*20 name
    ! Initialize the MPI library:
    call MPI_Init(ierr)
    ! Get size and nrank
    call MPI_Comm_Size(MPI_COMM_WORLD, numtasks, ierr)
    call MPI_Comm_Rank(MPI_COMM_WORLD, nrank, ierr)
    ! print date
    if (nrank == 0) then
        write(*,*)'System date'
        call system('date')
    endif
    call MPI_Barrier(MPI_COMM_WORLD, ierr)
    ! print nrank
    call MPI_Get_Processor_Name(name, len, ierr)
    write(*,*)"I am ", nrank, "of", numtasks, "on ", name
    call MPI_Barrier(MPI_COMM_WORLD, ierr)
    ! Tell the MPI library to release all resources it is using:
    call MPI_Finalize(ierr)
end program hello_mpi
