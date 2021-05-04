#include "funkcijos.h"



int main()
{
    
    int studsk, n, failodyd;
    std::chrono::duration<double> runtime;
    string fileName;
    vector<studentas> Stud, ger;
    string a;
    string b;
    
    srand(time(NULL));
    
    
        genfilename(failodyd, fileName);
        auto start = std::chrono::high_resolution_clock::now();
        failoived(Stud, fileName, runtime); 
          
    
   
   rikiavimas(Stud);
    vid(Stud);
    //med(Stud);
    fin(Stud);
    skirs(Stud, ger, runtime);
    rez(ger, Stud, runtime);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "programos veikimas " << diff.count() << endl;
  

    studentas test=Stud[1]+ger[1];
 
    cout << test ;

}
