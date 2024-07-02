#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <stdexcept>

class DATA {
private:
    int dia;
    int mes;
    int ano;
    int horas;
    int minutos;

public:
    DATA() : dia(0), mes(0), ano(0), horas(0), minutos(0) {}
    DATA(int d, int m, int a) : dia(d), mes(m), ano(a), horas(0), minutos(0) {
        if (!validarData(d, m, a)) {
            throw std::invalid_argument("Data inválida.");
        }
    }
    DATA(int d, int m, int a, int h, int mn) : dia(d), mes(m), ano(a), horas(h), minutos(mn) {
        if (!validarData(d, m, a) || !validarHora(h, mn)) {
            throw std::invalid_argument("Data ou hora inválidas.");
        }
    }

    // Getters
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }
    int getHoras() const { return horas; }
    int getMinutos() const { return minutos; }

    // Setters com validação básica
    void setDia(int d) { if (validarData(d, mes, ano)) dia = d; }
    void setMes(int m) { if (validarData(dia, m, ano)) mes = m; }
    void setAno(int a) { if (validarData(dia, mes, a)) ano = a; }
    void setHoras(int h) { if (validarHora(h, minutos)) horas = h; }
    void setMinutos(int mn) { if (validarHora(horas, mn)) minutos = mn; }

    // Exibição formatada da data e hora
    std::string getVerData() const {
        return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(ano) + " " + std::to_string(horas) + ":" + std::to_string(minutos);
    }

    // Função para validar os dados da data
    bool validarData(int d, int m, int a) const {
        if (m < 1 || m > 12) {
            return false;
        }

        if (d < 1) {
            return false;
        }

        static const int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int max_day = days_in_month[m - 1];
        
        if (m == 2) {
            bool is_leap_year = (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
            if (is_leap_year) {
                max_day = 29;
            }
        }

        return d <= max_day;
    }

    // Função para validar os dados da hora
    bool validarHora(int h, int mn) const {
        if (h < 0 || h > 23) {
            return false;
        }

        if (mn < 0 || mn > 59) {
            return false;
        }

        return true;
    }

    // Operador de igualdade (==) para comparar duas datas
    bool operator==(const DATA& outra) const {
        return dia == outra.dia && mes == outra.mes && ano == outra.ano && horas == outra.horas && minutos == outra.minutos;
    }

    // Operadores de comparação adicionais, se necessário
    bool operator!=(const DATA& outra) const {
        return !(*this == outra);
    }

    bool operator<(const DATA& outra) const {
        if (ano < outra.ano) return true;
        if (ano > outra.ano) return false;
        if (mes < outra.mes) return true;
        if (mes > outra.mes) return false;
        if (dia < outra.dia) return true;
        if (dia > outra.dia) return false;
        if (horas < outra.horas) return true;
        if (horas > outra.horas) return false;
        return minutos < outra.minutos;
    }

    bool operator>(const DATA& outra) const {
        return outra < *this;
    }

    bool operator<=(const DATA& outra) const {
        return !(outra < *this);
    }

    bool operator>=(const DATA& outra) const {
        return !(*this < outra);
    }
};

#endif // DATA_H
