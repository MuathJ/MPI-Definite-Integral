#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include "func.cpp"
using namespace std;

int main(int argc, char **argv) 
{
	if (argc != 4) 
	{	cout<<" You Need to Pass 3 Parameteres: a & b & n "<<endl;
        return 0;
    }
	
	float a, b, z, h, approx;
	int n;
	
	a = atof(argv[1]);
	b = atof(argv[2]);
	z = atof(argv[3]);
	
	n = (int) z;
	
	float *x = new float [n];
    x[0] = a;
    x[n-1] = b;
	
	h = (b-a) / n;
    approx = ( func(a) + func(b) ) / 2.0;
    for (int i=1 ; i<n ; i++) 
    {	x[i] = a + (i*h);
        approx += func(x[i]);
    }
    approx = h*approx;
    
    cout<<endl<<"-------------------------------------";
	cout<<endl<<" For n="<<n<<" Trapezoids from a="<< a <<" to b="<< b;
    cout<<endl<<" The Definite Integral Value is: "<< fixed << setprecision(20) <<approx <<endl<<endl;
	
	return 0;
}
