#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include "Medico.hpp"
#include "Paciente.hpp"
#include "Data.hpp"
#include <vector>
#pragma once
class CONSULTA {
private:
    int codigoConsulta;
    DATA dataConsulta;
    Medico *medico;
    PACIENTE *paciente;

public:
    CONSULTA();
    CONSULTA(int codigoConsulta, const Medico& medico, const PACIENTE& paciente, const DATA& dataConsulta);
    ~CONSULTA();
    
    void agendarConsulta(int codigoPaciente, int codigoMedico, int dia, int mes, int ano, int horas, int minutos);
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
