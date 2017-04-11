//
//  MemPool.cpp
//  MemoryPool
//
//  Created by blost on 4/11/17.
//  Copyright © 2017 blost. All rights reserved.
//

#include "MemPool.h"

MemPoolOperation::MemPoolOperation():MemPoolOperation(10,1){};

MemPoolOperation::MemPoolOperation(int blockNum1,int blockSize1){
    blockNum = blockNum1;
    blockSize = blockSize1;
    bigBlocknum = 0;
}
bool MemPoolOperation::InitMem(){
    for (int i =0;i<blockNum;i++){
        MemoryBlock block(0);
        block.SetBlockId(i);
        void * paddr = (void* )malloc(blockSize*1024);
        if (paddr == NULL) {
            blockNum = i;
            return false;// malloc fail memory not enough only part memspace
        }
        block.SetBlockAddr(paddr);
        avaliableBlock.push_back(block);
    }
    return true;
}
void* MemPoolOperation::applyMem(int size){
    void * paddr;
    if (size > blockSize*1024){
        paddr = (void *) malloc(size);
        if (paddr == NULL){
            return NULL;
        }
        bigBlocknum++;
        MemoryBlock block(1);
        block.SetBlockAddr(paddr);
        block.SetBlockId(bigBlocknum+blockNum);
        BigBlock.push_back(block);
    }
    else{
        if (avaliableBlock.size()==0){
            std::cout<<"mem pool already full \n";
            return NULL;
        }
        MemoryBlock block =(MemoryBlock)avaliableBlock.back();
        paddr = block.GetBlockAddr();
        block.SetFrequency(block.GetFrequency());
        busyBlock.push_back(block);
        avaliableBlock.pop_back();
    }
    return paddr;
}
bool MemPoolOperation::freeMem(void *addr){
    if (addr == NULL)
        return true;
    for (auto b= BigBlock.begin();b!=BigBlock.end();b++){
        if (b->GetBlockAddr() == addr){
            free(addr);
            return true;
        }
    }
    for (auto b= busyBlock.begin();b!=busyBlock.end();b++){
        if (b->GetBlockAddr()== addr){
            
            MemoryBlock block =*b;
            avaliableBlock.push_back(block);
            busyBlock.erase(b);
            return true;
        }
    }
    return false;
    
}
bool MemPoolOperation::cleanMem(){
    for (auto b= busyBlock.begin();b!=busyBlock.end();b++){
        free(b->GetBlockAddr());
    }
    busyBlock.clear();
    for (auto b= avaliableBlock.begin();b!=busyBlock.end();b++){
        free(b->GetBlockAddr());
    }
    avaliableBlock.clear();
    for (auto b= BigBlock.begin();b!=busyBlock.end();b++){
        free(b->GetBlockAddr());
    }
    BigBlock.clear();
    blockNum = 0;
    blockSize = 0;
    return true;
}