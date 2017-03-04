#ifndef _OR_H_
#define _OR_H_

#include "CommandPrompt.h"
#include "Connector.h"

class Or : public Connector {               //connector class that executes the right command if
                                            //and only if the left command fails.

  public:
    Or(){
      left = NULL;
      right = NULL;
    };
    
    Or(CommandPrompt* l, CommandPrompt* r){
      left = l;
      right = r;
    }
    
    void execute(){                         //executes the right command if and only if
      if (left == NULL) {
        return;
      }
      left->execute();                      //left command fails to execute.
      if (left->commandFailed()){            //if left command fails,
        if (right == NULL) {
          return;
        }
        right->execute();                   //execute right.
      }
      return;
    }
    
    bool commandFailed(){
      // if (right->commandFailed() || !left->commandFailed()){           //if the right fails, connector fails.
      //   return true;                                                  //function to determine whether the connector
      // }
      return right->commandFailed();                                                   //failed or if it passed.
    }
    
    void setLeft(CommandPrompt* l) {this->left = l;}
    
    void setRight(CommandPrompt* r) {this->right = r;}
    
  private:
    CommandPrompt* left; //left command
    CommandPrompt* right; //right command

};

#endif