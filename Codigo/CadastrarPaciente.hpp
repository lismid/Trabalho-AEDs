#ifndef CADASTRO_PESSOAS_H
#define CADASTRO_PESSOAS_H

#include "/home/julio/Documentos/Trabalho-AEDs/Classes/Paciente.hpp"
#include <vector>
#include <string>

class CadastroPessoas {
private:
    std::vector<PACIENTE> pacientes;

public:
    // Método para adicionar um novo paciente
    void adicionarPaciente(const PACIENTE& paciente) {
        pacientes.push_back(paciente);
    }

    // Método para encontrar um paciente pelo código
    PACIENTE* encontrarPacientePorCodigo(long int codigo) {
        for (auto& paciente : pacientes) {
            if (paciente.getCodigoPaciente() == codigo) {
                return &paciente;
            }
        }
        return nullptr; // Retorna nullptr se não encontrar
    }

    // Método para encontrar um paciente pelo nome
    PACIENTE* encontrarPacientePorNome(const std::string& nome) {
        for (auto& paciente : pacientes) {
            if (paciente.getNome() == nome) {
                return &paciente;
            }
        }
        return nullptr; // Retorna nullptr se não encontrar
    }
};

#endif
