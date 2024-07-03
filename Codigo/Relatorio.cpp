#include "../Classes/Paciente.hpp"
#include "../Classes/Relatorio.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

Relatorio::Relatorio() {}

Relatorio::~Relatorio() {}

vector<CONSULTA> Relatorio::lerConsultas() const {
    vector<CONSULTA> consultas;
    ifstream arquivo("consultas.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo de consultas." << endl;
        return consultas;
    }

    int codigoConsulta, codigoMedico, codigoPaciente, dia, mes, ano, horas, minutos;
    string nomeMedico, especialidadeMedico, nomePaciente;
    long int telefonePaciente;

    while (arquivo >> codigoConsulta >> codigoMedico >> nomeMedico >> especialidadeMedico 
                   >> codigoPaciente >> nomePaciente >> telefonePaciente 
                   >> dia >> mes >> ano >> horas >> minutos) {
        Medico medico(codigoMedico, nomeMedico, especialidadeMedico);
        DATA dataConsulta(dia, mes, ano, horas, minutos);
        Paciente paciente(nomePaciente, telefonePaciente, dataConsulta, "", 0, "", "", 0, "", "", codigoPaciente);
        CONSULTA consulta(codigoConsulta, medico, paciente, dataConsulta);
        consultas.push_back(consulta);
    }

    arquivo.close();
    return consultas;
}

vector<Medico> Relatorio::lerMedicos() const {
    vector<Medico> medicos;
    ifstream arquivo("medicos.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo de medicos." << endl;
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

vector<Paciente> Relatorio::lerPacientes() const {
    vector<Paciente> pacientes;
    ifstream arquivo("pacientes.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo de pacientes." << endl;
        return pacientes;
    }

    string nome, logradouro, bairro, complemento, cidade, estado;
    int codigo, numero, dia, mes, ano, horas, minutos;
    long int telefone, cep;
    while (arquivo >> nome >> telefone >> dia >> mes >> ano >> horas >> minutos 
                   >> logradouro >> numero >> bairro >> complemento >> cep 
                   >> cidade >> estado >> codigo) {
        DATA dataNascimento(dia, mes, ano, horas, minutos);
        Paciente paciente(nome, telefone, dataNascimento, logradouro, numero, bairro, complemento, cep, cidade, estado, codigo);
        pacientes.push_back(paciente);
    }

    arquivo.close();
    return pacientes;
}

void Relatorio::consultasPorData(const DATA& data) const {
    vector<CONSULTA> consultas = lerConsultas();
    cout << "Consultas no dia " << data.getVerData() << ":" << endl;
    for (const auto& consulta : consultas) {
        if (consulta.getDataConsulta().getDia() == data.getDia() &&
            consulta.getDataConsulta().getMes() == data.getMes() &&
            consulta.getDataConsulta().getAno() == data.getAno()) {
            cout << "Consulta de codigo: " << consulta.getCodigoConsulta() << endl;
        }
    }
}

void Relatorio::consultasPorPaciente(const string& nomeOuCodigoPaciente) const {
    vector<CONSULTA> consultas = lerConsultas();
    vector<Paciente> pacientes = lerPacientes();

    int codigoPaciente = -1;
    try {
        codigoPaciente = stoi(nomeOuCodigoPaciente);
    } catch (...) {
        // nomeOuCodigoPaciente is not a number, treat it as a name
    }

    cout << "Consultas do paciente " << nomeOuCodigoPaciente << ":" << endl;
    for (const auto& paciente : pacientes) {
        if (paciente.getCodigoPaciente() == codigoPaciente || paciente.getNome() == nomeOuCodigoPaciente) {
            for (const auto& consulta : consultas) {
                if (consulta.getCodigoPaciente() == paciente.getCodigoPaciente()) {
                    cout << "Consulta de codigo: " << consulta.getCodigoConsulta() << " em " << consulta.getDataConsulta().getVerData() << endl;
                }
            }
            return; // Patient found, exit loop
        }
    }
    cout << "Paciente nao encontrado." << endl;
}

void Relatorio::consultasPorMedico(const string& nomeOuCodigoMedico) const {

    vector<CONSULTA> consultas = lerConsultas();
    vector<Medico> medicos = lerMedicos();

    int codigoMedico = -1;
    try {
        codigoMedico = stoi(nomeOuCodigoMedico);
    } catch (...) {
        // nomeOuCodigoMedico is not a number, treat it as a name
    }

    cout << "Consultas do medico " << nomeOuCodigoMedico << " " << endl;
    for (const auto& medico : medicos) {
        if (medico.getCodigo() == codigoMedico || medico.getNome() == nomeOuCodigoMedico) {
            for (const auto& consulta : consultas) {
                if (consulta.getCodigoMedico() == medico.getCodigo()) {
                    cout << "Consulta de codigo: " << consulta.getCodigoConsulta() << " em " << consulta.getDataConsulta().getVerData() << endl;
                }
            }
            return; 
        }
    }
    cout << "Medico nao encontrado." << endl;
}
