#include "Medicamento.h"
#include "Persona_Paciente.h"
#include "Datos.h"
#include <iostream>
#include <string.h>

using namespace std;

Persona_Paciente *pacientes;
Medicamento *medicamentos;
int num_pacientes;

void traer_medicamentos()
{
  Datos datos;
  const int num_medicamentos = datos.Datos_Medicamentos.size();

  medicamentos = new Medicamento[num_medicamentos];

  for (int i = 0; i < num_medicamentos; i++)
  {
    char *datos_medicamento = datos.Datos_Medicamentos[i];

    // Calcular la longitud de la cadena y crear arreglo
    int len = strlen(datos_medicamento);
    char copia[len + 1];

    // Hacer una copia de la cadena utilizando strcpy
    strcpy(copia, datos_medicamento);

    // Dividir la cadena en tokens
    char *nombre = strtok(copia, " ");

    char *presentacion_char = strtok(NULL, " ");
    int presentacion = atoi(presentacion_char);

    char *fecha_vencimiento = strtok(NULL, " ");

    char *precio_char = strtok(NULL, " ");
    double precio = atof(precio_char);

    // Creamos los Medicamentos y los agregamos al arreglo
    Medicamento *medicamento = new Medicamento(nombre, presentacion, fecha_vencimiento, precio);
    medicamentos[i] = *medicamento;
  }
}

void traer_pacientes()
{
  Datos datos;

  num_pacientes = datos.Datos_Pacientes.size();
  pacientes = new Persona_Paciente[num_pacientes];

  int medicamentos_position = 0;

  for (int i = 0; i < num_pacientes; i++)
  {
    char *datos_paciente = datos.Datos_Pacientes[i];

    // Calcular la longitud de la cadena y crear arreglo
    int len = strlen(datos_paciente);
    char copia[len + 1];

    // Hacer una copia de la cadena utilizando strcpy
    strcpy(copia, datos_paciente);

    // Dividir la cadena en tokens
    char *nombre = strtok(copia, " ");

    char *apellido = strtok(NULL, " ");

    char *edad_char = strtok(NULL, " ");
    int edad = atoi(edad_char);

    char *telefono = strtok(NULL, " ");

    char *cantidad_char = strtok(NULL, " ");
    int cantidad = atoi(cantidad_char);

    // Cargar Medicamentos y crear el paciente

    Medicamento *medicamentos_paciente;
    medicamentos_paciente = new Medicamento[cantidad];

    for (int i = 0; i < cantidad; i++)
    {
      medicamentos_paciente[i] = medicamentos[medicamentos_position + i];
    }

    Persona_Paciente *paciente = new Persona_Paciente(nombre, apellido, edad, telefono, 0, cantidad, medicamentos_paciente);
    pacientes[i] = *paciente;

    medicamentos_position += cantidad;
  }
}

void traer_datos()
{
  traer_medicamentos();
  traer_pacientes();
}

void deuda_total()
{

  double total = 0.00;

  for (int i = 0; i < num_pacientes; i++)
  {
    total += pacientes[i].getDeudaReal();
  }

  cout << "La deuda total de todos los pacientes es: " << total << "\n"
       << endl;
}

void pacientes_convulsivos()
{
  int total = 0;
  cout << "Listado de personas que sufrieron sindrome convulsivo: " << endl;

  for (int i = 0; i < num_pacientes; i++)
  {
    if (pacientes[i].sufreSindromeConvulsivo())
    {
      cout << pacientes[i].concatenar_nom01() << endl;
      total++;
    }
  }
  cout << "Total de pacientes: " << total << endl;
  cout << "\n"
       << endl;
}

void listar_presentacion(int presentacion)
{
  switch (presentacion)
  {
  case 1:
    cout << "En Tableta:" << endl;
    break;
  case 2:
    cout << "En Jarabe:" << endl;
    break;
  case 3:
    cout << "En Ampolla:" << endl;
    break;
  }

  for (int i = 0; i < num_pacientes; i++)
  {
    bool bandera = true;

    for (int j = 0; j < pacientes[i].getCantMed(); j++)
    {
      if (pacientes[i].getPresentacionMed(j) == presentacion && bandera)
      {
        cout << pacientes[i].concatenar_nom01() << endl;
        bandera = false;
      }
    }
  }
  cout << endl;
}

// Metodo para setear los medicamentos a un paciente
void agregar_medicamentos()
{
  // Mostrar la lista de pacientes para que el usuario seleccione uno
  cout << "Lista de pacientes:" << endl;
  for (int i = 0; i < num_pacientes; i++)
  {
    cout << "[" << i << "] " << pacientes[i].getNombre() << endl;
  }
  cout << endl;

  // Pedir al usuario que seleccione la posición del paciente
  int pos_paciente;
  do
  {
    cout << "Seleccione la posición del paciente (0-" << num_pacientes - 1 << "): ";
    cin >> pos_paciente;
  } while (pos_paciente < 0 || pos_paciente >= num_pacientes);

  int cantidad_medicamentos = 0;
  cout << "Cantidad de medicamentos:";
  cin >> cantidad_medicamentos;

  Medicamento *medicamentos_paciente = new Medicamento[cantidad_medicamentos];

  for (int i = 0; i < cantidad_medicamentos; i++)
  {
    cout << "\nMedicamento " << i + 1 << endl;

    // Pedir al usuario los datos del nuevo medicamento
    char nombre_medicamento[50];
    int presentacion = 0;
    char fecha_vencimiento[20];
    double precio = 0.00;

    cout << "Ingrese el nombre del medicamento: ";
    cin >> nombre_medicamento;

    bool valido = false;
    while (!valido)
    {
      cout << "Ingrese la presentación del medicamento (1, 2, 3): ";
      cin >> presentacion;

      if (presentacion < 1 || presentacion > 3)
      {
        cout << "Presentación inválida, ingrese 1, 2 o 3" << endl;
      }
      else
      {
        valido = true;
      }
    }

    cout << "Ingrese la fecha de vencimiento (formato dia-mes-ano): ";
    cin >> fecha_vencimiento;

    cout << "Ingrese el precio del medicamento: ";
    cin >> precio;

    // Agregar el medicamento al paciente seleccionado
    Medicamento *medicamento = new Medicamento(nombre_medicamento, presentacion, fecha_vencimiento, precio);
    medicamentos_paciente[i] = *medicamento;
  }

  pacientes[pos_paciente].setMedicamentos(medicamentos_paciente, cantidad_medicamentos);
  cout << "Medicamento agregado exitosamente.\n" << endl;
}

int main(int argc, char const *argv[])
{
  traer_datos();
  cout << "Bienvenido al programa de gestión de pacientes." << endl;

  int opcion = 0;
  while (opcion != 5)
  {
    cout << "Por favor, seleccione una opción:" << endl;
    cout << "1. Mostrar deuda total de pacientes." << endl;
    cout << "2. Mostrar cantidad de pacientes que sufren síndrome convulsivo." << endl;
    cout << "3. Listar medicamentos por presentación." << endl;
    cout << "4. Agregar medicamentos a un cliente." << endl;
    cout << "5. Salir del programa." << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      deuda_total();
      break;
    case 2:
      pacientes_convulsivos();
      break;
    case 3:
      listar_presentacion(1);
      listar_presentacion(2);
      listar_presentacion(3);
      break;
    case 4:
      agregar_medicamentos();
      break;
    case 5:
      cout << "Saliendo del programa." << endl;
      break;
    default:
      cout << "Opción inválida. Por favor, seleccione otra opción." << endl;
      break;
    }
  }
  return 0;
}
