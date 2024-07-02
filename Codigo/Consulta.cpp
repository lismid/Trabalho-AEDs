#include "../Classes/Consulta.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

CONSULTA::CONSULTA() : codigoConsulta(0), medico(nullptr), paciente(nullptr) {}

CONSULTA::CONSULTA(int codigoConsulta, const Medico &medico, const PACIENTE &paciente, const DATA &dataConsulta)
    : codigoConsulta(codigoConsulta), dataConsulta(dataConsulta)
{
    this->medico = new Medico(medico);
    this->paciente = new PACIENTE(paciente);
}

CONSULTA::~CONSULTA()
{
    delete medico;
    delete paciente;
}

bool validarData(const string &dataInput)
{
    // Verifica se a string tem o formato dd/mm/aaaa
    if (dataInput.size() != 10) // deve ter exatamente 10 caracteres (dd/mm/aaaa)
        return false;

    if (dataInput[2] != '/' || dataInput[5] != '/') // verifica se as barras estão nos lugares certos
        return false;

    // Verifica se são números
    for (int i = 0; i < 10; ++i)
    {
        if (i == 2 || i == 5)
            continue; // pula as barras

        if (!isdigit(dataInput[i]))
            return false;
    }

    return true;
}

bool validarHora(const string &horaInput)
{
    // Verifica se a string tem o formato hh:mm
    if (horaInput.size() != 5) // deve ter exatamente 5 caracteres (hh:mm)
        return false;

    if (horaInput[2] != ':') // verifica se os dois pontos estão no lugar certo
        return false;

    // Verifica se são números
    for (int i = 0; i < 5; ++i)
    {
        if (i == 2)
            continue; // pula o dois pontos

        if (!isdigit(horaInput[i]))
            return false;
    }

    return true;
}

void CONSULTA::agendarConsulta(int codigoPaciente, int codigoMedico, int dia, int mes, int ano, int horas, int minutos) {
    string dataInput;
    do {
        cout << "Informe a data da consulta (dd/mm/aaaa): ";
        cin >> dataInput;
    } while (!validarData(dataInput));

    int diaConsulta, mesConsulta, anoConsulta;
    try {
        diaConsulta = stoi(dataInput.substr(0, 2));
        mesConsulta = stoi(dataInput.substr(3, 2));
        anoConsulta = stoi(dataInput.substr(6, 4));
    } catch (const std::invalid_argument& e) {
        cout << "Erro ao converter data. Consulta não agendada." << endl;
        return;
    }

    string horaInput;
    do {
        cout << "Informe a hora da consulta (hh:mm): ";
        cin >> horaInput;
    } while (!validarHora(horaInput));

    int horasConsulta, minutosConsulta;
    try {
        horasConsulta = stoi(horaInput.substr(0, 2));
        minutosConsulta = stoi(horaInput.substr(3, 2));
    } catch (const std::invalid_argument& e) {
        cout << "Erro ao converter hora. Consulta não agendada." << endl;
        return;
    }

    DATA dataConsulta(diaConsulta, mesConsulta, anoConsulta, horasConsulta, minutosConsulta);

    if (!dataConsulta.validarData()) {
        cout << "Data inválida. Consulta não agendada." << endl;
        return;
    }

    // Libera memória dos objetos anteriores, se existirem
    cancelarConsulta();

    // Aloca novos objetos
    medico = new Medico(codigoMedico, "", ""); 
    paciente = new PACIENTE("", 0, dataConsulta, "", 0, "", "", 0, "", "", codigoPaciente);

    // Outras operações de agendamento, se necessário
    dataConsulta = dataConsulta; // Certifique-se de que essa linha é necessária ou ajuste conforme necessário
    gerarCodigoConsulta();
    salvarConsulta();
    cout << "Consulta agendada com sucesso!" << endl;
}



int CONSULTA::getCodigoMedico() const
{
    return (medico) ? medico->getCodigo() : -1;
}

int CONSULTA::getCodigoPaciente() const
{
    return (paciente) ? paciente->getCodigoPaciente() : -1;
}

int CONSULTA::getCodigoConsulta() const
{
    return codigoConsulta;
}

DATA CONSULTA::getDataConsulta() const
{
    return dataConsulta;
}

void CONSULTA::cancelarConsulta()
{
    codigoConsulta = 0;
    delete medico;
    delete paciente;
    medico = nullptr;
    paciente = nullptr;
    cout << "Consulta cancelada!" << endl;
}

void CONSULTA::gerarCodigoConsulta()
{
    int maiorCodigo = 0;

    ifstream arquivo("consultas.txt");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo de consultas." << endl;
        return;
    }

    int codigo, codigoMedico, codigoPaciente, dia, mes, ano, horas, minutos;
    string nomeMedico, especialidadeMedico, nomePaciente;
    long int telefonePaciente;

    while (arquivo >> codigo >> codigoMedico >> nomeMedico >> especialidadeMedico >> codigoPaciente >> nomePaciente >> telefonePaciente >> dia >> mes >> ano >> horas >> minutos)
    {
        if (codigo > maiorCodigo)
        {
            maiorCodigo = codigo;
        }
    }

    codigoConsulta = maiorCodigo + 1;
    arquivo.close();
}

bool CONSULTA::podeAtenderMaisUmaConsulta(const vector<CONSULTA> &consultas, int codigoMedico, const DATA &data)
{
    int consultasNoDia = count_if(consultas.begin(), consultas.end(), [codigoMedico, &data](const CONSULTA &consulta)
                                  { return consulta.getCodigoMedico() == codigoMedico &&
                                           consulta.getDataConsulta() == data; });
    return consultasNoDia < 2;
}

void CONSULTA::salvarConsulta() const
{
    ofstream arquivo("consultas.txt", ios::app);
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo de consultas." << endl;
        return;
    }

    arquivo << codigoConsulta << " ";
    if (medico)
    {
        arquivo << medico->getCodigo() << " " << medico->getNome() << " " << medico->getEspecialidade() << " ";
    }
    else
    {
        arquivo << "-1 Nao Informado Nao Informado ";
    }

    if (paciente)
    {
        arquivo << paciente->getCodigoPaciente() << " " << paciente->getNome() << " " << paciente->getTelefone() << " ";
    }
    else
    {
        arquivo << "-1 Nao Informado 0 ";
    }

    arquivo << dataConsulta.getDia() << " " << dataConsulta.getMes() << " " << dataConsulta.getAno() << " "
            << dataConsulta.getHoras() << " " << dataConsulta.getMinutos() << endl;

    arquivo.close();
}
