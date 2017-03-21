#ifndef _COMMANDPROMPT_H_
#define _COMMANDPROMPT_H_
#include <iostream>
#include <vector>

using namespace std;

class CommandPrompt { //BASE CLASS FOR OUR COMPOSITE PATTERN

  public:
    CommandPrompt(){};
    virtual void execute() = 0;
    virtual bool commandFailed() = 0;
    virtual void setLeft(CommandPrompt* l) {};
    virtual void setRight(CommandPrompt* r) {};
    virtual CommandPrompt* getLeft() { return NULL; } ;
    virtual CommandPrompt* getRight() { return NULL; } ;
    virtual char** InputArray() {return NULL;} ;
    // virtual char** fileNameArray() {};
    virtual string fileNameString() { return "";} ;

};

#endif