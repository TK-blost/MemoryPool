//
//  MemPool.hpp
//  MemoryPool
//
//  Created by blost on 4/11/17.
//  Copyright © 2017 blost. All rights reserved.
//

#ifndef MemPool_hpp
#define MemPool_hpp

#include <stdio.h>
#include <list>
#include <stdlib.h>
#include "MemoryBlock.h"
#include <iostream>

#endif /* MemPool_hpp */
class MemPoolOperation{
public:
    MemPoolOperation();
    MemPoolOperation(int blockNum1,int blockSize1);

public:
    bool InitMem();
    void* applyMem(int size);
    bool freeMem(void *addr);
    bool cleanMem();

private:
    int AvaiableMemSize;
    int UsedMemsize;
    int blockNum;
    int blockSize;
    int bigBlocknum;
    std::list<MemoryBlock> avaliableBlock;
    std::list<MemoryBlock> busyBlock;
    std::list<MemoryBlock> BigBlock;
};
