class acceptance{
	private:
	bool accept;
	string state;
	transition *listTransition;
	acceptance *next;
	
	public:
	acceptance(string state, bool acceptance){
		this->accept = accept;
			this->state = state;
			listTransition = NULL;
			next = NULL;
	}	
	
	
	bool getAccept(){
			return accept;
		}
		
			string getState(){
			return state;
		}
	
	
	transition *getListTransition(){
			return listTransition;
		}
		
		void setNext(acceptance *next){
			this->next = next;
		}
		
		acceptance *getNext(){
			return next;
		}
	
	transition *getTransition(string state){
    	transition *listAssistant = listTransition;
        	while(listAssistant != NULL){
            	if(listAssistant->getStateTransition() == state){
            	    return listAssistant;
            	}
            	listAssistant = listAssistant->getNext();
        	}
        	return NULL;
		}
		
			transition *stateTransition(string state){
        	transition *listAssistant = listTransition;
        	while(listAssistant != NULL){
            	if(listAssistant->getStateTransition() == state){
            	    return listAssistant;
            	}
            	listAssistant = listAssistant->getNext();
        	}
        	return NULL;
    	}
    	
    	bool aggRule  (string arrival, char read, char popStack, string pushStack){
		transition *transitionAssistant = stateTransition(arrival);
		if(transitionAssistant != NULL){
			transitionAssistant->aggRule(new list(read, popStack, pushStack));
			return true;
		}else{
			false;
		}
	}
	
	void aggTransition(transition *transition){
        if(listTransition != NULL){
            if(stateTransition(transition->getStateTransition()) == NULL){
				transition->setNext(listTransition);
				listTransition = transition;

            }
        }else{
            listTransition = transition;
        }
	}
	
	void showTransition(){
        transition *listAssistant = listTransition;
        while(listAssistant != NULL){
            cout<<"["<<listAssistant->getStateTransition()<<"]"<<endl;
            listAssistant = listAssistant->getNext();
        }
	}
	
	void showRule(string departure, string arrival){
		transition *transitionAssistant = stateTransition(arrival);
		if(transitionAssistant != NULL){
			list *listRulesAssistant = transitionAssistant->getListRule();
			while(listRulesAssistant != NULL){
				cout<<listRulesAssistant->getReadDate()<<"/"<<listRulesAssistant->getPopStack()<<"/"
				<<listRulesAssistant->getPushStack()<<endl;
				listRulesAssistant = listRulesAssistant->getRule();
			}
			
		}
	}
	
	
};