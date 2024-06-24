#include <iostream>
#include <string>

using namespace std;


void meneu(){
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
               
                break;
            case 2:
               cout << "1. Opção 2" << endl;
                break;

            case 3:
                cout << "1. Opção 2" << endl;
                break;

                default:
               cout << "Opção inválida, por favor tente novamente." << endl;
            
            break;
        }
    }
}

void menuConsulta(){
    int escolha1;
    bool marcado = true;

    while (marcado)
    { cout << "<------------------------------->" << endl;
            cout << "\tMenu Consultas" << endl;
            cout << "<------------------------------->" << endl;
            cout << "1. Marca Consulta" << endl;
            cout << "2. Cancelar Consulta" << endl;
            cout << "3. Voltar no Menu Principal" << endl;
            cin >> escolha1;
        switch (escolha1)
        {
        case 1:
            break;
        
        default:
            break;
        }
    }
    

}