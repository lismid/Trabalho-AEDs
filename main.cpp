#include "CadastroPessoas.hpp"
#include "Consulta.hpp"
#include "Medico.hpp"
#include "Relatorio.hpp"
#include <iostream>
#include <vector>

using namespace std;

void menuPrincipal(vector<CONSULTA> &consultas, CadastroPessoas &cadastroPessoas, vector<Medico> &medicos);

int main()
{
    vector<CONSULTA> consultas;
    CadastroPessoas cadastroPessoas;
    vector<Medico> medicos = lerMedicos();

    menuPrincipal(consultas, cadastroPessoas, medicos);
    return 0;
}


