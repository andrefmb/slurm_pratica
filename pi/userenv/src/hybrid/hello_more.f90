program dummy

  use mpi

  implicit none

  character*MPI_MAX_PROCESSOR_NAME, save ::  pname
  integer mpierr, itd, gtd, nproc, nrank, grank, nlen

! Init MPI
    call MPI_Init(mpierr)

! Get Rank, Size
    call MPI_COMM_Rank(MPI_COMM_WORLD, nrank, mpierr)
    call MPI_COMM_Size(MPI_COMM_WORLD, nproc, mpierr)

! Print rank
    call MPI_GET_PROCESSOR_NAME(pname, nlen, mpierr)

! Get Date hostname etc
    if (nrank==0) then
        call system('tput setaf 2; tput smso; &
                     echo hostname/date; tput sgr0; &
                     hostname; date')
        write(6,*) "+---------------------------+"
        write(6,*) " "
        call system('tput setaf 2; tput smso; echo Check processes using pstree; tput sgr0; pstree -ap -u $USER')
        call system('sleep 5')
        write(6,*) " "
        write(6,*) "Print from each process"
        write(6,*) "+---------------------------+"
    end if

    call MPI_Barrier(MPI_COMM_WORLD, mpierr)

        write(*,'(2(a6,i6),a6,a8)')" Im ", nrank, &
                                   " of ", nproc, &
                                   " on ", pname
    
    call MPI_Barrier(MPI_COMM_WORLD, mpierr)

! Finalize
    call MPI_Finalize(mpierr)

end
