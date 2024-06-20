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

long int gerarCodigoPaciente() {
    static long int codigo = 100;
    return codigo++;
}

void cadastrarPaciente() {
    PACIENTE paciente;
    paciente.codigoPACIENTE = gerarCodigoPaciente();

    printf("Escreva o seu Nome completo: ");
    fgets(paciente.nome, sizeof(paciente.nome), stdin);
    
    printf("Escreva o seu Endereco: \n");
    printf("Escreva o seu Logradouro: ");
    fgets(paciente.endereco.logradouro, sizeof(paciente.endereco.logradouro), stdin);
    printf("Escreva o seu Numero: ");
    scanf("%d", & paciente.endereco.numero);
    getchar();
    printf("Escreva o seu Bairro: ");
    fgets(paciente.endereco.bairro, sizeof(paciente.endereco.bairro), stdin);
    printf("Escreva o seu Complemento (se nao tiver de enter): ");
    fgets(paciente.endereco.complemento, sizeof(paciente.endereco.complemento), stdin);
    printf("Escreva o seu CEP: ");
    scanf("%ld", & paciente.endereco.CEP);
    getchar();
    printf("Escreva a sua Cidade: ");
    fgets(paciente.endereco.cidade, sizeof(paciente.endereco.cidade), stdin);
    printf("Escreva o seu Estado (em sigla): ");
    fgets(paciente.endereco.estado, sizeof(paciente.endereco.estado), stdin);

    printf("Escreva o seu Telefone com DDD: ");
    scanf("%ld", & paciente.telefone);
    getchar();

    printf("Escreva a sua Data de Nascimento:\n");
    printf("Escreva o Dia: ");
    scanf("%d", & paciente.dataNASCIMENTO.dia);
    getchar();
    printf("Escreva o Mes: ");
    scanf("%d", & paciente.dataNASCIMENTO.mes);
    getchar();
    printf("Escreva o Ano: ");
    scanf("%d", & paciente.dataNASCIMENTO.ano);
    getchar();

    printf("Seu codigo de paciente e: %ld\n", paciente.codigoPACIENTE);
}