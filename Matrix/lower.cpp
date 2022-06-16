#include "lower.h"
using namespace std;

class Lower_Matrix : public Matrix
{
public:

	Lower_Matrix(double size)
	{
		Uno_Matrix a(size);
		double temp_double;
		columns = size;
		rows = size;
		for (double i = 0; i < size; ++i)
		{
			for (double j = 0; j < i + 1; j++)
			{
				cin >> temp_double;
				a.imatrix[i][j] = temp_double;
			}

		}
		imatrix = a.imatrix;
	}
};