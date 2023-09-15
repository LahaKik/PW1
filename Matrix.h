#pragma once
#include "Number.h"
#include <iostream>

class Matrix
{
private:
	unsigned int size;
	number** values;
	void copyMatrix(Matrix*);
	void applyGaussMethod();
public:
	Matrix(unsigned int);
	~Matrix();
	number Determinant();
	number GetValue(Uint, Uint);
	void SetTransposed();
	int ComputeRank();

	void Print()
	{
		for (unsigned short i = 0; i < size; i++)
		{
			for (unsigned short j = 0; j < size; j++)
			{
				std::cout << *(*(values + i) + j) << "\t";
			}
			std::cout << std::endl;
		}
	}
};

