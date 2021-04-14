#include "stdio.h"
#include "CComplexVector0.h"
#include"CComplexVector.h"
#include"CComplexPoint.h"
#include <fstream>
#include <iostream>
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
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	#pragma omp parallel shared(p,a)//”казываю какаие переменные общие дл€ потоков
    {
        #pragma omp for
	for(int i = 0; i < a.size(); i++){
		p.getVector()[i]=const_cast<CComplexVector &>(a).getVector()[i]+const_cast<CComplexVector &>(b).getVector()[i];
	
	    }
	}
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	int elapsed_ms = static_cast<int>( std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() );
    std::cout<< "Addition operator runtime is " <<elapsed_ms <<" ms\n";
	return p;
}
CComplexVector0 operator-(const CComplexVector &a, const CComplexVector &b){
	CComplexVector0 p(a.size());
	if (a.size() != b.size()) {
	    cout<<"No";
	}
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	#pragma omp parallel shared(p,a)//”казываю какаие переменные общие дл€ потоков
    {
        #pragma omp for
	for(int i = 0; i < a.size(); i++){
		p.getVector()[i]=const_cast<CComplexVector &>(a).getVector()[i]-const_cast<CComplexVector &>(b).getVector()[i];
	
	    }
	}
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	int elapsed_ms = static_cast<int>( std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() );
	std::cout<< "Addition operator runtime is " <<elapsed_ms <<" ms\n";
	return p;
}

