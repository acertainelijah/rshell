#ifndef _CONNECTOR_H_
#define _CONNECTOR_H_

#include "CommandPrompt.h"

class Connector : public CommandPrompt { //holds children(commands) for executing left and right
                                        //of the connector.
  public:
    Connector(){};
    Connector(CommandPrompt* a, CommandPrompt* b){
      left = a;
      right = b;
    } //SETS THE CHILDREN UP
    virtual void execute() = 0;
    virtual bool commandFailed() = 0;
    virtual void setLeft(CommandPrompt* l) = 0;
    virtual void setRight(CommandPrompt* r) = 0;
  private:
    //LEFT AND RIGHT CHILDREN FOR THE COMMANDS TO EXECUTE
    CommandPrompt* left; //left command
    CommandPrompt* right; //right command

};

#endif