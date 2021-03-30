#pragma once
#include<sstream>
#include<string>
#include"CComplexPoint.h"
#include"CComplexVector.h"
#include"CComplexVector0.h"
#include"CComplexVectorFabric.h"
class CComplexVectorFabric0:public  CComplexVectorFabric{
public:
	CComplexVector* create(std::string str){
		CComplexVector* tmp;
		istringstream ss(str);
		int m;
		double re,im;
		std::string filename;
        	ss >> filename;
        	ss >> m;
		tmp = new CComplexVector0(m);
        	tmp->setFilename(filename);
        	for(int j = 0; j < m; j++){
			ss >> re >> im;
		 	tmp->set(j,CComplexPoint(re,im));	
		}
		return tmp;
	}
};
