#include "funkcijos.h"



int main()
{
    
    int studsk, n, failodyd;
    std::chrono::duration<double> runtime;
    string fileName;
    list<studentas> Stud, ger;
    string a;
    string b;
  //  zmogus zmogus1(a, b);
    
    
    
        genfilename(failodyd, fileName);
        
        failoived(Stud, fileName, runtime); 
          
    
   
   
    vid(Stud);
    //med(Stud);
    fin(Stud);
    skirs(Stud, ger, runtime);
     rikiavimas(Stud);
      rikiavimas(ger);
    rez(ger, Stud, runtime);
  
}
