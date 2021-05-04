#include "funkcijos.h"
//class zmogus funkc
zmogus::~zmogus() = default;
void zmogus::setVard(string vard)
{
    vard_ = vard;
}
void zmogus::setPav(string pav)
{
    pav_ = pav;
}
zmogus::zmogus(const zmogus &s)
{
    vard_ = s.vard_;
    pav_ = s.pav_;
}
zmogus& zmogus::operator=(const zmogus& s){
    if (&s == this) return *this;
    vard_ = s.vard_;
    pav_ = s.pav_;
  
    return *this;
}

//class studentas funkc

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
    for (int j = 0; j < nd_.size(); j++)
    {
        sum = sum + nd_[j];
    }
    if (nd_.size() != 0)
        vidurkis_ = sum / nd_.size();
}
void studentas::skMedian()
{
    sort(nd_.begin(), nd_.end());
    if (nd_.size() % 2 == 0)
    {
        median_ = (nd_[nd_.size() / 2 - 1] + nd_[nd_.size() / 2]) / 2;
    }
    else
    {
        median_ = nd_[nd_.size() / 2];
    }
}
void studentas::skfinalsuvid()
{
    final_ = vidurkis_ * 0.4 + 0.6 * egz_;
    final_ = std::ceil(final_ * 100 + 0.5) / 100;
}
void studentas::skfinalsumed()
{
    final_ = vidurkis_ * 0.4 + 0.6 * median_;
    final_ = std::ceil(final_ * 100 + 0.5) / 100;
}
void studentas::resizeVard(int size)
{
    vard_.resize(size, ' ');
}
void studentas::resizePav(int size)
{
    pav_.resize(size, ' ');
}
studentas::~studentas() = default;
studentas::studentas(const studentas &s)
{
    vard_ = s.vard_;
    pav_ = s.pav_;
    nd_ = s.nd_;
    egz_ = s.egz_;
    vidurkis_ = s.vidurkis_;
    median_ = s.median_;
    final_ = s.final_;
}
studentas& studentas::operator=(const studentas& s){
    if (&s == this) return *this;
    vard_ = s.vard_;
    pav_ = s.pav_;
    nd_ = s.nd_;
    egz_ = s.egz_;
    vidurkis_ = s.vidurkis_;
    median_ = s.median_;
    final_ = s.final_;

    return *this;
}

ostream& operator<<(ostream& os, const studentas& s){
    os << s.vard_ << s.pav_ ;
    for(int i=0; i!=s.nd_.size(); ++i){
        os << s.nd_[i] << " ";
    }
    os << s.egz_ << endl;
 return os;
}


// likusios funkc.

void genfilename(int &n, string &fileName)
{
    cout << "kokio dydzio failas" << endl;
    cin >> n;
    string s = to_string(n);
    fileName = "studentai" + s + ".txt";
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

void rikiavimas(vector<studentas> &A)
{
    sort(A.begin(), A.end(), SortByPav);
}
void vid(vector<studentas> &A)
{

    for (int i = 0; i < A.size(); i++)
    {
        A[i].skVidurki();
    }
}
void med(vector<studentas> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        A[i].skMedian();
    }
}
void fin(vector<studentas> &A)
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
    for (int i = 0; i < A.size(); i++)
    {
        A[i].skfinalsuvid();
    }
    /*}
    } while (ats != 'm' && ats != 'v');*/
}
bool isgood(studentas &A)
{
    return A.getFinal() < 5;
}

void skirs(vector<studentas> &A, vector<studentas> &B, std::chrono::duration<double> &runtime)
{
    auto start = std::chrono::high_resolution_clock::now();

    vector<studentas>::iterator bound;
    bound = stable_partition(A.begin(), A.end(), isgood);
    for (vector<studentas>::iterator it = bound; it != A.end(); ++it)
    {

        B.push_back(*it);
    }
    int index = std::distance(A.begin(), bound);

    A.resize(index);

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    runtime += diff;
    std::cout << "skirstymas i dvi grupes " << diff.count() << " s\n";
}

void rez(vector<studentas> &A, vector<studentas> &B, std::chrono::duration<double> &runtime)
{
    char answ;
    string outputgood = "", outputbad = "";
    double final;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < A.size(); i++)
    {

        string s = to_string(A[i].getFinal());
        s.resize(4, ' ');

        A[i].resizeVard(20);
        A[i].resizePav(20);

        outputgood += A[i].getVard() + A[i].getPav() + s + ' ' + "\n";
    }
    for (int i = 0; i < B.size(); i++)
    {
        string s = to_string(B[i].getFinal());

        B[i].resizeVard(20);
        B[i].resizePav(20);
        outputbad += B[i].getVard() + B[i].getPav() + s + ' ' + "\n";
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