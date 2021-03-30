#include"CComplexPoint.h"
#include"CComplexVector.h"
#include "CComplexVector0.h"
#include "CComplexVector1.h"
#include "CComplexVectorFabric.h"
#include "CComplexVectorFabric0.h"
#include "CComplexVectorFabric1.h"
#include "stdio.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include<map>
#include<exception>
using namespace std;
int Autotest();
CComplexVector* CreateCComplexVector(string &str, map<string,CComplexVectorFabric*> &FabricMap){
    string tp;
    string arg;
    string fil;
    istringstream dad(str);
    dad >> tp;
    dad >> fil;
    arg = str.substr(str.find(fil));
    auto m = FabricMap.find(tp);
    if(m!=FabricMap.end()){
        return (*m).second->create(arg);
    }
    else{
        throw -1;
    }
}
int main () {
Autotest();
map<string,CComplexVectorFabric*> fabrip;
fabrip["Hori"] = new CComplexVectorFabric0(); 
fabrip["Vert"] = new CComplexVectorFabric1(); 
ifstream fin("zhozhozho.txt");
if (fin.fail()) {
        cout<<"File did not open!"<<endl;
        return 1;
}
string str;
std::vector<CComplexVector*> arr;
try {
    while(getline(fin,str)){
        arr.push_back(CreateCComplexVector(str,fabrip));
    }
    for(auto i = arr.begin(); i != arr.end(); ++i){
	    (*i)->output();
    }
    for(auto i = arr.begin(); i != arr.end(); ++i){
	    delete (*i);
    }
}
catch (int e) {
    printf("There is no correct input!");
}
delete fabrip["Hori"];
delete fabrip["Vert"];
return 0;
}
