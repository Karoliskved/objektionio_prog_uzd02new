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
#include <deque>

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
using std::deque;


struct studentas
{

    double egz, vidurkis = 0, median = 0;
    int final;
    deque<double> nd;
    
    string vard, pav;
    
};
bool vedbudas();
bool arfailagen();
void genfilename(int & n, string & fileName);
void failogen(string &fileName, int n, std::chrono::duration<double> &runtime);
void failoived(deque<studentas> &A, string  fileName, std::chrono::duration<double> &runtime);
void duomenys(int &studsk, int &n, deque<studentas> &A);
void fin(deque<studentas> &A);
int generaten();
int generaterez();
bool SortByPav(const studentas &A, const studentas &B);
void rikiavimas(deque<studentas> &A);
void vid( deque<studentas> &A);
void med( deque<studentas> &A);
void skirs(deque<studentas> &A, deque<studentas> &B, deque<studentas> &C, std::chrono::duration<double> &runtime);
void rez(deque<studentas> &A,deque<studentas> &B, std::chrono::duration<double> &runtime);


#endif