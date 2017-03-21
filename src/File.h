#ifndef _FILE_H_
#define _FILE_H_

#include "CommandPrompt.h"
#include "Connector.h"
#include "Command.h"
#include <vector>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

class File : public Command {
    
    private:
        vector<string> fileName;
        // char** fileNameArray;
    public:
        File(){};
        File(vector<string> fileName){
            this->fileName = fileName;
            // fileNameArray = new char*[fileName.size() + 1];
        };
        
        // char** fileNameArray(){
        //     for(unsigned i = 0; i < fileName.size(); i++){
        //         fileNameArray[i] = (char*)fileName.at(i).c_str();
        //       }
        //       fileNameArray[fileName.size()] = NULL; //null terminated array
        //       return fileNameArray;
        // }
        string fileNameString(){
            return fileName.at(0);
        }
    
};

#endif