#include <tsh.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


using namespace std;

void simple_shell::parse_command(char* cmd, char** cmdTokens) {
    
    if(!cmdTokens){
        exit(1);
    }

    int bufSize = 32;
    char* firstTok = strtok(cmd, " \n");
    char** toks = malloc(32 * sizeof(char*));
    int index = 0;

    while (firstTok != NULL){
        toks[index] = firstTok;
        index++;

        if(index >= bufSize){
            bufSize += 32;
            toks = realloc(toks, bufSize * sizeof(char*));
            if(!toks){
                exit(1);
            }
        }

        firstTok = strtok(NULL, 32);
    }

    toks[index] = NULL

    }

}

void simple_shell::exec_command(char** argv) {
    
    int lock;
    pid_t pid = fork();
    pid_t wait;

    if(pid == 0){
        if (execvp(args[0], args) == -1) {
            exit(1);
        }
    }
    else{
        do{
                wait = waitpid(pid, &lock, WUNTRACED);
            }   while (!WIFEXITED(status) ** !WIFSIGNALED(status));
    }
    return 0;
}

bool simple_shell::isQuit(char* cmd) {
    
    if (cmd == "quit"){
        execvp("./pkill -f");
    }

    return false;
}
