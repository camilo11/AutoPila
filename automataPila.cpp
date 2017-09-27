#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct nodo{
 
    char a;//campo donde se almacenara el caracter
    struct nodo *sgte;
};
 
typedef struct nodo *pila;
 
/*---------------Funcion para Apilar un Caracter--------*/
void apila(pila &p,const char a){
 
    pila q=new (struct nodo) ;
    q->a=a;
    q->sgte=p;
    p=q;
 }
 
/*------------- Funcion para Desapilar un elemento -----*/
void desapila(pila &p){
 
    int n=p->a;
 
    pila q=p;
    p=p->sgte;
    delete(q);
}




class Vertice{
    protected:
        string nombre;
        int numVert;
    public:
        Vertice(){}
        Vertice(string x){
            nombre=x;
            numVert=-1;
        }
        Vertice(string x, int n){
            nombre=x;
            numVert=n;
        }
        bool igual(string x){
            return x==nombre;
        }
        string getNombre(){
            return nombre;
        }
        void setNombre(string x){
            nombre=x;
        }
        int getNum(){
            return numVert;
        }
        void setNum(int n){
            numVert=n;
        }
};




