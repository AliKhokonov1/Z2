#include"CComplexPoint.h"
#include"CComplexVector.h"
#include "CComplexVector0.h"
#include "CComplexVector1.h"
#include "stdio.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int Autotest(){
string str;
CComplexPoint sk;
ifstream fin("test.txt");
if (fin.fail()) {
        cout<<"File did not open!"<<endl;
        return 1;
}
 ifstream vin("restest.txt");
    if (vin.fail()) {
        cout<<"File did not open!"<<endl;
        return 3;
    }

int n=0;
while(getline(fin,str)){
	n++;
}
CComplexVector  **arr = new CComplexVector* [n];
int x = 0;
string filename;
int m = 0;
int i = 0;
double re;
double im;
CComplexVector* tmp;
fin.clear();
fin.seekg(0);
while(getline(fin,str)){
        istringstream ss(str);//Работаем со строкой как с входным файлом
        ss >> x;
        ss >> filename;
        ss >> m;
        if(x == 0){
		tmp = new CComplexVector0(m);
	}
	else{
		tmp = new CComplexVector1(m);
	}
        tmp->setFilename(filename.c_str());//Устанавливаем char *  в filename
        for(int j = 0; j < m; j++){
		 ss >> re >> im;
		 tmp->set(j,CComplexPoint(re,im));//Инициализируем массив e входными данными	
	}
	arr[i++] = tmp;
}
for(int i = 0; i < n; i++){
	arr[i]->output();
}
CComplexVector0 w(m);
CComplexVector0 sum(m),raz(m);

for (int i=0;i<m;i++) {
    w.getVector()[i] = tmp->getVector()[i];
}

sum.setVector(vin);raz.setVector(vin);
sk=(w*w);
for (int i=0;i<m;i++) {
        if ((sum.getVector()[i].Re() != (w+w).getVector()[i].Re()) || (sum.getVector()[i].Im() != (w+w).getVector()[i].Im())) {
            cout<<"Autotest failed"<<endl;
            return 1;   
            }
    }
    for (int i=0;i<m;i++) {
        if ((raz.getVector()[i].Re() != (w-w).getVector()[i].Re()) || (raz.getVector()[i].Im() != (w-w).getVector()[i].Im())) {
            cout<<"Autotest failed"<<endl;
            return 2;
        }  
    }
    if ((sk.Re() != 3) || (sk.Im() != 0)) {
       cout<<"Autotest failed"<<endl;
            return 3; 
    }  
for(int i = 0; i < n;i++){
	delete arr[i];
}
delete arr;
cout<<"Autotest passed!"<<endl;
return 0;
}
