Original serial code from https://www.olcf.ornl.gov/tutorials/monte-carlo-pi/
Modified and then parallelized by Yuwu Chen for LSU HPC training purpose only

1. The module mvapich2 should be loaded before running mpi_pi.out. Use "module list" to check the current module list. 

2. If running on SuperMike2, use mpi_pi_mike.out and serialpi_mike.out. 

3. The source code (.c files) should be recompiled to generate a new .out executables if mvapich2 is not used (e.g. if openmpi is used, then mpi_pi.c should be recompiled by mpicc from openmpi to create a new executable)

4. To compile serialpi.c with gcc, use "-lm" (without quotes) option to link the math library.

5. Codes in the "userenv" directory are for demonstrating the part of "compiling and analyze codes on cluster", which is not included in the training session due to the time limit. 

