//��������������飺����.cpp�ļ����е�C���Դ���
//AΪ������ȷд������[Ӧ�ñȽ���Ҫ]��BΪ�����ᵽ���ĸ�������&�Լ���д������������������
// Created by Administrator on 2024/4/28.
//���Ա��������
#include <cstdio>

//��̬���� - �����ٲ���
#define MaxSize 10 // ������󳤶�
typedef struct {
    int data[MaxSize];  //ElemType data[MaxSize];
    int length;
}SqList;

//A - ��ʼ��
void InitList(SqList& L) {
    L.length = 0;
}

//A - ����λ��i����eԪ�� - O(n)
//��������β����i = n+1��Ԫ�ز����ƣ�O(1)
//������ͷ����i = 1��n��Ԫ�غ��ƣ�O(n)
//ƽ�������n/2 ---- �����㷨���ڿ��Կ������α�P29
bool ListInsert(SqList& L, int i, int e) {  //��дΪ��int& e
    if (i < 1 || i > L.length + 1) { //����i�ķ�Χ��1 - n+1����1λǰ �� ���һλ��
        return false;
    }
    if(L.length >= MaxSize){    //�洢�ռ��������ܲ���
        return false;
    }
    //�����Ϊ���������0��ʼ��������˳����1��ʼ������������ĵ�0λ��Ϊ���Ա�ĵ�1λ
    for (int j = L.length; j >= i; j--) {   //i֮ǰ���ݺ���
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;  //��i-1λ�÷���Ԫ��e
    L.length++;     //����+1
    return true;
}

//A - ����λ��iɾ��Ԫ�أ�����ɾ����Ԫ��ֵe - O(n)
//��������βɾ��i = n��Ԫ�ز����ƣ�O(1)
//������ͷɾ��i = 1��n��Ԫ�غ��ƣ�O(n)
//ƽ�������(n-1)/2 ---- �����㷨���ڿ��Կ������α�P30
bool ListDelete(SqList& L, int i, int& e) { //i�ķ�Χ��1 - n����1λ �� ���һλ
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];  //��ɾ��Ԫ�ظ�ֵ��e
    for (int j = i; j < L.length; j++) {    //ɾ����λ�ú��Ԫ�أ���i��Ԫ��ǰ��
        L.data[j - 1] = L.data[j];
    }
    L.length--; //���Ա���-1
    return true;
}

//B - ��λ����Ԫ�أ���λ��i����Ԫ�أ�����ֵ
int GetElem(SqList L, int i) {
    if (i < 1 || i > L.length) {
        return 0;
    }
    return L.data[i - 1];
}

//A - ��ֵ����Ԫ�أ���ֵe����Ԫ�أ�����λ�� - O(n)
//��������ͷ���ң�Ԫ�ز����ƣ��Ƚ�1�Σ�O(1)
//������β����/����Ԫ�ز����ڣ��Ƚ�n�Σ�O(n)
//ƽ�������(n+1)/2 ---- �����㷨���ڿ��Կ������α�P30
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {   //�±�Ϊi��Ԫ��ֵΪe
            return i + 1;   //������ӦԪ��λ����+1����i+1
        }
    }
    return 0;   //����ʧ��
}

//B - ����˳���Ԫ��
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("��%dλΪ%d\t",i+1, L.data[i]);   // \t
    }
}

//B - ��ȡ��
void Length(SqList L) {
    int Length = L.length;
    printf("���Ա�ı�Ϊ��%d",Length);
}


int main() {
    //���� - ���Ա�ĳ�ʼ��
    int e;
    SqList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    printf("---- ���������ʼ���ݲ���ǰ ----\n");
    printf("����Ԫ��˳����Ԫ��Ϊ��");
    PrintList(L);
    printf("\n---- ��ʼ���ݲ������ ----\n\n");

    //���� - ����������ڵ�2λ����6
    printf("---- ��λ��2��λ�ò���Ԫ�� ----\n����ǰ��");
    PrintList(L);
    printf("\n");
    Length(L);
    ListInsert(L, 2, 6);// ����2
    printf("\n�����");
    int ii = 1;
    PrintList(L);
    printf("\n");
    Length(L);
    printf("\n---- ������� ----\n\n");

    //���� - ɾ��������ɾ����3��Ԫ��
    printf("---- ɾ��λ��Ϊ3��Ԫ��ǰ ----\n");
    if (ListDelete(L, 3, e)) {
        printf("ɾ��λ��3��Ԫ��%d��", e);
        PrintList(L);
        printf("\n");
        Length(L);
    }
    printf("\n---- ɾ��λ��Ϊ3��Ԫ����� ----\n\n");

    printf("��λ����� - λ��3�����ǣ�%d\n", GetElem(L, 3));
    printf("��λ����� - ��ֵ��4��λ���ǣ�%d\n", LocateElem(L, 4));
}

