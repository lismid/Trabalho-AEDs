#ifndef DATA_H
#define DATA_H

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
    DATA(int d, int m, int a) : dia(d), mes(m), ano(a) {}
    DATA(int d, int m, int a, int h, int mn) : dia(d), mes(m), ano(a), horas(h), minutos(mn) {
        // Aqui, chame a função de validação diretamente no construtor
        if (!validarData()) {
            throw std::invalid_argument("Data e hora inválidas.");
        }
    }

    // Getters
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }
    int getHoras() const { return horas; }
    int getMinutos() const { return minutos; }

    // Setters com validação básica
    void setDia(int d) { if (d >= 1 && d <= 31) dia = d; }
    void setMes(int m) { if (m >= 1 && m <= 12) mes = m; }
    void setAno(int a) { ano = a; }
    void setHoras(int h) { if (h >= 0 && h <= 23) horas = h; }
    void setMinutos(int mn) { if (mn >= 0 && mn <= 59) minutos = mn; }

    // Exibição formatada da data e hora
    std::string getVerData() const {
        return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(ano) + " " + std::to_string(horas) + ":" + std::to_string(minutos);
    }

    // Função para validar os dados da data e hora
    bool validarData() const {
        if (ano < 0 || mes < 1 || mes > 12 || dia < 1 || dia > diasNoMes(mes, ano) || horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
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

private:
    int diasNoMes(int mes, int ano) const {
        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
                    return 29;
                else
                    return 28;
            default:
                return -1; // Valor inválido de mês
        }
    }
};

#endif // DATA_H
