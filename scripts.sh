g++ -w -c Medicamento.cpp -o bin/Medicamento.o
g++ -w -c Persona.cpp -o bin/Persona.o
g++ -w -c Persona_Paciente.cpp -o bin/Persona_Paciente.o
g++ -w -c main.cpp -o bin/main.o
g++ -w -Lbin -o bin/main bin/Medicamento.o bin/Persona.o bin/Persona_Paciente.o bin/main.o
bin/main