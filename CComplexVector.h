#pragma once
#include <fstream>
#include <iostream>
#include <vector>
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
    void setVector(ifstream &fin);
    void CopyOnly(const CComplexVector&b);
    std::vector<CComplexPoint>& getVector();
    virtual int output(const char* f = NULL) = 0;
    CComplexPoint operator*(CComplexVector &q);
    CComplexVector& operator=(const CComplexVector &b);
    void setFilename(std::string f); 
    int size() const;
protected:
    string filename;
    std::vector<CComplexPoint> e;
    int N;
};
