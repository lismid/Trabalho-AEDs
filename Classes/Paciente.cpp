#include "Paciente.hpp"
#include <iostream>

// Construtor padrão
PACIENTE::PACIENTE() : telefone(0), numero(0), CEP(0), codigoPACIENTE(0) {};

// Construtor parametrizado
PACIENTE::PACIENTE(const std::string &n, long int tel, const DATA &dataNasc, const std::string &log, int num, const std::string &bai, const std::string & comp, long int cep, const std::string &cid, const std::string &est, long int codPaciente)
    : nome(n), telefone(tel), dataNASCIMENTO(dataNasc), logradouro(log), numero(num), bairro(bai), complemento(comp ), CEP(cep), cidade(cid), estado(est), codigoPACIENTE(codPaciente) {}

// Getters
std::string PACIENTE::getNome() const { return nome; }
long int PACIENTE::getTelefone() const { return telefone; }
DATA PACIENTE::getDataNascimento() const { return dataNASCIMENTO; }
std::string PACIENTE::getLogradouro() const { return logradouro; }
int PACIENTE::getNumero() const { return numero; }
std::string PACIENTE::getBairro() const { return bairro; }
std::string PACIENTE::getComplemento() const { return complemento; }
long int PACIENTE::getCEP() const { return CEP; }
std::string PACIENTE::getCidade() const { return cidade; }
std::string PACIENTE::getEstado() const { return estado; }
long int PACIENTE::getCodigoPaciente() const { return codigoPACIENTE; }

// Setters
void PACIENTE::setNome(const std::string &n) { nome = n; }
void PACIENTE::setTelefone(long int tel) { telefone = tel; }
void PACIENTE::setDataNascimento(const DATA &dataNasc) { dataNASCIMENTO = dataNasc; }
void PACIENTE::setLogradouro(const std::string &log) { logradouro = log; }
void PACIENTE::setNumero(int num) { numero = num; }
void PACIENTE::setBairro(const std::string &bai) { bairro = bai; }
void PACIENTE::setComplemento(const std::string & comp ) { complemento = comp ; }
void PACIENTE::setCEP(long int cep) { CEP = cep; }
void PACIENTE::setCidade(const std::string &cid) { cidade = cid; }
void PACIENTE::setEstado(const std::string &est) { estado = est; }
void PACIENTE::setCodigoPaciente(long int codPaciente) { codigoPACIENTE = codPaciente; }

// Métodos para cadastrar e descadastrar paciente
void PACIENTE::cadastrarPaciente()
{
    std::cout << "Cadastrando paciente..." << std::endl;
    // Lógica de cadastro
}

void PACIENTE::descadastrarPaciente()
{
    std::cout << "Descadastrando paciente..." << std::endl;
    // Lógica de descadastro
}
