#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "/home/julio/Documentos/Trabalho-AEDs/Classes/Menu.hpp"

using namespace std;


void menu()
{
    int escolha;
    bool continuar = true;

    while (continuar)
    {
        cout << "<------------------------------->" << endl;
        cout << "\tMenu Principal" << endl;
        cout << "<------------------------------->" << endl;
        cout << "\t1. Consultas" << endl;
        cout << "\t2. Área de Cadastros" << endl;
        cout << "\t3. Quadro de Horários" << endl;
        cout << "\t0. Sair" << endl;
        cout << "\tEscolha uma opção:\n ";
        cin >> escolha;

        switch (escolha)
        {

        case 1:
            menuConsulta();
            break;
        case 2:
            menuCadastro();
            break;

        case 3:
            menuHorarios();
            break;
        case 0:
            exit(1);
        default:
            cout << "Opção inválida, por favor tente novamente." << endl;

            break;
        }
    }
}


void menuConsulta() {
    int escolha;
    bool marcado = true;
    vector<CONSULTA> consultas;

    while (marcado) {
        cout << "<------------------------------->" << endl;
        cout << "\tMenu Consultas" << endl;
        cout << "<------------------------------->" << endl;
        cout << "1. Marcar Consulta" << endl;
        cout << "2. Cancelar Consulta" << endl;
        cout << "3. Voltar ao Menu Principal" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1: {
                int codigoPaciente, codigoMedico, dia, mes, ano, horas, minutos;

                cout << "Informe o código do paciente: ";
                cin >> codigoPaciente;
                cout << "Informe o código do médico: ";
                cin >> codigoMedico;
                cout << "Informe a data da consulta (dd mm aaaa hh mm): ";
                cin >> dia >> mes >> ano >> horas >> minutos;

                CONSULTA consulta;
                consulta.agendarConsulta(codigoPaciente, codigoMedico, dia, mes, ano, horas, minutos);
                consultas.push_back(consulta);

                break;
            }
            case 2: {
                int codigoConsulta;

                cout << "Informe o código da consulta a cancelar: ";
                cin >> codigoConsulta;

                auto it = find_if(consultas.begin(), consultas.end(), [codigoConsulta](const CONSULTA& consulta) {
                    return consulta.getCodigoConsulta() == codigoConsulta;
                });

                if (it != consultas.end()) {
                    it->cancelarConsulta();
                    consultas.erase(it);
                } else {
                    cout << "Consulta não encontrada." << endl;
                }

                break;
            }
            case 3:
                marcado = false;
                break;
            default:
                cout << "Opção inválida, por favor tente novamente." << endl;
                break;
        }
    }
}
void menuCadastro() {
    vector<PACIENTE> pacientes;
    vector<Medico> medicos;
    bool marcado = true;
while(marcado){
        cout << "<------------------------------->" << endl;
        cout << "\tMenu Cadastro" << endl;
        cout << "<------------------------------->" << endl;
        cout << "1. Cadastrar Paciente" << endl;
        cout << "2. Consultar Cadastro de Paciente" << endl;
        cout << "3. Listar Pacientes" << endl;
        cout << "4. Editar Paciente" << endl;
        cout << "5. Remover Paciente" << endl;
        cout << "6. Cadastrar Médico" << endl;
        cout << "7. Consultar Cadastro de Médico" << endl;
        cout << "8. Listar Médicos" << endl;
        cout << "9. Editar Médico" << endl;
        cout << "10. Remover Médico" << endl;
        cout << "11. Voltar ao Menu Principal" << endl;
        cout << "Escolha uma opção: ";
        int escolha;
        cin >> escolha;

        switch (escolha) {
            case 1: {
                string nome, logradouro, bairro, complemento, cidade, estado;
                long int telefone, cep;
                int numero;
                int dia, mes, ano;

                cout << "Informe o nome do paciente: ";
                cin >> nome;
                cout << "Informe o telefone do paciente: ";
                cin >> telefone;
                cout << "Informe a data de nascimento (dd mm aaaa): ";
                cin >> dia >> mes >> ano;
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

                // Criar um novo objeto de PACIENTE
                PACIENTE novoPaciente(nome, telefone, DATA(dia, mes, ano), logradouro, numero, bairro,
                                      complemento, cep, cidade, estado, pacientes.size() + 1);
                // Adicionar o paciente ao vetor
                pacientes.push_back(novoPaciente);

                cout << "Paciente cadastrado com sucesso!" << endl;
                break;
            }
            case 2: {
                int opcaoBusca;
                cout << "Escolha uma opção de busca:" << endl;
                cout << "1. Buscar por nome" << endl;
                cout << "2. Buscar por código" << endl;
                cin >> opcaoBusca;

                if (opcaoBusca == 1) {
                    string nome;
                    cout << "Informe o nome do paciente: ";
                    cin >> nome;
                    buscarPaciente(pacientes, nome);
                } else if (opcaoBusca == 2) {
                    int codigo;
                    cout << "Informe o código do paciente: ";
                    cin >> codigo;
                    buscarPaciente(pacientes, codigo);
                } else {
                    cout << "Opção inválida." << endl;
                }
                break;
            }
            case 3: {
                listarPacientes(pacientes);
                break;
            }
            case 4: {
                int codigo;
                cout << "Informe o código do paciente que deseja editar: ";
                cin >> codigo;
                editarPaciente(pacientes, codigo);
                break;
            }
            case 5: {
                int codigo;
                cout << "Informe o código do paciente que deseja remover: ";
                cin >> codigo;
                removerPaciente(pacientes, codigo);
                break;
            }
            case 6: {
                string nome, especialidade;

                cout << "Informe o nome do médico: ";
                cin >> nome;
                cout << "Informe a especialidade do médico: ";
                cin >> especialidade;

                // Criar um novo objeto de Medico
                Medico novoMedico(medicos.size() + 1, nome, especialidade);
                // Adicionar o médico ao vetor
                medicos.push_back(novoMedico);

                cout << "Médico cadastrado com sucesso!" << endl;
                break;
            }
            case 7: {
                int opcaoBusca;
                cout << "Escolha uma opção de busca:" << endl;
                cout << "1. Buscar por nome" << endl;
                cout << "2. Buscar por código" << endl;
                cin >> opcaoBusca;

                if (opcaoBusca == 1) {
                    string nome;
                    cout << "Informe o nome do médico: ";
                    cin >> nome;
                    buscarMedico(medicos, nome);
                } else if (opcaoBusca == 2) {
                    int codigo;
                    cout << "Informe o código do médico: ";
                    cin >> codigo;
                    buscarMedico(medicos, codigo);
                } else {
                    cout << "Opção inválida." << endl;
                }
                break;
            }
            case 8: {
                listarMedicos(medicos);
                break;
            }
            case 9: {
                int codigo;
                cout << "Informe o código do médico que deseja editar: ";
                cin >> codigo;
                editarMedico(medicos, codigo);
                break;
            }
            case 10: {
                int codigo;
                cout << "Informe o código do médico que deseja remover: ";
                cin >> codigo;
                removerMedico(medicos, codigo);
                break;
            }
            case 11:
                marcado = false;
                break;
            default:
                cout << "Opção inválida, por favor tente novamente." << endl;
                break;
        }

        // Limpar o buffer de entrada
        limparBuffer();
    }}

void menuHorarios()
{
    Relatorio relatorio; // Instancia um objeto da classe Relatorio para usar seus métodos

    int escolha3;
    bool marcado3 = true;

    while (marcado3)
    {
        cout << "<------------------------------->" << endl;
        cout << "\tMenu Horários" << endl;
        cout << "<------------------------------->" << endl;
        cout << "1. Consultar Consultas do Médico" << endl;
        cout << "2. Consultar Consultas do Paciente" << endl;
        cout << "3. Consultar Consultas do Dia" << endl;
        cout << "4. Voltar ao Menu Principal" << endl;
        cin >> escolha3;

        switch (escolha3)
        {
        case 1:
        {
            string nomeOuCodigoMedico;
            cout << "Informe o nome ou código do médico: ";
            cin >> nomeOuCodigoMedico;
            relatorio.consultasPorMedico(nomeOuCodigoMedico);
            break;
        }
        case 2:
        {
            string nomeOuCodigoPaciente;
            cout << "Informe o nome ou código do paciente: ";
            cin >> nomeOuCodigoPaciente;
            relatorio.consultasPorPaciente(nomeOuCodigoPaciente);
            break;
        }
        case 3:
        {
            int dia, mes, ano;
            cout << "Informe o dia, mês e ano da consulta (DD MM AAAA): ";
            cin >> dia >> mes >> ano;
            DATA dataConsulta(dia, mes, ano, 0, 0); // Considera 00:00 como horário para consulta por dia
            relatorio.consultasPorData(dataConsulta);
            break;
        }
        case 4:
            marcado3 = false;
            break;
        default:
            cout << "Opção inválida, por favor tente novamente." << endl;
            break;
        }
    }
}