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
    char name[100];                                 //declare the name variable
    getlogin_r(name, 100);                          //get user name
    char *hostname;                                 //declare hostname variable
    hostname = (char *)malloc(1000*sizeof(char));
    gethostname(hostname, 1000);                    //gets the host name

    while (true){

      parsedUserInput.clear();
      cout << name << '@' << hostname << "$ ";		  //simply displays prompt

      getline(cin, userInput);
      stringstream ss(userInput);

      while (ss){
        string sub;
        ss >> sub;
        parsedUserInput.push_back(sub);
      }

      parsedUserInput.pop_back();

      vector<string> revisedUserInput;
      revisedUserInput.clear();

      for (unsigned i = 0; i < parsedUserInput.size(); ++i){
        if (parsedUserInput.at(i).find("#") != string::npos){ // stops at comment
          break;
        }
        else if (parsedUserInput.at(i).find(";") != string::npos){
          revisedUserInput.push_back(parsedUserInput.at(i).substr(0, parsedUserInput.at(i).find(";"))); //characters before ;
          revisedUserInput.push_back(";");
          if (parsedUserInput.at(i).at(parsedUserInput.at(i).size() - 1) != ';') {
            revisedUserInput.push_back(parsedUserInput.at(i).substr(parsedUserInput.at(i).find(";") + 1)); //characters after ;
          }
        }
        else {
          revisedUserInput.push_back(parsedUserInput.at(i));
        }
      }

      //begin tree hierarchy
      vector<string> commandInput;
      vector<CommandPrompt*> tree;
      CommandPrompt* tempLeft = NULL;
      CommandPrompt* tempRight = NULL;
      commandInput.clear();
      tree.clear();

      for (unsigned i = 0; i < revisedUserInput.size(); ++i){ //search through parsed input for connectors.
        //if last element
        if (i == revisedUserInput.size() - 1) {
          commandInput.push_back(revisedUserInput.at(i));
          if (tree.empty()) {
            tree.push_back(new Command(commandInput));
          }
          else {
            tree.back()->setRight(new Command(commandInput));
          }
          commandInput.clear();     //clears commandInput for other commands
        }
        else if (revisedUserInput.at(i) == "&&"){                  //if one is found, create new connector and create children for it.
          if (tree.empty() && tempLeft == NULL) {
            tempLeft = new Command(commandInput); //sets tempLeft child to && command
            commandInput.clear();     //clears commandInput for other commands
          }
          else {  //if connectore has no left and the list is not empty
            tempLeft = tree.back();
            tree.pop_back();
          }
          tree.push_back(new And());
          tree.back()->setLeft(tempLeft); //sets AND left to tempLeft
        }
        else if (revisedUserInput.at(i) == "||"){                  //if one is found, create new connector and create children for it.
          if (tree.empty() && tempLeft == NULL) {
            tempLeft = new Command(commandInput); //sets tempLeft child to || command
            commandInput.clear();     //clears commandInput for other commands
          }
          else {  //if connectore has no left and the list is not empty
            tempLeft = tree.back();
            tree.pop_back();
          }
          tree.push_back(new Or());
          tree.back()->setLeft(tempLeft); //sets OR left to tempLeft
        }
        else if (revisedUserInput.at(i) == ";"){                  //if one is found, create new connector and create children for it.
          if (tree.empty() && tempLeft == NULL) {
            tempLeft = new Command(commandInput); //sets tempLeft child to && command
            commandInput.clear();     //clears commandInput for other commands
          }
          else {  //if connector has no left and the list is not empty
            tempLeft = tree.back();
            tree.pop_back();
          }
          tree.push_back(new Semicolon());
          tree.back()->setLeft(tempLeft); //sets AND left to tempLeft
        }
        else if (tempLeft != NULL && ( (revisedUserInput.at(i + 1) == "&&") || (revisedUserInput.at(i + 1) == "||") || (revisedUserInput.at(i + 1) == ";") ) ) {
            commandInput.push_back(revisedUserInput.at(i));
            tempRight = new Command(commandInput);
            commandInput.clear();
            tree.back()->setRight(tempRight);
            tempLeft = NULL;
            tempRight = NULL;
          }
        else{ //if not a connector string
          commandInput.push_back(revisedUserInput.at(i));
        }
      }
      //end tree hierarchy

      //begin execution
      for (unsigned i = 0; i < tree.size(); i++) {
        tree.at(i)->execute();
      }
      //end execution
    }

  }
  bool commandFailed(){
    return false;
  }

};

#endif
