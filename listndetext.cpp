#include<iostream>
using namespace std;
struct ListNode//创建节点
{
    int val;
    ListNode *next;//这是为了范返回对象节点的指针
    ListNode(int x):val(x),next(nullptr){};//构造函数
};
class LinkedList//创建链表
{
    public:
    ListNode*head;
    int size;
    LinkedList()//构造函数这就是对链表的初始化
{
      head=new ListNode(0);//反正是指针就会初始化为nullptr，是值就会初始化为0.
      size =0;
}
    ~LinkedList()//析构函数
    {
       ListNode*cur=head;//先把头指针赋值给cur，才能开始遍历，因为因为一旦 head 的值被错误地修改，可能会导致整个链表无法访问，出现严重的错误
       ListNode*temp=cur;//把cur的地址赋给temp方便等下的删除，不能直接删cur不然遍历不了
       cur=cur->next;//这就是遍历
       delete temp;
    }

    void inserthead(int val)//头插
    {
         ListNode*newnode=new ListNode(val);
        newnode->next=head;
        head=newnode;
        size++;

    }
    void insertback(int val)//尾插
    {
        ListNode*newnode=new ListNode(val);
        if(head==nullptr)
        {
            head=newnode;
        }
        else
        {ListNode*cur=head;
        while(cur->next)
        {
          cur=cur->next;
        }
         cur->next=newnode;
    }
    }
    void deletehead()//头删
    {
      if(head==nullptr)
      {
        cout<<"无头结点"<<endl;
      }
      else
      {
        ListNode*temp=head;
        head=head->next;
        delete temp;
      }
    }
    void deleteback()//尾删
    {
        if(head ==nullptr)
        {
            cout<<"头指针都是空的"<<endl;
        }
        else if (head->next==nullptr)
        {
            delete head;
            head=nullptr;
        }
        else
        {
         ListNode*cur=head;
         while (head->next->next!=nullptr)
         {
            cur=cur->next;
         }
         ListNode*temp=cur->next;
         cur->next=nullptr;
         delete temp;
        }
    }
         ListNode*search(int target)//查找
    {
         ListNode*cur=head;
         while(cur->next!=nullptr)
         {
            if(cur->val=target)
            {
                return cur;
            }
                cur=cur->next;
         }
         return nullptr;
    }
    void delpop(int target)//删除目标位置的节点
    {
        ListNode*newhead=new ListNode(0);
        newhead->next=head;
        ListNode*cur=newhead;

        while(cur->next!=nullptr)
        {
            if(cur->next->val==target)
            {
                ListNode*temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else
            {
                cur=cur->next;
            }
            //删除虚拟头节点
            ListNode*temp=newhead;
            head=newhead->next;
            delete temp;

        }
       
    }
    void printlist()//打印链表
    {
      ListNode*cur=head;
      while(cur->next!=nullptr)
      {
        cout<< cur->val <<" ";
        cur=cur->next;
      }
      
    }

};