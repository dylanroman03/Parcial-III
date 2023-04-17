#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

class Medicamento
{
private:
  char *nombre;
  int presentacion;
  char *fecha_vencimiento;
  double precio;

public:
  // Constructor por defecto
  Medicamento();

  // Constructor con parámetros
  Medicamento(char *nombre, int presentacion, char *fecha_vencimiento, double precio);

  // Destructor
  ~Medicamento();

  // Getters
  char *getNombre();
  int getPresentacion();
  double getDeudaReal();
};

#endif
