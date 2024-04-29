//王道代码操作详情：需用.cpp文件运行的C语言代码
//A为书中明确写出代码[应该比较重要]，B为书中提到过的根据网络&自己编写出来的其他操作部分
// Created by Administrator on 2024/4/28.
//线性表操作详情
#include <cstdio>

//静态数组 - 无销毁操作
#define MaxSize 10 // 定义最大长度
typedef struct {
    int data[MaxSize];  //ElemType data[MaxSize];
    int length;
}SqList;

//A - 初始化
void InitList(SqList& L) {
    L.length = 0;
}

//A - 根据位序i插入e元素 - O(n)
//最好情况，尾插入i = n+1，元素不后移，O(1)
//最坏情况，头插入i = 1，n个元素后移，O(n)
//平均情况，n/2 ---- 具体算法后期可以看看，课本P29
bool ListInsert(SqList& L, int i, int e) {  //手写为：int& e
    if (i < 1 || i > L.length + 1) { //增加i的范围：1 - n+1，第1位前 至 最后一位后
        return false;
    }
    if(L.length >= MaxSize){    //存储空间满，不能插入
        return false;
    }
    //可理解为，计算机从0开始计数；但顺序表从1开始数，即计算机的第0位即为线性表的第1位
    for (int j = L.length; j >= i; j--) {   //i之前数据后移
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;  //在i-1位置放置元素e
    L.length++;     //长度+1
    return true;
}

//A - 根据位序i删除元素，返回删除的元素值e - O(n)
//最好情况，尾删除i = n，元素不后移，O(1)
//最坏情况，头删除i = 1，n个元素后移，O(n)
//平均情况，(n-1)/2 ---- 具体算法后期可以看看，课本P30
bool ListDelete(SqList& L, int i, int& e) { //i的范围：1 - n，第1位 至 最后一位
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];  //被删除元素赋值给e
    for (int j = i; j < L.length; j++) {    //删除的位置后的元素，即i后元素前移
        L.data[j - 1] = L.data[j];
    }
    L.length--; //线性表长度-1
    return true;
}

//B - 按位查找元素：按位序i查找元素，返回值
int GetElem(SqList L, int i) {
    if (i < 1 || i > L.length) {
        return 0;
    }
    return L.data[i - 1];
}

//A - 按值查找元素：按值e查找元素，返回位序 - O(n)
//最好情况，头查找，元素不后移，比较1次，O(1)
//最坏情况，尾查找/查找元素不存在，比较n次，O(n)
//平均情况，(n+1)/2 ---- 具体算法后期可以看看，课本P30
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {   //下表为i的元素值为e
            return i + 1;   //返回相应元素位序需+1，即i+1
        }
    }
    return 0;   //查找失败
}

//B - 遍历顺序表元素
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("第%d位为%d\t",i+1, L.data[i]);   // \t
    }
}

//B - 获取表长
void Length(SqList L) {
    int Length = L.length;
    printf("线性表的表长为：%d",Length);
}


int main() {
    //调用 - 线性表的初始化
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

    //调用 - 插入操作：在第2位插入6
    printf("---- 在位序2的位置插入元素 ----\n插入前：");
    PrintList(L);
    printf("\n");
    Length(L);
    ListInsert(L, 2, 6);// 插入2
    printf("\n插入后：");
    int ii = 1;
    PrintList(L);
    printf("\n");
    Length(L);
    printf("\n---- 插入完毕 ----\n\n");

    //调用 - 删除操作：删除第3个元素
    printf("---- 删除位序为3的元素前 ----\n");
    if (ListDelete(L, 3, e)) {
        printf("删除位序3的元素%d：", e);
        PrintList(L);
        printf("\n");
        Length(L);
    }
    printf("\n---- 删除位序为3的元素完毕 ----\n\n");

    printf("按位序查找 - 位序3的数是：%d\n", GetElem(L, 3));
    printf("按位序查找 - 数值是4的位序是：%d\n", LocateElem(L, 4));
}

