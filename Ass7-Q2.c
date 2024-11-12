#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes (world size)
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process (ID of the current process)
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Check if the number of processes is exactly 5
    if (world_size != 5) {
        if (world_rank == 0) {
            printf("This program requires exactly 5 processes, but %d were provided.\n", world_size);
        }
        // Finalize MPI and exit if the number of processes is not 5
        MPI_Finalize();
        return 0;
    }

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print the rank and communicator group information
    printf("Processor %s, Rank %d out of %d in the communicator group\n",
           processor_name, world_rank, world_size);

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}

