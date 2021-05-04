#include "funkcijos.h"



int main()
{
    
    int studsk, n, failodyd;
    std::chrono::duration<double> runtime;
    string fileName;
    list<studentas> Stud, ger;
    srand(time(NULL));
    
    
        genfilename(failodyd, fileName);
        
        failoived(Stud, fileName, runtime); 
          
    
   
    rikiavimas(Stud);
    vid(Stud);
    //med(Stud);
    fin(Stud);
    skirs(Stud, ger, runtime);
    rez(ger, Stud, runtime);
    list<studentas>::iterator it=Stud.begin();
    list<studentas>::iterator it1=ger.begin();
    studentas test=*it+*it1;
   
    cout << test ;

}
