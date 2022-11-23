#include<iostream>
using namespace std;
class Ensemble{
    int *tab;
    int taile;
    int nbelts;
    public:
    Ensemble();
    Ensemble(const Ensemble &);
    ~Ensemble();
    bool estVide();
    int cardinal();
    friend istream & operator>>(istream&,Ensemble &);
    friend ostream & operator<<(ostream&, Ensemble&);
    Ensemble operator+(const Ensemble &);
    void operator+(int );
    Ensemble& operator=(const Ensemble &);
    bool operator>(int );
    bool operator>(const Ensemble &);
};
