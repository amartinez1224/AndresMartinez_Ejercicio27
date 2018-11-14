/* para compilar es: cc sample.c -o sample.x  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "mpi.h"


int main(int argc, char** argv){
    MPI_Init (&argc, &argv);
    int N=atoi(argv[1]);
    int C=atoi(argv[2]);
    int S=atoi(argv[3]);
    int rank, size;
    srand(time(NULL));
    double *lista;
    lista =malloc(N*sizeof(double));
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    N = (int)((double)N/(double)size);
    rank=rank+1;
    FILE *in = fopen("sample_"+ std::to_string(rank) + ".dat","w");
    int i;
    for( i = 0; i<N; i++){
        if (((double)rand()/(double)RAND_MAX)>0.5){
            lista[i] = (log((double)rand()/(double)RAND_MAX)*S)+C;
            fprintf(in,"%f\n",lista[i]);
        }
        else{
            lista[i] = (-log((double)rand()/(double)RAND_MAX)*S)+C;
            fprintf(in,"%f\n",lista[i]);
        }
    }
    fclose(in);
    MPI_Finalize();
    return 0;
}
