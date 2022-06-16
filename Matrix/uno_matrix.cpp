#pragma once
#include "uno_matrix.h"


using namespace std;


class Uno_Matrix : public Matrix
{
public:


	Uno_Matrix()
	{
		vector <double> UM = { 1 };
	}
	Uno_Matrix(double size)
	{
		for (double i = 0; i < size; i++)
		{
			vector<double> temp;
			for (double j = 0; j < size; j++)
			{
				temp.push_back(0);
				if (i == j) temp.at(i) = 1;
			}
			imatrix.push_back(temp);
		}
		columns = size;
		rows = size;
	}
	
};