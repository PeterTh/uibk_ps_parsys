#include <stdio.h>
#include <unistd.h>
#include <mpi.h>

int main(int argc, char** argv) {

    MPI_Init(&argc, &argv);

    int world_rank=-1, world_size=-1;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    char host_name[64];
    gethostname(host_name, 64);

    printf("Running MPI process %2d / %2d on host %s.\n", world_rank, world_size, host_name);

    MPI_Finalize();
}