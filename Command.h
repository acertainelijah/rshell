#ifndef _COMMAND_H_
#define _COMMAND_H_
#include "CommandPrompt.h"
#include <vector>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

class Command : public CommandPrompt { 	//Leaf that will execute command + arguments
  private:
    //data
    vector<string> input; 		//vector of string of command + arguments
    char** inputArray;
    bool ifFailed;
    vector<string> flags;		  //vector of different flags for commands ***Is this needed for this assn? ***is this list of possible flags or list of flags within the string command?
    //functions
    void parseInput() {
      if(input.size() == 0) {
        //size error
      }
      else if (input.at(0) == "exit") {   //exits program if command is exit
        cout << "Terminating program... Goodbye!" << endl;
        exit(-1); //exit? or just exit out of class? return out of execute?
      }
      else {
          for(unsigned i = 0; i < input.size(); i++){
            inputArray[i] = (char*)input.at(i).c_str();
          }
      }
    }
  public:
    Command(){};

    Command(vector<string> input) {
      this->input = input;
      inputArray = new char*[input.size()];
      ifFailed = false;
    };

    void execute() { 			    //runs command
      this->parseInput();   //parses input to command and arguments
      //test code start
      pid_t childPID = fork();
      if(childPID < 0){   //fork pid error
        perror("Fork Error");
        exit(-1);         //exits program TODO is this appropriate action?
      }
      if(childPID > 0) {  //fork pid parent
       wait(NULL); //TODO waitpid()???
      }
      if(childPID == 0) { //fork pid child
        if (execvp (inputArray[0], inputArray) == -1) {     //1st arg command (turned into c string), 2nd arg arguments
          perror("exec");
          ifFailed = true;
          cout << "error!" << endl;
        }
      }
    }

   bool commandFailed() {return this->ifFailed;}  //returns if command has failed or not

};



#endif
