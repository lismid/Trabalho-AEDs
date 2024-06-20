#include "Struct.hpp"


void cadastrarConsulta(){
    CONSULTA consulta;
    
    consulta.codigoCONSULTA = gerarCodigoConsulta();
    
    printf("Escreva o código do médico: ");
    scanf("%li", & consulta.codigoMEDICO);
    printf("Escreva o código do paciente: ");
    scanf("%li", & consulta.codigoPACIENTE);
    
    printf("Escreva a hora: ");
    scanf("%d", & consulta.hora.horas);
    printf("Escreva os minutos: ");
    scanf("%d", & consulta.hora.minutos);
    
    printf("Escreva o dia: ");
    scanf("%d", & consulta.dataCONSULTA.dia);
    printf("Escreva o mês: ");
    scanf("%d", & consulta.dataCONSULTA.mes);
    printf("Escreva o ano: ");
    scanf("%li", & consulta.dataCONSULTA.ano);
    
    printf("Seu código da sua consulta é: %li\n", consulta.codigoCONSULTA);
}

