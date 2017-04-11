//
//  MemoryBlock.hpp
//  MemoryPool
//
//  Created by blost on 4/11/17.
//  Copyright © 2017 blost. All rights reserved.
//

#ifndef MemoryBlock_hpp
#define MemoryBlock_hpp

#include <stdio.h>


#endif /* MemoryBlock_hpp */
class MemoryBlock{
public:
    MemoryBlock(int requent);
public:
    int GetBlockId();
    void SetBlockId(int id);
    void *GetBlockAddr();
    void SetBlockAddr(void *arg);
    int GetFrequency();
    void SetFrequency(int newFre);
    
private:
    int frequency;
    int blockId;
    void * blockAddr;
};
