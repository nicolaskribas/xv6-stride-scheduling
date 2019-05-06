#include "types.h"
#include "user.h"

#define NFILHOS 6

int main(){
    int pid, i, n;

    for (i = 0, n = 0; i < NFILHOS; i++, n+=20){
        pid = fork(n);
        if(pid == 0){
            for(;;){
            }
            exit();
        }
    }
    while(1){
      pid = wait();
      if(pid < 0) break;
    }
    exit();
}
