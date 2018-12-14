//
//  main.c
//  内存对齐
//
//  Created by Zac on 2018/12/1.
//  Copyright © 2018 gonglx. All rights reserved.
//

#include <stdio.h>
/**
 1.取pack(n) 的值 ,去结构体中类型最大的值m 两者取其小即为外对齐大小 Y = m < n ? m:n;
 2.与结构体中每个类型和Y 比较取小即为X,作为内对齐大小
 3.所谓按 X 对齐，即为地址(设起始地址为 0)能被 x 整除的地方开始存放数据
 4.外部对齐原则是依据 Y 的值(Y 的最小整数倍)，进行补空操作。
 
 */
#pragma pack(1)

struct node {
    int data;
    struct node next;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
