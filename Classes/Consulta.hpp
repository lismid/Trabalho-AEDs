#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include <vector>
#include "Data.hpp"
#include "Medico.hpp"
#include "Paciente.hpp"

class CONSULTA{
private:
    int codigoConsulta;
    DATA dataConsulta;
    Medico* medico;
    PACIENTE* paciente;

public:
    CONSULTA();
    ~CONSULTA()= default;

    void agendarConsulta(int codigoPaciente, int codigoMedico, const DATA& data);
    int getCodigoMedico() const;
    int getCodigoPaciente() const;
    void cancelarConsulta();
    void gerarCodigoConsulta();
    static bool podeAtenderMaisUmaConsulta(const std::vector<CONSULTA>& consultas, int codigoMedico, const DATA& data);
};

#endif 
