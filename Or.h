#ifndef _OR_H_
#define _OR_H_

#include "CommandPrompt.h"
#include "Connector.h"

class Or : public Connector { //connector class that executes the right command if
                              //and only if the left command fails.

  public:
    Or(){};
    Or(CommandPrompt* l, CommandPrompt* r){
      left = l;
      right = r;
    }
    void execute(); //execute right command only if the left fails to execute.
  private:
    CommandPrompt* left; //left command
    CommandPrompt* right; //right command

};

#endif
