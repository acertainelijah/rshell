#ifndef _SEMICOLON_H_
#define _SEMICOLON_H_

#include "CommandPrompt.h"
#include "Connector.h"

class Semicolon : public Connector {

  public:
    Semicolon(){};
    Semicolon(CommandPrompt* l, CommandPrompt* r){
      left = l;
      right = r;
    }
    void execute(); //EXECUTE RIGHT COMMAND REGARDLESS OF WHETHER OR NOT
                    //LEFT COMMAND SUCCESSFULLY EXECUTES

  private:
    CommandPrompt* left;
    CommandPrompt* right;

};

#endif
