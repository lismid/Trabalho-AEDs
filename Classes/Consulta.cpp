#include "Consulta.hpp"
#include <iostream>
#include <algorithm>

CONSULTA::CONSULTA() : codigoConsulta(0), medico(nullptr), paciente(nullptr) {}

CONSULTA::~CONSULTA() {}

void CONSULTA::agendarConsulta(int codigoPaciente, int codigoMedico, const DATA& data) {
    // Implementar lógica para buscar e associar médico e paciente usando seus códigos
    dataConsulta = data;
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
    medico = nullptr;
    paciente = nullptr;
    std::cout << "Consulta cancelada!" << std::endl;
}

void Consulta::gerarCodigoConsulta(){
    static int contador = 1;
    codigoConsulta = contador++;
}

bool Consulta::podeAtenderMaisUmaConsulta(const std::vector<CONSULTA>& consultas, int codigoMedico, const Data& data) {
    int consultasNoDia = std::count_if(consultas.begin(), consultas.end(), [codigoMedico, &data](const Consulta& consulta) {
        return consulta.getCodigoMedico() == codigoMedico && consulta.dataConsulta == data;
    });
    return consultasNoDia < 10; // Exemplo: permitir até 10 consultas por dia
}

