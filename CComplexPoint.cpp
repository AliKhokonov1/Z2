#include"CComplexPoint.h"
#include <iostream>
#include <math.h>
using namespace std;
CComplexPoint::CComplexPoint() {re=0;im = 0;}
CComplexPoint::CComplexPoint(double re, double im) {this->re=re; this->im=im;}
double CComplexPoint::Re()const{return re;}
double CComplexPoint::Im()const{return im;}
double CComplexPoint::abs() {return sqrt(im*im + re*re);}
void   CComplexPoint::print() {cout<<"("<<re<<","<<im<<")";}
CComplexPoint CComplexPoint::operator+(const CComplexPoint &m) 
{ 
    CComplexPoint r(re+m.Re(),im+m.Im());
    return r;
}
CComplexPoint CComplexPoint::operator-(const CComplexPoint &m) 
{ 
    CComplexPoint r(re-m.Re(),im-m.Im());
    return r;
}
