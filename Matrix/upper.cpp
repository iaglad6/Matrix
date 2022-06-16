#include "pch.h"
#include "upper.h"

using namespace std;

class Upper_Matrix : public Matrix
{
public:



	Upper_Matrix(double size)
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
			}

		}
		imatrix = a.imatrix;
	}
};