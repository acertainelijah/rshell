#ifndef _PARENTHESIS_H_
#define _PARENTHESIS_H_
#include "CommandPrompt.h"
#include "Connector.h"

class Parenthesis : public CommandPrompt {
// class Parenthesis : public Connector {
    
    private:
        CommandPrompt* child;
        
    public:
        Parenthesis() {
            child = NULL;
        };
        Parenthesis(CommandPrompt* l){
            child = l;
        }
        void execute(){
            if(child != NULL) {
                child->execute();
            }
        }
        bool commandFailed(){
            return child->commandFailed();
        }
        void setChild(CommandPrompt* c) {
            child = c;
        }
        void setLeft(CommandPrompt* l)  { this->setChild(l); }
        void setRight(CommandPrompt* r) { this->setChild(r); }

};

#endif