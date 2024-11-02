#include "Inscripcion.h"

Inscripcion::Inscripcion(){

}


 Candidato Inscripcion::CrearMarca()
{

	Candidato candidatos;
	string ced, nomb, apel;
	int votos, idprd;
	
    //int votos;

	ced = "-1";
	nomb = "$$$$$";
	apel = "$$$$$";
	votos =-1;
	idprd = -1;
    //votos= -1;


	candidatos.setCedula(ced);
	candidatos.setNombre(nomb);
	candidatos.setApellido(apel);
	candidatos.setIdPartido(idprd);
	candidatos.setEstatusInicial();

	return candidatos;
}

void Inscripcion::RegistrarCandidato(Candidato cand)
{
	if (cand.getIdPartido() < 0 || cand.getIdPartido() >= 5) {
        cout << "ID de partido no válido." << endl;
        return;
    }
    if (candidatosPorPartido[cand.getIdPartido()] >= 5) {
        cout << "El partido ya tiene 5 candidatos inscritos." << endl;
        return;
    }
    if (candidatos.Contar() >= 25) {
        cout << "Se alcanzó el máximo de 25 candidatos." << endl;
        return;
    }

    // Crear e insertar el candidato en la cola
    //Candidato nuevoCandidato(cedula, nombre, apellido, idPartido);
    //cand.setEstatusInicial();
    candidatos.InsertarNodoCola(cand);

    candidatosPorPartido[cand.getIdPartido()]++;
    cout << "Candidato inscrito exitosamente." << endl;
}


void Inscripcion::EliminarCandidato(string cedCandidato)
{

	Candidato candAux, marca;
	bool encontrado = false;
	//bool candEliminado = false;
	marca = CrearMarca();

	//lista temporal para almacenar los candidatos que no fueron eliminados
	Lista<Candidato> temp;

	if (candidatos.Llena())
	{
		//insertamos un marcador al final para marcar el final de la cola
		candidatos.InsertarNodoCola(marca);

		while (!encontrado)
		{
			//Remueve al primer candidato de la cola y se guarda en la cola temporal
			candidatos.RemoverNodoCola(candAux);

			//Si la cedula del candidto en la cola temporal es igual a la cedula de la marca
			//entonces encontramos el marcador en la cola orignal
			//significa que hemos terminado de recorres la cola y salimos del bucle
			if (candAux.getCedula() == marca.getCedula())
			{
				encontrado = true;
			}
			else
			{
				//en caso contrario,si la cedula del candidato actual tiene la ced 
				//que queremos eliminar
				if (candAux.getCedula() == cedCandidato)
				{
					cout << "\n\nCandidato eliminado\n\n";
					encontrado = true; //se indica que lo encontramos y no lo volvemos a insertar
					//en la cola original
					candidatosPorPartido[candAux.getIdPartido()]; // Actualizamos el contador de candidatos por partido
				}
				else
				{
					//si no es el candidato que queremos eliminar, se reinserta al final de la cola
					temp.InsertarNodoCola(candAux);
				}
			}
		}

		 // Ahora reinserta todos los candidatos de la cola temporal a la cola original en el orden original
    	while (!temp.Vacia()) {
        
        temp.RemoverNodoCola(candAux);
		candidatos.InsertarNodoCola(candAux);
    	}
	}

	if (!encontrado) {
        cout << "Candidato no encontrado." << endl;
    }

}

void Inscripcion::MostrarCandidatos() {
        nodo<Candidato>* actual = candidatos.ObtPrimero();
        if (!actual) {
            cout << "No hay candidatos inscritos en la cola." << endl;
            return;
        }

        cout << "Candidatos inscritos:" << endl;
		while (actual) {
        Candidato candidatoActual = candidatos.ObtInfo(actual); // Usar ObtInfo aquí
        candidatoActual.mostrarInformacion(); // Mostrar la información del candidato
        actual = candidatos.ObtProx(actual); // Mover al siguiente nodo
    }
}
    