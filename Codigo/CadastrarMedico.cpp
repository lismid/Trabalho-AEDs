<<<<<<< Updated upstream
=======
@ -0,0 +1,103 @@
#include <iostream>
#include <fstream>
#include <vector> //essa é a biblioteca pra usar vetor, que a gente ta usando pra alocar os médicos de forma dinâmica 
#include <sstream> //essa é pra manipular string tipo arquivo, com entrada (istream) e saida (ostream)

using namespace std;

class Medico {
private:
    int codigo;
    string nome;
    string telefone;
    string especialidade;

public:
    // Construtor
    Medico(int codigo, const string& nome, const string& telefone, const string& especialidade)
        : codigo(codigo), nome(nome), telefone(telefone), especialidade(especialidade) {}

    // Método para cadastrar médico
    void cadastrar() {
        ofstream arquivoMedicos("medicos.txt", ios::app);

        if (!arquivoMedicos.is_open()) {
            cerr << "Erro ao abrir o arquivo de medicos." << endl;
            return;
        }

        // Verificar se já existe um médico com o mesmo código
        ifstream arquivoConsulta("medicos.txt");
        string linha;
        while (getline(arquivoConsulta, linha)) {
            stringstream ss(linha);
            int codigoExistente;
            ss >> codigoExistente;  // Lendo o código do médico existente
            if (codigoExistente == codigo) {
                cout << "Erro: Ja existe um medico cadastrado com o codigo " << codigo << endl;
                arquivoMedicos.close();
                return;
            }
        }
        arquivoConsulta.close();

        // Escrever os dados do médico no arquivo
        arquivoMedicos << codigo << " " << nome << " " << telefone << " " << especialidade << endl;

        arquivoMedicos.close();

        cout << "Medico cadastrado com sucesso!" << endl;
    }

    int getCodigo() const { return codigo; }
    const string& getNome() const { return nome; }
    const string& getTelefone() const { return telefone; }
    const string& getEspecialidade() const { return especialidade; }
};

// Função para ler médicos do arquivo
vector<Medico> lerMedicos() {
    vector<Medico> medicos;

    ifstream arquivoMedicos("medicos.txt");

    if (!arquivoMedicos.is_open()) {
        cerr << "Erro ao abrir o arquivo de medicos." << endl;
        return medicos;
    }

    // Ler cada linha do arquivo e criar objetos Medico
    string linha;
    while (getline(arquivoMedicos, linha)) {
        stringstream ss(linha); //Usando stringstream pq ela meio que separa os dados usando espaços em branco como delimitadores por padrão
        int codigo;
        string nome, telefone, especialidade;
        ss >> codigo >> nome >> telefone >> especialidade; //Ai aq usando ss os dados sao separados direitinho
        medicos.push_back(Medico(codigo, nome, telefone, especialidade));
    }

    arquivoMedicos.close();

    return medicos;
}

// Função main para testar o cadastro de médico
int main() {
    // Exemplo de cadastro de médico
    Medico medico1(1, "Dr. Joao", "(31) 98765-4321", "Cardiologia");
    Medico medico2(2, "Dra. Maria", "(31) 99876-5432", "Dermatologia");

    medico1.cadastrar();
    medico2.cadastrar();

    // Ler médicos cadastrados
    vector<Medico> listaMedicos = lerMedicos();

    // Exibir lista de médicos cadastrados
    cout << "Medicos cadastrados:" << endl;
    for (const Medico& medico : listaMedicos) {
        cout << "Codigo: " << medico.getCodigo() << ", Nome: " << medico.getNome() << ", Telefone: " << medico.getTelefone() << ", Especialidade: " << medico.getEspecialidade() << endl;
    }

    return 0;
}
>>>>>>> Stashed changes
