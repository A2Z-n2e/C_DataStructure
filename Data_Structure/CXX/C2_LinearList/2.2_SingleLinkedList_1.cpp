//
// Created by Administrator on 2024/4/29.
//单链表操作详情
#include <cstdio>
#include <cstdlib>
//定义单链表结点类型
typedef struct LNode {
    int data;           //数据域
    struct LNode* next; //指针域
}LNode, * LinkList;

//A - 单链表初始化
bool InitList(LinkList& L){     //?
    L = (LNode*) malloc((sizeof (LNode)));
    L->next = NULL;
    return true;
}

//带头结点单链表的建立 - 头插法
LinkList List_HeadInsert(LinkList& L) {// 头插法，建立逆序单链表
    LNode* s;
    int x;
    L = (LNode *)malloc(sizeof(LNode));// 创建头结点
    L->next = NULL;						// 初始为空链表,不然会指向不确定的地方
    scanf("%d", &x);
    while (x != 99) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
//带头结点单链表的建立 - 尾插法
LinkList List_TailInsert(LinkList& L) {// 尾插法
    int x;
    L = (LinkList)malloc(sizeof(LNode));// 创建头结点
    LNode* s, * r = L;
    scanf("%d", &x);
    while (x != 0) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;// 尾部的结点下一个为空
    return L;
}

//A - 按位序i查找结点:头结点的位序是0，1是第一个节点
LNode* GetElem(LinkList L, int i) {
    // 书上写法
	/*if(i == 0){
		return L;				// 返回头结点
	}
	if(i < 1){
		return NULL;			// 不合法
	}
	int j = 1; 					// 初始化为1，因为默认位序0是头结点, 1是第一个节点
	LNode *p = L->next;			// 默认找到第一个结点
	while(p != NULL && j < i){	// 依次寻找
		p = p->next;
		j++;
	}*/
    // 视频写法，更简洁
    if (i < 0) {    //i不能<0：书上没写
        return NULL;
    }
    LNode* p = L;	//头结点开始
    int j = 0;	//当前结点位序，带头结点从0开始
    while (p != NULL && j < i) {	//依次寻找到第i个结点
        p = p->next;
        j++;
    }
    printf("按位查找 - 第%d位为:%d\n",i,p->data);
    return p;   //返回第i个结点的指针/NULL
}

//A - 按值e查找结点
LNode* LocateElem(LinkList L, int e) {
    LNode* p = L->next;	//先得出头结点的下一个节点，即首元/第一个节点

    /*while (p != NULL && p->data != e) {	//从首元/第一个节点开始查找数据域为e的结点
        p = p->next;
        int i = 0;
        if(p->data != e){
            p = p->next;
            i++;
        }else{
            printf("按值查找 - 值为%d的元素为:第%d位\n",e,i);
        }
    }
    return p;*/   //返回该结点的指针/NULL

    //这种写法仅是为了输出方便看
    int i = 0,a = 0;
    while(p != NULL && p->data !=e){
        p = p->next;
        i++;
        a = i;
    }
    printf("值为%d的元素在第%d位\n",e,a);
    return p;
}

// 后插操作：在结点p后插入新节点-方法1
bool InsertNextNode(LNode* p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));	// 创造结点
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;									// 将s结点连到p之后
    return true;
}
// 前插操作：在结点p之前插入元素e-方法2
bool InsertPriorNode(LNode* p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->next = p->next;	// 新结点s的下个节点是p的下个节点
    p->next = s;		// 新结点s连到p之后
    s->data = p->data;	// 将p中的元素复制到s中
    p->data = e;		// 将p中的元素覆盖为e，完成交换
    return true;
}

//A - 插入
bool ListInsert(LinkList& L,int i,int e){
    LNode *p = L;
    int j = 0;
    while(p != NULL && j<i-1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return false;
    }
    LNode *s = (LNode*) malloc(sizeof (LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// - 在位序i的位置插入结点操作
bool ListInsert2(LinkList& L, int i, int e) {
    LNode* p = GetElem(L, i - 1);					// 找到i的前一个结点
    return InsertNextNode(p, e);
}
// 在位序i的位置插入结点操作
bool ListInsertBefore(LinkList& L, int i, int e) {
    LNode* p = GetElem(L, i);						// 找到i结点，这里不同于上一个函数找到i-1的前一个结点
    return InsertPriorNode(p, e);
}

//A - 删除第i个元素
bool ListDelete(LinkList &L,int i,int &e){
    LNode *p = L;
    int j = 0;
    while(p != NULL && j<i-1){
        p = p->next;
        j++;
    }
    if(p == NULL ||p->next == NULL){
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
//A - 删除指定结点
bool ListSpecifiedDelete(LinkList &L,int i){
    LNode *p = L;
    int j = 0;
    while(p != NULL && j<i-1){
        p = p->next;
        j++;
    }
    if(p == NULL ||p->next == NULL){
        return false;
    }
    LNode* q = p->next;	// 令q指向p的后继结点
    p->data = p->next->data;	// 和后继结点交换数据域
    p->next = q->next;	// 将*q结点在链中断开
    free(q);			// 释放原后继结点的存储空间
    return true;
}

// 在位序i的位置删除结点操作-方法1
bool ListDelete2(LinkList& L, int i, int& e) {
    LNode* p = GetElem(L, i - 1);					// 找到i的前一个结点
    if (p == NULL) {
        return false;
    }
    LNode* q = p->next;	// 令q指向被删除结点
    p->next = q->next;	// 令q节点在链中断开
    e = q->data;			// e为被删除结点的值
    free(q);			// 释放被删除结点的空间
    return true;
}
//  删除指定结点p, 不通过前驱节点操作，用交换数据那样删除，但是注意最后一个节点不能这样删除-方法2
bool DeleteZhidingLNode(LNode* p) {
    if (p == NULL) {
        return false;
    }
    LNode* q = p->next;	// 令q指向p的后继结点
    p->data = q->data;	// 和后继结点交换数据域
    p->next = q->next;	// 将*q结点在链中断开
    free(q);			// 释放原后继结点的存储空间
    return true;
}
// 在位序i的位置删除结点操作
bool ListDeleteZhiding(LinkList& L, int i, int& e) {
    LNode* p = GetElem(L, i);					// 找到i结点
    if (p == NULL) {
        return false;
    }
    return DeleteZhidingLNode(p);
}

//A - 求表长
void Length(LinkList L) {
    int len = 0;
    LNode* p = L;
    while (p->next != NULL) {// 注意是p->next
        p = p->next;
        len++;
    }
    printf("单链表长度：%d\n",len);
    /*return len;*/
}
// 链表输出
void PrintLinkList(LinkList& L) {
    LNode* p = L;
    int i = 0;
    while (p->next != NULL) {
        p = p->next;
        printf("第%d位为%d\t",i, p->data);// 放后面因为头结点是没有值的
        i++;
    }
    printf("\n");
}

void DestroyLinkedList(LNode *L){
    LNode *p = L;

    while (L != NULL){
        p = L;
        L = L->next;
        delete(p);
        break;
    }
    printf("销毁完成！\n");
}

void ClearLinkedList(LNode *L){
    LNode *p;
    while (L->next){
        p = L->next;
        L->next = p->next;
        delete(p);
        break;
    }
    printf("清空完成！\n");
}

int main() {
    /*int e;
    // 实现操作
    LinkList L;
    printf("输入值建立链表，输入0结束\n");
    //InitList(L);
    List_TailInsert(L);// 尾插
    //	List_HeadInsert(L);// 头插
    PrintLinkList(L);
    GetElem(L,1);
    Length(L);
    // 两种插入方法测试，都是在i的位置插入节点
    printf("在位序3的位置插入结点\n");
    ListInsert(L, 3, 33);
    PrintLinkList(L);
    printf("在位序5的位置插入结点\n");
    ListInsertBefore(L, 5, 55);
    PrintLinkList(L);
    // 两种删除方法测试
    printf("删除位序2的结点\n");
    ListDelete(L, 2, e);			// 通过前驱节点
    PrintLinkList(L);
    printf("删除位序4的结点\n");
    ListDeleteZhiding(L, 4, e);// 不通过前驱节点，通过交换数据方法
    PrintLinkList(L);*/


    LinkList L;
    int e;
    InitList(L);
    Length(L);
    ListInsert(L,0,1);
    ListInsert(L,0,2);
    ListInsert(L,0,3);
    ListInsert(L,0,4);
    ListInsert(L,0,5);
    Length(L);
    PrintLinkList(L);

    GetElem(L,2);
    PrintLinkList(L);
    LocateElem(L,5);
    LocateElem(L,1);

    printf("---- 删除第%d位元素 ----\n",2);
    ListDelete(L,2,e);
    PrintLinkList(L);
    printf("---- 删除完毕 ----\n---- 删除指定结点0上的元素 ----\n");
    ListSpecifiedDelete(L,0);
    PrintLinkList(L);
    printf("---- 删除完毕 ----\n\n");

    printf("---- 清空表L ----\n");
    ClearLinkedList(L);
    printf("---- 清空完毕 ----\n\n");

    LinkList A;
    InitList(A);
    ListInsert(A,0,1);
    ListInsert(A,0,2);
    ListInsert(A,0,3);
    ListInsert(A,0,4);
    ListInsert(A,0,5);
    Length(A);
    PrintLinkList(A);

    printf("\n---- 销毁表新建表A ----\n");
    DestroyLinkedList(A);   //暂且未知：销毁表运行后项目没停止
    printf("---- 销毁完毕 ----\n");
}
