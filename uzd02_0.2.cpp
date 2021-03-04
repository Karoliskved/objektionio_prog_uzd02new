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

#include "stdshortcut.h"

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

int main()
{
    int studsk, n;
    vector<studentas> Stud;
    srand(time(NULL));
    if (vedbudas() == true)
    {
        failoived(Stud);
    }
    else
    {
        cout << "Įveskite studentu skaičiu " << endl;
        cin >> studsk;
        duomenys(studsk, n, Stud);
    }
    rikiavimas(Stud);
    vid( Stud);
    med(Stud);
    fin(Stud);
    rez( Stud);
}
bool vedbudas()
{
    char answ;
    do
    {
        cout << "ar bus vykdmas skaitymas is failo  y/n" << endl;
        cin >> answ;
    } while (answ != 'y' && answ != 'n');
    if (answ == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void failoived(vector<studentas> &A)
{
    ifstream open_f("studentai10000.txt");
    stringstream buffer;
    string eil, output = "", laik, laik1;
    vector<string> eilvec;
    int i = 0;

    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    buffer << open_f.rdbuf();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Failo nuskaitymas į buferį užtruko: " << diff.count() << " s\n";

    getline(buffer, eil);
    start = std::chrono::high_resolution_clock::now();
    while (getline(buffer, eil))
    {

        stringstream ss(eil);

        A.push_back(studentas());
        ss >> laik >> laik1;
        A[i].vard = laik;
        A[i].pav = laik1;
        int num;
        while (ss >> num)
        {
            A[i].nd.push_back(num);
        }
        A[i].egz = A[i].nd.back();
        A[i].nd.pop_back();
        i++;

        
    }
    
    open_f.close();
    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "is buffer i vektoriu ivedimas uztruko" << diff.count() << " s\n";
    cout << i << endl;
   
}
void duomenys(int &studsk, int &n, vector<studentas> &A)
{
    char answ, answ2;
    string v;
    double laikinas;
    do
    {
        cout << "ar zinomas pazymių skaicius y/n" << endl;
        cin >> answ;
    } while (answ != 'y' && answ != 'n');
    do
    {
        cout << "ar norite pazymius ir egzamino rezultata atsitiktinai generuoti y/n" << endl;
        cin >> answ2;
    } while (answ2 != 'y' && answ2 != 'n');
    if (answ == 'y' && answ2 == 'y')
    {

        cout << "iveskite pazymiu skaiciu" << endl;
        cin >> n;
    }
    else if (answ == 'y' && answ2 == 'n')
    {
        cout << "iveskite pazymiu skaiciu" << endl;
        cin >> n;
    }
    else if (answ == 'n' && answ2 == 'y')
    {
        n = generaten();
    }
    for (int i = 0; i < studsk; i++)
    {
        cout << "iveskite studento varda " << endl;
        A.push_back(studentas());
        cin >> A[i].vard;
        cout << "iveskite studento pavarde " << endl;
        cin >> A[i].pav;

       
        if (answ == 'y' && answ2 == 'y')
        {
            for (int j = 0; j < n; j++)
            {
                A[i].nd.push_back(generaterez());
            }
            A[i].egz = generaterez();
        }
        else if (answ == 'y' && answ2 == 'n')
        {

            cout << "iveskite " << n << " pazymius" << endl;
            for (int j = 0; j < n; j++)
            {
                cin >> laikinas;
                A[i].nd.push_back(laikinas);
            }
            cout << "iveskite egzamino rezulta" << endl;
            cin >> A[i].egz;
        }
        else if (answ == 'n' && answ2 == 'y')
        {
            for (int j = 0; j < n; j++)
            {
                A[i].nd.push_back(generaterez());
            }
            A[i].egz = generaterez();
        }
        else
        {
            if (i == 0)
            {

                n = 0;

                do
                {
                    n++;
                    cin >> laikinas;
                    A[i].nd.push_back(laikinas);

                } while (A[i].nd[n - 1] > 0 && A[i].nd[n - 1] <= 10);
                n--;
            }
            else
            {
                cout << "iveskite " << n << " pazymius" << endl;
                for (int j = 0; j < n; j++)
                {
                    cin >> laikinas;
                    A[i].nd.push_back(laikinas);
                }
            }
            cout << "iveskite egzamino rezulta" << endl;
            cin >> A[i].egz;
        }
    }
}
int generaten()
{

    return (rand() % 10 + 1);
}
double generaterez()
{

    return (rand() % 10 + 1);
}
bool SortByPav(const studentas &A, const studentas &B)
{
    return A.pav < B.pav;
}

void rikiavimas(vector<studentas> &A){
    sort(A.begin(), A.end(), SortByPav );
}
void vid(vector<studentas> &A)
{
    double sum;
    for (int i = 0; i < A.size(); i++)
    {
        sum = 0;
        for (int j = 0; j < A[i].nd.size(); j++)
        {
            sum = sum + A[i].nd[j];
        }
        if (A[i].nd.size() != 0)
            A[i].vidurkis = sum / A[i].nd.size();
    }
}
void fin(vector<studentas> &A){
    for(int i=0; i<A.size(); i++){
      A[i].final = round(A[i].vidurkis * 0.4 + 0.6 * A[i].egz);  
    }
   
   
}
void med( vector<studentas> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].nd.size(); j++)
        {
            sort(A[i].nd.begin(), A[i].nd.end());
            if (A[i].nd.size() % 2 == 0)
            {
                A[i].median = (A[i].nd[A[i].nd.size() / 2 - 1] + A[i].nd[A[i].nd.size() / 2]) / 2;
            }
            else
            {
                A[i].median = A[i].nd[A[i].nd.size() / 2];
            }
        }
    }
}
void rez( vector<studentas> &A)
{
    char answ;
    string output = "";
    double final;
    cout << "ar norite gauti mediana y/n" << endl;
    cin >> answ;

    if (answ == 'y')
    {
        for (int i = 0; i < A.size(); i++)
        {
            string s = to_string(A[i].final);
            string s2= to_string(A[i].median);
            A[i].vard.resize(15, ' ');
            A[i].pav.resize(15, ' ');
            output += A[i].vard + " " + A[i].pav + " " + s + " " + s2 + "\n";
        }
    }
    else{
        for (int i = 0; i < A.size(); i++)
        {
            string s = to_string(A[i].final);
            A[i].vard.resize(15, ' ');
            A[i].pav.resize(15, ' ');
            output += A[i].vard + " " + A[i].pav + " " + s + "\n";
        }
    }

    ofstream out_f("rezultatas.txt");
    out_f << output;
    out_f.close();
}
