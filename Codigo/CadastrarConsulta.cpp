#include "/home/julio/Documentos/Trabalho-AEDs/Classes/Consulta.hpp"
#include "CadastrarPaciente.hpp"
#include "Medico.hpp"
#include <iostream>
#include <vector>

void cadastrarConsulta(vector<CONSULTA>& consultas, CadastroPessoas& cadastroPessoas) {
    int codigoPaciente, codigoMedico;
    DATA dataConsulta;

    cout << "Informe o código do paciente: ";
    cin >> codigoPaciente;
    cout << "Informe o código do médico: ";
    cin >> codigoMedico;
    cout << "Informe a data da consulta (dia mes ano horas minutos): ";
    cin >> dataConsulta;

    if (CONSULTA::podeAtenderMaisUmaConsulta(consultas, codigoMedico, dataConsulta)) {
        PACIENTE* paciente = cadastroPessoas.encontrarPacientePorCodigo(codigoPaciente);
        vector<Medico> medicos = lerMedicos();
        Medico* medico = nullptr;

        for (auto& med : medicos) {
            if (med.getCodigo() == codigoMedico) {
                medico = &med;
                break;
            }
        }

        if (paciente && medico) {
            CONSULTA novaConsulta;
            novaConsulta.agendarConsulta(codigoPaciente, codigoMedico, dataConsulta);
            consultas.push_back(novaConsulta);
        } else {
            cout << "Erro: Paciente ou médico não encontrado." << endl;
        }
    } else {
        cout << "Erro: O médico já possui o máximo de consultas agendadas para o dia." << endl;
    }
}
