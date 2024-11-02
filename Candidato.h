#ifndef Candidato_H
#define Candidato_H
#include <iostream>
#include <string>
#include "Libreria/Lista.h"
using namespace std;

/*struct Partido{
	int id;
	string nombre;
	Partido() :
		id(0) { // Inicializacion de los valores numericos para el struct
	}
};*/


class Candidato
{
private:
	string cedula, nombre, apellido, partido;
	int idPartido, votos;
	Lista <string> pilaEstatus;
	string nombresPartidos[5] = {"Partido A", "Partido B", "Partido C", "Partido D", "Partido E"};

public:
	Candidato();
    
	Candidato(const string& ced, const string& nom, const string& apel, int partidoId);


	//setter y getters
	void setCedula(string ced);
	string getCedula();
	void setNombre (string n);
	string getNombre ();
	void setApellido (string apel);
	string getApellido ();
	void setIdPartido(int idprd);
	int getIdPartido();
	void setVotos(int vot);
	int getVotos();

	/*Partido getPartido ();
	int getIdPartido();
	string getNombrePartido();*/
	// Métodos para modificar información del candidato
    void agregarVoto() { votos++; }

	//metodos para pila estatus
	void setEstatusInicial();
	string getEstatus();
	void ModificarEstatus(string);
	//void setEstatusEliminado();


    // Método para obtener el nombre del partido según el ID
    string getNombrePartido();
	
	
	void mostrarInformacion();
	

	
};
#include "Candidato.cpp" 
#endif
