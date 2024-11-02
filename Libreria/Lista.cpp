#include "Lista.h"


template <class Tipo>
nodo<Tipo>* Lista<Tipo>::ObtPrimero() {
  return Primero;          
};

template <class Tipo>
void Lista<Tipo>::AsigPrimero(nodo<Tipo>* p){
     Primero=p;
};

template <class Tipo>
Lista<Tipo>::Lista()
{
     Primero=NULL;
};

template <class Tipo>
Lista<Tipo>::Lista(const Lista<Tipo> &that)
{
	Apuntador p;
	Apuntador thatP;
	while(!Vacia()){
		p = Primero->prox;
		delete Primero;
		Primero = p;
	}

	if(that.Primero != NULL){
		thatP = that.Primero;
		InsComienzo(thatP->info);
		thatP = thatP->prox;
		p = ObtPrimero();
		while(thatP != NULL)
		{
			Apuntador nuevo;
			if (!Llena()){
	               nuevo=new nodo<Tipo>;
	               nuevo->info=thatP->info;
	               nuevo->prox=p->prox;
	               p->prox=nuevo;
	               p = p->prox;
			}
			thatP = thatP->prox;
		}
	}
};

template <class Tipo>
Lista<Tipo>& Lista<Tipo>::operator= (const Lista<Tipo> &that)
{
	if(this != &that){
		Apuntador p;
		Apuntador thatP;

		while(!Vacia()){
			p = Primero->prox;
			delete Primero;
			Primero = p;
		}

		if(that.Primero != NULL){
			thatP = that.Primero;
			InsComienzo(thatP->info);
			thatP = thatP->prox;
			p = ObtPrimero();
			while(thatP != NULL)
			{
				Apuntador nuevo;
				if (!Llena()){
		               nuevo=new nodo<Tipo>;
		               nuevo->info=thatP->info;
		               nuevo->prox=p->prox;
		               p->prox=nuevo;
		               p = p->prox;
				}
				thatP = thatP->prox;
			}
		}
	}
	return *this;
};

template <class Tipo>
bool Lista<Tipo>::Vacia()
{
  return Primero == NULL;
};

template <class Tipo>
bool Lista<Tipo>::Llena()
{
  nodo<Tipo> *p;
  p=new nodo<Tipo>;
  if (p==NULL)
     return true;
  else
    { 
      delete p;
      return false;       
    }   
};  

//metodo para pilas y
template <class Tipo>
bool Lista<Tipo>::InsComienzo(Tipo Valor)
{
  Apuntador nuevo;
  if (!Llena()) 
     {
      nuevo=new nodo<Tipo>;
      nuevo->info=Valor;
      nuevo->prox=Primero;
      Primero=nuevo;
      return true;
     }
  else
      return false;    
};

template <class Tipo>
bool Lista<Tipo>::EliComienzo(Tipo &Valor)
{
  Apuntador viejo;
  if (!Vacia()) 
     {
      viejo=Primero;          
      Valor=viejo->info;
      Primero=Primero->prox;
      delete viejo;
      return true;
     }
  else
      return false;    
};

template <class Tipo>
bool Lista<Tipo>::InsDespues(Apuntador p,Tipo Valor)
{
  Apuntador nuevo;
  if (!Llena())      
      if (p==NULL)
         return false;
      else
         {          
               nuevo=new nodo<Tipo>;
               nuevo->info=Valor;
               nuevo->prox=p->prox;
               p->prox=nuevo;
               return true;
         }
  else
      return false;    
};

template <class Tipo>
bool Lista<Tipo>::EliDespues(Apuntador p,Tipo &Valor)
{
  Apuntador viejo;  
     if (p==NULL)
         return false;
     else
        if (p->prox==NULL)
           return false;
        else   
             {                
                   viejo=p->prox;          
                   Valor=viejo->info;
                   p->prox=viejo->prox;
                   delete viejo;
                   return true;
             };
};

template <class Tipo>
nodo<Tipo>* Lista<Tipo>::ObtProx(Apuntador p)
{
  return p->prox;        
};         

template <class Tipo>
void Lista<Tipo>::AsigProx(Apuntador p,Apuntador q)
{
  p->prox=q;
};         

template <class Tipo>
Tipo Lista<Tipo>::ObtInfo(Apuntador p)
{
  return p->info;
};         

template <class Tipo>
void Lista<Tipo>::AsigInfo(Apuntador p,Tipo Valor)
{
  p->info=Valor;
};         
template <class Tipo>
Lista<Tipo>::~Lista()
{
  nodo<Tipo> *p;
  while (!Vacia())
   {
        p=Primero->prox;
        delete Primero;
        Primero=p;
   };
};

template <class Tipo>
int Lista<Tipo>::Contar(){
	nodo<Tipo>* p;
	int cont = 0;
	p = Primero;
	while(p != NULL){
		cont++;
		p = p->prox;
	}
	return cont;
}

template <class Tipo>
nodo<Tipo>* Lista<Tipo>::Buscar(Tipo Valor)
{
	nodo<Tipo> *aux =NULL;
	Apuntador ap;
	if(ap!=NULL){
		aux=ap;
		while(aux !=NULL){
			if (aux->info==Valor){
				return aux;
			}
			aux = aux->prox;
		}
	}

}

template <class Tipo>
void Lista<Tipo>::pasarListaAux(Lista<Tipo> &listaFuente, Lista<Tipo> &listaDestino) {
	Tipo valor;
	int tamano = 0;
	tamano = listaFuente.Contar();
	for(int i = 0; i < tamano; i++){
		listaFuente.EliComienzo(valor);
		listaDestino.InsComienzo(valor);
	}
}
template <class Tipo>
bool Lista<Tipo>::RemoverNodoCola(Tipo &Valor)
{
     Apuntador viejo;
     if (!Vacia())//Cola no vacia
     {
          viejo = Primero;
          Valor = viejo->info;
          Primero = viejo->prox;
          if (Primero == NULL)//Su se elimina el ultimo nodo
               Final = NULL;
          delete viejo;
          return true;
     }
     else
          return false;
};

template <class Tipo>
bool Lista<Tipo>::InsertarNodoCola(Tipo Valor)
{
     Apuntador nuevo;
     if (!Llena())//Cola no vacia
     {
          nuevo=new nodo<Tipo>;
          nuevo->info = Valor;
          nuevo->prox = NULL;
          if (Final == NULL)//Cola esta vacía
               Primero = nuevo;
          else
               Final->prox = nuevo;
          Final = nuevo;
          return true;
     }
     else
          return false;//Memoria insuficiente
};
