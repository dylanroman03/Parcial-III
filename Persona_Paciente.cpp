#include "Persona_Paciente.h"
#include <iostream>
#include <string.h>

using namespace std;

// Constructor que recibe todos los atributos de la clase (incluyendo el vector de medicamentos) y los inicializa
Persona_Paciente::Persona_Paciente(char *nom_paciente, char *ape_paciente, int edad_paciente, char *telf_paciente, int num_cuarto, int cant_med, Medicamento *medicamentos)
    : Persona(nom_paciente, ape_paciente, edad_paciente, telf_paciente)
{
  this->num_cuarto = num_cuarto;
  this->cant_med = cant_med;
  this->medicamentos = new Medicamento[cant_med];
  for (int i = 0; i < cant_med; i++)
  {
    this->medicamentos[i] = medicamentos[i];
  }
}

Persona_Paciente::Persona_Paciente() : Persona()
{
  this->num_cuarto = 0;
  this->cant_med = 0;
  this->medicamentos = new Medicamento[0];
}

char *Persona_Paciente::concatenar_nom01()
{
  char *nombre = getNombre();
  char *apellido = getApellido();

  char *nombre_completo = new char[strlen(nombre) + strlen(apellido) + 3];
  strcpy(nombre_completo, nombre);
  strcat(nombre_completo, ",");
  strcat(nombre_completo, apellido);

  return nombre_completo;
}

// Sobrecarga del método concatenar_nom01() de la clase Persona, que retorna el nombre completo del paciente y el nombre del medicamento que recibe
char *Persona_Paciente::concatenar_nom01(int medicamento)
{
  char *nombre_completo = concatenar_nom01();

  char *medicamento_name = medicamentos[medicamento].getNombre();

  char *concatenado = new char[strlen(nombre_completo) + strlen(medicamento_name) + 6];
  strcpy(concatenado, nombre_completo);
  strcat(concatenado, " - ");
  strcat(concatenado, medicamento_name);

  return concatenado;
};

// Método que retorna la cantidad de medicamentos que recibió el paciente (el valor del atributo correspondiente)
int Persona_Paciente::getCantMed()
{
  return cant_med;
}

// Método para llenar los datos de los medicamentos que tiene asignado el paciente
void Persona_Paciente::setMedicamentos(Medicamento *medicamentos, int cant_med)
{
  this->cant_med = cant_med;
  this->medicamentos = new Medicamento[cant_med];
  for (int i = 0; i < cant_med; i++)
  {
    this->medicamentos[i] = medicamentos[i];
  }
}

// Método para indicar si la persona sufre Síndrome Convulsivo (conociendo que a estos pacientes se les suministra alguno de estos medicamentos ACIDO VALPROICO, LEVETIRACETAM o LAMOTRIGINA). Este debe retornar true si el paciente la padece o false si no la padece.
bool Persona_Paciente::sufreSindromeConvulsivo()
{
  for (int i = 0; i < cant_med; i++)
  {
    char *nombre_med = medicamentos[i].getNombre();

    if (strcmp(nombre_med, "Acido Valproico") == 0 || strcmp(nombre_med, "Levetiracetam") == 0 || strcmp(nombre_med, "Lamotrigina") == 0)
    {
      return true;
    }
  }
  return false;
}

// Método que retorna la deuda real del paciente, de todos los medicamentos que utilizó
double Persona_Paciente::getDeudaReal()
{
  double deuda_total = 0;

  for (int i = 0; i < cant_med; i++)
  {
    deuda_total += medicamentos[i].getDeudaReal();
  }

  return deuda_total;
}

// Método que recibe el número del medicamento del paciente y este retorne su presentación
int Persona_Paciente::getPresentacionMed(int num_med)
{
  return medicamentos[num_med].getPresentacion();
}
