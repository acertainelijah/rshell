#ifndef _PROMPT_H_
#define _PROMPT_H_
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include "CommandPrompt.h"
#include "Parenthesis.h"

class Prompt : public CommandPrompt { //Leaf that simply displays the prompt

protected:
  string userInput;
  vector<string> parsedUserInput;
  vector<CommandPrompt*> tree;
  // int numOpen = 0;
  // int numClosed = 0;
  //
  string newString;

public:
  Prompt(){};

  void execute() {
    char name[100];
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
<<<<<<< HEAD
      
      // cout << "testing" << endl;
      
=======

      // cout << "testing" << endl;

>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
      // for(unsigned e = 0; e < parsedUserInput.size(); ++e){
      //   cout << parsedUserInput.at(e) << endl;
      // }
      int numOpen = 0;
      int numClosed = 0;
      vector<string> revisedUserInput;
      revisedUserInput.clear();

      for (unsigned i = 0; i < parsedUserInput.size(); ++i){
        numOpen = 0;
        numClosed = 0;
        if (parsedUserInput.at(i).find("#") != string::npos){ // stops at comment
          break;
        }
        else if(parsedUserInput.at(i).size() == 1) {
          revisedUserInput.push_back(parsedUserInput.at(i));
        }
        else{ //if size > 1
          if (parsedUserInput.at(i).find(";") != string::npos){ // EXAMPLE: ls;
            revisedUserInput.push_back(parsedUserInput.at(i).substr(0, parsedUserInput.at(i).find(";"))); //characters before ;
            revisedUserInput.push_back(";");
            if (parsedUserInput.at(i).at(parsedUserInput.at(i).size() - 1) != ';') {
              revisedUserInput.push_back(parsedUserInput.at(i).substr(parsedUserInput.at(i).find(";") + 1)); //characters after ;
            }
<<<<<<< HEAD
          }
          else if (parsedUserInput.at(i).find("(") != string::npos || parsedUserInput.at(i).find(")") != string::npos){
            for(unsigned j = 0; j < parsedUserInput.at(i).size(); j++) {
              if(parsedUserInput.at(i).at(j) == '(') { //counts num open parenthesis in current string
                numOpen++; //aha my original design IS BEING USED #feelsgoodman
              }
              else if(parsedUserInput.at(i).at(j) == ')') { //counts num closed parenthesis in current string
                numClosed++; //aha my original design IS BEING USED #feelsgoodman
              }
            }
            
            for(unsigned j = 0; j < numOpen; j++){
              revisedUserInput.push_back("(");
            }
            newString = parsedUserInput.at(i).substr(numOpen, parsedUserInput.at(i).size() - numOpen - numClosed);
            revisedUserInput.push_back(newString);
            for(unsigned j = 0; j < numClosed; j++){
              revisedUserInput.push_back(")");
            }
          }
          else {
            revisedUserInput.push_back(parsedUserInput.at(i));
          }
          
=======
          }
          else if (parsedUserInput.at(i).find("(") != string::npos || parsedUserInput.at(i).find(")") != string::npos){
            for(unsigned j = 0; j < parsedUserInput.at(i).size(); j++) {
              if(parsedUserInput.at(i).at(j) == '(') { //counts num open parenthesis in current string
                numOpen++; //aha my original design IS BEING USED #feelsgoodman
              }
              else if(parsedUserInput.at(i).at(j) == ')') { //counts num closed parenthesis in current string
                numClosed++; //aha my original design IS BEING USED #feelsgoodman
              }
            }

            for(unsigned j = 0; j < numOpen; j++){
              revisedUserInput.push_back("(");
            }
            newString = parsedUserInput.at(i).substr(numOpen, parsedUserInput.at(i).size() - numOpen - numClosed);
            revisedUserInput.push_back(newString);
            for(unsigned j = 0; j < numClosed; j++){
              revisedUserInput.push_back(")");
            }
          }
          else {
            revisedUserInput.push_back(parsedUserInput.at(i));
          }

>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
          // else if (parsedUserInput.at(i).find("(") != string::npos && parsedUserInput.at(i).find(")") != string::npos){ // EXAMPLE: (ls)
          //   // revisedUserInput.push_back("(");
          //   // revisedUserInput.push_back(parsedUserInput.at(i).substr(parsedUserInput.at(i).find("(") + 1, parsedUserInput.at(i).size() - 2)); //word after (
          //   // revisedUserInput.push_back(")");
<<<<<<< HEAD
            
=======

>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
          // }
          // else if (parsedUserInput.at(i).find(")") != string::npos){ // EXAMPLE: ls)
          //   // revisedUserInput.push_back(parsedUserInput.at(i).substr(0, parsedUserInput.at(i).size() - 1)); //word before )
          //   // revisedUserInput.push_back(")");
          // }
          // else if (parsedUserInput.at(i).find("(") != string::npos){ // EXAMPLE: (ls
          //   // revisedUserInput.push_back("(");
          //   // revisedUserInput.push_back(parsedUserInput.at(i).substr(parsedUserInput.at(i).find("(") + 1)); //word after (
          // }                                                                     //TODO handle when parenthesis is reached in a word, push onto revisedUserInput EXAMPLE: (((echo a && echo b) ...

<<<<<<< HEAD
        
          // revisedUserInput.push_back(parsedUserInput.at(i));
          
        }
        
=======

          // revisedUserInput.push_back(parsedUserInput.at(i));

        }

>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
        // while(numOpen != 0){
        //   revisedUserInput.push_back("(");
        //   --numOpen;
        // }
        // while(numClosed != 0){
        //   revisedUserInput.push_back(")");
        //   --numClosed;
        // }
        // else if (parsedUserInput.at(i) == "("){
        //   for(unsigned j = i+1; parsedUserInput.at(j) != ")"; ++j)
        //     revisedUserInput.push_back(parsedUserInput.at(j));
        // }
        // else {
        //   revisedUserInput.push_back(parsedUserInput.at(i));
        // }
      }
<<<<<<< HEAD
      
      // for( int i = 0; i < revisedUserInput.size(); i++){ //**TESTING
      //   cout << revisedUserInput.at(i) << endl; 
      // }
      
=======

      // for( int i = 0; i < revisedUserInput.size(); i++){ //**TESTING
      //   cout << revisedUserInput.at(i) << endl;
      // }

>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
      //begin parenthesis parse
      //create vector of vecotr<string>
      //go through entire input
      //once it reaches a (, start a new subvector
      //once it reaches ), end subvector
      //Example:
      //() () () 3 parenthesis
      // for ( 3 times ) {
<<<<<<< HEAD
        
      // }
      
      
=======

      // }


>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
      // for () {
      //   makeTree(parentheticalInput.at(i))
      // }
      // vector<vector<string> > parentheticalInput;
      // vector<string> temp;
      // for (unsigned i = 0; i < revisedUserInput.size(); i++) {
      //   if (revisedUserInput.at(i).at(0) == "(") {
<<<<<<< HEAD
          
      //   }
      // }
      
=======

      //   }
      // }

>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
      //test
      // for(int a = 0; a < revisedUserInput.size(); ++a){
      //   cout << revisedUserInput.at(a) << " ";
      // }
      tree.clear();
      if(std::find(revisedUserInput.begin(), revisedUserInput.end(), "(") != revisedUserInput.end()) {
        unsigned numSkips = 0;
        CommandPrompt* temp = this->makeParenthesisTree(revisedUserInput, numSkips);
        tree.push_back(temp);
      }
      else {
<<<<<<< HEAD
        this->makeTree(revisedUserInput);  
=======
        this->makeTree(revisedUserInput);
>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
      }
      //begin execution
      for (unsigned i = 0; i < tree.size(); i++) {
        tree.at(i)->execute();
      }
      //end execution
    }

  }
<<<<<<< HEAD
  
  CommandPrompt* makeParenthesisTree(vector<string> revisedUserInput, unsigned &numSkips) {
          //begin tree hierarchy 
=======

  CommandPrompt* makeParenthesisTree(vector<string> revisedUserInput, unsigned &numSkips) {
          //begin tree hierarchy
>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
      vector<string> commandInput;
      CommandPrompt* tempLeft = NULL;
      CommandPrompt* tempRight = NULL;
      commandInput.clear();
      vector<CommandPrompt*> subTree;
      subTree.clear();
      vector<string> revisedUserInputv2;
      revisedUserInputv2.clear();
<<<<<<< HEAD
      
      for (unsigned i = 0; i < revisedUserInput.size(); ++i){ //search through parsed input for connectors.
        //if last element
        
=======

      for (unsigned i = 0; i < revisedUserInput.size(); ++i){ //search through parsed input for connectors.
        //if last element

>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
        if (revisedUserInput.at(i) == "(") {
          //numSkips = 0; //replaced this with tempSkips (below)
          numSkips = i; //***TESTING solution 2
          // unsigned tempSkips = 0;
          vector<string> restOfInput(revisedUserInput.begin() + i + 1, revisedUserInput.end());
          if (tempLeft != NULL /*&& tempRight == NULL*/) {  //if not empty and tempLeft != NULL and right exists //**TESTING (it might run into a case where left && right exist)
            tempRight = new Parenthesis();
            tempRight->setRight(makeParenthesisTree(restOfInput, numSkips));   //recursive call  (setRight == setChild for Parenthesis Class)
<<<<<<< HEAD
            subTree.back()->setRight(tempRight); 
=======
            subTree.back()->setRight(tempRight);
>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
            tempLeft = NULL;
            tempRight = NULL;
          }
          // else if (tempRight != NULL) { //**TESTING
<<<<<<< HEAD
            
=======

>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
          // }
          else { //if tree empy
            subTree.push_back(new Parenthesis());
            subTree.back()->setRight(makeParenthesisTree(restOfInput, numSkips));  //sets parenthesis child
          }
          i = numSkips;
          // i = numSkips + 1; //***TESTUING solution 1
          // numSkips += tempSkips;
<<<<<<< HEAD
        }
        else if (revisedUserInput.at(i) == ")") {
          //numSkips++; //**TESTING
          if (subTree.empty()) {
            subTree.push_back(new Command (commandInput));
          }
          return subTree.front();
        }
=======
        }
        else if (revisedUserInput.at(i) == ")") {
          //numSkips++; //**TESTING
          if (subTree.empty()) {
            subTree.push_back(new Command (commandInput));
          }
          return subTree.front();
        }
>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
        // else if(revisedUserInput.at(i) == "(" && revisedUserInput.at(revisedUserInput.size() - 1) == ")"){
        //   revisedUserInput.pop_back();
        //   for(unsigned g = 0; g < revisedUserInput.size(); ++g){
        //     revisedUserInputv2.at(g) = revisedUserInput.at(g + 1);
        //   }
        //   makeTree(revisedUserInputv2);
        //}
        else if (i == revisedUserInput.size() - 1) {        // if at last element
          commandInput.push_back(revisedUserInput.at(i));
          if (subTree.empty()) { //if tree is empty, push a command
            subTree.push_back(new Command(commandInput));
          }
<<<<<<< HEAD
          else {        //if tree is not empty, there has to be a connector. 
            subTree.back()->setRight(new Command(commandInput)); 
=======
          else {        //if tree is not empty, there has to be a connector.
            subTree.back()->setRight(new Command(commandInput));
>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
          }
          commandInput.clear();     //clears commandInput for other commands
        }
        else if (revisedUserInput.at(i) == "&&"){                  //if one is found, create new connector and create children for it.
          if (subTree.empty() && tempLeft == NULL) {
            tempLeft = new Command(commandInput); //sets tempLeft child to && command
            commandInput.clear();     //clears commandInput for other commands
          }
          else {  //if connector has no left and the list is not empty
            tempLeft = subTree.back();
            subTree.pop_back();
          }
          subTree.push_back(new And());
          subTree.back()->setLeft(tempLeft); //sets AND left to tempLeft
        }
        else if (revisedUserInput.at(i) == "||"){                  //if one is foubnd, create new connector and create children for it.
          if (subTree.empty() && tempLeft == NULL) {
            tempLeft = new Command(commandInput); //sets tempLeft child to || command
            commandInput.clear();     //clears commandInput for other commands
          }
          else {  //if connectore has no left and the list is not empty
            tempLeft = subTree.back();
            subTree.pop_back();
          }
          subTree.push_back(new Or());
          subTree.back()->setLeft(tempLeft); //sets OR left to tempLeft
        }
        else if (revisedUserInput.at(i) == ";"){                  //if one is found, create new connector and create children for it.
          if (subTree.empty() && tempLeft == NULL) {
            tempLeft = new Command(commandInput); //sets tempLeft child to && command
            commandInput.clear();     //clears commandInput for other commands
          }
          else {  //if connector has no left and the list is not empty
            tempLeft = subTree.back();
            subTree.pop_back();
          }
<<<<<<< HEAD
          subTree.push_back(new Semicolon());  
=======
          subTree.push_back(new Semicolon());
>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
          subTree.back()->setLeft(tempLeft); //sets AND left to tempLeft
        }
        else if (tempLeft != NULL && ( (revisedUserInput.at(i + 1) == "&&") || (revisedUserInput.at(i + 1) == "||") || (revisedUserInput.at(i + 1) == ";") || (revisedUserInput.at(i + 1) == ")") ) ) { //**TESTING added ")""
            commandInput.push_back(revisedUserInput.at(i));
            tempRight = new Command(commandInput);
            commandInput.clear();
            subTree.back()->setRight(tempRight);
            tempLeft = NULL;
            tempRight = NULL;
          }
        else{ //if not a connector string
          commandInput.push_back(revisedUserInput.at(i));
        }
        numSkips++;  //this is how many elements in the parent inputVector to skip to finish reading command
      }
<<<<<<< HEAD
      
      return subTree.front(); //not sure if returning this here is correct
  }
  
  void makeTree(vector<string> revisedUserInput){
    
    //begin tree hierarchy 
=======

      return subTree.front(); //not sure if returning this here is correct
  }

  void makeTree(vector<string> revisedUserInput){

    //begin tree hierarchy
>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
      vector<string> commandInput;
      CommandPrompt* tempLeft = NULL;
      CommandPrompt* tempRight = NULL;
      commandInput.clear();
      tree.clear();

      for (unsigned i = 0; i < revisedUserInput.size(); ++i){ //search through parsed input for connectors.
        //if last element
        if (i == revisedUserInput.size() - 1) {        // if at last element
          commandInput.push_back(revisedUserInput.at(i));
          if (tree.empty()) { //if tree is empty, push a command
            tree.push_back(new Command(commandInput));
          }
<<<<<<< HEAD
          else {        //if tree is not empty, there has to be a connector. 
=======
          else {        //if tree is not empty, there has to be a connector.
>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
            tree.back()->setRight(new Command(commandInput)); //FIXME
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
        else if (revisedUserInput.at(i) == "||"){                  //if one is foubnd, create new connector and create children for it.
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
<<<<<<< HEAD
    
  }
  
=======

  }

>>>>>>> 8eb112326780cf5c658075f75e6bea24839c0791
  bool commandFailed(){
    return false;
  }

};

#endif
