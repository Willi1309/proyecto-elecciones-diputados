
#ifndef Inscripcion_H
#define Inscripcion_H
#include <string>
#include "Candidato.h"
using namespace std;

class Inscripcion {

   private:
   	Lista<Candidato> candidatos;
    int candidatosPorPartido[5] = {0};  

   public:
    // Constructor
    Inscripcion();

    Candidato CrearMarca();
    // Metodo para registrar un candidato
    void RegistrarCandidato(Candidato);

    //Método para eliminar un candidato
    void EliminarCandidato(string);

    void MostrarCandidatos();
    
};

#endif
