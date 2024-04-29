//AΪ������ȷд������[Ӧ�ñȽ���Ҫ]��BΪ�����ᵽ���ĸ�������&�Լ���д�����������������֣�CΪ����û�ᵽ���Ĳ���
// Created by Administrator on 2024/4/28.
//���Ա��������
#include <cstdio>
#include <cstdlib>
//��̬����
#define InitSize 5      //������󳤶�
#define IncreaseSize 5  //ÿ�θı�Ĳ���
typedef struct {
    int* data;
    int MaxSize,length;
}SqList;

//A - ��ʼ��
void InitList(SqList& L) {
    L.data = (int*)malloc(sizeof(int) * InitSize);// ��ʼ���ռ�
    L.length = 0;
    L.MaxSize = InitSize;
}

//C - ��չ�ռ䣬ʵ�ָı������С
void IncreaseSpace(SqList& L, int len) {
    printf("�ռ�+5\n");
    int* p = L.data;// ������
    L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));// �¿ռ�
    for (int i = 0; i < L.length; i++) {// �����ɵ�����
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;// ����
    free(p);// �ͷ�ԭ���ռ�
}

//A - ����λ��i����eԪ��
bool ListInsert(SqList& L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    // ������ˣ�����ռ�
    if (L.length >= L.MaxSize) {
        IncreaseSpace(L, IncreaseSize);
    }
    // �ȴ�ǰ�����ƶ��ٲ���
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//A - ����λ��iɾ��Ԫ�أ�����ɾ����Ԫ��ֵe
bool ListDelete(SqList& L, int i, int& e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    // ֱ�ӴӺ���ǰ��ɾ��
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

//B - ��λ��i����Ԫ�أ�����ֵ
int GetElem(SqList& L, int i) {
    if (i < 1 || i > L.length) {
        return 0;
    }
    return L.data[i - 1];
}

//A - ��ֵe����Ԫ�أ�����λ��
int LocateElem(SqList& L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

//B - ����˳���Ԫ��
void PrintList(SqList& L) {
    for (int i = 0; i < L.length; i++) {
        printf("��%dλΪ%d\t",i+1, L.data[i]);   // \t
    }
    printf("\n");
}

//B - ��ȡ��
void Length(SqList L){
    int Length = L.length;
    printf("���Ա�ı�Ϊ��%d",Length);
}

//B- �пղ���
void Empty(SqList L){
    if(L.length == 0)
        printf("��գ���Ϊ��%d\n",L.length);
    else
        printf("��ǿգ���Ϊ��%d\n",L.length);
}

//C - ������Ա�
void ClearList(SqList& L){
    L.length = 0;
    printf("����ձ�\n");
}

//B - ���ٱ�
void DestroyList(SqList& L){
    free(L.data);   //�ͷſռ�
    L.data = NULL;
    L.length = 0;
    L.MaxSize = 0;
    printf("�����ٱ�\n");
}

int main() {
    int e;
    SqList L;
    InitList(L);
    printf("---- ��ʼ���� ----\n");
    Empty(L);   //��Ҫ��ʼ�����ܲ��Ա��Ƿ�Ϊ�գ�����
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);// ����
    PrintList(L);
    Empty(L);
    printf("---- ��ʼ������� ----\n\n");

    //���� - �������
    printf("---- ��ǰ�Ѿ�������5��Ԫ�� ----\n");
    ListInsert(L, 2, 6);    //��ǰ�Ѿ�������5�����ٲ�������ӿռ�
    printf("2λ����Ԫ��6��");
    PrintList(L);
    Length(L);
    printf("\n");
    printf("7λ����Ԫ��7��");
    ListInsert(L,7,7);  //�˴οռ仹��ʣ�࣬�������ӿռ�
    PrintList(L);
    Length(L);
    printf("\n---- ����Ԫ����� ----\n\n");

    //���� - ɾ��������ɾ����3��Ԫ��
    printf("---- ɾ��λ��Ϊ7��Ԫ��ǰ ----\n");
    if (ListDelete(L, 7, e)) {
        printf("ɾ��λ��7��Ԫ��%d��", e);
        PrintList(L);
        Length(L);
    }
    printf("\n---- ɾ��λ��Ϊ7��Ԫ����� ----\n\n");

    printf("��λ����� - λ��3�����ǣ�%d\n", GetElem(L, 3));
    printf("��λ����� - ��ֵ��4��λ���ǣ�%d\n", LocateElem(L, 4));

    //���� - ��ձ�
    printf("\n---- ��ձ� ----\n");
    ClearList(L);
    Length(L);
    printf("\n");
    Empty(L);
    printf("---- ��ձ���� ----\n");

    //���� - ���ٱ�
    ListInsert(L, 1, 1);
    printf("\n---- ���ٱ� ---\n");
    Length(L);
    printf("\n");
    Empty(L);
    DestroyList(L);
    Length(L);
    printf("\n");
    Empty(L);
    printf("---- ���ٱ���� ----");
}

