#include "/home/julio/Documentos/Trabalho-AEDs/Classes/Paciente.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void CadastroPessoas::cadastrarPaciente() {
    string nome, logradouro, bairro, complemento, cidade, estado;
    long int telefone, cep, codigoPaciente;
    int numero;
    DATA dataNasc;

    cout << "Informe o nome do paciente: ";
    cin >> nome;
    cout << "Informe o telefone do paciente: ";
    cin >> telefone;
    cout << "Informe a data de nascimento (dia mes ano horas minutos): ";
    cin >> dataNasc;
    cout << "Informe o logradouro: ";
    cin >> logradouro;
    cout << "Informe o número: ";
    cin >> numero;
    cout << "Informe o bairro: ";
    cin >> bairro;
    cout << "Informe o complemento: ";
    cin >> complemento;
    cout << "Informe o CEP: ";
    cin >> cep;
    cout << "Informe a cidade: ";
    cin >> cidade;
    cout << "Informe o estado: ";
    cin >> estado;
    cout << "Informe o código do paciente: ";
    cin >> codigoPaciente;

    // Verificar se já existe paciente com o mesmo código
    if (encontrarPacientePorCodigo(codigoPaciente) != nullptr) {
        cout << "Erro: Já existe um paciente cadastrado com o código " << codigoPaciente << endl;
        return;
    }

    PACIENTE novoPaciente(nome, telefone, dataNasc, logradouro, numero, bairro, complemento, cep, cidade, estado, codigoPaciente);
    adicionarPaciente(novoPaciente);

    ofstream arquivoPacientes("pacientes.txt", ios::app);
    if (!arquivoPacientes.is_open()) {
        cerr << "Erro ao abrir o arquivo de pacientes." << endl;
        return;
    }

    arquivoPacientes << codigoPaciente << " " << nome << " " << telefone << " " << dataNasc.getverdata() << " "
                     << logradouro << " " << numero << " " << bairro << " " << complemento << " "
                     << cep << " " << cidade << " " << estado << endl;

    arquivoPacientes.close();

    cout << "Paciente cadastrado com sucesso!" << endl;
}
