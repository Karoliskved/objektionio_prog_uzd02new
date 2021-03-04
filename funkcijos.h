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


struct studentas
{

    double egz, vidurkis = 0, median = 0;
    int final;
    vector<double> nd;
    
    string vard, pav;
    
};
bool vedbudas();
void failoived(vector<studentas> &A);
void duomenys(int &studsk, int &n, vector<studentas> &A);
void fin(vector<studentas> &A);
int generaten();
double generaterez();
bool SortByPav(const studentas &A, const studentas &B);
void rikiavimas(vector<studentas> &A);
void vid( vector<studentas> &A);
void med( vector<studentas> &A);
void rez(vector<studentas> &A);

#endif