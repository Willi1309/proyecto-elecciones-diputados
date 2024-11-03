#include "Candidato.h"
#include "Inscripcion.h"
#include <iostream>

using namespace std;

int main() {
    Inscripcion inscripcion;
    int opcionInicial;
    string cedEliminar;
    
    // Menu inicial
    cout << "Bienvenido al sistema de gestion de elecciones." << endl;
    cout << "1. Entrar al sistema de gestion de candidatos" << endl;
    cout << "2. Salir" << endl;
    cout << "Elige una opcion: ";
    cin >> opcionInicial;
    cin.ignore(); // Limpiar el buffer de entrada

    if (opcionInicial == 1) {
        int opcion;
        do {
            cout << "\n--- Menu de gestion de candidatos ---" << endl;
            cout << "1. Registrar candidato" << endl;
            cout << "2. Mostrar candidatos" << endl;
            cout << "3. Eliminar candidato" << endl;
            cout << "4. Salir" << endl;
            cout << "Elige una opcion: ";
            cin >> opcion;
            cin.ignore(); // Limpiar el buffer de entrada

            switch(opcion) {
                case 1: {
                    string cedula, nombre, apellido;
                    int idPartido;

                    cout << "Cedula del candidato: ";
                    getline(cin, cedula);
                    cout << "Nombre del candidato: ";
                    getline(cin, nombre);
                    cout << "Apellido del candidato: ";
                    getline(cin, apellido);
                    cout << "ID del Partido del candidato: ";
                    cin >> idPartido;
                    cin.ignore(); // Limpiar el buffer de entrada

                    cout << "Registrando candidato: " << cedula << ", " << nombre << ", " << apellido << ", " << idPartido << endl;

                    Candidato candidato(cedula, nombre, apellido, idPartido);
                    cout << "Candidato creado." << endl; // Mensaje de depuración
                    inscripcion.RegistrarCandidato(candidato);
                    cout << "Candidato registrado exitosamente." << endl; // Mensaje de depuración
                    break;
                }
                case 2:
                    inscripcion.MostrarCandidatos();
                    break;
                case 3:
                    cout << "Ingrese la cedula del candidato a eliminar: ";
                    cin >> cedEliminar;
                    cin.ignore(); // Limpiar el buffer de entrada
                    inscripcion.EliminarCandidato(cedEliminar);
                    break;
                case 4:
                    cout << "Saliendo del sistema de gestion de candidatos." << endl;
                    break;
                default:
                    cout << "Opcion no valida. Intenta de nuevo." << endl;
            }
        } while (opcion != 4);
    } else if (opcionInicial == 2) {
        cout << "Saliendo del programa." << endl;
    } else {
        cout << "Opcion no valida. Terminando el programa." << endl;
    }

    return 0;
}