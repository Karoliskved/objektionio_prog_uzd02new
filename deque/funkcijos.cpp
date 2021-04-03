#include "funkcijos.h"

void genfilename(int & n, string & fileName)
{
    cout << "kokio dydzio failas" << endl;
    cin >> n;
    string s = to_string(n);
    fileName = "studentai" + s + ".txt";
    
}
void failoived(deque<studentas> &A, string fileName, std::chrono::duration<double> &runtime)
{
    ifstream open_f;
    try
    {

        open_f.open(fileName);
        if (!open_f)
            throw std::runtime_error("failas neatsidare");
    }
    catch (std::exception &ex)
    {
        cout << "programa neveike, nes: " << ex.what() << endl;
    }

    stringstream buffer;
    string eil, output = "", laik, laik1;
    deque<string> eilvec;
    int i = 0;

    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    buffer << open_f.rdbuf();
   

    getline(buffer, eil);
    
    while (getline(buffer, eil))
    {
        studentas B;
        stringstream ss(eil);

        ss >> laik >> laik1;
        //cout << laik << " " <<laik1<< " ";
        B.vard = laik;
        B.pav = laik1;
        int num;
        while (ss >> num)
        {
            B.nd.push_back(num);
            //cout << num << " ";
        }
        B.egz = B.nd.back();
        //cout << B.egz << endl;
        B.nd.pop_back();
        A.push_back(B);
    }

    open_f.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; 
    runtime+=diff;
    std::cout << "nuskaitymas uztruko " << diff.count() << " s\n";
}

int generaten()
{

    return (rand() % 10 + 1);
}
int generaterez()
{
    return (rand() % 10 + 1);
}
bool SortByPav(const studentas &A, const studentas &B)
{
    return A.pav < B.pav;
}

void rikiavimas(deque<studentas> &A)
{
    sort(A.begin(), A.end(), SortByPav);
}
void vid(deque<studentas> &A)
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
void fin(deque<studentas> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        A[i].final = round(A[i].vidurkis * 0.4 + 0.6 * A[i].egz);
    }
}
void med(deque<studentas> &A)
{
    for (int i = 0; i < A.size(); i++)
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
void skirs(deque<studentas> &A, deque<studentas> &B, deque<studentas> &C, std::chrono::duration<double> &runtime)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i].final >= 5)
        {
            B.push_back(A[i]);
        }
        if (A[i].final < 5)
        {
            C.push_back(A[i]);
        }
       
    }
     A.clear();
    
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; 
    runtime+=diff;
    std::cout << "skirstymas i dvi grupes " << diff.count() << " s\n";
}

void rez(deque<studentas> &A, deque<studentas> &B, std::chrono::duration<double> &runtime)
{
    char answ;
    string outputgood = "", outputbad = "";
    double final;
    //cout << "ar norite gauti mediana y/n" << endl;
    //cin >> answ;
    auto start = std::chrono::high_resolution_clock::now();
   // if (answ == 'y')
   // {
        for (int i = 0; i < A.size(); i++)
        {

            string s = to_string(A[i].final);
            //string s2 = to_string(A[i].median);
            A[i].vard.resize(15, ' ');
            A[i].pav.resize(15, ' ');
            outputgood += A[i].vard + A[i].pav + s + " " + "\n";
        }
        for (int i = 0; i < B.size(); i++)
        {
            string s = to_string(B[i].final);
            //string s2 = to_string(B[i].median);
            B[i].vard.resize(15, ' ');
            B[i].pav.resize(15, ' ');
            outputbad += B[i].vard + B[i].pav + s + " "  + "\n";
        }
    //}

   /* else
    {
        
        for (int i = 0; i < A.size(); i++)
        {

            string s = to_string(A[i].final);
            A[i].vard.resize(15, ' ');
            A[i].pav.resize(15, ' ');
            outputgood += A[i].vard + A[i].pav + s + " " +"\n";
        }
        for (int i = 0; i < B.size(); i++)
        {
            string s = to_string(B[i].final);
            B[i].vard.resize(15, ' ');
            B[i].pav.resize(15, ' ');
            outputbad += B[i].vard + B[i].pav + s + " " +  "\n";
        }
        
    }*/

    ofstream out_fgood("rezultatasdauguz5.txt");
    out_fgood << outputgood;
    out_fgood.close();
    ofstream out_fbad("rezultatasmazuz5.txt");
    out_fbad << outputbad;
    out_fbad.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; 
    runtime+=diff;
    std::cout << "rezultato rasymas i faila " << diff.count() << " s\n";
    cout << "visas laikas " << runtime.count() << endl;
}