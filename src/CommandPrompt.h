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

};

#endif