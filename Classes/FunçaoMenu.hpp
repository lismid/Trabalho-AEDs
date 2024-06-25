#include "Paciente.hpp"
#include "Medico.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip> // Para manipulação de formatação de texto
#include <limits>  // Para limpar o buffer de entrada

using namespace std;

// Função para listar todos os pacientes
void listarPacientes(const vector<PACIENTE>& pacientes) {
    cout << "<------------------------------->" << endl;
    cout << "\tLista de Pacientes" << endl;
    cout << "<------------------------------->" << endl;

    if (pacientes.empty()) {
        cout << "Nenhum paciente cadastrado." << endl;
    } else {
        for (const auto& paciente : pacientes) {
            cout << "Código: " << paciente.getCodigoPaciente() << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "Telefone: " << paciente.getTelefone() << endl;
            cout << "Endereço: " << paciente.getLogradouro() << ", " << paciente.getNumero() << endl;
            cout << "Bairro: " << paciente.getBairro() << endl;
            cout << "CEP: " << paciente.getCEP() << endl;
            cout << "Cidade/Estado: " << paciente.getCidade() << " - " << paciente.getEstado() << endl;
            cout << "Data de Nascimento: " << paciente.getDataNascimento().getDia() << "/"
                 << paciente.getDataNascimento().getMes() << "/"
                 << paciente.getDataNascimento().getAno() << endl;
            cout << "<------------------------------->" << endl;
        }
    }
}

// Função para listar todos os médicos
void listarMedicos(const vector<Medico>& medicos) {
    cout << "<------------------------------->" << endl;
    cout << "\tLista de Médicos" << endl;
    cout << "<------------------------------->" << endl;

    if (medicos.empty()) {
        cout << "Nenhum médico cadastrado." << endl;
    } else {
        for (const auto& medico : medicos) {
            cout << "Código: " << medico.getCodigo() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            cout << "<------------------------------->" << endl;
        }
    }
}

// Função para buscar paciente por nome
void buscarPaciente(const vector<PACIENTE>& pacientes, const string& nome) {
    bool encontrado = false;
    for (const auto& paciente : pacientes) {
        if (paciente.getNome() == nome) {
            cout << "Paciente encontrado:" << endl;
            cout << "Código: " << paciente.getCodigoPaciente() << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "Telefone: " << paciente.getTelefone() << endl;
            cout << "Endereço: " << paciente.getLogradouro() << ", " << paciente.getNumero() << endl;
            cout << "Bairro: " << paciente.getBairro() << endl;
            cout << "CEP: " << paciente.getCEP() << endl;
            cout << "Cidade/Estado: " << paciente.getCidade() << " - " << paciente.getEstado() << endl;
            cout << "Data de Nascimento: " << paciente.getDataNascimento().getDia() << "/"
                 << paciente.getDataNascimento().getMes() << "/"
                 << paciente.getDataNascimento().getAno() << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Paciente não encontrado." << endl;
    }
}

// Função para buscar paciente por código
void buscarPaciente(const vector<PACIENTE>& pacientes, int codigo) {
    bool encontrado = false;
    for (const auto& paciente : pacientes) {
        if (paciente.getCodigoPaciente() == codigo) {
            cout << "Paciente encontrado:" << endl;
            cout << "Código: " << paciente.getCodigoPaciente() << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "Telefone: " << paciente.getTelefone() << endl;
            cout << "Endereço: " << paciente.getLogradouro() << ", " << paciente.getNumero() << endl;
            cout << "Bairro: " << paciente.getBairro() << endl;
            cout << "CEP: " << paciente.getCEP() << endl;
            cout << "Cidade/Estado: " << paciente.getCidade() << " - " << paciente.getEstado() << endl;
            cout << "Data de Nascimento: " << paciente.getDataNascimento().getDia() << "/"
                 << paciente.getDataNascimento().getMes() << "/"
                 << paciente.getDataNascimento().getAno() << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Paciente não encontrado." << endl;
    }
}

// Função para buscar médico por nome
void buscarMedico(const vector<Medico>& medicos, const string& nome) {
    bool encontrado = false;
    for (const auto& medico : medicos) {
        if (medico.getNome() == nome) {
            cout << "Médico encontrado:" << endl;
            cout << "Código: " << medico.getCodigo() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Médico não encontrado." << endl;
    }
}

// Função para buscar médico por código
void buscarMedico(const vector<Medico>& medicos, int codigo) {
    bool encontrado = false;
    for (const auto& medico : medicos) {
        if (medico.getCodigo() == codigo) {
            cout << "Médico encontrado:" << endl;
            cout << "Código: " << medico.getCodigo() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Médico não encontrado." << endl;
    }
}

// Função para editar paciente por código
void editarPaciente(vector<PACIENTE>& pacientes, int codigo) {
    bool encontrado = false;
    for (auto& paciente : pacientes) {
        if (paciente.getCodigoPaciente() == codigo) {
            string nome, logradouro, bairro, complemento, cidade, estado;
            long int telefone, cep;
            int numero;
            int dia, mes, ano;

            cout << "Informe o novo nome do paciente: ";
            cin >> nome;
            cout << "Informe o novo telefone do paciente: ";
            cin >> telefone;
            cout << "Informe a nova data de nascimento (dd mm aaaa): ";
            cin >> dia >> mes >> ano;
            cout << "Informe o novo logradouro: ";
            cin >> logradouro;
            cout << "Informe o novo número: ";
            cin >> numero;
            cout << "Informe o novo bairro: ";
            cin >> bairro;
            cout << "Informe o novo complemento: ";
            cin >> complemento;
            cout << "Informe o novo CEP: ";
            cin >> cep;
            cout << "Informe a nova cidade: ";
            cin >> cidade;
            cout << "Informe o novo estado: ";
            cin >> estado;

            paciente.setNome(nome);
            paciente.setTelefone(telefone);
            paciente.setDataNascimento(DATA(dia, mes, ano));
            paciente.setLogradouro(logradouro);
            paciente.setNumero(numero);
            paciente.setBairro(bairro);
            paciente.setComplemento(complemento);
            paciente.setCEP(cep);
            paciente.setCidade(cidade);
            paciente.setEstado(estado);

            encontrado = true;
            cout << "Paciente atualizado com sucesso!" << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "Paciente não encontrado." << endl;
    }
}

// Função para editar médico por código
void editarMedico(vector<Medico>& medicos, int codigo) {
    bool encontrado = false;
    for (auto& medico : medicos) {
        if (medico.getCodigo() == codigo) {
            string nome, especialidade;

            cout << "Informe o novo nome do médico: ";
            cin >> nome;
            cout << "Informe a nova especialidade do médico: ";
            cin >> especialidade;

            medico.setNome(nome);
            medico.setEspecialidade(especialidade);

            encontrado = true;
            cout << "Médico atualizado com sucesso!" << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "Médico não encontrado." << endl;
    }
}

// Função para remover paciente por código
void removerPaciente(vector<PACIENTE>& pacientes, int codigo) {
    auto it = pacientes.begin();
    while (it != pacientes.end()) {
        if (it->getCodigoPaciente() == codigo) {
            it = pacientes.erase(it);
            cout << "Paciente removido com sucesso!" << endl;
            return;
        } else {
            ++it;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

// Função para remover médico por código
void removerMedico(vector<Medico>& medicos, int codigo) {
    auto it = medicos.begin();
    while (it != medicos.end()) {
        if (it->getCodigo() == codigo) {
            it = medicos.erase(it);
            cout << "Médico removido com sucesso!" << endl;
            return;
        } else {
            ++it;
        }
    }
    cout << "Médico não encontrado." << endl;
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Função principal do menu de cadastro
void menuCadastro() {
    vector<PACIENTE> pacientes;
    vector<Medico> medicos;
    bool marcado = true;

