//
// Created by Administrator on 2024/4/27.
//���Ա� - ���й淶
#include <stdio.h>
#include <stdlib.h>
//��ʼ����1.��̬����
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
        printf("��ʼ��ʧ��");
        exit(0);
    }
    L.length=0;
    /*L.size=MaxSize;*/
    return L;
}
//���˳�����Ԫ�صĺ���
void printList(SqList L){
    for (int i=0;i<L.length;i++) {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
int main(){
    SqList L=initList();
    //��˳��������Ԫ��
    for (int i=1; i<=MaxSize; i++) {
        L.data[i-1]=i;
        L.length++;
    }
    printf("˳����д洢��Ԫ�طֱ��ǣ�\n");
    printList(L);
    return 0;
}