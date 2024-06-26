#include "../Classes/Consulta.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

CONSULTA::CONSULTA() : codigoConsulta(0), medico(nullptr), paciente(nullptr) {}

CONSULTA::CONSULTA(int codigoConsulta, const Medico& medico, const PACIENTE& paciente, const DATA& dataConsulta)
    : codigoConsulta(codigoConsulta), dataConsulta(dataConsulta), medico(new Medico(medico)), paciente(new PACIENTE(paciente)) {}

CONSULTA::~CONSULTA() {
    delete medico;
    delete paciente;
}

void CONSULTA::agendarConsulta(int codigoPaciente, int codigoMedico, int dia, int mes, int ano, int horas, int minutos) {
    string nomeMedico, especialidadeMedico;
    string nomePaciente, logradouroPaciente, bairroPaciente, complementoPaciente, cidadePaciente, estadoPaciente;
    long int telefonePaciente, cepPaciente;
    int numeroPaciente;

    // Solicitar e ler os dados do médico
    cout << "Informe o nome do médico: ";
    cin >> nomeMedico;
    cout << "Informe a especialidade do médico: ";
    cin >> especialidadeMedico;

    medico = new Medico(codigoMedico, nomeMedico, especialidadeMedico);

    // Solicitar e ler os dados do paciente
    cout << "Informe o nome do paciente: ";
    cin >> nomePaciente;
    cout << "Informe o telefone do paciente: ";
    cin >> telefonePaciente;

    DATA dataNascimentoPaciente(dia, mes, ano, horas, minutos); // Criação do objeto DATA com os dados fornecidos

    cout << "Informe o logradouro: ";
    cin >> logradouroPaciente;
    cout << "Informe o número: ";
    cin >> numeroPaciente;
    cout << "Informe o bairro: ";
    cin >> bairroPaciente;
    cout << "Informe o complemento: ";
    cin >> complementoPaciente;
    cout << "Informe o CEP: ";
    cin >> cepPaciente;
    cout << "Informe a cidade: ";
    cin >> cidadePaciente;
    cout << "Informe o estado: ";
    cin >> estadoPaciente;

    paciente = new PACIENTE(nomePaciente, telefonePaciente, dataNascimentoPaciente,
                            logradouroPaciente, numeroPaciente, bairroPaciente,
                            complementoPaciente, cepPaciente, cidadePaciente,
                            estadoPaciente, codigoPaciente);

    dataConsulta = dataNascimentoPaciente;
    gerarCodigoConsulta();
    salvarConsulta();
    cout << "Consulta agendada com sucesso!" << endl;
}

int CONSULTA::getCodigoMedico() const {
    return medico ? medico->getCodigo() : -1;
}

int CONSULTA::getCodigoPaciente() const {
    return paciente ? paciente->getCodigoPaciente() : -1;
}

int CONSULTA::getCodigoConsulta() const {
    return codigoConsulta;
}

DATA CONSULTA::getDataConsulta() const {
    return dataConsulta;
}

void CONSULTA::cancelarConsulta() {
    codigoConsulta = 0;
    delete medico;
    delete paciente;
    medico = nullptr;
    paciente = nullptr;
    cout << "Consulta cancelada!" << endl;
}

void CONSULTA::gerarCodigoConsulta() {
    int maiorCodigo = 0;

    ifstream arquivo("consultas.txt");
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo de consultas." << endl;
        return;
    }

    int codigo, codigoMedico, codigoPaciente, dia, mes, ano, horas, minutos;
    string nomeMedico, especialidadeMedico, nomePaciente;
    long int telefonePaciente;

    while (arquivo >> codigo >> codigoMedico >> nomeMedico >> especialidadeMedico 
                   >> codigoPaciente >> nomePaciente >> telefonePaciente 
                   >> dia >> mes >> ano >> horas >> minutos) {
        if (codigo > maiorCodigo) {
            maiorCodigo = codigo;
        }
    }

    codigoConsulta = maiorCodigo + 1;
    arquivo.close();
}

bool CONSULTA::podeAtenderMaisUmaConsulta(const vector<CONSULTA>& consultas, int codigoMedico, const DATA& data) {
    int consultasNoDia = count_if(consultas.begin(), consultas.end(), [codigoMedico, &data](const CONSULTA& consulta) {
        return consulta.getCodigoMedico() == codigoMedico && consulta.dataConsulta.getDia() == data.getDia() &&
               consulta.dataConsulta.getMes() == data.getMes() && consulta.dataConsulta.getAno() == data.getAno();
    });
    return consultasNoDia < 2;
}

void CONSULTA::salvarConsulta() const {
    ofstream arquivo("consultas.txt", ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo de consultas." << endl;
        return;
    }

    arquivo << codigoConsulta << " "
            << medico->getCodigo() << " " << medico->getNome() << " " << medico->getEspecialidade() << " "
            << paciente->getCodigoPaciente() << " " << paciente->getNome() << " " << paciente->getTelefone() << " "
            << dataConsulta.getDia() << " " << dataConsulta.getMes() << " " << dataConsulta.getAno() << " "
            << dataConsulta.getHoras() << " " << dataConsulta.getMinutos() << endl;

    arquivo.close();
}
