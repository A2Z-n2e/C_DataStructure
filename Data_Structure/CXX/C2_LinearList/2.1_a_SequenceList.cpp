//
// Created by Administrator on 2024/4/28.

//线性表操作略写
InitList(&L)	        初始化表	    构造一个空的线性表
Length(L)		        求表长	    返回线性表L的长度,即L中数据元素的个数
LocateElem(L,e)     	按值查找操作	在表L中查找具有给定关键字值的元素
GetElem(L,i)	        按位查找操作	获取表L中第i个位置的元素的值
ListInsert(&L,i,&e)	    插入操作	    在表中的第i个位置插入指定元素e
ListDelete(&L,i,&e)	    删除操作	    删除表中第i个位置的元素,并用e返回删除元素的值
PrintList(L)	        输出操作	    按前后顺序输出线性表的所有元素值
DestroyList(&L)     	销毁操作	    销毁线性表,并释放空间

初始化表
1.静态分配
#define MaxSize 50 //定义线性表的最大长度
typedef struct
{
    ElemType data[MaxSize]; //顺序表的元素
    int length;                 //顺序表当前长度
} SqList;                   //顺序表的类型定义
2.动态分配[C语言初始动态分配语句：L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);]
#define InitSize 100 //表长度的初始定义
typedef struct
{
    ElemType *data;           //指示动态分配数组的指针
    int Maxsize,length;  //数组的最大容量和当前个数
} SeqList;                       //动态分配数组顺序表的类型定义



插入操作：在表中的第i个位置插入指定元素e
bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1) //判断i的范围是否有效 (1~n+1) [最后一位插入]
        return false;
    if (L.length >= Maxsize) //当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--) //将第i个元素及以后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e; //在位置i处放入e
    L.length++;
    return true;
}



删除操作
bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length + 1) //判断i的范围是否有效
        return false;
    e = L.data[i - 1];                 //将被删除的元素赋值给e
    for (int j = i; j < L.length; j++) //将第i个元素以后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--; //线性表长度减1
    return true;
}

按值查找
int LocateElem(SqList &L, int i, ElemType &e)
{
    int i;
    for (i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1; //下标为i的元素值等于e，返回其位序i+1
    return 0;             //退出循环，说明查找失败
}