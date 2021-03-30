#include "stdio.h"
#include "CComplexVector1.h"
#include"CComplexVector.h"
#include"CComplexPoint.h"
#include <fstream>
CComplexVector1::CComplexVector1(int M):CComplexVector(M){}
CComplexVector1::~CComplexVector1() {}
CComplexVector1::CComplexVector1(const CComplexVector &b):CComplexVector(b) {}
int CComplexVector1::output(const char* f) {
    ofstream file; 
    if(f == NULL){
    	file.open(filename.c_str());
    }
    else{
        file.open(f);
    }
    for(int i = 0; i < N; i++){
    	file << '('<<e[i].Re() << ',' << e[i].Im() << ')' << '\n'; 
    }
    file.close();
   return 0;
}
