class Transition{
    
        private:		
       
        List *rules;
        Transition *next;
         string stateRelate;
    
        public:	
        
        Transition(){
            rules = NULL;
           next = NULL;
        }
        
        Transition(string stateRelate){
            this->stateRelate =  stateRelate;
            rules = NULL;
            next = NULL;
        }    
    
        string getStateRelate(){
            return stateRelate;
        }
        
        List *getRules(){
            return rules;
        }
        
        Transition *getNext(){
            return next;
        }
    
        void setNext(Transition *next){
            this->next = next;
        }
    
        void aggRule(List *rule){
            if(rules != NULL){
                rule->setRule(rules);
                rules = rule;
            }else{
                rules = rule;
            }
        }
    };