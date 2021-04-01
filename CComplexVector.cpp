#include <fstream>
#include <iostream>
#include"CComplexPoint.h"
#include"CComplexVector.h"
#include <string.h>
#include <vector>
using namespace std;
CComplexVector::CComplexVector(int M){
    SetZero();
	N=M;
	e.resize(N);
}
void CComplexVector::set(int i,CComplexPoint y) {
	if (i>N) {
		cout<<"Big length!";
		return;
	}
	e[i]=y;
	
}
void CComplexVector::setVector(ifstream &fin){
	double a,b;
	for(int i = 0;i < N; i++){
	fin>>a>>b;
		e[i]=CComplexPoint(a,b);
	}
}
CComplexVector::~CComplexVector() {
    Clean();
}
void CComplexVector::CopyOnly(const CComplexVector &b) {
		N = b.N;
		e=b.e;
}
CComplexVector::CComplexVector(const CComplexVector &b) {
CopyOnly(b);
}

CComplexVector& CComplexVector::operator=(const CComplexVector &b) 
{   if (this!=&b) 
    {     Clean();
          CopyOnly(b);
        }
return *this;
}
void CComplexVector::Clean(){SetZero();}

void CComplexVector::SetZero(){N=0;}

std::vector<CComplexPoint>& CComplexVector::getVector() {
return e;
}

CComplexPoint CComplexVector::operator*(CComplexVector &q){
	CComplexPoint s(0,0);
	for(int i = 0; i < N; i++){
		s=s+CComplexPoint(e[i].Re()*q.getVector()[i].Re()+e[i].Im()*q.getVector()[i].Im(),e[i].Re()*q.getVector()[i].Im()-e[i].Im()*q.getVector()[i].Re());		 
	}
	return s;
}
void CComplexVector::setFilename(std::string f){
	this->filename = f;
}

int CComplexVector::size() const {
    return N;
}



