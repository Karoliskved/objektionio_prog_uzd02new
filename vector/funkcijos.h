#ifndef FUNKICJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;
using std::string;
using std::sort;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::to_string;
using std::exception;
using std::partition;


class studentas
{
private:
    string vard_, pav_;
    vector<double> nd_;
    double egz_, vidurkis_ = 0, median_ = 0;
    double final_;
    
   
public:
studentas() : egz_(0) {}
//inline string vard() const{return vard_;}
//inline string pav() const{return pav_;}
void setVard(string);
void setPav(string);
void setNd(double);
void setEgz(double);
void skVidurki();
void skMedian();
void skfinalsuvid();
void skfinalsumed();
void resizeVard(int);
void resizePav(int);
string getVard() const{
    return vard_;
}
string getPav() const{
    return pav_;
}
void popbackGrade(){
    return nd_.pop_back();
}
double getFinal() const{
    return final_;
}

};




//bool vedbudas();
//bool arfailagen();
void genfilename(int & n, string & fileName);
//void failogen(string &fileName, int n, std::chrono::duration<double> &runtime);
void failoived(vector<studentas> &A, string  fileName, std::chrono::duration<double> &runtime);
//void duomenys(int &studsk, int &n, vector<studentas> &A);
void vid( vector<studentas> &A);
void med( vector<studentas> &A);
void fin(vector<studentas> &A);
bool SortByPav(const studentas &A, const studentas &B);
void rikiavimas(vector<studentas> &A);
void skirs(vector<studentas> &A, vector<studentas> &B,  std::chrono::duration<double> &runtime);
void rez(vector<studentas> &A,vector<studentas> &B, std::chrono::duration<double> &runtime);
int generaten();
int generaterez();




#endif