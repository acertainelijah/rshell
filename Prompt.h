#ifndef _PROMPT_H_
#define _PROMPT_H_
#include "CommandPrompt.h"

class Prompt : public CommandPrompt { //Leaf that simply displays the prompt 

  public:
    Prompt(){};
    void execute() {
		cout << "$ ";		//simply displays prompt
    }

};

#endif
