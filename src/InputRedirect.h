#ifndef _INPUT_REDIRECT_H_
#define _INPUT_REDIRECT_H_

#include "CommandPrompt.h"
#include "Connector.h"
#include <unistd.h>

class Input : public Connector { //<
    
    private:
        CommandPrompt* left;
        CommandPrompt* right;
        char** fileNameArray;
    
    public:
        Input(){
            fileNameArray = new char*[2];
        };
        Input(CommandPrompt* left, CommandPrompt* right){
            this->left = left;
            this->right = right;
            fileNameArray = new char*[2];
        }
        void execute(){
            fileNameArray[0] = (char*)right->fileNameString().c_str();
            fileNameArray[1] = NULL;
            int newIn = open(fileNameArray[0], O_RDONLY);
            int save_stdin = dup(0);
            close(0);
            dup(newIn);
            left->execute();
            dup2(save_stdin, 0);
            // dup2(newOut, 1);
            close(newIn);
            close(save_stdin); //?
            cout << endl;
        }
        bool commandFailed(){
            return 0; //TODO idk what to do here, lol
        }
        void setLeft(CommandPrompt* l) {this->left = l;}
    
        void setRight(CommandPrompt* r) {this->right = r;}
    
};

#endif