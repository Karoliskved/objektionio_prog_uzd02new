#include "funkcijos.h"



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
    vid(Stud);
    med(Stud);
    fin(Stud);
    rez(Stud);
}
