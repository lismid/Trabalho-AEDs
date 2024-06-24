#include "Consulta.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

CONSULTA::CONSULTA() : codigoConsulta(0), medico(nullptr), paciente(nullptr) {}

CONSULTA::~CONSULTA() {}

void CONSULTA::agendarConsulta(int codigoPaciente, int codigoMedico, const DATA& data) {
    // Implementar lógica para buscar e associar médico e paciente usando seus códigos
    dataConsulta = data;
    gerarCodigoConsulta();
    cout << "Consulta agendada com sucesso!" << endl;
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
    cout << "Consulta cancelada!" << endl;
}

void CONSULTA::gerarCodigoConsulta(){
    static int contador = 1;
    codigoConsulta = contador++;
}

bool CONSULTA::podeAtenderMaisUmaConsulta(const vector<CONSULTA>& consultas, int codigoMedico, const DATA& data) {
    int consultasNoDia = count_if(consultas.begin(), consultas.end(), [codigoMedico, &data](const CONSULTA& consulta) {
        return consulta.getCodigoMedico() == codigoMedico && consulta.dataConsulta == data;
    });
    return consultasNoDia < 2; 
}

