#ifndef _COMMANDPROMPT_H_
#define _COMMANDPROMPT_H_

class CommandPrompt { //BASE CLASS FOR OUR COMPOSITE PATTERN

  public:
    CommandPrompt(){};
    virtual void execute() = 0;

};

#endif
