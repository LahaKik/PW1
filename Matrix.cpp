#include "Matrix.h"

Matrix::Matrix(unsigned int size): size(size)
{

	values = new number * [size];
	int t = rand() % 50;
	for (unsigned int i = 0; i < size; i++)
	{
		*(values + i) = new number[size];
		for (unsigned int j = 0; j < size; j++)
		{
			*(*(values + i) + j) = t;
			t = rand() % 50;
		}
	}
}
Matrix::~Matrix()
{
	for (unsigned int i = 0; i < size; i++)
	{
		delete[] * (values + i);
	}
	delete[] values;
}

number Matrix::Determinant()
{
	Matrix temp(size);
	temp.copyMatrix(this);

	applyGaussMethod();
	
	number com = 1;
	for (Uint i = 0; i < size; i++)
	{
		com *= values[i][i];
	}

	this->copyMatrix(&temp);

	return com;
}

number Matrix::GetValue(Uint i, Uint j)
{
	return values[i][j];
}

void Matrix::copyMatrix(Matrix* target)
{
	for (Uint i = 0; i < size; i++)
	{
		for (Uint j = 0; j < size; j++)
		{
			*(*(values + i) + j) = target->GetValue(i, j);
		}
	}
}

void Matrix::SetTransposed()
{
	for (Uint i = 0; i < size; i++)
	{
		for (Uint j = i+1; j < size; j++)
		{
			number temp = values[i][j];
			values[i][j] = values[j][i];
			values[j][i] = temp;
		}
	}
}

void Matrix::applyGaussMethod()
{
	for (int k = 0; k < size - 1; k++)
	{
		for (int i = k + 1; i < size; i++)
		{
			double tmp = -values[i][k] / (double)values[k][k];
			for (int j = 0; j < size; j++)
			{
				values[i][j] += values[k][j] * tmp;
				values[i][j] = round(values[i][j]*100000)/100000;
			}
		}
	}
}

int Matrix::ComputeRank()
{
	Matrix temp(size);
	temp.copyMatrix(this);

	applyGaussMethod();
	std::cout << std::endl;
	Print();
	int rank = 0;

	for (Uint i = 0; i < size; i++)
	{
		if (values[i][i] != 0)
			rank++;
		else
			break;
	}
	return rank;
}