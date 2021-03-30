#include "stdio.h"
#include "CComplexVector0.h"
#include"CComplexVector.h"
#include"CComplexPoint.h"
#include <fstream>
CComplexVector0::CComplexVector0(int M):CComplexVector(M){}
CComplexVector0::~CComplexVector0() {}
CComplexVector0::CComplexVector0(const CComplexVector &b):CComplexVector(b) {}
int CComplexVector0::output(const char* f) {
   ofstream file; 
   if(f == NULL){
        file.open(filename.c_str());
    }
    else{
        file.open(f);
    }
    for(int i = 0; i < N; i++){
    	file << '('<<e[i].Re() << ',' <<e[i].Im() << ')' << ' '; 
    }
    file.close();
    return 0;
}
CComplexVector0 operator+(const CComplexVector &a, const CComplexVector &b){
	CComplexVector0 p(a.size());
	if (a.size() != b.size()) {
	    cout<<"No";
	}
	for(int i = 0; i < a.size(); i++){
		p.getVector()[i]=a.getVector()[i]+b.getVector()[i];
	}
	return p;
}
CComplexVector0 operator-(const CComplexVector &a, const CComplexVector &b){
	CComplexVector0 p(a.size());
	if (a.size() != b.size()) {
	    cout<<"No";
	}
	for(int i = 0; i < a.size(); i++){
		p.getVector()[i]=a.getVector()[i]-b.getVector()[i];
	}
	return p;
}
