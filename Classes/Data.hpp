#ifndef DATA_H
#define DATA_H

#include <string>
#pragma once
class DATA {
private:
    int dia;
    int mes;
    int ano;
    int horas;
    int minutos;

public:

    DATA() : dia(0), mes(0), ano(0), horas(0), minutos(0) {}
    DATA(int dia, int mes, int ano);
    DATA(int d, int m, int a, int h, int mn) : dia(d), mes(m), ano(a), horas(h), minutos(mn) {}

    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }
    int getHoras() const { return horas; }
    int getMinutos() const { return minutos; }

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }
    void setHoras(int h) { horas = h; }
    void setMinutos(int mn) { minutos = mn; }

    std::string getVerData() const {
        return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(ano) + " " + std::to_string(horas) + ":" + std::to_string(minutos);
    }
};

#endif // DATA_H
