#ifndef PERSONA_PACIENTE_H
#define PERSONA_PACIENTE_H

#include "Persona.h"
#include "Medicamento.h"
#include "string"

class Persona_Paciente : public Persona {
private:
    int num_cuarto;
    int cant_med;
    Medicamento* medicamentos;
public:
    Persona_Paciente();
    Persona_Paciente(char*, char*, int, char*, int, int, Medicamento*);

    // Metodos
    char* concatenar_nom01() override;
    char* concatenar_nom01(int i);
    void setMedicamentos(Medicamento*, int cant_med);
    int getCantMed(); // Metodo que retorna la cantidad de medicamentos que recibió el paciente (el valor del atributo correspondiente)
    double getDeudaReal();
    bool sufreSindromeConvulsivo();
    int getPresentacionMed(int);
};

#endif //PERSONA_PACIENTE_H
