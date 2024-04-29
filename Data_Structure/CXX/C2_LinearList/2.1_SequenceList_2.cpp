//A为书中明确写出代码[应该比较重要]，B为书中提到过的根据网络&自己编写出来的其他操作部分，C为书上没提到过的操作
// Created by Administrator on 2024/4/28.
//线性表操作详情
#include <cstdio>
#include <cstdlib>
//动态数组
#define InitSize 5      //定义最大长度
#define IncreaseSize 5  //每次改变的步长
typedef struct {
    int* data;
    int MaxSize,length;
}SqList;

//A - 初始化
void InitList(SqList& L) {
    L.data = (int*)malloc(sizeof(int) * InitSize);// 初始化空间
    L.length = 0;
    L.MaxSize = InitSize;
}

//C - 扩展空间，实现改变数组大小
void IncreaseSpace(SqList& L, int len) {
    printf("空间+5\n");
    int* p = L.data;// 旧数据
    L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));// 新空间
    for (int i = 0; i < L.length; i++) {// 拷贝旧的数据
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;// 增加
    free(p);// 释放原来空间
}

//A - 根据位序i插入e元素
bool ListInsert(SqList& L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    // 如果满了，扩大空间
    if (L.length >= L.MaxSize) {
        IncreaseSpace(L, IncreaseSize);
    }
    // 先从前往后移动再插入
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//A - 根据位序i删除元素，返回删除的元素值e
bool ListDelete(SqList& L, int i, int& e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    // 直接从后往前移删除
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

//B - 按位序i查找元素，返回值
int GetElem(SqList& L, int i) {
    if (i < 1 || i > L.length) {
        return 0;
    }
    return L.data[i - 1];
}

//A - 按值e查找元素，返回位序
int LocateElem(SqList& L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

//B - 遍历顺序表元素
void PrintList(SqList& L) {
    for (int i = 0; i < L.length; i++) {
        printf("第%d位为%d\t",i+1, L.data[i]);   // \t
    }
    printf("\n");
}

//B - 获取表长
void Length(SqList L){
    int Length = L.length;
    printf("线性表的表长为：%d",Length);
}

//B- 判空操作
void Empty(SqList L){
    if(L.length == 0)
        printf("表空，表长为：%d\n",L.length);
    else
        printf("表非空，表长为：%d\n",L.length);
}

//C - 清空线性表
void ClearList(SqList& L){
    L.length = 0;
    printf("已清空表。\n");
}

//B - 销毁表
void DestroyList(SqList& L){
    free(L.data);   //释放空间
    L.data = NULL;
    L.length = 0;
    L.MaxSize = 0;
    printf("已销毁表。\n");
}

int main() {
    int e;
    SqList L;
    InitList(L);
    printf("---- 初始化表 ----\n");
    Empty(L);   //先要初始化才能测试表是否为空！！！
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);// 插入
    PrintList(L);
    Empty(L);
    printf("---- 初始化表完毕 ----\n\n");

    //调用 - 插入操作
    printf("---- 此前已经插入了5个元素 ----\n");
    ListInsert(L, 2, 6);    //此前已经插入了5个，再插入会增加空间
    printf("2位插入元素6：");
    PrintList(L);
    Length(L);
    printf("\n");
    printf("7位插入元素7：");
    ListInsert(L,7,7);  //此次空间还有剩余，不用增加空间
    PrintList(L);
    Length(L);
    printf("\n---- 插入元素完毕 ----\n\n");

    //调用 - 删除操作：删除第3个元素
    printf("---- 删除位序为7的元素前 ----\n");
    if (ListDelete(L, 7, e)) {
        printf("删除位序7的元素%d：", e);
        PrintList(L);
        Length(L);
    }
    printf("\n---- 删除位序为7的元素完毕 ----\n\n");

    printf("按位序查找 - 位序3的数是：%d\n", GetElem(L, 3));
    printf("按位序查找 - 数值是4的位序是：%d\n", LocateElem(L, 4));

    //调用 - 清空表
    printf("\n---- 清空表 ----\n");
    ClearList(L);
    Length(L);
    printf("\n");
    Empty(L);
    printf("---- 清空表完毕 ----\n");

    //调用 - 销毁表
    ListInsert(L, 1, 1);
    printf("\n---- 销毁表 ---\n");
    Length(L);
    printf("\n");
    Empty(L);
    DestroyList(L);
    Length(L);
    printf("\n");
    Empty(L);
    printf("---- 销毁表完毕 ----");
}

