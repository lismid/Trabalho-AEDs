#include <stdio.h>
#include <stdlib.h>

//Structs: 
//////////

typedef struct {
    int dia;
    int mes;
    long int ano;
} DATA;

typedef struct {
    int horas;
    int minutos;
} HORARIO;

typedef struct {
    char logradouro[100];
    int numero;
    char bairro[50];
    char complemento[50];
    long int CEP;
    char cidade[50];
    char estado[3];
} ENDERECO;

typedef struct {
    long int codigoPACIENTE;
    char nome[100];
    ENDERECO endereco;
    long int telefone;
    DATA dataNASCIMENTO;
} PACIENTE;

typedef struct {
    long int codigoMEDICO;
    char nome[100];
    long int telefone;
    char especialidade[50];
} MEDICO;

typedef struct {
    long int codigoCONSULTA;
    DATA dataCONSULTA;
    HORARIO hora;
    long int codigoMEDICO;
    long int codigoPACIENTE;
} CONSULTA;

//Função de cadastro do paciente:
/////////////////////////////////

long int gerarCodigoPaciente() {
    static long int codigo = 100;
    return codigo++;
}

void cadastrarPaciente() {
    PACIENTE paciente;
    paciente.codigoPACIENTE = gerarCodigoPaciente();

    printf("Complete as seguintes informacoes pessoais para prosseguir:\n");
    printf("Nome completo: ");
    fgets(paciente.nome, sizeof(paciente.nome), stdin);
    
    printf("Endereco: \n");
    printf("Logradouro: ");
    fgets(paciente.endereco.logradouro, sizeof(paciente.endereco.logradouro), stdin);
    printf("Numero: ");
    scanf("%d", & paciente.endereco.numero);
    getchar();
    printf("Bairro: ");
    fgets(paciente.endereco.bairro, sizeof(paciente.endereco.bairro), stdin);
    printf("Complemento (caso nao houver, de enter): ");
    fgets(paciente.endereco.complemento, sizeof(paciente.endereco.complemento), stdin);
    printf("CEP: ");
    scanf("%ld", & paciente.endereco.CEP);
    getchar();
    printf("Cidade: ");
    fgets(paciente.endereco.cidade, sizeof(paciente.endereco.cidade), stdin);
    printf("Estado (em sigla): ");
    fgets(paciente.endereco.estado, sizeof(paciente.endereco.estado), stdin);

    printf("Telefone (com DDD): ");
    scanf("%ld", & paciente.telefone);
    getchar();

    printf("Data de Nascimento:\n");
    printf("Dia: ");
    scanf("%d", & paciente.dataNASCIMENTO.dia);
    getchar();
    printf("Mes: ");
    scanf("%d", & paciente.dataNASCIMENTO.mes);
    getchar();
    printf("Ano: ");
    scanf("%ld", & paciente.dataNASCIMENTO.ano);
    getchar();

    printf("Seu codigo de paciente e: %ld\n", paciente.codigoPACIENTE);
}

//Função de cadastro do médico:
///////////////////////////////

long int gerarCodigoMedico() {
    static long int codigo = 1000;
    return codigo++;
}


int cadastrarMedico(){
    MEDICO medico;

long int codigoM = gerarCodigoMedico();

    printf("Complete as seguintes informacoes pessoais para prosseguir:\n");
    printf("Nome: \n");
    fgets(medico.nome, 100, stdin);
    getchar();

    printf("Telefone (com ddd): \n");
    scanf(" %ld", &medico.telefone);
    getchar();

    printf("Especialidade: \n");
    fgets(medico.especialidade, 50, stdin);
    getchar();

    printf("Seu codigo de medico e: %ld\n", codigoM);

    return 0;

}

//Função de cadastro da consulta:
/////////////////////////////////

long int gerarCodigoConsulta() {
    static long int codigo = 9000;
    return codigo++;
}

void cadastrarConsulta(){
    CONSULTA consulta;
    
    consulta.codigoCONSULTA = gerarCodigoConsulta();
    
    printf("Para cadastrar a consulta, preencha as informacoes abaixo:\n");
    printf("Codigo do medico: ");
    scanf("%li", & consulta.codigoMEDICO);
    printf("Codigo do paciente: ");
    scanf("%li", & consulta.codigoPACIENTE);
    
    printf("Hora da consulta: ");
    scanf("%d", & consulta.hora.horas);
    printf("Minutos da consulta: ");
    scanf("%d", & consulta.hora.minutos);
    
    printf("Dia da consulta: ");
    scanf("%d", & consulta.dataCONSULTA.dia);
    printf("Mes da consulta: ");
    scanf("%d", & consulta.dataCONSULTA.mes);
    printf("Ano da consulta: ");
    scanf("%li", & consulta.dataCONSULTA.ano);
    
    printf("\nCodigo da consulta: %li\n", consulta.codigoCONSULTA);
}

//Função main:
//////////////

int main(){

    //Print do cadastro do paciente:
    cadastrarPaciente();
    printf("\n");

    //Print do cadastro do médico:
    cadastrarMedico();
    printf("\n");

    //Print do cadastro da consulta:
    cadastrarConsulta();
    printf("\n");
    cadastrarConsulta();

    return 0;
}