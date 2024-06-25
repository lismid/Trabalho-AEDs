#include "Medico.hpp"
#include <iostream>
#include <fstream>
#include <vector>

std::vector<Medico> lerMedicos() {
    std::vector<Medico> medicos;
    std::ifstream arquivo("medicos.txt");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de médicos." << std::endl;
        return medicos;
    }

    int codigo;
    std::string nome, especialidade;
    while (arquivo >> codigo >> nome >> especialidade) {
        medicos.emplace_back(codigo, nome, especialidade);
    }

    arquivo.close();
    return medicos;
}

void salvarMedicos(const std::vector<Medico>& medicos) {
    std::ofstream arquivo("medicos.txt");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de médicos para escrita." << std::endl;
        return;
    }

    for (const auto& medico : medicos) {
        arquivo << medico.getCodigo() << " "
                << medico.getNome() << " "
                << medico.getEspecialidade() << std::endl;
    }

    arquivo.close();
}


void cadastrarMedico() {
    std::string nome, especialidade;

    // Verificar a lista de médicos existentes para determinar o próximo código
    std::vector<Medico> medicos = lerMedicos();
    int proximoCodigo = medicos.empty() ? 1 : medicos.back().getCodigo() + 1;

    std::cout << "Informe o nome do médico: ";
    std::cin >> nome;
    std::cout << "Informe a especialidade do médico: ";
    std::cin >> especialidade;
    

    // Criar um novo objeto de Medico
    Medico novoMedico(proximoCodigo, nome, especialidade);
    novoMedico.cadastrar();

    // Adicionar o novo médico ao vetor
    medicos.push_back(novoMedico);

    // Salvar os médicos de volta no arquivo
    salvarMedicos(medicos);

    std::cout << "Médico cadastrado com sucesso!" << std::endl;
}
