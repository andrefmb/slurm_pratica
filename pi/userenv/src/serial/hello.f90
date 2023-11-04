program test

    real :: t0, t1, t2, t3
    real :: s(16)
    integer :: val0(8), val1(8)

    call cpu_time(t0)
    call date_and_time(VALUES=val0)
    !call system('sleep 10')
    do i = 1,1000000000
        s = i / 2.0 *4.9
    end do

    call date_and_time(VALUES=val1)
    call cpu_time(t1)
    
    t2=float(val0(2) + val0(3)*3600*24 + val0(5)*3600 +&
             val0(7) + val0(6)*60)     + val0(8)*.001
    t3=float(val1(2) + val1(3)*3600*24 + val1(5)*3600 +&
             val1(7) + val1(6)*60)     + val1(8)*.001
    write(6,*) "Time Elapsed", t3-t2
    write(6,*) "Time Cpu",     t1-t0

end
