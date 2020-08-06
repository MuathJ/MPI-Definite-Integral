#include <mpi.h>
#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include "func.cpp"
using namespace std;

// mpic++ -o mpi_integrate_v2 mpi_integrate_v2.cpp 

float T(float *x, int n) 
{
    float estimate, y;
    int i;

    estimate = (func(x[0]) + func(x[1])) / 2.0;

    for (i=1 ; i<=n-1 ; i++) 
    {	y = x[0] + i*x[2];
        estimate += func(y);
    }
    estimate = estimate * x[2];
    return estimate;
}

int main(int argc, char **argv) 
{
	if (argc != 4) 
	{	cout<<" You Need to Pass 3 Parameteres: a & b & n "<<endl;
        return 0;
    }
	
	int my_rank, comm_sz, n = 1024, local_n;
	double a = 0.0, b = 3.0, h, local_a, local_b;
    double local_int, total_int, z;
    int source;
	
	
	a = atof(argv[1]);
	b = atof(argv[2]);
	z = atof(argv[3]);
	n = (int) z;
	
	
	MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	
	h = (b-a) / n;
    local_n = n / comm_sz;
    
    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;
	
	float x[3];
    x[0] = local_a;
    x[1] = local_b;
    x[2] = h;
	
	local_int = T(x,local_n);
	
	
	if (my_rank != 0) 
	{	MPI_Send (&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    
    else 
    {	total_int = local_int;
		for (source=1 ; source<comm_sz ; source++) 
			{	MPI_Recv(&local_int, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
				total_int += local_int;
			}
    }

    if (my_rank == 0) 
    {
		cout<<endl<<"-------------------------------------";
		cout<<endl<<" For n="<<n<<" Trapezoids from a="<< a <<" to b="<< b;
		cout<<endl<<" The Definite Integral Value is: "<< fixed << setprecision(20) <<total_int <<endl<<endl;
	}
		
	MPI_Finalize();
	return 0;
}
