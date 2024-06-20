#ifndef Paciente_h
#define Paciente_h
#include "Data.hpp"


class PACIENTE{
    private:
    char nome[100];
    long int telefone;
    DATA dataNASCIMENTO;
    char logradouro[100];
    int numero;
    char bairro[50];
    char complemento[50];
    long int CEP;
    char cidade[50];
    char estado[3];
    long int codigoPACIENTE;
    public:
    float cadatrapaciente();
    float descadastrapaciente();
     
} ;
#endif