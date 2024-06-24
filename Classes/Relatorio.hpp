#include "Consulta.hpp"
#include "Medico.hpp"
#include <iostream>
#include <vector>

void relatorioConsultasDoMedico(const vector<CONSULTA>& consultas, const vector<Medico>& medicos, long int codigoMedico) {
    const Medico* medico = nullptr;

    for (const auto& med : medicos) {
        if (med.getCodigo() == codigoMedico) {
            medico = &med;
            break;
        }
    }

    if (!medico) {
        cout << "Erro: Médico não encontrado." << endl;
        return;
    }

    cout << "Consultas do médico " << medico->getNome() << ":" << endl;
    for (const auto& consulta : consultas) {
        if (consulta.getCodigoMedico() == codigoMedico) {
            cout << "Consulta código: " << consulta.getCodigoConsulta() 
                 << ", Paciente código: " << consulta.getCodigoPaciente() 
                 << ", Data: " << consulta.getDataConsulta().getverdata() << endl;
        }
    }
}
