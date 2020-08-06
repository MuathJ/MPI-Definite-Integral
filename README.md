# MPI Definite Integral

 A program that takes from the line command an integer number n, and two floating-point numbers a and b. Then, your program should compute
the definite integral of a given function func on the interval [a, b]. The function func should be provided in a separate file named func.cpp

------------------------
1. integrate.cpp

*stored the argument [argv] values to a,b,n using (atof) function*
*defined array of float x of length n with the 1st element a and last element b*


output:

 For n=100 Trapezoids from a=1 to b=4
 
 The Definite Integral Value is: 73.50044250488281250000

------------------------
2. mpi_integrate_v1.cpp

*in addition to the code from "integrate.cpp", the T function was added with all MPI functions*


output:

 For n=100 Trapezoids from a=1 to b=4
 
 The Definite Integral Value is: 73.50044536590576171875

------------------------
3. mpi_integrate_v2.cpp

*from the previous code "mpi_integrate_v1.cpp", MPI_Recv function was modified to "MPI_ANY_SOURCE, MPI_ANY_TAG" as per requirements*


output:

 For n=100 Trapezoids from a=1 to b=4
 
 The Definite Integral Value is: 73.50044536590576171875

------------------------
4. mpi_integrate_v3.cpp

*from the previous code "mpi_integrate_v2.cpp", an additional communicator was created "NEW_COMM" in addition to the existing one "MPI_COMM_WORLD"*


output:

 For n=100 Trapezoids from a=1 to b=4
 
 The Definite Integral Value is: 73.50044536590576171875

------------------------
