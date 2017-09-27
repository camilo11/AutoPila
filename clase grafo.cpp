class GrafoMatriz{
    protected:
        int maxVerts;
        int numVerts;
        Vertice *verts;
        int **matAd;
    public:
        GrafoMatriz(){
            maxVerts=1;
            GrafoMatriz(maxVerts);
        }
        GrafoMatriz(int mx){
            maxVerts=mx;
            verts = new Vertice[mx];
            matAd= new int* [mx];
            numVerts=0;
            for(int i=0;i<mx;i++){
                matAd[i]=new int[mx];
                for(int j=0;j<mx;j++){
                    matAd[i][j]=0;
                }
            }
        }
        int getNumVerts(){
            return numVerts;
        }
        void setNumVerts(int n){
            numVerts=n;
        }
        int getMaxVerts(){
            return maxVerts;
        }
        int numVertice(string nom){
            int i;
            bool encontrado=false;
            for(i=0;(i<numVerts)&&!encontrado;){
                encontrado=verts[i].igual(nom);
                if(!encontrado){
                    i++;
                }
            }
            if(i<numVerts){
                return i;
            }else{
                return -1;
            }
        }
        void nuevoVertice(string nom){
            bool esta=numVertice(nom)>=0;
            if(!esta){
                Vertice v= Vertice(nom,numVerts);
                verts[numVerts++]=v;
            }else{
                cout<<"no se puede insertar"<<endl;
            }
        }
        void nuevoArco(string a, string b){
            int va,vb;
            va=numVertice(a);
            vb=numVertice(b);
            if(va<0||vb<0){
                cout<<"Vertice no existe";
            }else{
                matAd[va][vb]=1;
            }
        }
        void nuevoArco(string a, string b,int val){
            int va,vb;
            va=numVertice(a);
            vb=numVertice(b);
            if(va<0||vb<0){
                cout<<"Vertice no existe";
            }else{
                matAd[va][vb]=val;
            }
        }
        void nuevoArco(int va, int vb){
            if(va<0||vb<0||va>numVerts||vb>numVerts){
                cout<<"Vertice no existe";
            }else{
                matAd[va][vb]=1;
            }
        }
        void nuevoArco(int va, int vb,int val){
            if(va<0||vb<0||va>numVerts||vb>numVerts){
                cout<<"Vertice no existe";
            }else{
                matAd[va][vb]=val;
            }
        }
        bool adyacente(string a, string b){
            int va=numVertice(a);
            int vb=numVertice(b);
            if(va<0||vb<0){
                cout<<"Vertice no existe";
            }else{
                return matAd[va][vb]>=1;
            }
        }
        bool adyacente(int a, int b){
            if(a<0||b<0||a>numVerts||b>numVerts){
                cout<<"Vertice no existe";
                return false;
            }else{
                return matAd[a][b]>=1;
            }
        }
        int getValor(int a, int b){
            if(a<0||b<0||a>numVerts||b>numVerts){
                cout<<"Vertice no existe";
                return -1;
            }else{
                return matAd[a][b];
            }
            
        }
    
        int getValor(string a, string b){
            int va ,vb;
            va=numVertice(a);
            vb=numVertice(b);
            if(va<0||vb<0){
                cout<<"Vertice no existe";
                return -1;
            }else{
                return matAd[va][vb];
            }   
        }
        void setValor(int a, int b, int v){
            if(a<0||b<0||a>numVerts||b>numVerts){
                cout<<"Vertice no se puede crear"<<endl;
            }else{
                matAd[a][b]=v;
            }
        }
        
        void setValor(string a, string b, int v){
            int va ,vb;
            va=numVertice(a);
            vb=numVertice(b);
            if(va<0||vb<0||va>numVerts||vb>numVerts){
                cout<<"Vertice no se puede crear"<<endl;
            }else{
                matAd[va][vb]=v;
            }       
        }
        Vertice getVertice(int va){
            if(va<0||va>=numVerts){
                cout<<"Vertice no existe"<<endl;
            }else{
                return verts[va];
            }
        }
        void setVertice(int a, Vertice v){
            if(a<0||a>numVerts){
                cout<<"Vertice no existe "<<endl;
            }else{
                verts[a]=v;
            }
        }
        void imprimir(){
            cout<<"Numero de estados{";
            for(int i=0;i<numVerts;i++){
                cout<<"["<<verts[i].getNombre()<<"]";
            }
            cout<<"}"<<endl;
        }
        void impMatAD(){
            cout<<"MatAd"<<endl;
            for(int i=0;i<numVerts;i++){
                for(int j=0;j<numVerts;j++){
                    cout<<"[";
                    if(matAd[i][j]==0){
                        cout<<setfill(' ')<<setw(3)<<" ";
                    }else{
                        cout<<setfill(' ')<<setw(3)<<matAd[i][j];
                    }
                    cout<<"]";
                }
                cout<<endl;
            }
        }
        //matriz de 
        void impMatAdFor(){
            cout<<"A {";
            for(int i=0;i<numVerts;i++){
                for(int j=0;j<numVerts;j++){
                        if(matAd[i][j]>=1){
                            cout<<"("<<verts[i].getNombre()<<", "<<verts[j].getNombre()<<"),";
                        }
                }   
            }
            cout<<"}"<<endl;
        }   

