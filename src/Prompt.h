#ifndef _PROMPT_H_
#define _PROMPT_H_
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>
#include "CommandPrompt.h"

class Prompt : public CommandPrompt { //Leaf that simply displays the prompt

private:
  string userInput;
  vector<string> parsedUserInput;

public:
  Prompt(){};
  void execute() {
    char *name;                                         //declare the name variable
    name = (char *)malloc(100*sizeof(char));
    getlogin_r(name, 100);                              //get user name
    char *hostname;                                     //declare hostname variable
    hostname = (char *)malloc(1000*sizeof(char));
    gethostname(hostname, 1000);                        //gets the host name

    bool commentFound = false;

    while(true){

      parsedUserInput.clear();

      cout << name << '@' << hostname << "$ ";		      //simply displays prompt

      getline(cin, userInput);
      stringstream ss(userInput);

      while(ss){
        string sub;
        ss >> sub;
        parsedUserInput.push_back(sub);
      }

      parsedUserInput.pop_back();
      
      vector<string> temp;

      for(unsigned i = 0; i < parsedUserInput.size(); ++i){
        if(parsedUserInput.at(i).find("#") != string::npos){ //comments
          break;
        }
        else {
          temp.push_back(parsedUserInput.at(i));
        }
      }
      CommandPrompt* object = new Command(temp);
      object->execute();

    }

  }
  bool commandFailed(){
    return false;
  }

};

#endif
