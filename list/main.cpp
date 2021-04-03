#include "funkcijos.h"



int main()
{
    int studsk, n, failodyd;
    std::chrono::duration<double> runtime;
    string fileName;
    list<studentas> Stud, ger, blog;
    srand(time(NULL));
    
    
        genfilename(failodyd, fileName);
        
        failoived(Stud, fileName, runtime); 
          
    
   
    rikiavimas(Stud);
    vid(Stud);
    //med(Stud);
    fin(Stud);
    skirs(Stud, ger, blog, runtime);
    rez(ger, blog, runtime);
    
}
