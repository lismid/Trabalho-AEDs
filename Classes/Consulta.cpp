#include "Consulta.hpp"
#include <iostream>
#include <algorithm>

CONSULTA::CONSULTA() : codigoConsulta(0), medico(nullptr), paciente(nullptr) {}

CONSULTA::~CONSULTA() {
    delete medico;
    delete paciente;
}

void CONSULTA::agendarConsulta(int codigoPaciente, int codigoMedico, int dia, int mes, int ano, int horas, int minutos) {
    std::string nomeMedico, especialidadeMedico;
    std::string nomePaciente, logradouroPaciente, bairroPaciente, complementoPaciente, cidadePaciente, estadoPaciente;
    long int telefonePaciente, cepPaciente;
    int numeroPaciente;

    // Solicitar e ler os dados do médico
    std::cout << "Informe o nome do médico: ";
    std::cin >> nomeMedico;
    std::cout << "Informe a especialidade do médico: ";
    std::cin >> especialidadeMedico;

    medico = new Medico(codigoMedico, nomeMedico, especialidadeMedico);

    // Solicitar e ler os dados do paciente
    std::cout << "Informe o nome do paciente: ";
    std::cin >> nomePaciente;
    std::cout << "Informe o telefone do paciente: ";
    std::cin >> telefonePaciente;
    
    DATA dataNascimentoPaciente(dia, mes, ano, horas, minutos); // Criação do objeto DATA com os dados fornecidos
    
    std::cout << "Informe o logradouro: ";
    std::cin >> logradouroPaciente;
    std::cout << "Informe o número: ";
    std::cin >> numeroPaciente;
    std::cout << "Informe o bairro: ";
    std::cin >> bairroPaciente;
    std::cout << "Informe o complemento: ";
    std::cin >> complementoPaciente;
    std::cout << "Informe o CEP: ";
    std::cin >> cepPaciente;
    std::cout << "Informe a cidade: ";
    std::cin >> cidadePaciente;
    std::cout << "Informe o estado: ";
    std::cin >> estadoPaciente;

    paciente = new PACIENTE(nomePaciente, telefonePaciente, dataNascimentoPaciente,
                            logradouroPaciente, numeroPaciente, bairroPaciente,
                            complementoPaciente, cepPaciente, cidadePaciente,
                            estadoPaciente, codigoPaciente);

    dataConsulta = dataNascimentoPaciente;
    gerarCodigoConsulta();
    std::cout << "Consulta agendada com sucesso!" << std::endl;
}

int CONSULTA::getCodigoMedico() const {
    return medico ? medico->getCodigo() : -1;
}

int CONSULTA::getCodigoPaciente() const {
    return paciente ? paciente->getCodigoPaciente() : -1;
}

void CONSULTA::cancelarConsulta() {
    codigoConsulta = 0;
    delete medico;
    delete paciente;
    medico = nullptr;
    paciente = nullptr;
    std::cout << "Consulta cancelada!" << std::endl;
}

void CONSULTA::gerarCodigoConsulta() {
    static int contador = 1;
    codigoConsulta = contador++;
}

bool CONSULTA::podeAtenderMaisUmaConsulta(const std::vector<CONSULTA>& consultas, int codigoMedico, const DATA& data) {
    int consultasNoDia = std::count_if(consultas.begin(), consultas.end(), [codigoMedico, &data](const CONSULTA& consulta) {
        return consulta.getCodigoMedico() == codigoMedico && consulta.dataConsulta.getDia() == data.getDia() &&
               consulta.dataConsulta.getMes() == data.getMes() && consulta.dataConsulta.getAno() == data.getAno();
    });
    return consultasNoDia < 2;
}
