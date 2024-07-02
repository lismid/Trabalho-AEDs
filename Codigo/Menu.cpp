#include <string>
//#include <iomanip>
#include <limits>
//#include <fstream>
//#include <sstream>
#include <algorithm>
#include "../Classes/Relatorio.hpp"
#include "../Classes/Menu.hpp"
#include "../Classes/Paciente.hpp"
#include "../Classes/Medico.hpp"
#include "../Classes/Data.hpp"
using namespace std;

void listarPacientes(vector<PACIENTE> pacientes) {
    cout << "<------------------------------->" << endl;
    cout << "\tLista de Pacientes" << endl;
    cout << "<------------------------------->" << endl;

    if (pacientes.empty()) {
        cout << "Nenhum paciente cadastrado." << endl;
    } else {
        for (const auto &paciente : pacientes) {
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
void listarMedicos(const vector<Medico> &medicos) {
    cout << "<------------------------------->" << endl;
    cout << "\tLista de Médicos" << endl;
    cout << "<------------------------------->" << endl;

    if (medicos.empty())
    {
        cout << "Nenhum médico cadastrado." << endl;
    }
    else
    {
        for (const auto &medico : medicos)
        {
            cout << "Código: " << medico.getCodigo() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            cout << "<------------------------------->" << endl;
        }
    }
}

// Função para buscar paciente por nome
void buscarPacientenome(const vector<PACIENTE> &pacientes, const string &nome)
{
    bool encontrado = false;
    for (const auto &paciente : pacientes)
    {
        if (paciente.getNome() == nome)
        {
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
    if (!encontrado)
    {
        cout << "Paciente não encontrado." << endl;
    }
}

// Função para buscar paciente por código
void buscarPacientecodigo(const vector<PACIENTE> &pacientes, int codigo) {
    bool encontrado = false;
    for (const auto &paciente : pacientes)
    {
        if (paciente.getCodigoPaciente() == codigo)
        {
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
    if (!encontrado)
    {
        cout << "Paciente não encontrado." << endl;
    }
}

// Função para buscar médico por nome
void buscarMediconome(const vector<Medico> &medicos, const string &nome)
{
    bool encontrado = false;
    for (const auto &medico : medicos)
    {
        if (medico.getNome() == nome)
        {
            cout << "Médico encontrado:" << endl;
            cout << "Código: " << medico.getCodigo() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        cout << "Médico não encontrado." << endl;
    }
}

// Função para buscar médico por código
void buscarMedicocodigo(const vector<Medico> &medicos, int codigo)
{
    bool encontrado = false;
    for (const auto &medico : medicos)
    {
        if (medico.getCodigo() == codigo)
        {
            cout << "Médico encontrado:" << endl;
            cout << "Código: " << medico.getCodigo() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        cout << "Médico não encontrado." << endl;
    }
}

// Função para editar paciente por código
void editarPaciente(vector<PACIENTE> &pacientes, int codigo)
{
    bool encontrado = false;
    for (auto &paciente : pacientes)
    {
        if (paciente.getCodigoPaciente() == codigo)
        {
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
    if (!encontrado)
    {
        cout << "Paciente não encontrado." << endl;
    }
}

void editarMedico(vector<Medico> &medicos, int codigo)
{
    bool encontrado = false;
    for (auto &medico : medicos)
    {
        if (medico.getCodigo() == codigo)
        {
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
    if (!encontrado)
    {
        cout << "Médico não encontrado." << endl;
    }
}

// Função para remover paciente por código
void removerPaciente(vector<PACIENTE> &pacientes, int codigo)
{
    auto it = pacientes.begin();
    while (it != pacientes.end())
    {
        if (it->getCodigoPaciente() == codigo)
        {
            it = pacientes.erase(it);
            cout << "Paciente removido com sucesso!" << endl;
            return;
        }
        else
        {
            ++it;
        }
    }
    cout << "Paciente não encontrado." << endl;
}

// Função para remover médico por código
void removerMedico(vector<Medico> &medicos, int codigo)
{
    auto it = medicos.begin();
    while (it != medicos.end())
    {
        if (it->getCodigo() == codigo)
        {
            it = medicos.erase(it);
            cout << "Médico removido com sucesso!" << endl;
            return;
        }
        else
        {
            ++it;
        }
    }
    cout << "Médico não encontrado." << endl;
}

// Função para limpar o buffer de entrada
void limparBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void menu() {
    int escolha, retorno;
    bool continuar = true;

    while (continuar) {
        cout << "<------------------------------->" << endl;
        cout << "\tMenu Principal" << endl;
        cout << "<------------------------------->" << endl;
        cout << "\t1. Consultas" << endl;
        cout << "\t2. Area de Cadastros" << endl;
        cout << "\t3. Quadro de Horarios" << endl;
        cout << "\t0. Sair" << endl;
        cout << "\tEscolha uma opcao:\n ";
        cin >> escolha;

        switch (escolha)
        {
            case 0:
                continuar = false;
                break;
            case 1:
                menuConsulta();
                break;
            case 2:
                retorno = menuCadastro();
                if (retorno == 0) 
                    continuar = false;
                break;
            case 3:
                menuHorarios();
                break;
            default:
                cout << "Opção inválida, por favor tente novamente." << endl;
                break;
        }
    }
}

DATA date;
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
            case 1:
            { 
                int codigoPaciente, codigoMedico, diaConsulta, mesConsulta, anoConsulta, horasConsulta, minutosConsulta;
                cout << "Informe o código do paciente: ";
                cin >> codigoPaciente;

                cout << "Informe o código do médico: ";
                cin >> codigoMedico;

                string dataInput;
                do {
                    cout << "Informe a data da consulta (dd/mm/aaaa): ";
                    cin >> dataInput;

                    // Analisar a entrada para extrair dia, mês e ano
                    if (sscanf(dataInput.c_str(), "%d/%d/%d", &diaConsulta, &mesConsulta, &anoConsulta) != 3) {
                        cout << "Formato inválido. Use dd/mm/aaaa." << endl;
                        continue;
                    }

                    // Validar a data usando os métodos da classe DATA
                    if (!date.validarData(diaConsulta, mesConsulta, anoConsulta)) {
                        cout << "Data inválida. Por favor, informe uma data válida." << endl;
                        continue;
                    }

                    // Se chegou aqui, a data está válida
                    break;

                } while (true);

                string horaInput;
                do {
                    cout << "Informe a hora da consulta (hh:mm): ";
                    cin >> horaInput;

                    // Analisar a entrada para extrair horas e minutos
                    if (sscanf(horaInput.c_str(), "%d:%d", &horasConsulta, &minutosConsulta) != 2) {
                        cout << "Formato inválido. Use hh:mm." << endl;
                        continue;
                    }

                    // Validar a hora usando os métodos da classe DATA
                    if (!date.validarHora(horasConsulta, minutosConsulta)) {
                        cout << "Hora inválida. Por favor, informe uma hora válida." << endl;
                        continue;
                    }

                    // Se chegou aqui, a hora está válida
                    break;

                } while (true);

                // Criar e adicionar a consulta ao vetor de consultas
                CONSULTA consulta;
                //agendarConsulta() está causando um loop infinito
                //consulta.agendarConsulta(codigoPaciente, codigoMedico, diaConsulta, mesConsulta, anoConsulta, horasConsulta, minutosConsulta);
                consultas.push_back(consulta);

                marcado = false;
                break;
            }
            case 2:
            {
                int codigoConsulta;

                cout << "Informe o código da consulta a cancelar: ";
                cin >> codigoConsulta;

                auto it = find_if(consultas.begin(), consultas.end(), [codigoConsulta](const CONSULTA &consulta)
                                { return consulta.getCodigoConsulta() == codigoConsulta; });

                if (it != consultas.end())
                {
                    it->cancelarConsulta();
                    consultas.erase(it);
                }
                else
                {
                    cout << "Consulta não encontrada." << endl;
                }
                marcado = false;
                break;
            }
            case 3:
                marcado = false;
                break;
            default:
                cout << "Opção inválida, por favor tente novamente." << endl;
                break;
        }
        break;
    }
}

int menuCadastro()
{
    vector<PACIENTE> pacientes;
    vector<Medico> medicos;
    bool marcado = true;
    while (marcado)
    {
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

        switch (escolha)
        {
        case 1:
        {
            string nome, logradouro, bairro, complemento, cidade, estado;
            long int telefone, cep;
            int numero;
            int dia, mes, ano;

            cout << "Informe o nome do paciente: ";
            limparBuffer(); // Limpar o buffer antes de getline
            getline(cin, nome);

            cout << "Informe o telefone do paciente: ";
            cin >> telefone;

            cout << "Informe a data de nascimento (dd mm aaaa): ";
            cin >> dia >> mes >> ano;

            limparBuffer(); // Limpar o buffer antes de getline
            cout << "Informe o logradouro: ";
            getline(cin, logradouro);

            cout << "Informe o número: ";
            cin >> numero;

            limparBuffer(); // Limpar o buffer antes de getline
            cout << "Informe o bairro: ";
            getline(cin, bairro);

            cout << "Informe o complemento: ";
            getline(cin, complemento);

            cout << "Informe o CEP: ";
            cin >> cep;

            limparBuffer(); // Limpar o buffer antes de getline
            cout << "Informe a cidade: ";
            getline(cin, cidade);

            cout << "Informe o estado: ";
            getline(cin, estado);

            // Criar um novo objeto de PACIENTE
            PACIENTE novoPaciente(nome, telefone, DATA(dia, mes, ano), logradouro, numero, bairro,
                                  complemento, cep, cidade, estado, pacientes.size() + 1);
            // Adicionar o paciente ao vetor
            pacientes.push_back(novoPaciente);

            cout << "Paciente cadastrado com sucesso!" << endl;
            cout << "Código do paciente: " << novoPaciente.getCodigoPaciente() << endl;
            break;
        }
        case 2:
        {
            int opcaoBusca;
            cout << "Escolha uma opção de busca:" << endl;
            cout << "1. Buscar por nome" << endl;
            cout << "2. Buscar por código" << endl;
            cin >> opcaoBusca;

            if (opcaoBusca == 1)
            {
                string nome;
                cout << "Informe o nome do paciente: ";
                cin >> nome;
                buscarPacientenome(pacientes, nome);
            }
            else if (opcaoBusca == 2)
            {
                int codigo;
                cout << "Informe o código do paciente: ";
                cin >> codigo;
                buscarPacientecodigo(pacientes, codigo);
            }
            else
            {
                cout << "Opção inválida." << endl;
            }
            break;
        }
        case 3:
        {
            listarPacientes(pacientes);
            break;
        }
        case 4:
        {
            int codigo;
            cout << "Informe o código do paciente que deseja editar: ";
            cin >> codigo;
            editarPaciente(pacientes, codigo);
            break;
        }
        case 5:
        {
            int codigo;
            cout << "Informe o código do paciente que deseja remover: ";
            cin >> codigo;
            removerPaciente(pacientes, codigo);
            break;
        }
        case 6:
        {
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
            cout << "Código do medico: " << novoMedico.getCodigo() << endl;
            break;
        }
        case 7:
        {
            int opcaoBusca;
            cout << "Escolha uma opção de busca:" << endl;
            cout << "1. Buscar por nome" << endl;
            cout << "2. Buscar por código" << endl;
            cin >> opcaoBusca;

            if (opcaoBusca == 1)
            {
                string nome;
                cout << "Informe o nome do médico: ";
                cin >> nome;
                buscarMediconome(medicos, nome);
            }
            else if (opcaoBusca == 2)
            {
                int codigo;
                cout << "Informe o código do médico: ";
                cin >> codigo;
                buscarMedicocodigo(medicos, codigo);
            }
            else
            {
                cout << "Opção inválida." << endl;
            }
            break;
        }
        case 8:
        {
            listarMedicos(medicos);
            break;
        }
        case 9:
        {
            int codigo;
            cout << "Informe o código do médico que deseja editar: ";
            cin >> codigo;
            editarMedico(medicos, codigo);
            break;
        }
        case 10:
        {
            int codigo;
            cout << "Informe o código do médico que deseja remover: ";
            cin >> codigo;
            removerMedico(medicos, codigo);
            break;
        }
        case 11:
            marcado = false;
            return 1;
        default:
            cout << "Opção inválida, por favor tente novamente." << endl;
            break;
        }

        // Limpar o buffer de entrada
        limparBuffer();
    }
    return 1;
}

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