#ifndef MEDICO_HPP
#pragma once
#define MEDICO_HPP
#include <cstddef>
#include <iostream>
#include <vector>
#include <fstream>
#pragma once
using namespace std;

class Medico 
{
private:
    int codigo;
    string nome;
    string especialidade;

public:
    Medico() {codigo = 0; nome = "" ; especialidade = "";};
    Medico(int codigo = -1, const std::string &nome = "", const std::string &especialidade = "")
        : codigo(codigo), nome(nome), especialidade(especialidade) {}

    //Getters
    int getCodigo() const {return codigo;};
    const string &getNome() const{return nome;};
    const string &getTelefone() const{return especialidade;} ;
    const string &getEspecialidade() const { return especialidade;};

    //Setters
    void setNome(const std::string &nome) {
        this->nome = nome;
    };
    void setEspecialidade(const std::string& especialidade) {
        this->especialidade = especialidade;
    };
    
    static vector<Medico> lerMedicos() {
        vector<Medico> medicos;
        ifstream arquivo("medicos.txt");
        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo de médicos." << endl;
            return medicos;
        }

        int codigo;
        string nome, especialidade;
        while (arquivo >> codigo >> nome >> especialidade) {
            medicos.emplace_back(codigo, nome, especialidade);
        }

        arquivo.close();
        return medicos;
    };

    static void salvarMedicos(const vector<Medico>& medicos) {
        ofstream arquivo("medicos.txt");
        if (!arquivo.is_open()) {
            cerr << "Erro ao abrir o arquivo de médicos para escrita." << endl;
            return;
        }

        for (const auto& medico : medicos) {
            arquivo << medico.getCodigo() << " "
                    << medico.getNome() << " "
                    << medico.getEspecialidade() << endl;
        }

        arquivo.close();
    }

    void cadastrar() {
        cout << "Cadastrando médico: " << nome << " com especialidade: " << especialidade << endl;
    }

    void cadastrarMedico() {
        string nome, especialidade;
        
        // Verificar a lista de médicos existentes para determinar o próximo código
        vector<Medico> medicos = Medico::lerMedicos();
        int proximoCodigo = medicos.empty() ? 1 : medicos.back().getCodigo() + 1;

        cout << "Informe o nome do médico: ";
        cin >> nome;
        cout << "Informe a especialidade do médico: ";
        cin >> especialidade;

        // Criar um novo objeto de Medico
        Medico novoMedico(proximoCodigo, nome, especialidade);
        novoMedico.cadastrar();

        // Adicionar o novo médico ao vetor
        medicos.push_back(novoMedico);

        // Salvar os médicos de volta no arquivo
        salvarMedicos(medicos);

        cout << "Médico cadastrado com sucesso!" << endl;

    }
};

#endif 
