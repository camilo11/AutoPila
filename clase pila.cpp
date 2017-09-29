using namespace std;

struct nodo{
 
    char a;//campo donde se almacenara el caracter
    struct nodo *sgte;
};
 typedef struct nodo *Puntero;

class Pila{
	
	 public:
        Pila(void);
        void Apilar(char );
        int Desapilar(void );
        bool PilaVacia(void);
        void MostrarPila(void);
        
 
    private:
        Puntero cima;
};

Pila::Pila(void){
    cima="";
}

void Pila::Apilar(char x){
 
    Puntero aux;
    aux=new(struct nodo);
    aux->a=x;
    aux->sgte=cima;
    cima=aux;
 
}

int Pila::Desapilar(void){
    char x;
    Puntero aux;
    if(cima=="")
        cout<<"\n\n\tPila Vacia...!!";
    else{
        aux=cima;
        x=aux->a;
        cima=cima->sgte;
        delete(aux);
    }
    return x;
}

bool Pila::PilaVacia(void){
    if(cima=="")
        return true;
    else
        return false;
}

void Pila::MostrarPila(void){
    Puntero aux;
    aux=cima;
 
    while(aux!=""){
        cout<<"\t "<<aux->a<<endl;
        aux=aux->sgte;
    }
}
