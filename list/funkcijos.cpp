#include "funkcijos.h"

//class studenat funkc

void studentas::setVard(string vard)
{
    vard_ = vard;
}
void studentas::setPav(string pav)
{
    pav_ = pav;
}
void studentas::setNd(double nd)
{
    nd_.push_back(nd);
}
void studentas::setEgz(double egz)
{
    egz_ = egz;
}
void studentas::skVidurki()
{
    double sum = 0;
    list<double>::iterator it1;
    for (it1 = nd_.begin(); it1 != nd_.end(); ++it1)
    {
        sum = sum + *it1;
    }
    if (nd_.size() != 0)
        vidurkis_ = sum / nd_.size();
}
void studentas::skMedian()
{
    nd_.sort();
    list<double>::iterator it1;
    
    if (nd_.size() % 2 == 0)
    {
        it1 = nd_.begin();
            for (int i = 0; i < nd_.size() / 2; i++)
            {
                it1++;
            }
        median_ = ((double)*it1 + *--it1) / 2;
    }
    else
    {
        for (int i = 0; i < nd_.size() / 2; i++)
            {
                it1++;
            }
        median_ = *it1;
    }
}
void studentas::skfinalsuvid(){
    final_ = vidurkis_ * 0.4 + 0.6 * egz_;
    final_=std::ceil(final_ * 100 + 0.5)/100;
}
void studentas::skfinalsumed(){
    final_ = vidurkis_ * 0.4 + 0.6 * median_;
     final_=std::ceil(final_ * 100 + 0.5)/100;
}
void studentas::resizeVard(int size){
    vard_.resize(size, ' ');
}
void studentas::resizePav(int size){
    pav_.resize(size, ' ');
}



// likusios funkc.


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
        B.setVard(laik); 
        B.setPav(laik1);
        int num;
        while (ss >> num)
        {
            B.setNd(num);
            //cout << num << " ";
        }
        B.popbackGrade();
        //cout << B.egz << endl;
        B.setEgz(num);
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
    return A.getPav() < B.getPav();
}

void rikiavimas(list<studentas> &A)
{
    A.sort(SortByPav);
}
void vid(list<studentas> &A)
{
    list<studentas>::iterator it;
    for (it = A.begin(); it != A.end(); ++it)
    {
        it->skVidurki();
    }
}
void med(list<studentas> &A)
{
    list<studentas>::iterator it;
    for (it = A.begin(); it != A.end(); ++it)
    {
            it->skMedian();
    }
}
void fin(list<studentas> &A)
{
    //char ats;

    /*do
    {
        cout << "ar norite galutini bala skaiciuot su mediana iveskite m, jei su vidurkiu iveskite v" << endl;
        cin >> ats;
        if (ats = 'm')
        {
            med(A);
            for (int i = 0; i < A.size(); i++)
            {
                A[i].skfinalsumed();
            }
        }
        if (ats = 'v')
        {*/
    list<studentas>::iterator it;
    for (it = A.begin(); it != A.end(); ++it)
    {
        it->skfinalsuvid();
    }
    /*}
    } while (ats != 'm' && ats != 'v');*/
}
bool isgood(studentas &A)
{
    return A.getFinal() < 5;
}

void skirs(list<studentas> &A, list<studentas> &B, std::chrono::duration<double> &runtime)
{
    auto start = std::chrono::high_resolution_clock::now();

    list<studentas>::iterator bound;
    bound = stable_partition(A.begin(), A.end(), isgood);
    for (list<studentas>::iterator it = bound; it != A.end(); ++it)
    {

        B.push_back(*it);
    }
    int index = std::distance(A.begin(), bound);
   
    A.resize(index);


    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    runtime += diff;
    std::cout << "skirstymas i dvi grupes " << diff.count() << " s\n";
}

void rez(list<studentas> &A, list<studentas> &B, std::chrono::duration<double> &runtime)
{
    char answ;
    string outputgood = "", outputbad = "";
    double final;
    list<studentas>::iterator it;
    auto start = std::chrono::high_resolution_clock::now();

    for (it = A.begin(); it != A.end(); ++it)
    {

        string s = to_string(it->getFinal());
        s.resize(4, ' ');

       it->resizeVard(20);
       it->resizePav(20);
      
        outputgood += it->getVard() + it->getPav() + s + ' ' + "\n";
    }
    for (it = B.begin(); it != B.end(); ++it)
    {
        string s = to_string(it->getFinal());

        it->resizeVard(20);
        it->resizePav(20);
        outputbad += it->getVard() + it->getPav() + s + ' ' + "\n";
    }

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