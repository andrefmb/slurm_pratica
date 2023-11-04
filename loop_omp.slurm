#!/bin/bash
#SBATCH --job-name=loop_OMP
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=2
#SBATCH --partition=express
#SBATCH --mem=500M

echo Output do job $SLURM_JOB_ID
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
./loop_omp


