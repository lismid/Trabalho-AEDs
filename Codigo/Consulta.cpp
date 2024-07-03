#include "../Classes/Consulta.hpp"
#include <iostream>
#include <fstream>
#include <system_error>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

CONSULTA::CONSULTA() : codigoConsulta(0), medico(nullptr), paciente(nullptr) {}

CONSULTA::CONSULTA(int codigoConsulta, const Medico &medico, const Paciente &paciente, const DATA &dataConsulta)
    : codigoConsulta(codigoConsulta), dataConsulta(dataConsulta)
{
    this->medico = new Medico(medico);
    this->paciente = new Paciente(paciente);
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

CONSULTA CONSULTA::agendarConsulta(int codigoPaciente, int codigoMedico, int dia, int mes, int ano, int horas, int minutos) {
    // Abrir arquivo de consultas em modo de adição
    std::ofstream arquivoConsultas("consultas.txt", std::ios::app);
    if (!arquivoConsultas) {
        std::cerr << "Erro ao abrir o arquivo de consultas." << std::endl;
        return *this;
    }

    // Gerar um código de consulta único
    gerarCodigoConsulta();
    // Preencher os dados do objeto consulta
    codigoPaciente = codigoPaciente;
    codigoMedico = codigoMedico;
    dia = dia;
    mes = mes;
    ano = ano;
    horas = horas;
    minutos = minutos;

    // Escrever os dados da consulta no arquivo
    arquivoConsultas << codigoConsulta << " " << codigoPaciente << " " 
                     << codigoMedico << " " << dia << " " << mes << " " << ano << " "
                     << horas << " " << minutos << std::endl;
    

    // Fechar o arquivo
    arquivoConsultas.close();


    std::cout << "Consulta agendada com sucesso. Código da consulta: " << codigoConsulta << std::endl;
    return *this;
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

void CONSULTA::gerarCodigoConsulta() {
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

void CONSULTA::salvarConsulta() const {
    // Se o medico ou paciente não existirem, salva -1 e informações padrão
    ofstream arquivo("consultas.txt", ios::app);
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo de consultas." << endl;
        return;
    }

    //Salva o código de consulta no arquivo
    arquivo << codigoConsulta << " ";
    if (medico) {
        arquivo << medico->getCodigo() << " " << medico->getNome() << " " << medico->getEspecialidade() << " ";
    } else {
        arquivo << "-1 Nao Informado Nao Informado ";
    }

    // Salva o código do paciente no arquivo
    if (paciente) {
        arquivo << paciente->getCodigoPaciente() << " " << paciente->getNome() << " " << paciente->getTelefone() << " ";
    } else {
        arquivo << "-1 Nao Informado 0 ";
    }

    // Salva a data da consulta no arquivo
    arquivo << dataConsulta.getDia() << " " << dataConsulta.getMes() << " " << dataConsulta.getAno() << " "
            << dataConsulta.getHoras() << " " << dataConsulta.getMinutos() << endl;

    arquivo.close();
}