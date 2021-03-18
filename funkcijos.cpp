#include "funkcijos.h"
bool vedbudas()
{
    char answ;
    do
    {
        cout << "ar bus vykdmas skaitymas is failo  y/n" << endl;
        cin >> answ;
    } while (answ != 'y' && answ != 'n');
    return answ == 'y';
}
bool arfailagen()
{
    char answ;
    do
    {
        cout << "ar sugeneruoti faila  y/n" << endl;
        cin >> answ;
    } while (answ != 'y' && answ != 'n');
    return answ == 'y';
}
void genfilename(int & n, string & fileName)
{
    cout << "kokio dydzio failas" << endl;
    cin >> n;
    string s = to_string(n);
    fileName = "studentai" + s + ".txt";
    
}
void failogen(string &fileName, int n, std::chrono::duration<double> &runtime)
{

    int num, m = generaten();
    string output = "\n";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        string vard = "Vardas" + s;
        string pav = "Pavarde" + s;
        vard.resize(15, ' ');
        pav.resize(15, ' ');
        output += vard + " " + pav + " ";
        for (int j = 0; j < m; j++)
        {
            num = round(generaterez());

            string s = to_string(num);
            output += s + " ";
        }
        int egz = generaterez();
        string s1 = to_string(egz);
        output += s1 + "\n";
    }

    ofstream out_f(fileName);
    out_f << output;
    out_f.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; 
    runtime+=diff;
    std::cout << "generavimas uztruko " << diff.count() << " s\n";
}
void failoived(vector<studentas> &A, string fileName, std::chrono::duration<double> &runtime)
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
    vector<string> eilvec;
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

void rikiavimas(vector<studentas> &A)
{
    sort(A.begin(), A.end(), SortByPav);
}
void vid(vector<studentas> &A)
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
void fin(vector<studentas> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        A[i].final = round(A[i].vidurkis * 0.4 + 0.6 * A[i].egz);
    }
}
void med(vector<studentas> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].nd.size(); j++)
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
}
void skirs(vector<studentas> &A, vector<studentas> &B, vector<studentas> &C, std::chrono::duration<double> &runtime)
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
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; 
    runtime+=diff;
    std::cout << "skirstymas i dvi grupes " << diff.count() << " s\n";
}

void rez(vector<studentas> &A, vector<studentas> &B, std::chrono::duration<double> &runtime)
{
    char answ;
    string outputgood = "", outputbad = "";
    double final;
    cout << "ar norite gauti mediana y/n" << endl;
    cin >> answ;
    auto start = std::chrono::high_resolution_clock::now();
    if (answ == 'y')
    {
        for (int i = 0; i < A.size(); i++)
        {

            string s = to_string(A[i].final);
            string s2 = to_string(A[i].median);
            A[i].vard.resize(15, ' ');
            A[i].pav.resize(15, ' ');
            outputgood += A[i].vard + A[i].pav + s + " " + s2 + "\n";
        }
        for (int i = 0; i < B.size(); i++)
        {
            string s = to_string(B[i].final);
            string s2 = to_string(B[i].median);
            B[i].vard.resize(15, ' ');
            B[i].pav.resize(15, ' ');
            outputbad += B[i].vard + B[i].pav + s + " " + s2 + "\n";
        }
    }

    else
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
        
    }

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