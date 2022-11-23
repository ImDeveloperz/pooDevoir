#include<iostream>
#include"Ensemble.h"

using namespace std;
Ensemble::Ensemble(){
    taile=0; 
    nbelts=0; 
}
Ensemble::Ensemble(const Ensemble & E){
    taile=E.taile;
    nbelts=E.nbelts;
    tab=new int(taile);
    for(int i=0;i<nbelts;i++){
     tab[i]=E.tab[i];
    }
}
 Ensemble::~Ensemble(){
    cout<<"appele distructeur"<<endl;
    delete[] tab;
    taile=0;
    nbelts=0;
}
bool Ensemble::estVide(){
   if(nbelts==0){
      return true;
   }
   return false;
}
int Ensemble::cardinal(){
    return nbelts;
}
ostream& operator<<(ostream& cout,Ensemble& E){
    cout<<"nombre elements est : "<<E.nbelts<<endl;
    cout<<"la taile du l ensemble est : "<<E.taile<<endl;
    for(int i=0;i<E.nbelts;i++)
    cout<<E.tab[i]<<"    "; 
    return cout;
}
istream & operator >>(istream & cin, Ensemble & E){
    int nouveau;
    cout<<"saisie nbelmts"<<endl;
    cin>>E.nbelts;
    cout<<"saisie taile"<<endl;
    cin>>E.taile;
    E.tab=new int(E.taile);
    cout<<"saisie elements" <<endl;
    for(int i=0;i<E.nbelts;i++){
            cin>>nouveau;
    if(E>nouveau)i--;
    else
    E.tab[i]=nouveau;
    }
    return cin;
}
void Ensemble::operator+(int a){ 
    if(taile>nbelts && !(*this>a)){
        nbelts++;
        tab[nbelts-1]=a;
        cout<<"adding .."<<a<<endl;
    }
    else{
       cout<<"table plien can't add"<<a<<endl;
    }
}
Ensemble Ensemble::operator+(const Ensemble& E){ 
    Ensemble E1;
    int j=nbelts;
     E1.taile=taile+E.taile;
     E1.tab=new int(E1.taile);
     bool trouve=false;
     for(int i=0;i<nbelts;i++){
          E1.tab[i]=tab[i];
     }
     for(int i=0;i<E.nbelts;i++){
        trouve=false;
        for(int k=0;k<j;k++){
         if(E1.tab[k]==E.tab[i])
       trouve=true;
        }
        if(!trouve){
           E1.tab[j]=E.tab[i];
          j++;
        }
     }
     E1.nbelts=j;
     return E1;
    }
    //{1,2,3}+{1,4,5}={1,2,4,3,5};

 Ensemble& Ensemble::operator=(const Ensemble & E){
    taile=E.taile;
    nbelts=E.nbelts;
    tab=new int(taile);
    for(int i=0;i<nbelts;i++){
          tab[i]=E.tab[i];
    }
    return *this;
 }
 //e1=e2=e3
//e1=*this pointe sur e2
bool Ensemble::operator>(int a){
    for(int i=0;i<nbelts;i++)
    { if(tab[i]==a) return true;
    }
    return false;
}
//{1,2,3,4,5} a=5 true 
bool Ensemble::operator>(const Ensemble & E){
    if(nbelts<E.nbelts) return false;
     int cpt=0;
    while(cpt<E.nbelts){
        if(!(*this>E.tab[cpt])){
            return false;
        }
        cpt++;
}
      return true;
        
    }
//e1={1,2,3,4} e2={1 ,2,6} e1>e2