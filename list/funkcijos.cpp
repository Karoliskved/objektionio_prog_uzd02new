#include "funkcijos.h"

void genfilename(int &n, string &fileName)
{
    cout << "kokio dydzio failas" << endl;
    cin >> n;
    string s = to_string(n);
    fileName = "studentai" + s + ".txt";
}
void failoived(list<studentas> &A, string fileName, std::chrono::duration<double> &runtime)
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
    list<string> eilvec;
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
    runtime += diff;
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

void rikiavimas(list<studentas> &A)
{
    A.sort(SortByPav);
}
void vid(list<studentas> &A)
{
    double sum;
    list<studentas>::iterator it;
    list<double>::iterator it1;
    for (it = A.begin(); it != A.end(); ++it)
    {
        sum = 0;
        for (it1 = it->nd.begin(); it1 != it->nd.end(); ++it1)
        {
            sum = sum + *it1;
        }
        if (it->nd.size() != 0)
            it->vidurkis = sum / it->nd.size();
    }
}
void fin(list<studentas> &A)
{
    list<studentas>::iterator it;
    for (it = A.begin(); it != A.end(); ++it)
    {
        it->final = round(it->vidurkis * 0.4 + 0.6 * it->egz);
    }
}
void med(list<studentas> &A)
{
    list<studentas>::iterator it;
    list<double>::iterator it1;

    for (it = A.begin(); it != A.end(); ++it)
    {

       // sort(it->nd.begin(), it->nd.end());
        it->nd.sort();
        if (it->nd.size() % 2 == 0) // sprendima kaip apskaiciuoti mediana list nariu radau cia: http://cplusplus.com/forum/beginner/196747/
        {
            it1 = it->nd.begin();
            for (int i = 0; i < it->nd.size() / 2; i++)
            {
                it1++;
            }

            it->median = ((double)*it1 + *--it1) / 2;
        }
        else
        {
            for (int i = 0; i < it->nd.size() / 2; i++)
            {
                it1++;
            }
            it->median = *it1;
        }
    }
}
void skirs(list<studentas> &A, list<studentas> &B, list<studentas> &C, std::chrono::duration<double> &runtime)
{
    auto start = std::chrono::high_resolution_clock::now();
    list<studentas>::iterator it;
    for (it = A.begin(); it != A.end(); ++it)
    {
        if (it->final >= 5)
        {
            B.push_back(*it);
        }
        if (it->final < 5)
        {
            C.push_back(*it);
        }
    }
    A.clear();

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    runtime += diff;
    std::cout << "skirstymas i dvi grupes " << diff.count() << " s\n";
}

void rez(list<studentas> &A, list<studentas> &B, std::chrono::duration<double> &runtime)
{
    char answ;
    string outputgood = "", outputbad = "";
    double final;
    //cout << "ar norite gauti mediana y/n" << endl;
    //cin >> answ;
    auto start = std::chrono::high_resolution_clock::now();
    // if (answ == 'y')
    // {
    list<studentas>::iterator it;
    for (it = A.begin(); it != A.end(); ++it)
    {

        string s = to_string(it->final);
        //string s2 = to_string(it->median);
        it->vard.resize(15, ' ');
        it->pav.resize(15, ' ');
        outputgood += it->vard + it->pav + s + " "  + "\n";
    }
    for (it = A.begin(); it != A.end(); ++it)
    {
        string s = to_string(it->final);
        //string s2 = to_string(it->median);
        it->vard.resize(15, ' ');
        it->pav.resize(15, ' ');
        outputbad += it->vard + it->pav + s + " " + "\n";
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
    runtime += diff;
    std::cout << "rezultato rasymas i faila " << diff.count() << " s\n";
    cout << "visas laikas " << runtime.count() << endl;
}