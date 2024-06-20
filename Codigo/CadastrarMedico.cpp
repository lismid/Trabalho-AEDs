#include "Struct.hpp"

long int gerarCodigoMedico() {
    static long int codigo = 1000;
    return codigo++;
}


int cadastrarMedico(){
    MEDICO medico;

long int codigoM = gerarCodigoMedico();

    printf("Cadastro do medico:\n");
    printf("Seu codigo eh: %ld\n", codigoM);

    printf("Escreva seu nome: \n");
    fgets(medico.nome, 100, stdin);
    getchar();

    printf("Escreva seu telefone (com ddd): \n");
    scanf(" %ld", &medico.telefone);
    getchar();

    printf("Escreva sua especialidade: \n");
    fgets(medico.especialidade, 50, stdin);
    getchar();


}
