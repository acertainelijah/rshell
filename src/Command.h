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
//#include <errno.h>

class Command : public CommandPrompt { 	//Leaf that will execute command + arguments
  private:
    //data
    vector<string> input; 		//vector of string of command + arguments
    char** inputArray;
    bool ifFailed;
    
    //functions
    void parseInput() {
      //cout << "Input.at(0): " << input.at(0) << endl;
      if(input.size() == 0) {
        cout << "Nothing in vector<string>!" << endl;
      }
      else if (input.at(0) == "exit") {   //exits program if command is exit
        exit(-1); //exit? or just exit out of class? return out of execute?
      }
      else {
          for(unsigned i = 0; i < input.size(); i++){
            inputArray[i] = (char*)input.at(i).c_str();
          }
          inputArray[input.size()] = NULL; //null terminated array
      }
    }   
    
  public:
    Command(){};
    
    Command(vector<string> input) {
      this->input = input;
      inputArray = new char*[input.size() + 1];
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
        }
      }
    }
    
   bool commandFailed() {return this->ifFailed;}  //returns if command has failed or not

};



#endif
