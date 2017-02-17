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
    void execute(){                         //executes the right command regardless
      left->execute();                      //of the left command
      right->execute();
      return;
    }
    bool commandFailed(){
      if(right->commandFailed()){           //if right fails, connector fails.
        return true;                        //function to determine whether the connector
      }
      return false;                         //failed or if it passed.
    }


  private:
    CommandPrompt* left;
    CommandPrompt* right;

};

#endif