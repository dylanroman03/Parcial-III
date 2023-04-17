#ifndef PERSONA_H
#define PERSONA_H

class Persona {
private:
    char* nom_paciente;
    char* ape_paciente;
    int edad_paciente;
    char* telf_paciente;
    
public:
    Persona();
    Persona(char* nom_paciente, char* ape_paciente, int edad_paciente, char* telf_paciente);
    virtual ~Persona();
    
    char* getNombre() const;
    char* getApellido() const;
    int getEdad() const;
    char* getTelefono() const;
    
    virtual char* concatenar_nom01() = 0;
};

#endif /* PERSONA_H */
