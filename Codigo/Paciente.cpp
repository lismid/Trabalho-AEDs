
#include "../Classes/Paciente.hpp"
using namespace std;

// Construtor
PACIENTE::PACIENTE(const string &n, long int tel, const DATA &dataNasc, const string &log, int num,
                   const string &bai, const string &comp, long int cep, const string &cid,
                   const string &est, long int codPaciente)
    : nome(n), telefone(tel), dataNascimento(dataNasc), logradouro(log), numero(num),
      bairro(bai), complemento(comp), CEP(cep), cidade(cid), estado(est), codigoPaciente(codPaciente) {}

// Getters
string PACIENTE::getNome() const {
    return nome;
}

long int PACIENTE::getTelefone() const {
    return telefone;
}

DATA PACIENTE::getDataNascimento() const {
    return dataNascimento;
}

string PACIENTE::getLogradouro() const {
    return logradouro;
}

int PACIENTE::getNumero() const {
    return numero;
}

string PACIENTE::getBairro() const {
    return bairro;
}

string PACIENTE::getComplemento() const {
    return complemento;
}

long int PACIENTE::getCEP() const {
    return CEP;
}

string PACIENTE::getCidade() const {
    return cidade;
}

string PACIENTE::getEstado() const {
    return estado;
}

long int PACIENTE::getCodigoPaciente() const {
    return codigoPaciente;
}

// Setters
void PACIENTE::setNome(const string &n) {
    nome = n;
}

void PACIENTE::setTelefone(long int tel) {
    telefone = tel;
}

void PACIENTE::setDataNascimento(const DATA &dataNasc) {
    dataNascimento = dataNasc;
}

void PACIENTE::setLogradouro(const string &log) {
    logradouro = log;
}

void PACIENTE::setNumero(int num) {
    numero = num;
}

void PACIENTE::setBairro(const string &bai) {
    bairro = bai;
}

void PACIENTE::setComplemento(const string &comp) {
    complemento = comp;
}

void PACIENTE::setCEP(long int cep) {
    CEP = cep;
}

void PACIENTE::setCidade(const string &cid) {
    cidade = cid;
}

void PACIENTE::setEstado(const string &est) {
    estado = est;
}

void PACIENTE::setCodigoPaciente(long int codPaciente) {
    codigoPaciente = codPaciente;
}

// Métodos para manipulação de pacientes
void PACIENTE::cadastrarPaciente() {
    // Implementação do cadastro de paciente
}

void PACIENTE::descadastrarPaciente() {
    // Implementação do descadastro de paciente
}

void PACIENTE::adicionarPaciente(const string &nome, long int telefone, const DATA &dataNasc,
                                 const string &logradouro, int numero, const string &bairro,
                                 const string &complemento, long int cep, const string &cidade,
                                 const string &estado, long int codigoPaciente) {
    // Implementação da adição de paciente
}
