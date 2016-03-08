#include <iostream>

using namespace std;

//����ṹ
struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

//����һ��������
ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;

    return pNode;
}

//�������β��ӽ��
void AddToTail(ListNode **pHead, int value)
{
    ListNode *pNew = CreateListNode(value);
    if(*pHead == NULL)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}

void PrintList(ListNode *pHead)
{
    if(pHead == NULL)
        cout<<"����Ϊ��"<<endl;
    else
        cout<<"����:";
    ListNode* pNode = pHead;
    while(pNode)
    {
        cout<<" "<<pNode->m_nValue;
        pNode = pNode->m_pNext;
    }
    cout<<endl;
}

//��ֵ�������в��ң���ɾ���ý��
void RemoveNode(ListNode **pHead, int value)
{
    if( pHead == NULL || *pHead == NULL)
        return ;

    ListNode* pToBeDeleted = NULL;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;
        if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }
    if(pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

int main()
{
    ListNode* pList1 = NULL;
    AddToTail(&pList1, 1);
    PrintList(pList1);
    AddToTail(&pList1, 2);
    PrintList(pList1);
    AddToTail(&pList1, 3);
    PrintList(pList1);
    AddToTail(&pList1, 4);
    PrintList(pList1);
    AddToTail(&pList1, 5);
    PrintList(pList1);

    PrintList(pList1);

    RemoveNode(&pList1,5);
    PrintList(pList1);
    RemoveNode(&pList1,4);
    PrintList(pList1);
    RemoveNode(&pList1,3);
    PrintList(pList1);
    RemoveNode(&pList1,2);
    PrintList(pList1);
    RemoveNode(&pList1,1);
    PrintList(pList1);

    return 0;
}
