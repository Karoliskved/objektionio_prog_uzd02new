#ifndef STDSHORTCUT_H_INCLUDED
#define STDSHORTCUT_H_INCLUDED

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
#include <list>

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
using std::list;


struct studentas
{

    double egz, vidurkis = 0, median = 0;
    int final;
    list <double> nd;
    
    string vard, pav;
    
};
bool vedbudas();
bool arfailagen();
void genfilename(int & n, string & fileName);
void failogen(string &fileName, int n, std::chrono::duration<double> &runtime);
void failoived(list<studentas> &A, string  fileName, std::chrono::duration<double> &runtime);
void duomenys(int &studsk, int &n, list<studentas> &A);
void fin(list<studentas> &A);
int generaten();
int generaterez();
bool SortByPav(const studentas &A, const studentas &B);
void rikiavimas(list<studentas> &A);
void vid( list<studentas> &A);
void med( list<studentas> &A);
void skirs(list<studentas> &A, list<studentas> &B, list<studentas> &C, std::chrono::duration<double> &runtime);
void rez(list<studentas> &A,list<studentas> &B, std::chrono::duration<double> &runtime);


#endif