#pragma once
#include "stdio.h"
#include"CComplexVector.h"
using namespace std;
class CComplexVector1: public CComplexVector{
    public:
    	using CComplexVector::operator=;
        CComplexVector1 (int M);
        ~CComplexVector1 ();
        CComplexVector1 (const CComplexVector &b);
        int output(const char* f = NULL);
};
