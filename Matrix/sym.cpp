#pragma once

#include "sym.h"

using namespace std;

class Sym_Matrix : public Matrix
{
public:



	Sym_Matrix(double size)
	{
		Uno_Matrix a(size);
		double temp_double;
		columns = size;
		rows = size;
		for (double i = 0; i < size; ++i)
		{
			for (double j = i; j < size; j++)
			{
				cin >> temp_double;
				a.imatrix[i][j] = temp_double;
				a.imatrix[j][i] = temp_double;

			}

		}
		imatrix = a.imatrix;
	}
};