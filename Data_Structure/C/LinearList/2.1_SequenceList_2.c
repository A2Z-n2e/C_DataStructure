//
// Created by Administrator on 2024/4/27.
//线性表 - 自行规范
#include <stdio.h>
#include <stdlib.h>
//初始化表：1.静态分配
#define MaxSize 10
typedef struct{
    /*int * head;*/
    int * data; //ElemType data[MaxSize];
    int length;
    /*int size;*/
}SqList;
SqList initList(){
    SqList L;
    /*L.head=(int*)malloc(MaxSize*sizeof(int));*/
    L.data=(int*)malloc(MaxSize*sizeof(int));
    if (!L.data)
    {
        printf("初始化失败");
        exit(0);
    }
    L.length=0;
    /*L.size=MaxSize;*/
    return L;
}
//输出顺序表中元素的函数
void printList(SqList L){
    for (int i=0;i<L.length;i++) {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
int main(){
    SqList L=initList();
    //向顺序表中添加元素
    for (int i=1; i<=MaxSize; i++) {
        L.data[i-1]=i;
        L.length++;
    }
    printf("顺序表中存储的元素分别是：\n");
    printList(L);
    return 0;
}