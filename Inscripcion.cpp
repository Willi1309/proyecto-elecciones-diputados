#include "Inscripcion.h"
#include <iostream>

Inscripcion::Inscripcion() {
    std::cout << "Constructor de Inscripcion llamado." << std::endl; // Mensaje de depuración
}

Candidato Inscripcion::CrearMarca() {
    Candidato candidatos;
    string ced, nomb, apel;
    int votos, idprd;

    ced = "-1";
    nomb = "$$$$$";
    apel = "$$$$$";
    votos = -1;
    idprd = -1;

    candidatos.setCedula(ced);
    candidatos.setNombre(nomb);
    candidatos.setApellido(apel);
    candidatos.setIdPartido(idprd);
    candidatos.setEstatusInicial();

    return candidatos;
}

void Inscripcion::RegistrarCandidato(Candidato cand) {
    std::cout << "Entrando a RegistrarCandidato." << std::endl; // Mensaje de depuración
    if (cand.getIdPartido() < 0 || cand.getIdPartido() >= 5) {
        std::cout << "ID de partido no válido." << std::endl;
        return;
    }
    if (candidatosPorPartido[cand.getIdPartido()] >= 5) {
        std::cout << "El partido ya tiene 5 candidatos inscritos." << std::endl;
        return;
    }
    if (candidatos.Contar() >= 25) {
        std::cout << "Se alcanzó el máximo de 25 candidatos." << std::endl;
        return;
    }

    std::cout << "Antes de insertar en la cola." << std::endl; // Mensaje de depuración
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

    if (candidatos.Llena()) {
        candidatos.InsertarNodoCola(marca);

        while (!encontrado) {
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