#include "Medicamento.h"
#include <cstring>
#include <string.h>
#include <iostream>

using namespace std;

// Constructor por defecto
Medicamento::Medicamento()
{
  nombre = new char[1];
  nombre[0] = '\0';
  presentacion = 0;
  fecha_vencimiento = new char[1];
  fecha_vencimiento[0] = '\0';
  precio = 0.0;
}

// Constructor con parámetros
Medicamento::Medicamento(char *nombre, int presentacion, char *fecha_vencimiento, double precio)
{
  this->nombre = new char[strlen(nombre) + 1];
  strcpy(this->nombre, nombre);
  this->presentacion = presentacion;

  char *nueva_fecha = new char[9];            // Reservamos memoria para la nueva fecha
  strncpy(nueva_fecha, fecha_vencimiento, 2); // Copiamos los dos primeros caracteres del día
  nueva_fecha[2] = '-';
  strncpy(nueva_fecha + 3, fecha_vencimiento + 3, 2); // Copiamos los dos primeros caracteres del mes
  nueva_fecha[5] = '-';
  strncpy(nueva_fecha + 6, fecha_vencimiento + 8, 2); // Copiamos los dos primeros caracteres del año
  nueva_fecha[8] = '\0';

  this->fecha_vencimiento = new char[strlen(nueva_fecha) + 1];
  strcpy(this->fecha_vencimiento, nueva_fecha);

  this->precio = precio;
}

// Destructor
Medicamento::~Medicamento()
{
  delete[] nombre;
  delete[] fecha_vencimiento;
}

double Medicamento::getDeudaReal()
{
  double total = precio;

  char *anio = new char[5];
  sscanf(fecha_vencimiento, "%2s-%2s-%4s", new char[3], new char[3], anio);

  if (atoi(anio) <= 22)
  {
    total -= precio * 0.10;
  }

  total += precio * 0.16;

  return total;
}

// Getters
char *Medicamento::getNombre()
{
  return nombre;
}

int Medicamento::getPresentacion()
{
  return presentacion;
}