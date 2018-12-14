//
//  main.c
//  struct
//
//  Created by Zac on 2018/12/1.
//  Copyright © 2018 gonglx. All rights reserved.
//

#include <stdio.h>

typedef struct stu {
    
    char name[100];
    int age;
    char sex;
} Stu;

int main(int argc, const char * argv[]) {
   
    
    Stu stu = {"gongleixing",4,'x'};
    
    printf("%d \n",stu.age );
    
    return 0;
}
