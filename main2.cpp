#include<iostream>
// #include"Ensemble.h"
#include"Ensemble.cpp"
using namespace std;
int main (){
    Ensemble e3,e1,e4;
    if(e1.estVide()){
        cout<<"e1 est vide"<<endl;
    }
    else{
        cout<<"e1 n est pas vide"<<endl;
    }
    cin>>e1;
    cout<<"cardinal de e1 est  "<<e1.cardinal()<<endl;
    Ensemble e2(e1);
    e2+17;
    e2+11;
    e2+3;
    e2+7;
    e1+7;
    cout<<e2;
    e3=e1+e2;
    cout<<e3;
    cout<<e2;
    cout<<e1;
    if(e1>7){
        cout<<"e1 contient 7"<<endl;
    }
    else{
        cout<<"e1 ne contient pas 7"<<endl;
    }
    if(e2>e1){
    cout<<"e2 contient e1"<<endl;
    }
    else {
        cout<<"e2 ne contient pas e1"<<endl;
    }
return 0;
}