#include "Matrix.h"


int main()
{
	std::cout.precision(2);
	Matrix a(5);
	a.Print();
	std::cout << std::endl << a.ComputeRank();
}