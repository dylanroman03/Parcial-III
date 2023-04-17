#ifndef DATOS_H
#define DATOS_H

#include <vector>
using namespace std;

class Datos
{
public:
  vector<char*> Datos_Pacientes = {"Pedro Vargas 36 04166769989 1",
                                              "Salvador Martinez 23 04123430020 2",
                                              "Carla Monsalve 56 04166768989 1",
                                              "Milena Rosas 44 04241234567 2",
                                              "Luis Quintero 26 04146547892 3"};

  vector<char*> Datos_Medicamentos = {"Lamotrigina 3 25-11-2023 80.0",
                                                 "Clorotimetrol 2 09-09-2020 45.5",
                                                 "Cataflam 1 10-03-2024 20.5",
                                                 "Azitromicina 3 10-10-2025 30.0",
                                                 "Acetaminofen 1 10-10-2022 65.75",
                                                 "Amoxicilina 3 10-10-2021 340.5",
                                                 "Levetiracetam 1 10-10-2024 239.25",
                                                 "Melatonina 3 10-10-2022 160.0",
                                                 "Lamotrigina 2 10-10-2022 180.5"};

  Datos(){};
  ~Datos(){};
};

#endif // DATOS_H
