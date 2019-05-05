#include "types.h"
#include "user.h"

#define NFILHOS 11

int main(){
    int pid, i, n;

    for (i = 0, n = 100; i < NFILHOS; i++, n-=10){
        pid = fork(n);
        if(pid == 0){
            for(i = 0; i < 99999999; i++){
                if(i % 9999999 == 0) printf(1," ");
            }
            printf(1,"\nF: %d\n", getpid());
            exit();
        }
    }
    while(1){
      pid = wait();
      if(pid < 0) break;
    }
    printf(1, "___________________________");
    for (i = 0, n = 0; i < NFILHOS; i++, n+=10){
        pid = fork(n);
        if(pid == 0){
            for(i = 0; i < 99999999; i++){
                if(i % 9999999 == 0) printf(1," ");
            }
            printf(1,"\nF: %d\n", getpid());
            exit();
        }
    }
    while(1){
      pid = wait();
      if(pid < 0) break;
    }
    exit();
}
