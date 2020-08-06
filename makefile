CC=mpic++
CFLAGS=-I -O3 -Wall

DEPS=
OBJ = integrate.o .o func.o mpi_integrate_v1.o mpi_integrate_v2.o mpi_integrate_v3.o

all: integrate mpi_integrate_v1 mpi_integrate_v2 mpi_integrate_v3

integrate: integrate.o
		g++ -o $@ $^
mpi_integrate_v1: mpi_integrate_v1.o
		$(CC) -o $@ $^
mpi_integrate_v2: mpi_integrate_v2.o
		$(CC) -o $@ $^
mpi_integrate_v3: mpi_integrate_v3.o
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
		
%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
test1: integrate
		./integrate 1 4 100
test2: mpi_integrate_v1
		mpic++ -o mpi_integrate_v1 mpi_integrate_v1.cpp 
		mpirun -np 4 ./mpi_integrate_v1 1 4 100
test3: mpi_integrate_v2
		mpirun -np 4 ./mpi_integrate_v2 1 4 100
test4: mpi_integrate_v3
		mpirun -np 4 ./mpi_integrate_v3 1 4 100
		
clean:
		rm -f *.o *~ core
