#!/bin/bash
#SBATCH --job-name=hello_world
#SBATCH --nodes=1
#SBATCH --partition=express
#SBATCH --mem=500M

echo Output do job $SLURM_JOB_ID
./hello_world


