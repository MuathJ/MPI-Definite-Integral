# MPI Parallel Definite Integral

 A program that takes from the line command an integer number n, and two floating-point numbers a and b. Then, the program should compute
the definite integral of a given function func on the interval [a, b]. The function func is provided in a separate file named func.cpp

------------------------
1. integrate.cpp
* A sequential program integrate.cpp that computes the integration. The program should exit with usage message if the user didn't pass the correct number of parameters.*

*stored the argument [argv] values to a,b,n using (atof) function*
*defined array of float x of length n with the 1st element a and last element b*



output:

 For n=100 Trapezoids from a=1 to b=4
 
 The Definite Integral Value is: 73.50044250488281250000

------------------------
2. mpi_integrate_v1.cpp

*an MPI parallel program mpi_integrate_v1.cpp that does the integration by dividing the work a among p processes. For example, if n is 100 and p is 10, then each process computes its local integration on part of the interval using the trapezoid rule. Then have each process sends its local integration value to the master process (process 0) using point-to-point communication. The MPI program accept parameters from the line command similar to the serial version, for example $ mpirun –np 4 ./mpi_integrate 1 3.5 100 *

*in addition to the code from "integrate.cpp", the T function was added with all MPI functions*



output:

 For n=100 Trapezoids from a=1 to b=4
 
 The Definite Integral Value is: 73.50044536590576171875

------------------------
3. mpi_integrate_v2.cpp
* Modify the mpi_integration_v1 program, so that the master process receives from any source instead of receiving from process 1, 2, …, etc.*

*from the previous code "mpi_integrate_v1.cpp", MPI_Recv function was modified to "MPI_ANY_SOURCE, MPI_ANY_TAG" as per requirements*



output:

 For n=100 Trapezoids from a=1 to b=4
 
 The Definite Integral Value is: 73.50044536590576171875

------------------------
4. mpi_integrate_v3.cpp
* Modify the program so that you use collective communication instead of point-to-point communication.*

*from the previous code "mpi_integrate_v2.cpp", an additional communicator was created "NEW_COMM" in addition to the existing one "MPI_COMM_WORLD"*



output:

 For n=100 Trapezoids from a=1 to b=4
 
 The Definite Integral Value is: 73.50044536590576171875

------------------------
