#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include "Consulta.hpp"
#include "Medico.hpp"
#include "Paciente.hpp"
#include "Data.hpp"
#include <vector>
#include <string>
#pragma once
using namespace std;


class Relatorio {
public:
    Relatorio();
    ~Relatorio();

    void consultasPorData(const DATA& data) const;
    void consultasPorPaciente(const string& nomeOuCodigoPaciente) const;
    void consultasPorMedico(const string& nomeOuCodigoMedico) const;

private:
    vector<CONSULTA> lerConsultas() const;
    vector<Medico> lerMedicos() const;
    vector<PACIENTE> lerPacientes() const;
};

#endif // RELATORIO_HPP
