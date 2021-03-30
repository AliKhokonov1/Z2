#pragma once
#include<sstream>
#include<string>
#include"CComplexPoint.h"
#include"CComplexVector.h"
#include"CComplexVector1.h"
#include"CComplexVectorFabric.h"
class CComplexVectorFabric1:public  CComplexVectorFabric{
public:
	CComplexVector* create(std::string str){
		CComplexVector* tmp;
		istringstream ss(str);
        	int m;
		double re,im;
		std::string filename;
		ss >> filename;
        	ss >> m;
		tmp = new CComplexVector1(m);
        	tmp->setFilename(filename);
        	for(int j = 0; j < m; j++){
			ss >> re >> im;
		 	tmp->set(j,CComplexPoint(re,im));	
		}
		return tmp;
	}
};
