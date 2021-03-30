#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class CComplexPoint {
public:
    CComplexPoint ();
    CComplexPoint (double re, double im);
    double Re()const;
    double Im()const;
    double abs();
    void print();
    CComplexPoint operator+(const CComplexPoint &m);
    CComplexPoint operator-(const CComplexPoint &m);
private:
    double im;
    double re;
};
