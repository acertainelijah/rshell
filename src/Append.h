#ifndef _APPEND_H_
#define _APPEND_H_

#include "CommandPrompt.h"
#include "Connector.h"
#include <unistd.h>

class Append : public Connector { //>>
    
    private:
        CommandPrompt* left;
        CommandPrompt* right;
        char** fileNameArray;
    
    public:
        Append(){
            fileNameArray = new char*[2];
        };
        Append(CommandPrompt* left, CommandPrompt* right){
            this->left = left;
            this->right = right;
            fileNameArray = new char*[2];
        }
        //WHY DID IT PRINT TEST
        void execute(){
            fileNameArray[0] = (char*)right->fileNameString().c_str();
            fileNameArray[1] = NULL;
            // cout << "test" << endl;
            int newOut = open(fileNameArray[0], O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
            int save_stdout = dup(1);
            close(1);
            dup(newOut);
            left->execute();
            dup2(save_stdout, 1);
            // dup2(newOut, 1);
            close(newOut);
            close(save_stdout); //?
        }
        bool commandFailed(){
            return 0; //TODO idk what to do here, lol
        }
        void setLeft(CommandPrompt* l) {this->left = l;}
    
        void setRight(CommandPrompt* r) {this->right = r;}
    
};


#endif