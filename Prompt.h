#ifndef _PROMPT_H_
#define _PROMPT_H_
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <vector>
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

      // for(unsigned i = 0; i < parsedUserInput.size(); ++i){
      //   cout << parsedUserInput.at(i) << endl;
      // }

      CommandPrompt* object = new Command(parsedUserInput);
      object->execute();

    }

  }
  bool commandFailed(){
    return false;
  }

};

#endif
