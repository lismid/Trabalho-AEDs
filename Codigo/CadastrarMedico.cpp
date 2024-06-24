#include "/home/julio/Documentos/Trabalho-AEDs/Classes/Medico.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void cadastrarMedico() {
    int codigo;
    string nome, telefone, especialidade;

    cout << "Informe o código do médico: ";
    cin >> codigo;
    cout << "Informe o nome do médico: ";
    cin >> nome;
    cout << "Informe o telefone do médico: ";
    cin >> telefone;
    cout << "Informe a especialidade do médico: ";
    cin >> especialidade;

    vector<Medico> medicos = lerMedicos();
    for (const auto& medico : medicos) {
        if (medico.getCodigo() == codigo) {
            cout << "Erro: Já existe um médico cadastrado com o código " << codigo << endl;
            return;
        }
    }

    Medico novoMedico(codigo, nome, telefone, especialidade);
    novoMedico.cadastrar();
}
