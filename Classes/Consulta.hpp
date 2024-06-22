#ifndef Consulta_h
#define Consulta_h
#include <vector>
#include "Data.hpp"
#include "Medico.hpp"
#include "Paciente.hpp"

class CONSULTA
{
private:
    float codigoCONSULTA;
    DATA dataCONSULTA;
    MEDICO codigodomedico;
    PACIENTE codigoPACIENTE;

public:
    CONSULTA();
    ~CONSULTA();
    void setagendaconsulta(int codigoPaciente, int codigoMedico, const DATA& data);
    int getcodigomedico() const;
    int getcodigopaciente() const;
    void setcancelarconsulta();
    void setgeracodigoconsulta();
    static bool podeAtenderMaisUmaConsulta(const std::vector<CONSULTA>& consultas, int codigoMedico, const DATA& data);
};
#endif