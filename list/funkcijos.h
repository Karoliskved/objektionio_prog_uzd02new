#ifndef FUNKICJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <list>
#include <random>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <chrono>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::list;
using std::string;
using std::sort;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::getline;
using std::to_string;
using std::exception;
using std::partition;



class studentas
{
private:
    string vard_, pav_;
    list<double> nd_;
    double egz_, vidurkis_ = 0, median_ = 0;
    double final_;
    
   
public:
studentas(){
}
studentas(string vard, string pav, list<double> nd, double egz )  {
    vard_=vard;
    pav_=pav;
    nd_=nd;
    egz_=egz;
}
~studentas();
studentas(const studentas& s);
studentas& operator=(const studentas& s);

friend ostream& operator<<(ostream& os, const studentas& dt);
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
void failoived(list<studentas> &A, string  fileName, std::chrono::duration<double> &runtime);
//void duomenys(int &studsk, int &n, list<studentas> &A);
void vid( list<studentas> &A);
void med( list<studentas> &A);
void fin(list<studentas> &A);
bool SortByPav(const studentas &A, const studentas &B);
void rikiavimas(list<studentas> &A);
void skirs(list<studentas> &A, list<studentas> &B,  std::chrono::duration<double> &runtime);
void rez(list<studentas> &A,list<studentas> &B, std::chrono::duration<double> &runtime);
int generaten();
int generaterez();




#endif