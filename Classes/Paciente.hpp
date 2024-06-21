#ifndef PACIENTE_H
#define PACIENTE_H

#include "Data.hpp"
#include <string>
using namespace std;

class PACIENTE
{
private:
    string nome;
    long int telefone;
    DATA dataNASCIMENTO;
    string logradouro;
    int numero;
    string bairro;
    string complemento;
    long int CEP;
    string cidade;
    string estado;
    long int codigoPACIENTE;

public:
    PACIENTE();
    PACIENTE(const string &n, long int tel, const DATA &dataNasc, const string &log, int num, const string &bai, const string &comp, long int cep, const string &cid, const string &est, long int codPaciente);

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
    void cadastrarPaciente();
    void descadastrarPaciente();
};

#endif
