//
//  main.cpp
//  MemoryPool
//
//  Created by blost on 4/11/17.
//  Copyright © 2017 blost. All rights reserved.
//

#include <iostream>
#include <string>
#include "MemPool.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "MemPool test!\n";
    MemPoolOperation mem(5,1);
    char *p[10];
    mem.InitMem();
    for (int i =0;i<10;i++){
        if (i==8){
            p[i] =(char*)mem.applyMem (2048);
        }else{
            p[i] = (char*)mem.applyMem(512);
        }
        if (p[i]==NULL) continue;
        char *t = "this is i";
        memcpy(p[i], t, strlen(t));
        std::cout<<(char*)p[i]<<std::endl;
    }
    for (int i =0;i<4;i++){
        mem.freeMem(p[i]);
    }
    for (int i =0;i<10;i++){
        p[i] = (char*)mem.applyMem(512);
        if (p[i]==NULL) continue;
        char *t = "this is i";
        memcpy(p[i], t, strlen(t));
        std::cout<<(char*)p[i]<<std::endl;
    }
    return 0;
}
