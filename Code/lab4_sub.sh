#!/bin/bash
#SBATCH --nodes=3
#SBATCH --ntasks-per-node=1
#SBATCH --partition=mycluster
cd $SLURM_SUBMIT_DIR
echo "Master node: $(hostname)"
mpirun a.out
