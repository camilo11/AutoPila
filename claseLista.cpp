 class list{
 private:
 	char readDate;
 char popStack;
 string pushStack;
 list *rule;
 public:
 	list(){
	 rule = NULL;
	 
	 
	 }
	 list(char readDate, char popStack, string pushStack){
	 this->readDate = readDate;
	 this->popStack = popStack;
	 this->pushStack = pushStack;
	 rule = NULL;
	 
	 }
 char getReadDate(){
 	return readDate;
 }
 
 char getPopStack(){
 	
 	return popStack;
 }
 
 string getPushStack(){
 	return pushStack;
 }
 
 list *getRule(){
 	
 	return rule;
 }
 
 void setRule(list *otherRule){
 
 rule = otherRule;
 }
}; 
 