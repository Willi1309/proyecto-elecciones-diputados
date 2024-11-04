#include "Inscripcion.h"
#include <iostream>

Inscripcion::Inscripcion() {
    std::cout << "Constructor de Inscripcion llamado." << std::endl; // Mensaje de depuración
    //Candidato aux;
    //candidatos.InsComienzo(aux);
    std::cout << "cola candidatos " << candidatos.ObtPrimero() << std::endl; // Mensaje de depuración
}

void mensaje(){
    std::cout << "mensaje de objeto inscripcion." << std::endl; // Mensaje de depuración
}

Candidato Inscripcion::CrearMarca() {
    Candidato candidatos;
    string ced, nomb, apel;
    int votos, idprd;

    ced = "-999999999999";
    nomb = "$$$$$";
    apel = "$$$$$";
    votos = -999999999999;
    idprd = -999999999999;

    candidatos.setCedula(ced);
    candidatos.setNombre(nomb);
    candidatos.setApellido(apel);
    candidatos.setIdPartido(idprd);
    //candidatos.setEstatusInicial();

    return candidatos;
}

bool Inscripcion::verificarDisponibilidad(Candidato cand){
    if (cand.getIdPartido() < 0 || cand.getIdPartido() >= 5) {
        std::cout << "ID de partido no válido." << std::endl;
        return false;
    }
    if (candidatosPorPartido[cand.getIdPartido()] >= 5) {
        std::cout << "El partido ya tiene 5 candidatos inscritos." << std::endl;
        return false;
    }
    if (candidatos.Contar() >= 25) {
        std::cout << "Se alcanzó el máximo de 25 candidatos." << std::endl;
        return false;
    }

    std::cout << "\n Disponibilidad Aprobada" << std::endl; // Mensaje de depuración
    return true;
}

void Inscripcion::RegistrarCandidato(Candidato cand) {
    std::cout << "\n Entrando a RegistrarCandidato." << std::endl; // Mensaje de depuración

    std::cout << "\n Antes de insertar en la cola." << std::endl; // Mensaje de depuración
    //candidatos.InsComienzo(cand);
    candidatos.InsertarNodoCola(cand);
    std::cout << "Después de insertar en la cola." << std::endl; // Mensaje de depuración
    candidatosPorPartido[cand.getIdPartido()]++;
    std::cout << "Candidato inscrito exitosamente en RegistrarCandidato." << std::endl; // Mensaje de depuración
}

void Inscripcion::EliminarCandidato(string cedCandidato) {
    std::cout << "Entrando a EliminarCandidato." << std::endl; // Mensaje de depuración
    // Declara dos objetos de tipo Candidato: candAux y marca
    Candidato candAux, marca;
    // Declara una variable booleana para indicar si se encontró el candidato
    bool encontrado = false;
    // Crea un objeto "marca" que se usará como marcador
    marca = CrearMarca();

    // Declara una lista temporal de candidatos
    Lista<Candidato> temp;

    // Verifica si la lista de candidatos no está llena
    if (!candidatos.Llena()) {

        // Inserta el marcador al final de la lista de candidatos
        candidatos.InsertarNodoCola(marca);

        // Mientras no se haya encontrado el candidato
        while (!encontrado) {

            // Remueve el último nodo de la lista de candidatos y lo almacena en candAux
            candidatos.RemoverNodoCola(candAux);

            // Si el candidato removido es el marcador, se ha llegado al final de la lista
            if (candAux.getCedula() == marca.getCedula()) {
                encontrado = true;
            } else {
                // Si el candidato removido tiene la cédula que se quiere eliminar
                if (candAux.getCedula() == cedCandidato) {
                    std::cout << "\n\nCandidato eliminado\n\n";
                    encontrado = true;
                    // Actualiza el contador de candidatos por partido
                    candidatosPorPartido[candAux.getIdPartido()]--;
                } else {
                    // Si no es el candidato a eliminar, se inserta en la lista auxiliar
                    temp.InsertarNodoCola(candAux);
                }
            }
        }

        // Mientras la lista auxiliar no esté vacía
        while (!temp.Vacia()) {
            // Remueve el último nodo de la lista auxiliar y lo almacena en candAux
            temp.RemoverNodoCola(candAux);
            // Inserta el candidato de vuelta en la lista original
            candidatos.InsertarNodoCola(candAux);
        }
    }

    // Si no se encontró el candidato, se imprime un mensaje
    if (!encontrado) {
        std::cout << "Candidato no encontrado." << std::endl;
    }
}

void Inscripcion::MostrarCandidatos() {
    std::cout << "Entrando a MostrarCandidatos." << std::endl; // Mensaje de depuración
    nodo<Candidato>* actual = candidatos.ObtPrimero();
    if (!actual) {
        std::cout << "No hay candidatos inscritos en la cola." << std::endl;
        return;
    }

    std::cout << "Candidatos inscritos:" << std::endl;
    while (actual) {
        Candidato candidatoActual = candidatos.ObtInfo(actual);
        candidatoActual.mostrarInformacion();
        actual = candidatos.ObtProx(actual);
    }

    
}
