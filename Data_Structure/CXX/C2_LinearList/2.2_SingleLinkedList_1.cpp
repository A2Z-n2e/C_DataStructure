//
// Created by Administrator on 2024/4/29.
//�������������
#include <cstdio>
#include <cstdlib>
//���嵥����������
typedef struct LNode {
    int data;           //������
    struct LNode* next; //ָ����
}LNode, * LinkList;

//A - �������ʼ��
bool InitList(LinkList& L){     //?
    L = (LNode*) malloc((sizeof (LNode)));
    L->next = NULL;
    return true;
}

//��ͷ��㵥����Ľ��� - ͷ�巨
LinkList List_HeadInsert(LinkList& L) {// ͷ�巨��������������
    LNode* s;
    int x;
    L = (LNode *)malloc(sizeof(LNode));// ����ͷ���
    L->next = NULL;						// ��ʼΪ������,��Ȼ��ָ��ȷ���ĵط�
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
//��ͷ��㵥����Ľ��� - β�巨
LinkList List_TailInsert(LinkList& L) {// β�巨
    int x;
    L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
    LNode* s, * r = L;
    scanf("%d", &x);
    while (x != 0) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;// β���Ľ����һ��Ϊ��
    return L;
}

//A - ��λ��i���ҽ��:ͷ����λ����0��1�ǵ�һ���ڵ�
LNode* GetElem(LinkList L, int i) {
    // ����д��
	/*if(i == 0){
		return L;				// ����ͷ���
	}
	if(i < 1){
		return NULL;			// ���Ϸ�
	}
	int j = 1; 					// ��ʼ��Ϊ1����ΪĬ��λ��0��ͷ���, 1�ǵ�һ���ڵ�
	LNode *p = L->next;			// Ĭ���ҵ���һ�����
	while(p != NULL && j < i){	// ����Ѱ��
		p = p->next;
		j++;
	}*/
    // ��Ƶд���������
    if (i < 0) {    //i����<0������ûд
        return NULL;
    }
    LNode* p = L;	//ͷ��㿪ʼ
    int j = 0;	//��ǰ���λ�򣬴�ͷ����0��ʼ
    while (p != NULL && j < i) {	//����Ѱ�ҵ���i�����
        p = p->next;
        j++;
    }
    printf("��λ���� - ��%dλΪ:%d\n",i,p->data);
    return p;   //���ص�i������ָ��/NULL
}

//A - ��ֵe���ҽ��
LNode* LocateElem(LinkList L, int e) {
    LNode* p = L->next;	//�ȵó�ͷ������һ���ڵ㣬����Ԫ/��һ���ڵ�

    /*while (p != NULL && p->data != e) {	//����Ԫ/��һ���ڵ㿪ʼ����������Ϊe�Ľ��
        p = p->next;
        int i = 0;
        if(p->data != e){
            p = p->next;
            i++;
        }else{
            printf("��ֵ���� - ֵΪ%d��Ԫ��Ϊ:��%dλ\n",e,i);
        }
    }
    return p;*/   //���ظý���ָ��/NULL

    //����д������Ϊ��������㿴
    int i = 0,a = 0;
    while(p != NULL && p->data !=e){
        p = p->next;
        i++;
        a = i;
    }
    printf("ֵΪ%d��Ԫ���ڵ�%dλ\n",e,a);
    return p;
}

// ���������ڽ��p������½ڵ�-����1
bool InsertNextNode(LNode* p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));	// ������
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;									// ��s�������p֮��
    return true;
}
// ǰ��������ڽ��p֮ǰ����Ԫ��e-����2
bool InsertPriorNode(LNode* p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->next = p->next;	// �½��s���¸��ڵ���p���¸��ڵ�
    p->next = s;		// �½��s����p֮��
    s->data = p->data;	// ��p�е�Ԫ�ظ��Ƶ�s��
    p->data = e;		// ��p�е�Ԫ�ظ���Ϊe����ɽ���
    return true;
}

//A - ����
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

// - ��λ��i��λ�ò��������
bool ListInsert2(LinkList& L, int i, int e) {
    LNode* p = GetElem(L, i - 1);					// �ҵ�i��ǰһ�����
    return InsertNextNode(p, e);
}
// ��λ��i��λ�ò��������
bool ListInsertBefore(LinkList& L, int i, int e) {
    LNode* p = GetElem(L, i);						// �ҵ�i��㣬���ﲻͬ����һ�������ҵ�i-1��ǰһ�����
    return InsertPriorNode(p, e);
}

//A - ɾ����i��Ԫ��
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
//A - ɾ��ָ�����
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
    LNode* q = p->next;	// ��qָ��p�ĺ�̽��
    p->data = p->next->data;	// �ͺ�̽�㽻��������
    p->next = q->next;	// ��*q��������жϿ�
    free(q);			// �ͷ�ԭ��̽��Ĵ洢�ռ�
    return true;
}

// ��λ��i��λ��ɾ��������-����1
bool ListDelete2(LinkList& L, int i, int& e) {
    LNode* p = GetElem(L, i - 1);					// �ҵ�i��ǰһ�����
    if (p == NULL) {
        return false;
    }
    LNode* q = p->next;	// ��qָ��ɾ�����
    p->next = q->next;	// ��q�ڵ������жϿ�
    e = q->data;			// eΪ��ɾ������ֵ
    free(q);			// �ͷű�ɾ�����Ŀռ�
    return true;
}
//  ɾ��ָ�����p, ��ͨ��ǰ���ڵ�������ý�����������ɾ��������ע�����һ���ڵ㲻������ɾ��-����2
bool DeleteZhidingLNode(LNode* p) {
    if (p == NULL) {
        return false;
    }
    LNode* q = p->next;	// ��qָ��p�ĺ�̽��
    p->data = q->data;	// �ͺ�̽�㽻��������
    p->next = q->next;	// ��*q��������жϿ�
    free(q);			// �ͷ�ԭ��̽��Ĵ洢�ռ�
    return true;
}
// ��λ��i��λ��ɾ��������
bool ListDeleteZhiding(LinkList& L, int i, int& e) {
    LNode* p = GetElem(L, i);					// �ҵ�i���
    if (p == NULL) {
        return false;
    }
    return DeleteZhidingLNode(p);
}

//A - ���
void Length(LinkList L) {
    int len = 0;
    LNode* p = L;
    while (p->next != NULL) {// ע����p->next
        p = p->next;
        len++;
    }
    printf("�������ȣ�%d\n",len);
    /*return len;*/
}
// �������
void PrintLinkList(LinkList& L) {
    LNode* p = L;
    int i = 0;
    while (p->next != NULL) {
        p = p->next;
        printf("��%dλΪ%d\t",i, p->data);// �ź�����Ϊͷ�����û��ֵ��
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
    printf("������ɣ�\n");
}

void ClearLinkedList(LNode *L){
    LNode *p;
    while (L->next){
        p = L->next;
        L->next = p->next;
        delete(p);
        break;
    }
    printf("�����ɣ�\n");
}

int main() {
    /*int e;
    // ʵ�ֲ���
    LinkList L;
    printf("����ֵ������������0����\n");
    //InitList(L);
    List_TailInsert(L);// β��
    //	List_HeadInsert(L);// ͷ��
    PrintLinkList(L);
    GetElem(L,1);
    Length(L);
    // ���ֲ��뷽�����ԣ�������i��λ�ò���ڵ�
    printf("��λ��3��λ�ò�����\n");
    ListInsert(L, 3, 33);
    PrintLinkList(L);
    printf("��λ��5��λ�ò�����\n");
    ListInsertBefore(L, 5, 55);
    PrintLinkList(L);
    // ����ɾ����������
    printf("ɾ��λ��2�Ľ��\n");
    ListDelete(L, 2, e);			// ͨ��ǰ���ڵ�
    PrintLinkList(L);
    printf("ɾ��λ��4�Ľ��\n");
    ListDeleteZhiding(L, 4, e);// ��ͨ��ǰ���ڵ㣬ͨ���������ݷ���
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

    printf("---- ɾ����%dλԪ�� ----\n",2);
    ListDelete(L,2,e);
    PrintLinkList(L);
    printf("---- ɾ����� ----\n---- ɾ��ָ�����0�ϵ�Ԫ�� ----\n");
    ListSpecifiedDelete(L,0);
    PrintLinkList(L);
    printf("---- ɾ����� ----\n\n");

    printf("---- ��ձ�L ----\n");
    ClearLinkedList(L);
    printf("---- ������ ----\n\n");

    LinkList A;
    InitList(A);
    ListInsert(A,0,1);
    ListInsert(A,0,2);
    ListInsert(A,0,3);
    ListInsert(A,0,4);
    ListInsert(A,0,5);
    Length(A);
    PrintLinkList(A);

    printf("\n---- ���ٱ��½���A ----\n");
    DestroyLinkedList(A);   //����δ֪�����ٱ����к���Ŀûֹͣ
    printf("---- ������� ----\n");
}
