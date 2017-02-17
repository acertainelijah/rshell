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
  CommandPrompt* test = new Prompt();
  test->execute();

  // vector<string> LS;
  // LS.push_back("ls");
  // LS.push_back(" ");
  // CommandPrompt* command = new Command(LS);
  // command->execute();

  //Testing vector input parsing and command execute
  // CommandPrompt* c = new Command();
  // c->execute();

return 0;
}
