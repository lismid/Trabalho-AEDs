#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#pragma once

#include <fstream>
#include "Data.hpp"
#include <string>
#include <vector>
#pragma once
using namespace std;

class Paciente {
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
    Paciente(const string &n, long int tel, const DATA &dataNasc, const string &log, int num,
            const string &bai, const string &comp, long int cep, const string &cid,
            const string &est, long int codPaciente): nome(n),telefone(tel),dataNascimento(dataNasc), logradouro(log),numero(num),bairro(bai),
            complemento(comp),CEP(cep),cidade(cid),estado(est),codigoPaciente(codPaciente){}

    // Getters
    string getNome() const {
        return nome;
    };
    long int getTelefone() const {
        return telefone;
    };
    DATA getDataNascimento() const {
        return dataNascimento;
    };
    string getLogradouro() const {
        return logradouro;
    };
    int getNumero() const {
        return numero;
    };
    string getBairro() const {
        return bairro;
    };
    string getComplemento() const {
        return complemento;
    };
    long int getCEP() const {
        return CEP;
    };
    string getCidade() const {
        return cidade;
    };
    string getEstado() const {
        return estado;
    };
    long int getCodigoPaciente() const {
        return codigoPaciente;
    };

    // Setters
    void setNome(const string &n) {
        nome = n;
    };
    void setTelefone(long int tel) {
        telefone = tel;
    };
    void setDataNascimento(const DATA &dataNasc) {
        dataNascimento = dataNasc;
    };
    void setLogradouro(const string &log) {
        logradouro = log;
    };
    void setNumero(int num){
        numero = num;
    };
    void setBairro(const string &bai){
        bairro = bai;
    };
    void setComplemento(const string &comp){
        complemento = comp;
    };
    void setCEP(long int cep){
        CEP = cep;
    };
    void setCidade(const string &cid){
        cidade = cid;
    };
    void setEstado(const string &est){
        estado = est;
    };
    void setCodigoPaciente(long int codPaciente){
        codigoPaciente = codPaciente;
    };

    // Métodos para manipulação de pacientes
    void adicionarPaciente(const string &nome, long int telefone, const DATA &dataNasc,
                           const string &logradouro, int numero, const string &bairro,
                           const string &complemento, long int cep, const string &cidade,
                           const string &estado, long int codigoPaciente);

    // Métodos para manipulação de pacientes
    void cadastrarPaciente() {
        // Implementação do cadastro de paciente
    }

    void descadastrarPaciente() {
        // Implementação do descadastro de paciente
    }

    void static salvarPacientes(const vector<Paciente> &pacientes) {
        ofstream arquivo("pacientes.txt");
        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo de médicos para escrita." << endl;
            return;
        }

        for (const auto& paciente : pacientes) {
            arquivo << paciente.getCodigoPaciente() << " "
                    << paciente.getNome() << endl;
        }

        arquivo.close();
    }
};

#endif 
