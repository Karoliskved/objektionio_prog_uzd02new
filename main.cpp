#include "funkcijos.h"



int main()
{
    int studsk, n, failodyd;
    std::chrono::duration<double> runtime;
    string fileName;
    vector<studentas> Stud, ger, blog;
    srand(time(NULL));
    if (vedbudas() == true)
    {
        genfilename(failodyd, fileName);
        if(arfailagen()==true){
        failogen(fileName, failodyd, runtime);
        }
        failoived(Stud, fileName, runtime); 
          
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
    skirs(Stud, ger, blog, runtime);
    rez(ger, blog, runtime);
    
}
