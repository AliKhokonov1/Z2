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
	CComplexPoint global_s(0,0);
	 std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	 #pragma omp parallel shared(e) private(s)
    {
        #pragma omp for
	for(int i = 0; i < N; i++){
		s=s+CComplexPoint(e[i].Re()*q.getVector()[i].Re()+e[i].Im()*q.getVector()[i].Im(),e[i].Re()*q.getVector()[i].Im()-e[i].Im()*q.getVector()[i].Re());		 
	    }
	#pragma omp critical
	global_s=global_s + s;
    }
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	int elapsed_ms = static_cast<int>( std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() );
	std::cout<< "Scalar product operator runtime is " <<elapsed_ms <<" ms\n";
	return global_s;
    }
void CComplexVector::setFilename (std::string f){
	this->filename = f;
}

int CComplexVector::size () const {
    return N;
}

