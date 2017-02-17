#include <iostream>
#include "And.h"
#include "Command.h"
#include "CommandPrompt.h"
#include "Connector.h"
#include "Or.h"
#include "Prompt.h"
#include "Semicolon.h"

using namespace std;

int main() {

  // cout << "Testing if repository: " << endl;
  // string userInput;
  // cout << "Input something yo: ";
  // cin >> userInput;
  // CommandPrompt* c = new Command(userInput);
  // c->execute();

  // ------------------Testing Prompt------------------
//   CommandPrompt* test = new Prompt();
//   test->execute();

  // vector<string> LS;
  // LS.push_back("ls");
  // LS.push_back(" ");
  // CommandPrompt* command = new Command(LS);
  // command->execute();

  //Testing vector input parsing and command execute
  // CommandPrompt* c = new Command();
  // c->execute();
  // vector<string> ECHO;
  // vector<string> ECHO1;
  // ECHO.push_back("ls");
  // //ECHO.push_back("a");
  // ECHO1.push_back("echo");
  // ECHO1.push_back("b");
  // CommandPrompt* test = new Command(ECHO);
  // CommandPrompt* test1 = new Command(ECHO1);

  // test->execute();                        //a
  // test1->execute();                       //b
  // CommandPrompt* OR = new Or(test, test1);
  // OR->execute();                          //a
  // CommandPrompt* SEMI = new Semicolon(OR, test1);
  // SEMI->execute();                        //a b
  // CommandPrompt* AND = new And(OR, test1);
  // AND->execute();                         //a
  
  //----------------------------Testing comments------------------------
  CommandPrompt* testcomm = new Prompt();
  testcomm->execute();
  
  return 0;
}