all: main.o Relatorio.o Paciente.o Menu.o Consulta.o CadastrarMedico.o
	g++ main.o Relatorio.o Paciente.o Menu.o Consulta.o CadastrarMedico.o -o main

main.o: main.cpp
	g++ -c main.cpp

Relatorio.o: ./Codigo/Relatorio.cpp
	g++ -c ./Codigo/Relatorio.cpp

Paciente.o: ./Codigo/Paciente.cpp
	g++ -c ./Codigo/Paciente.cpp

Menu.o: ./Codigo/Menu.cpp
	g++ -c ./Codigo/Menu.cpp

Consulta.o: ./Codigo/Consulta.cpp
	g++ -c ./Codigo/Consulta.cpp

CadastrarMedico.o: ./Codigo/CadastrarMedico.cpp
	g++ -c ./Codigo/CadastrarMedico.cpp

clear:
	rm -r *.o