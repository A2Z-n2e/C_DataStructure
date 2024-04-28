//
// Created by Administrator on 2024/4/27.
//���Ա� - ���й淶
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10
typedef struct{
    /*int * head;*/
    int * data;
    int length;
    /*int size;*/
}SqList;
void InitList(){    //SqList L
    SqList L;
    L.length = 0;
    /*L.data=(int*)malloc(MaxSize * sizeof(int));
    if (!L.data)
    {
        printf("��ʼ��ʧ��\n");
        exit(0);
    }
    L.length=0;
    *//*t.size=MaxSize;*//*
    return L;*/
}
//�������
bool ListInsert(SqList L, int i,int e)
{
    if (i < 1 || i > L.length + 1) {
        printf("����λ��������\n");
        return false;
    }
    if (L.length >= MaxSize) {
        L.data=(int *)realloc(L.data, (MaxSize + 1) * sizeof(int));
        if (!L.data) {
            printf("�洢����ʧ��\n");
        }
        /*MaxSize += 1;*/
    }
    for (int j= L.length - 1; j >= i - 1; j--) {
        L.data[j + 1]=L.data[j];
    }
    L.data[i - 1]=e;
    L.length++;
    return true;
}
//ɾ������
bool ListDelete(SqList L, int i,int e){
    if (i < 1 || i > L.length + 1) {    //i > L.length || i < 1
        printf("��ɾ��Ԫ�ص�λ������\n");
        return false;
    }
    e = L.data[i-1];
    /*for (int j=i; j < L.length; j++) {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return L;*/

}
//��ֵ����Ԫ��
int LocateElem(SqList L, int e){
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i+1;
        }
    }
    /*return -1;*/
    return 0;
}
//�޸�
SqList amendTable(SqList L, int i, int e){
    int add=LocateElem(L, i);
    L.data[add - 1]=e;
    return L;
}
void displayTable(SqList t){
    for (int i=0;i<t.length;i++) {
        printf("%d ",t.data[i]);
    }
    printf("\n");
}

int main(){
    SqList L=InitList();
    for (int i=1; i <= MaxSize; i++) {
        L.data[i - 1]=i;
        L.length++;
    }
    printf("ԭ˳���\n");
    displayTable(L);

    printf("ɾ��Ԫ��1:\n");
    L = ListDelete(L,1,1);
    displayTable(L);

    printf("�ڵ�2��λ�ò���Ԫ��5:\n");
    L = ListInsert(L, 5, 2);
    displayTable(L);

    printf("����Ԫ��3��λ��:\n");
    int add=LocateElem(L, 3);
    printf("%d\n",add);

    printf("��Ԫ��3��Ϊ6:\n");
    L=amendTable(L, 3, 6);
    displayTable(L);
    return 0;
}