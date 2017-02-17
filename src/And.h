#ifndef _AND_H_
#define _AND_H_

#include "CommandPrompt.h"
#include "Connector.h"

class And : public Connector {              // class for executing the right command if and ONLY
                                            //if the left command executes properly.

  public:
    And(){};
    And(CommandPrompt* l, CommandPrompt* r){
      left = l;
      right = r;
    }
    void execute(){                         //executes the right command if and only if
      left->execute();                      //left command successfully executes.
      if(!left->commandFailed()){           //if left command doesnt fail
        right->execute();                   //execute right.
      }
      return;
    }
    bool commandFailed(){
      if(left->commandFailed() || right->commandFailed()){            //if left fails, connector fails.
        return true;                                                  //function to determine whether the connector
      }
      return false;                                                   //failed or if it passed.
    }

  private:
    CommandPrompt* left;                    //left command
    CommandPrompt* right;                   //right command

};

#endif