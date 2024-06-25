#ifndef PACIENTE_H
#define PACIENTE_H

#include "Data.hpp"
#include <string>

using namespace std;

class PACIENTE {
private:
    string nome;
    long int telefone;
    DATA dataNascimento; 
    string logradouro;
    int numero;
    string bairro;
    string complemento;
    long int CEP;
    string cidade;
    string estado;
    long int codigoPaciente;

public:
    // Construtor
    PACIENTE(const string &n, long int tel, const DATA &dataNasc, const string &log, int num,
            const string &bai, const string &comp, long int cep, const string &cid,
            const string &est, long int codPaciente);

    // Getters
    string getNome() const;
    long int getTelefone() const;
    DATA getDataNascimento() const;
    string getLogradouro() const;
    int getNumero() const;
    string getBairro() const;
    string getComplemento() const;
    long int getCEP() const;
    string getCidade() const;
    string getEstado() const;
    long int getCodigoPaciente() const;

    // Setters
    void setNome(const string &n);
    void setTelefone(long int tel);
    void setDataNascimento(const DATA &dataNasc);
    void setLogradouro(const string &log);
    void setNumero(int num);
    void setBairro(const string &bai);
    void setComplemento(const string &comp);
    void setCEP(long int cep);
    void setCidade(const string &cid);
    void setEstado(const string &est);
    void setCodigoPaciente(long int codPaciente);

    // Métodos para manipulação de pacientes
    void cadastrarPaciente();
    void descadastrarPaciente();
    void adicionarPaciente(const string &nome, long int telefone, const DATA &dataNasc,
                           const string &logradouro, int numero, const string &bairro,
                           const string &complemento, long int cep, const string &cidade,
                           const string &estado, long int codigoPaciente);
};

#endif // PACIENTE_H
