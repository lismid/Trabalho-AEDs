#ifndef CONSULTA_HPP
#define CONSULTA_HPP
#pragma once

#include "Medico.hpp"
#include "Paciente.hpp"
#include "Data.hpp"
#include <vector>

class CONSULTA {
private:
    int codigoConsulta;
    DATA dataConsulta;
    Medico *medico;
    Paciente *paciente;

public:
    CONSULTA();
    CONSULTA(int codigoConsulta, const Medico& medico, const Paciente& paciente, const DATA& dataConsulta);
    ~CONSULTA();
    
    CONSULTA agendarConsulta(int codigoPaciente, int codigoMedico, int dia, int mes, int ano, int horas, int minutos);
    int getCodigoMedico() const;
    int getCodigoPaciente() const;
    int getCodigoConsulta() const;
    DATA getDataConsulta() const;
    void cancelarConsulta();
    void gerarCodigoConsulta();
    static bool podeAtenderMaisUmaConsulta(const std::vector<CONSULTA>& consultas, int codigoMedico, const DATA& data);
    void salvarConsulta() const;
};

#endif 
