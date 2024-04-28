//
// Created by Administrator on 2024/4/28.
//线性表操作详情
#include <stdio.h>

//静态数组
#define MaxSize 10 // 定义最大长度
typedef struct {
    int data[MaxSize];  //ElemType data[MaxSize];
    int length;
}SqList;

//初始化
void InitList(SqList& L) {
    L.length = 0;
}
//根据位序i插入e元素
bool ListInsert(SqList& L, int i, int e) {
    if (i < 1 || i > L.length + 1) { // i的范围：1 - n+1，第1位前 至 最后一位后
        return false;
    }
    for (int j = L.length; j >= i; j--) {   //i之前数据后移
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;  //在i-1位置放置e
    L.length++;     //长度+1
    return true;
}
// 根据位序i删除元素，返回删除的元素值e
bool ListDelete(SqList& L, int i, int& e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {// 删除的位置后的元素往前移动
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
// 按位序i查找元素，返回值
int GetElem(SqList& L, int i) {
    if (i < 1 || i > L.length) {
        return 0;
    }
    return L.data[i - 1];
}
// 按值e查找元素，返回位序
int LocateElem(SqList& L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (e == L.data[i]) {
            return i + 1;
        }
    }
    return 0;
}
// 遍历顺序表元素
void PrintList(SqList& L) {
    for (int i = 0; i < L.length; i++) {
        printf("第%d位为%d\t",i+1, L.data[i]);   // \t
    }
}

int main() {
    int e;
    SqList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    printf("---- 建表并插入初始数据插入前 ----\n");
    printf("插入元素顺序表的元素为：");
    PrintList(L);
    printf("\n---- 初始数据插入完毕 ----\n\n");

    //在第2位插入6
    printf("---- 在位序2的位置插入元素 ----\n插入前：\n");
    PrintList(L);
    ListInsert(L, 2, 6);// 插入2
    printf("\n插入后：\n");
    int ii = 1;
    PrintList(L);
    printf("\n---- 插入完毕 ----\n");
    PrintList(L);
    if (ListDelete(L, 3, e)) {
        printf("删除位序3的元素%d成功：", e);
        PrintList(L);
    }
    printf("位序3的数是：%d\n", GetElem(L, 3));
    printf("数值是4的位序是：%d\n", LocateElem(L, 4));
}

