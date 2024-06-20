#include <string>
#include <iostream>
#include "Struct.hpp"



using namespace std;

void menuprincipal(){
    int escolha;
    bool continuar = true;

    while (continuar) {
        cout << "\nMenu Principal:" << endl;
        cout << "1. Opção 1" << endl;
        cout << "2. Opção 2" << endl;
        cout << "3. Opção 3" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
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
 