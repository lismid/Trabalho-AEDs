
#include <iostream>
#include <string>

using namespace std;

void menuConsulta() ;
void menuCadastro() ;
void menuHorarios() ;

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

void menuConsulta()
{
    int escolha1;
    bool marcado = true;

    while (marcado)
    {
        cout << "<------------------------------->" << endl;
        cout << "\tMenu Consultas" << endl;
        cout << "<------------------------------->" << endl;
        cout << "1. Marca Consulta" << endl;
        cout << "2. Cancelar Consulta" << endl;
        cout << "3. Visualizar Consulta Agendadas" << endl;
        cout << "4. Voltar no Menu Principal" << endl;
        cin >> escolha1;
        switch (escolha1)
        {
        case 1:
        
            break;
        case 2:
        
            break;
        case 3:
        
            break;
        case 4:
        marcado = false;

        default:
            cout << "Opção inválida, por favor tente novamente." << endl;
            break;
        }
    }
}
void menuCadastro()
{
    int escolha2;
    bool marcado2 = true;

    while (marcado2)
    {
        cout << "<------------------------------->" << endl;
        cout << "\tMenu Cadastro" << endl;
        cout << "<------------------------------->" << endl;
        cout << "1. Cadastra Paciente" << endl;
        cout << "2. Consulta Cadastro Paciente" << endl;
        cout << "3. Cadastra Medico" << endl;
        cout << "4. Consulta Cadastro Medico" << endl;
        cout << "5. Voltar no Menu Principal" << endl;
        cin >> escolha2;
        switch (escolha2)
        {
        case 1:
        
            break;
        case 2:
        
            break;
        case 3:
        
            break;
        case 4:
        
            break;
        case 5:
        marcado2 = false;
            break;
        default:
            cout << "Opção inválida, por favor tente novamente." << endl;
            break;
        }
    }
}

void menuHorarios()
{
    int escolha3;
    bool marcado3 = true;

    while (marcado3)
    {
        cout << "<------------------------------->" << endl;
        cout << "\tMenu Horarios" << endl;
        cout << "<------------------------------->" << endl;
        cout << "1. Consultar Consultas do Medico" << endl;
        cout << "2. Consultar Consultas do Paciente" << endl;
        cout << "3. Consultar Consultas do Dia" << endl;
        cout << "4. Voltar no Menu Principal" << endl;
        cin >> escolha3;
        switch (escolha3)
        {
        case 1:
        
            break;
        case 2:
        
            break;
        case 3:
        
            break;
        case 4:
            marcado3 = false;
            break;

        default:
            cout << "Opção inválida, por favor tente novamente." << endl;
            break;
        }
    }
}