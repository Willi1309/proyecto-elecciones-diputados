#include "Inscripcion.h"
#include <iostream>

Inscripcion::Inscripcion() {}

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
    return true;
}

void Inscripcion::RegistrarCandidato(Candidato cand) {

    candidatos.InsertarNodoCola(cand);
    candidatosPorPartido[cand.getIdPartido()]++;
}

void Inscripcion::EliminarCandidato(string cedCandidato) {

    Candidato marca = CrearMarca();

    if (!candidatos.Llena() && !candidatos.Vacia()) {
        Candidato candAux;
        bool encontrado = false;

        candidatos.InsertarNodoCola(marca);

        while (true){

            candidatos.RemoverNodoCola(candAux);

            if (candAux.getCedula() == marca.getCedula()) { break; }

            if (candAux.getCedula() == cedCandidato) {

                    std::cout << "\n\nCandidato eliminado\n\n";
                    encontrado = true;
                    candidatosPorPartido[candAux.getIdPartido()]; // Actualizamos el contador de candidatos por partido

            } else { candidatos.InsertarNodoCola(candAux); }
        }

        if (!encontrado) { std::cout << "Candidato no encontrado." << std::endl; }
    }
}

void Inscripcion::MostrarCandidatos() {

    nodo<Candidato>* actual = candidatos.ObtPrimero();
    if (!actual) {
        std::cout << "No hay candidatos inscritos en la cola." << std::endl;
        return;
    }

    std::cout << "Candidatos inscritos: \n" << std::endl;
    while (actual) {
        Candidato candidatoActual = candidatos.ObtInfo(actual);
        candidatoActual.mostrarInformacion();
        actual = candidatos.ObtProx(actual);
    }
}

Candidato Inscripcion::BuscarCandidato(string ced) {

    if (candidatos.Vacia()) cout << "Lista vacia" << endl;
    Candidato encontrado;
    // crear marca 
    Candidato marca;

    marca = CrearMarca();

    marca.getCedula() = "$$$";

    candidatos.InsFinal(marca);

    while (candidatos.ObtInfo(candidatos.ObtPrimero()).getCedula() != marca.getCedula()) {
        Candidato actual = candidatos.ObtInfo(candidatos.ObtPrimero());

        if (actual.getCedula() == ced) {
            encontrado = actual;
        }

        candidatos.InsFinal(actual);
        candidatos.AsigPrimero(candidatos.ObtProx(candidatos.ObtPrimero()));


    }

    Candidato primero = candidatos.ObtInfo(candidatos.ObtPrimero());
    if (primero.getCedula() == marca.getCedula()) {
        candidatos.EliComienzo(marca);
        // cout << "eliminada la marca!" << endl; 
    }

    if (encontrado.getNombre().empty()) {
        cout << "Candidato no encontrado" << endl;
        return Candidato();
    }

    return encontrado;
}