#!/bin/bash
#PBS -l nodes=1:ppn=8, mem=64gb
#PBS -l walltime=02:00
#PBS -M a.martinez@uniandes.edu.co
#PBS -m abe
#PBS -N Programa

cd /hpcfs/home/fisi4028/a.martinez/AndresMartinez_Ejercicio27
make -f make.mk
./Listings1
./Listings2

