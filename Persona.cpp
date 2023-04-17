#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;

// Constructor sin parámetros
Persona::Persona()
{
  nom_paciente = new char[1];
  nom_paciente[0] = '\0';

  ape_paciente = new char[1];
  ape_paciente[0] = '\0';

  edad_paciente = 0;

  telf_paciente = new char[1];
  telf_paciente[0] = '\0';
}

// Constructor con parámetros
Persona::Persona(char *nom_paciente, char *ape_paciente, int edad_paciente, char *telf_paciente)
{
  this->nom_paciente = new char[strlen(nom_paciente) + 1];
  strcpy(this->nom_paciente, nom_paciente);

  this->ape_paciente = new char[strlen(ape_paciente) + 1];
  strcpy(this->ape_paciente, ape_paciente);

  this->edad_paciente = edad_paciente;

  this->telf_paciente = new char[strlen(telf_paciente) + 1];
  strcpy(this->telf_paciente, telf_paciente);
}

// Destructor
Persona::~Persona()
{
  delete[] nom_paciente;
  delete[] ape_paciente;
  delete[] telf_paciente;
}

// Métodos get
char *Persona::getNombre() const
{
  return nom_paciente;
}

char *Persona::getApellido() const
{
  return ape_paciente;
}

int Persona::getEdad() const
{
  return edad_paciente;
}

char *Persona::getTelefono() const
{
  return telf_paciente;
}