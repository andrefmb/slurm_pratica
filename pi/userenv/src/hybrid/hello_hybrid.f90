program dummy

  use omp_lib
  use mpi

  implicit none

  character*MPI_MAX_PROCESSOR_NAME, save ::  pname
  integer mpierr, itd, gtd, nproc, nrank, grank, nlen

! Init MPI
    call MPI_Init(mpierr)

! Get Rank Size
    call MPI_COMM_Rank(MPI_COMM_WORLD, nrank, mpierr)
    call MPI_COMM_Size(MPI_COMM_WORLD, nproc, mpierr)

! Print rank
    call MPI_GET_PROCESSOR_NAME(pname, nlen, mpierr)

! Get Date hostname etc
    if (nrank==0) then
        call system('hostname && date && echo rank-pid $$')
    end if
    !if (nrank==0) then
       !call system('top -n 1 -b -H -u bthakur')
       !call system('pstree -ap -u bthakur')
    !end if
    call MPI_Barrier(MPI_COMM_WORLD, mpierr)

! OpenMP
    !$OMP PARALLEL PRIVATE(itd,gtd)
      itd= omp_get_thread_num()
      gtd= omp_get_num_threads()
      grank= nrank*gtd + itd
      write(*,'(4(a6,i6),a2,a8)')"Gid ", grank, " Im ", nrank, &
                                " of ", nproc, &
                                " thd", itd,    &
                                " on ", pname
    !$OMP FLUSH
    !$OMP BARRIER
      if (nrank==0 .and. itd==0) then
         call system('pstree -ap -u $USER')
         !call system('for f in `cat $PBS_NODEFILE|uniq`; do ssh $f pstree -ap -u bthakur; done;')
                
         call system('sleep 10')
      end if
    !$OMP FLUSH
    !$OMP END PARALLEL
    
    call MPI_Barrier(MPI_COMM_WORLD, mpierr)

! Finalize
    call MPI_Finalize(mpierr)
end
