#include "Q01.h"


SeqList* createSeqList(int size)
{
    SeqList* seqList = (SeqList*)malloc(sizeof(SeqList));
    seqList->length = size;
    seqList->elem = new int[size];
    for(int i=0; i<size; i++)
        seqList->elem[i] = i;
    
    return seqList;
}

void binarySearch()
{
    int size = 9;
    int target = 5;

    SeqList* seqList = createSeqList(10);
    // for(int i=0; i<seqList->length; i++)
    //     cout << seqList->elem[i] << ' ';
    // cout << endl;

    int low=0, hight=size-1;
    while(low <= hight)
    {
        int mid = (hight + low) / 2;
        if(seqList->elem[mid] > target)
            hight = mid - 1;
        else if(seqList->elem[mid] < target)
            low = mid + 1;
        else
        {
            cout << "target index: " << mid - 1 << endl;
            return;
        }
    }
    
    cout << "target index no be found." << endl;
}
