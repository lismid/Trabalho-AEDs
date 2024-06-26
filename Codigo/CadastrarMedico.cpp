
#include "../Classes/Medico.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 

vector<Medico> lerMedicos() {
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
}
void Medico::setEspecialidade(const std::string& especialidade) {
    this->especialidade = especialidade;
}

void salvarMedicos(const vector<Medico>& medicos) {
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
void Medico::setNome(const std::string& nome) {
    this->nome = nome;
}

void cadastrarMedico() {
    string nome, especialidade;

    // Verificar a lista de médicos existentes para determinar o próximo código
    vector<Medico> medicos = lerMedicos();
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

void Medico::setNome(const string& nome) {
    this->nome = nome;
}

void Medico::setEspecialidade(const string& especialidade) {
    this->especialidade = especialidade;
}