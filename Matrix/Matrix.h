#pragma once
#ifdef MATRIX_EXPORTS
#define MATRIX_API __declspec(dllexport)
#else
#define MATRIX_API __declspec(dllimport)
#endif // MATHWIN32DLL_EXPORTS
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
class Matrix
{
public:
    int columns;
    int rows;
    vector<vector<double>> imatrix;
    Matrix();
    Matrix(int, int);
    friend ostream& operator<<(ostream&, Matrix);
    friend Matrix operator+(Matrix, Matrix);
    friend Matrix operator-(Matrix, Matrix);
    friend Matrix operator*(Matrix, double);
    friend Matrix operator*(Matrix, Matrix);
    friend Matrix operator&(Matrix, Matrix);
    double trace();
    double det();
    friend double operator%(Matrix, Matrix );
    double ev_norm_vector();
    double max_norm_vector();
    double freb_norm_matrix();
    friend double operator^(Matrix, Matrix);
    double rank();
    void trans();
    Matrix add();
    Matrix poisk_obrat();
    void zapis_bin(const char*);
    void read_bin(const char*, int, int);
    friend ofstream& operator<<(ofstream&, Matrix&);
    friend istream& operator>>(istream&, Matrix&);


  
    
    
};

