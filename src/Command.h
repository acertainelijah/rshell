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
#include <sys/stat.h>
//#include <errno.h>

class Command : public CommandPrompt { 	//Leaf that will execute command + arguments
  private:
    //data
    vector<string> input; 		//vector of string of command + arguments
    char** inputArray;
    bool ifFailed;
    
    //functions
    void parseInput() {
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
    
    void testCommand() {
      // const char* path = input.at(input.size() - 1).c_str();
      const char* path;
      if (input.at(0) == "test") {
        path = input.at(input.size() - 1).c_str();
      } 
      else if (input.at(0) == "[") {
        path = input.at(input.size() - 2).c_str();
      }
      //char** path = inputArray;
      struct stat s;
        if( stat(path,&s) == 0 ) //TODO what is path?
        {
          
          if (input.at(1) == "-d" || input.at(1) == "-f") {
           
            if( s.st_mode & S_IFDIR && input.at(1) == "-d")      // -d
            {
                //it's a directory
                cout << "(True)" << endl;
                cout << "Its a directory" << endl;
            }
            else if( s.st_mode & S_IFREG && input.at(1) == "-f") // -f
            {
                //it's a file
                cout << "(True)" << endl;
                cout << "Its a file" << endl;
            }
            else
            {
                //something else
                ifFailed = true;
                cout << "(False)" << endl;
            }
          }
          else { // no flag
            cout << "(True)" << endl;
          }
        }
        else {
            ifFailed = true;
            cout << "(False)" << endl;
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
      if (input.at(0) == "test" || (input.at(0) == "[" && input.at(input.size()-1) == "]") ) { // if "test" command
        this->testCommand();    ///runs test command 
      }
      else {                          // all other commands
        this->parseInput();           //parses input to command and arguments
        //test code start
        pid_t childPID = fork();
        if(childPID < 0){             //fork pid error
          perror("Fork Error");
          exit(-1);                   //exits program TODO is this appropriate action?
        }
        if(childPID > 0) {            //fork pid parent
         wait(NULL); 
        }
        if(childPID == 0) { //fork pid child
          if (execvp (inputArray[0], inputArray) == -1) {     //1st arg command (turned into c string), 2nd arg arguments
            perror("exec");
            ifFailed = true;
          }
        }
      }
    }
  
   bool commandFailed() {return this->ifFailed;}  //returns if command has failed or not

};



#endif
