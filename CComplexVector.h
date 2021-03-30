#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class CComplexPoint;
class CComplexVector {
public:
    CComplexVector(int M);
    virtual ~CComplexVector();
    CComplexVector(const CComplexVector&b);
    void Clean();
    void SetZero();
    void set(int i,CComplexPoint y);
    void CopyOnly(const CComplexVector&b);
    CComplexPoint* getVector() const;
    void setVector(ifstream &fin);
    virtual int output(const char* f = NULL) = 0;
    CComplexPoint operator*(CComplexVector &q);
    CComplexVector& operator=(const CComplexVector &b);
    void setFilename(std::string f); 
    int size() const;
protected:
    string filename;
    CComplexPoint *e;
    int N;
};
