#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <vector>
#include "stdshortcut.h"
#include <random>
#include <time.h>
#include <algorithm>
struct studentas
{

    double egz;
    vector<double> nd;
    double vidurkis = 0, median = 0;
    string vard, pav;
};

void duomenys(int &studsk, int &n, vector<studentas> &A);
int generaten();
double generaterez();
void vid(int studsk, int n, vector<studentas> &A);
void med(int studsk, int n, vector<studentas> &A);
void rez(int studsk, vector<studentas> &A);

int main()
{
    int studsk, n;
    srand(time(NULL));
    cout << "Įveskite studentu skaičiu " << endl;
    cin >> studsk;
    vector<studentas> Stud;

    duomenys(studsk, n, Stud);
    vid(studsk, n, Stud);
    med(studsk, n, Stud);
    rez(studsk, Stud);
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

        /*do
        {
            cout << "ar žinomas pažymių skaičius y/n" << endl;
            cin >> answ;
        } while (answ != 'y' && answ != 'n');
        do
        {
            cout << "ar norite pažymius ir egzamino rezultata atsitiktinai generuoti y/n" << endl;
            cin >> answ2;
        } while (answ2 != 'y' && answ2 != 'n');*/
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
    //srand(time(NULL));
    return (rand() % 10 + 1);
}
double generaterez()
{

    return (rand() % 10 + 1);
}
void vid(int studsk, int n, vector<studentas> &A)
{
    double sum;
    for (int i = 0; i < studsk; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum = sum + A[i].nd[j];
        }
        if(n!=0)
        A[i].vidurkis = sum / n;
    }
}
void med(int studsk, int n, vector<studentas> &A)
{
    for (int i = 0; i < studsk; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sort(A[i].nd.begin(), A[i].nd.end());
            if (n % 2 == 0)
            {
                A[i].median = (A[i].nd[n / 2 - 1] + A[i].nd[n / 2]) / 2;
            }
            else
            {
                A[i].median = A[i].nd[n / 2];
            }
        }
    }
}
void rez(int studsk, vector<studentas> &A)
{
    char answ;
    cout << "ar norite gauti mediana y/n" << endl;
    cin >> answ;
    if (answ == 'y')
        for (int i = 0; i < studsk; i++)
        {
            cout << A[i].vard << " "<< " "<< A[i].pav << " " << A[i].vidurkis * 0.4 + 0.6 * A[i].egz << " " << A[i].median << endl;
            /*for(int j=0; j<A[i].n; j++){
            cout << A[i].nd[j] << endl;
        }
         cout << A[i].egz << endl;*/
        }
    else
    {
        for (int i = 0; i < studsk; i++)
        {
            cout << A[i].vard << " " << A[i].vidurkis * 0.4 + 0.6 * A[i].egz << endl;
        }
    }
}
