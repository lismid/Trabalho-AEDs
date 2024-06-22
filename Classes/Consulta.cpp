#include "Consulta.hpp"
#include <iostream>
#include <vector>

CONSULTA::CONSULTA() : codigoCONSULTA(0), codigodomedico(), codigoPACIENTE(), dataCONSULTA(0,0,0,0,0){}
CONSULTA::~CONSULTA() {}

void CONSULTA::setagendaconsulta(int codigoPaciente, int codigoMedico, const DATA& data)
{
    if (!podeAtenderMaisUmaConsulta(consultas,codigoMedico))
    {
        /* code */
    }
    
}