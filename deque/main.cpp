#include "funkcijos.h"



int main()
{
    
    int studsk, n, failodyd;
    std::chrono::duration<double> runtime;
    string fileName;
    deque<studentas> Stud, ger;
    string a;
    string b;
    //zmogus zmogus1(a, b);
   
    
    
        genfilename(failodyd, fileName);
        
        failoived(Stud, fileName, runtime); 
          
    
   
    rikiavimas(Stud);
    vid(Stud);
    //med(Stud);
    fin(Stud);
    skirs(Stud, ger, runtime);
    rez(ger, Stud, runtime);
    studentas test=Stud[1]+ger[1];
  
    cout << test ;
    
}
