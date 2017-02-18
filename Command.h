#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "CommandPrompt.h"
#include <vector>
#include <string>

class Command : public CommandPrompt { 	//Leaf that will execute command + arguments
  private:
    string command; 			//string of the command to be executed
    vector<string> flags;		//vector of different flags for commands ***Is this needed for this assn? ***is this list of possible flags or list of flags within the string command?
  public:
    Command(){};
    void execute() { 			//runs command
	//TODO
    }

};

//askdjhfaskldhflkadshflkash

#endif
