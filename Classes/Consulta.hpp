#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include "Medico.hpp"
#include "Paciente.hpp"
#include "Data.hpp" // Assumindo que a classe DATA está definida aqui

class CONSULTA {
private:
    int codigoConsulta;
    DATA dataConsulta;
    Medico* medico;
    PACIENTE* paciente;

public:
    CONSULTA();
    ~CONSULTA();

    void agendarConsulta(int codigoPaciente, int codigoMedico, int dia, int mes, int ano, int horas, int minutos);
    int getCodigoMedico() const;
    int getCodigoPaciente() const;
    void cancelarConsulta();
    void gerarCodigoConsulta();
    static bool podeAtenderMaisUmaConsulta(const std::vector<CONSULTA>& consultas, int codigoMedico, const DATA& data);
};

#endif // CONSULTA_HPP
