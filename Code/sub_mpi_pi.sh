#!/bin/bash

cd $SLURM_SUBMIT_DIR

echo "Master node: $(hostname)"

mpirun a.out
