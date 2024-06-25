
#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <iostream>
#include <vector>

using namespace std;

class Medico
{
private:
    int codigo;
    string nome;
    string especialidade;

public:
    Medico();
    Medico(int codigo = -1, const std::string &nome = "", const std::string &especialidade = "")
        : codigo(codigo), nome(nome), especialidade(especialidade) {}

    void cadastrar();

    int getCodigo() const;
    const string &getNome() const;
    const string &getTelefone() const;
    const string &getEspecialidade() const;
    void setNome(const std::string& nome);
    void setEspecialidade(const std::string& especialidade);
};


vector<Medico> lerMedicos();

#endif // MEDICO_HPP
