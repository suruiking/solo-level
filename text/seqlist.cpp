#include<seqlist.h>
void SeqListInit(seqlist*psl0)
{
    psl->arrayn=NULL;
    psl->size=0;
    psl-capacity=0;
}
void seqListPushBack(SeqList* psl, int x) {
    CheckCapacity(psl);
    psl->array[psl->size++] = x;}
    
