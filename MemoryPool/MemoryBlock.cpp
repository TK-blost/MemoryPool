//
//  MemoryBlock.cpp
//  MemoryPool
//
//  Created by blost on 4/11/17.
//  Copyright © 2017 blost. All rights reserved.
//

#include "MemoryBlock.h"

MemoryBlock::MemoryBlock(int requent){
    frequency = requent;
}
int MemoryBlock::GetBlockId(){
    return blockId;
}
void MemoryBlock::SetBlockId(int id){
    blockId = id;
}
void *MemoryBlock::GetBlockAddr(){
    return blockAddr;
}
void MemoryBlock::SetBlockAddr(void *arg){
    blockAddr = arg;
}
int MemoryBlock::GetFrequency(){
    return frequency;
}
void MemoryBlock::SetFrequency(int newFre){
    frequency = newFre;
}

