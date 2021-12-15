#!/bin/bash
#SBATCH --ntasks=6
cd $SLURM_SUBMIT_DIR
mpiexec -n 6 /clusterfs/usr/bin/python3 calculate.py
