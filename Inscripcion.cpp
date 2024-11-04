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
    Candidato candAux, marca;
    bool encontrado = false;
    marca = CrearMarca();

    Lista<Candidato> temp;

    if (!candidatos.Llena()) {

        //revisar
        candidatos.InsertarNodoCola(marca);

        while (!encontrado) {

            //revisar
            candidatos.RemoverNodoCola(candAux);

            if (candAux.getCedula() == marca.getCedula()) {
                encontrado = true;
            } else {
                if (candAux.getCedula() == cedCandidato) {
                    std::cout << "\n\nCandidato eliminado\n\n";
                    encontrado = true;
                    candidatosPorPartido[candAux.getIdPartido()]; // Actualizamos el contador de candidatos por partido
                } else {



                    temp.InsertarNodoCola(candAux);
                }
            }
        }

        while (!temp.Vacia()) {


            //revisar
            temp.RemoverNodoCola(candAux);
            candidatos.InsertarNodoCola(candAux);
        }
    }

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
