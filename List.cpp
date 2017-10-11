class List{

private:
     
    char popStack,readDate;
    string pushStack;
    List *rule;

public:
    List(){
        rule = NULL;
    }

    List(char readDate, char popStack, string pushStack){
        this->readDate = readDate;
        this->popStack = popStack;
        this->pushStack = pushStack;
        rule = NULL;
    }

    char getReadDate(){
        return readDate;
    }


    string getPushStack(){
        return pushStack;
    }

    List *getRule(){
        return rule;
    }
    
     char getPopStack(){
        return popStack;
    }

    void setRule(List *rules){
        rule = rules;
    }

};