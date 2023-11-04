#!/bin/bash
#SBATCH --job-name=loop_serial
#SBATCH --nodes=1
#SBATCH --partition=express
#SBATCH --mem=500M

echo Output do job $SLURM_JOB_ID
./loop_serial


