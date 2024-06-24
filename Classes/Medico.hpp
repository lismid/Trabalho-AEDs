#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <iostream>
#include <vector>

using namespace std;

class Medico {
private:
    int codigo;
    string nome;
    string telefone;
    string especialidade;

public:
    Medico(int codigo, const string& nome, const string& telefone, const string& especialidade);

    void cadastrar();

    int getCodigo() const;
    const string& getNome() const;
    const string& getTelefone() const;
    const string& getEspecialidade() const;
};

vector<Medico> lerMedicos();

#endif // MEDICO_HPP
