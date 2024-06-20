#ifndef Consulta_h
#define Consulta_h
#include "Data.hpp"
#include "Medico.hpp"
#include "Paciente.hpp"

class CONSULTA{
    private:
    float codigoCONSULTA;
    DATA dataCONSULTA;
    MEDICO codigodomedico;
    PACIENTE codigoPACIENTE;
    public:
    float agendaconsulta();
    int getcodigomedico() const;
    int getcodigopaciente()const;
    float cancelarconsulta();


} ;
#endif