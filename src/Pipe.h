#ifndef _PIPE_H_
#define _PIPE_H_

#include "CommandPrompt.h"
#include "Connector.h"

class Pipe : public Connector {
    
    private:
    
        CommandPrompt* left;
        CommandPrompt* right;
    
    public:
        Pipe(){};
        Pipe(CommandPrompt* left, CommandPrompt* right){
            this->left = left;
            this->right = right;
        }
        void execute(){
            
            int p[2];
            pipe(p);
            
            int save_stdout;
            int save_stdin;
            int newOut = p[1];
            int newIn = p[0];
        
            save_stdout = dup(1);
            close(1);
            dup(newOut);
            left->execute();
            
            dup2(save_stdout, 1);
            
            save_stdin = dup(0);
            close(0);
            dup(newIn);
            right->execute();
            
            
            dup2(save_stdin, 0);
            close(newOut);
            close(newIn);
            close(save_stdout); 
            close(save_stdin);
            
            // int p[2];
            // pipe(p);
            
            // int save_stdout;
            // int save_stdin;
            // int newOut = p[1];
            // int newIn = p[0];
        
            // if (fork() == 0) {
            //     save_stdout = dup(1);
            //     close(1);
            //     dup(newOut);
            //     left->execute();

            // } else {
            //     save_stdin = dup(0);
            //     close(0);
            //     dup(newIn);
            //     right->execute();
            // }
            
            // close(newOut);
            // close(newIn);
            // dup2(save_stdout, 1);
            // dup2(save_stdin, 0);
            // close(save_stdout); 
            // close(save_stdin);
            
            
            
            // int p[2];
            // pipe(p); // Creates a pipe with file descriptors Eg. input = 3 and output = 4 (Since, 0,1 and 2 are not available)
            // if (fork() == 0) {
            // // Child process
            //     close(0); // Release fd no - 0
            //     close(p[0]); // Close pipe fds since useful one is duplicated
            //     close(p[1]);
            //     dup(p[0]); // Create duplicate of fd - 3 (pipe read end) with fd 0.
            //     left->execute();
                
            // } else {
            //     // Parent process
            //     close(1); // Release fd no - 1
            //     close(p[0]); // Close pipe fds since useful one is duplicated
            //     close(p[1]);
            //     dup(p[1]); // Create duplicate of fd - 4 (pipe write end) with fd 1.
            //     right->execute();
            // }
        }
        bool commandFailed(){
            return 0; //TODO idk what to do here, lol
        }
        void setLeft(CommandPrompt* l) {this->left = l;}
    
        void setRight(CommandPrompt* r) {this->right = r;}
        
};

#endif