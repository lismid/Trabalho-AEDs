#include <iostream>
#include "/home/julio/Documentos/Trabalho-AEDs/Codigo/CadastrarPaciente.hpp"
#include "/home/julio/Documentos/Trabalho-AEDs/Classes/Paciente.hpp"
#include "Data.hpp"

int main() {
    CadastroPessoas cadastro;

    // Adicionando pacientes ao cadastro
    PACIENTE paciente1("João", 1234567890, DATA(1, 1, 1990, 0, 0), "Rua A", 10, "Bairro B", "Compl C", 12345678, "Cidade D", "ES", 1);
    PACIENTE paciente2("Maria", 2345678901, DATA(2, 2, 1985, 0, 0), "Rua B", 20, "Bairro C", "Compl D", 23456789, "Cidade E", "RJ", 2);
    PACIENTE paciente3("José", 3456789012, DATA(3, 3, 2000, 0, 0), "Rua C", 30, "Bairro D", "Compl E", 34567890, "Cidade F", "SP", 3);

    cadastro.adicionarPaciente(paciente1);
    cadastro.adicionarPaciente(paciente2);
    cadastro.adicionarPaciente(paciente3);

    // Encontrando pacientes pelo código
    PACIENTE* paciente = cadastro.encontrarPacientePorCodigo(2);
    if (paciente) {
        std::cout << "Paciente encontrado: " << paciente->getNome() << " (Código: " << paciente->getCodigoPaciente() << ")" << std::endl;
    } else {
        std::cout << "Paciente não encontrado pelo código." << std::endl;
    }

    // Encontrando pacientes pelo nome
    paciente = cadastro.encontrarPacientePorNome("José");
    if (paciente) {
        std::cout << "Paciente encontrado: " << paciente->getNome() << " (Código: " << paciente->getCodigoPaciente() << ")" << std::endl;
    } else {
        std::cout << "Paciente não encontrado pelo nome." << std::endl;
    }

    return 0;
}
