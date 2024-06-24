
#include "Data.hpp"
#include <iostream>
using namespace std;

DATA::DATA(int d,int m ,int a ,int h ,int mn ) :dia(d) ,mes(m) ,ano(a),horas(h),minutos(mn){}

void DATA::setInserirdia(int d){
    if(d>30)
    {
       cout<< "data escolhida nao existente";
    }
    dia =d; 
    
}

void DATA::setInserirdia(int d) {
    if (d > 30 || d < 1) {
        cout << "Data escolhida nao existente" << endl;
    } else {
        dia = d;
    }
}

void DATA::setInserirhora(int h) {
    if (h > 23 || h < 0) {
        cout << "Hora escolhida nao existente" << endl;
    } else {
        horas = h;
    }
}

void DATA::setInserirmes(int m) {
    if (m > 12 || m < 1) {
        cout << "Mes escolhido nao existente" << endl;
    } else {
        mes = m;
    }
}

void DATA::setInserirano(int a) {
    ano = a;
}

void DATA::setInserirminutos(int mn) {
    if (mn > 59 || mn < 0) {
        cout << "Minutos escolhidos nao existentes" << endl;
    } else {
        minutos = mn;
    }
}

void DATA::setModificarrdia(int d) {
    setInserirdia(d);
}

void DATA::setModificarrhora(int h) {
    setInserirhora(h);
}

void DATA::setModificarrmes(int m) {
    setInserirmes(m);
}

void DATA::setModificarrano(int a) {
    setInserirano(a);
}

void DATA::setModificarrminutos(int mn) {
    setInserirminutos(mn);
}

int DATA::getverdatas() {
    cout<<dia<<'/'<<mes<<"/"<<ano;
    cout<<horas<<":"<<minutos;
    return ano;
}