#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int procNum, procRank;
    int m,n, size;
    int sumProc = 0, sumAll =0;
    char test[] = "hi";

    MPI_Status status;

    MPI_Init(NULL, NULL);
    // stores total number of threads in procNum
    MPI_Comm_size(MPI_COMM_WORLD, &procNum);
    // each thread stores its own rank in procRank
    MPI_Comm_rank(MPI_COMM_WORLD, &procRank);

    // get the size of the array in rank 0 this demo has to get the inputs 4 by 5
    if(procRank == 0)
    {
        printf("Type the array size \n")
        scanf("%i %i", &m, &n);
    }
    // send the array size to all threads
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // set the array static for this demo sums to 866
    float arr[4][5]={
    {50,55,62,70,85},
    {35,42,45,47,49},
    {32,33,36,37,38},
    {25,30,30,35,30}
    };

    // send the array out to all threads
    for (int i=0; i < m; i++)
    {
        MPI_Bcast(arr[i], n, MPI_INT, 0, MPI_COMM_WORLD);
    }

    // each thread sums its row
    for(int i = 0; i < n; i++)
    {
        sumProc += arr[procRank][i];
    }

    // have each thread output its name and sum
    printf("Hi, I'm %i ", procRank);
    printf("My sum is: %i", sumProc);
    printf("\n");


    //sum all back to thread 0
    MPI_Reduce(&sumProc, &sumAll, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // if thread 0 sum all thread results together
    if (procRank == 0);
    {
        //print the output
        printf("sumAll = %i \n", sumAll);
    }

    //end program
    MPI_Finalize();
    return 0;
}
