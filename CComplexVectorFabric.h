#pragma once
#include<string>
#include<sstream>
#include"CComplexVector.h"
class CComplexVectorFabric{
public:
	virtual CComplexVector* create(std::string str) = 0;
};
