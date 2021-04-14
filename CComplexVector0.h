#pragma once
#include<chrono>
#include "stdio.h"
#include"CComplexVector.h"
using namespace std;
class CComplexVector0: public CComplexVector {
    public:
    	using CComplexVector::operator=;
        CComplexVector0 (int M);
        ~CComplexVector0 ();
        CComplexVector0 (const CComplexVector &b);
        int output(const char* f = NULL);
        friend CComplexVector0 operator+(const CComplexVector &a, const CComplexVector &b);
        friend CComplexVector0 operator-(const CComplexVector &a, const CComplexVector &b);
};
