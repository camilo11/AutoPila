class Graph{
	private:
		Vertex *vertes;
		string entryNode;

	public:
		Graph(){
			vertes = NULL;
			entryNode = "";
		}

		Vertex *location(string state){
        	Vertex *vertexAssistant = vertes;
        	while(vertexAssistant != NULL){
            	if(vertexAssistant->getState() == state){
            	    return vertexAssistant;
            	}
            	vertexAssistant = vertexAssistant->getNext();
        	}
        	return NULL;
    	}
	
	bool aggVertex(Vertex *verte){
        if(vertes != NULL){
            if(location(verte->getState()) == NULL){
                Vertex *vertexAssistant = vertes;
                while(vertes->getNext() != NULL){
                    vertes = vertes->getNext();
				}
				vertes->setNext(verte);
                vertes = vertexAssistant;

            }else{
				return false;
				delete(verte);
            }
        }else{
            vertes = verte;
		}
		return true;
	}

	bool thereEntryNode(){
		return !(entryNode == "");
	}

	string getEntryNode(){
		return entryNode;
	}
	
	bool selectEntryNode(string entryNode){
		if(this->entryNode == "" && location(entryNode) != NULL){
			this->entryNode = entryNode;
			return true;
		}
		return false;
	}

	void showVertex(){
        Vertex *vertexAsisstant = vertes;
        while(vertexAsisstant != NULL){
            cout<<"["<<vertexAsisstant->getState()<<"]"<<endl;
            vertexAsisstant = vertexAsisstant->getNext();
        }
    }


    bool relate(string origin, string arrival){
        Vertex *vertexAssistant = location(origin);

        if(vertexAssistant != NULL && location(arrival) != NULL){

            if(vertexAssistant->Relate(arrival) == NULL){
				vertexAssistant->aggRelate(new Transition(arrival));
				return true;
			}
			return false;
		}
		return false;
	}
	
	bool aggRule(string departure, string arrival, char readDate, char popStack, string pushStack){
		Vertex *vertexAssistant = location(departure);

		if(vertexAssistant != NULL && location(arrival) != NULL){
			return vertexAssistant->aggRule(arrival, readDate , popStack, pushStack);
		}
		return false;
	}

	bool check(string currentState, string read, Stack pila, bool entry = true){
		Vertex *vertexCurrent = location(currentState);
		Transition *relateCurrent = vertexCurrent->getListRelate();

		while(relateCurrent != NULL){
			List *listRule = relateCurrent->getRules();
			while(listRule != NULL){

				if(entry){
					if(listRule->getReadDate() == read[0]){
						for(int i = 0; i < listRule->getPushStack().length(); i++){
							pila.push(listRule->getPushStack()[i]);
						}
						if(read.length() == 1 && location(relateCurrent->getStateRelate())->getAccept() == true){
							return true;
						}
						bool accept = check(relateCurrent->getStateRelate(), 
						read.substr(1, read.length()), pila, false);
						if(accept){
							return true;
						}						

					}
				}else{
					if(!pila.empty()){
						Stack Assistant = pila;
						char date = pila.pop();						
						if(listRule->getReadDate() == read[0] && listRule->getPopStack() == date){
							for(int i = 0; i < listRule->getPushStack().length(); i++){
								Assistant.push(listRule->getPushStack()[i]);
							}

							if(read.length() == 1 && location(relateCurrent->getStateRelate())->getAccept()){
								return true; 
							}
							bool accept = check(relateCurrent->getStateRelate(), 
							read.substr(1, read.length()), Assistant, false);
							if(accept){
								return true;
							}
						}
						pila.push(date);
					}			
				}

				listRule = listRule->getRule();
			}

			relateCurrent = relateCurrent->getNext();
		}

	}

	bool showNodeRule(string departure, string arrival){
		Vertex *vertexAsssistant = location(departure);
		if(vertexAsssistant != NULL && location(arrival)){
			vertexAsssistant->showRule(departure, arrival);
			return true;
		}
		return false;
	}

        void showVertexRelate(){
        	Vertex *vertexAssistant = vertes;
        	while(vertexAssistant != NULL){
            	cout<<"["<<vertexAssistant->getState()<<"] relacionados: "<<endl;
            	vertexAssistant->showRelate();
            	cout<<endl;
            	cout<<"------"<<endl;
            	vertexAssistant = vertexAssistant->getNext();
        	}
    	}

};

