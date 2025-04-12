#include<iostream>
typedef struct seqlist
{
int *array;
int size;
int capacity;
}
void SeqListInit(SeqList* psl);//初始化
// 顺序表尾插
void SeqListPushBack(SeqList* psl, int x);