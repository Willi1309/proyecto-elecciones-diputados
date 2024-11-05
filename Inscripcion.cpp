#include "Inscripcion.h"
#include <iostream>

Inscripcion::Inscripcion() {}

bool Inscripcion::verificarDisponibilidad(Candidato cand){
    if (cand.getIdPartido() < 0 || cand.getIdPartido() > 5) {
        std::cout << "ID de partido no valido." << std::endl;
        return false;
    }
    if (candidatosPorPartido[cand.getIdPartido()] >= 5) {
        std::cout << "El partido ya tiene 5 candidatos inscritos." << std::endl;
        return false;
    }
    return true;
}

void Inscripcion::Registrar() {
    Candidato nuevo; string nuevaCedula, nuevoNombre, nuevoApellido, nuevoStatus; int idNuevoPartido;

    cout << "\tRegistrando Candidato  ------------ \n ";

    cout<<"Cedula:"; cin>>nuevaCedula; cin.ignore();
    nuevo.setCedula(nuevaCedula);

    cout<<"Nombre:"; getline(cin, nuevoNombre);
    nuevo.setNombre(nuevoNombre);

    cout<<"Apellido:"; getline(cin, nuevoApellido);
    nuevo.setApellido(nuevoApellido);

    cout<<"ID del partido:"; cin>>idNuevoPartido;
    nuevo.setIdPartido(idNuevoPartido);

    //cout<<"Nuevo estatus del candidato: "; cin>>nuevoStatus;
    //cand.setStatus(nuevoStatus);

    if(verificarDisponibilidad(nuevo)) {
        candidatos.InsertarNodoCola(nuevo);
        partidos[nuevo.getIdPartido()].InsertarNodoCola(nuevo);
        candidatosPorPartido[nuevo.getIdPartido()]++;

        cout << "\nCandidato registrado exitosamente:\n";
        nuevo.mostrarInformacion();

    } else cout << "\nFallo al registrar el candidato\n";
}

void Inscripcion::Eliminar(Candidato cand) {
    std::cout << "\n\nCandidato Eliminado:\n";
    cand.mostrarInformacion();
    candidatosPorPartido[cand.getIdPartido()]; // Actualizamos el contador de candidatos por partido
}

void Inscripcion::Buscar(Candidato cand) {
    std::cout << "\n\nCandidato Mostrado:\n";
    cand.mostrarInformacion();
}

Candidato Inscripcion::Modificar(Candidato cand) {
    Candidato nuevo; string nuevaCedula, nuevoNombre, nuevoApellido, nuevoStatus; int idNuevoPartido;

    cout << "\n\nCandidato encontrado\n" << endl;
    cand.mostrarInformacion();

    cout << "\tIngrese los nuevos datos para el candidato con cedula "<<cand.getCedula()<<" \n\n";

    cout<<"Cedula:"; cin>>nuevaCedula; cin.ignore();
    nuevo.setCedula(nuevaCedula);

    cout<<"Nombre:"; getline(cin, nuevoNombre);
    nuevo.setNombre(nuevoNombre);

    cout<<"Apellido:"; getline(cin, nuevoApellido);
    nuevo.setApellido(nuevoApellido);

    cout<<"ID del partido:"; cin>>idNuevoPartido;
    nuevo.setIdPartido(idNuevoPartido);

    //cout<<"Nuevo estatus del candidato: "; cin>>nuevoStatus;
    //cand.setStatus(nuevoStatus);

    if(verificarDisponibilidad(nuevo)) {
        cout << "\nCandidato modificado exitosamente:\n";
        nuevo.mostrarInformacion();
        return nuevo;
    }
    cout << "\nCandidato no modificado\n";
    return cand;
}


void Inscripcion::iterarCandidatos(string cedCandidato, int opcion) {

    Candidato marca; marca.setCedula("$$$$$$");

    if (candidatos.Vacia()) cout << "No hay candidatos inscritos." << endl; else {
        Candidato candAux;
        bool encontrado = false;

        candidatos.InsertarNodoCola(marca);

        while (true){

            candidatos.RemoverNodoCola(candAux);

            if (candAux.getCedula() == marca.getCedula()) { break; }

            if (candAux.getCedula() == cedCandidato) {
                encontrado = true;

                if(opcion == 3) { Buscar(candAux); }
                if(opcion == 4) { candAux = Modificar(candAux); }
                if(opcion == 5) { Eliminar(candAux); continue; }

            }
            candidatos.InsertarNodoCola(candAux);
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

void Inscripcion::ReporteGeneral() {
    // hay que mostrar a los candidatos por partido
    int i = 0;
    while (i <= 5)
    {
        Lista<Candidato> partidoActual = partidos[i];

        if (!partidoActual.Vacia()) {
            nodo<Candidato>* actual = partidoActual.ObtPrimero();
            std::cout << "==================================" << endl;
            std::cout << "Partido " << partidoActual.ObtInfo(actual).getNombrePartido() << endl;
            std::cout << "==================================" << endl;
            while (actual) {
                Candidato candidatoActual = partidoActual.ObtInfo(actual);
                cout << "Candidato: " << candidatoActual.getNombre()  << " " << candidatoActual.getApellido() <<  endl;
                cout << "Cedula: " << candidatoActual.getCedula() << endl;
                actual = partidoActual.ObtProx(actual);
            }

            std::cout << endl;
        }

        i++;

    }

}
