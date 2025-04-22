
#include<iostream>
using namespace std;
struct listnode
{
    int val;
    listnode*next;
    listnode(int x):val(x),next(nullptr){}
};
class linkedlist{
    listnode*head;
    int size;
    public:
    // ���캯��
    linkedlist() : head(nullptr), size(0) {}
    // �������������� public ��
    ~linkedlist() {
        while (head != nullptr) {
            listnode* tmp = head;
            head = head->next;
            delete tmp;}
        }
    void remove(int val)
{
    listnode*dummyhead=new listnode(0);
    dummyhead->next=head;
    listnode*cur=dummyhead;
    while(cur->next!=nullptr)
    {
        if(cur->next->val==val)
        {//ʵ�ֹ���
            listnode*tmp=cur->next;//�Ȱ�ֵ���һ��ָ����ܿճ�����
            cur->next=cur->next->next;
            delete tmp;
        }
        else
        {
           cur=cur->next;
        }
    }
    head=dummyhead->next;
    delete dummyhead;
    
}
void printlist()
{//��ӡ����
    listnode*cur=head;
    while(cur!=nullptr)
    {
        cout<< cur->val <<endl;
        cur=cur->next;
    }
}
void inserthead(int val)
{//��������
    listnode*newnode=new listnode(val);
    newnode->next= head;
    head=newnode;
    size++;
}
void insertback(int val)
{
    listnode*newnode=new listnode(val);
    if(head==nullptr)
    {//Ϊ�յ�ʱ���½ڵ����ͷ���
        head=newnode;
    }
    else{
        listnode*cur=head;//��ͷ������
        while(cur->next)
        {
            cur=cur->next;//������cur���������һ���ڵ�
        }
        cur->next=newnode;//���һ���ڵ����ӵ��½ڵ㡣
        size++;
    }

}
};
int main()
{
    linkedlist surui;
    //��������
   surui.insertback(1);
   surui.insertback(2);
   surui.insertback(6);
   surui.insertback(3);
   surui.insertback(6);
   surui.inserthead(9);
    cout<<"���ڵ�����"<<endl;
    surui.printlist();
    surui.remove(6);
    cout<<"ɾ���������"<<endl;
    surui.printlist();
    /*while(head!=nullptr)
    {
        listnode*tmp=head;
        head=head->next;
        delete tmp;
    }*///���������������Զ��ͷ��ڴ�
        return 0;
}

   
