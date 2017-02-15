#ifndef _AND_H_
#define _AND_H_

#include "CommandPrompt.h"
#include "Connector.h"

class And : public Connector { // class for executing the right command if and ONLY
                              //if the left command executes properly.

  public:
    And(){};
    And(CommandPrompt* l, CommandPrompt* r){
      left = l;
      right = r;
    }
    void execute(); //EXECUTE RIGHT CHILD COMMAND IF AND ONLY IF THE LEFT COMMAND
                    //SUCCESSFULLY EXECUTES
  private:
    CommandPrompt* left; //left command
    CommandPrompt* right; //right command

};

#endif
