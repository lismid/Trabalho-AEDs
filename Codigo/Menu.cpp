
#include <string>
#include <iostream>


using namespace std;

void menuprincipal(){
    int escolha;
    bool continuar = true;

    while (continuar) {
        cout << "<------------------------------->" << endl;
        cout << "\tMenu Principal" << endl;
        cout << "<------------------------------->" << endl;
        cout << "\t1. Consultas" << endl;
        cout << "\t2. Area de Cadastros" << endl;
        cout << "\t3. Quadro de Horarios" << endl;
        cout << "\t0. Sair" << endl;
        cout << "\tEscolha uma opção:\n ";
        cin >> escolha;
        


        switch (escolha) {
            case 1:
                  cout << "1. Opção 1" << endl;
                break;
            case 2:
                  cout << "1. Opção 2" << endl;
                break;
            case 3:
                  cout << "1. Opção 3" << endl;
                break;
            case 0:
                continuar = false;
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida, por favor tente novamente." << endl;
        }
    }

}
 