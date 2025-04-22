
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
    // 构造函数
    linkedlist() : head(nullptr), size(0) {}
    // 将析构函数放在 public 下
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
        {//实现过程
            listnode*tmp=cur->next;//先把值存进一个指针才能空出手来
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
{//打印链表
    listnode*cur=head;
    while(cur!=nullptr)
    {
        cout<< cur->val <<endl;
        cur=cur->next;
    }
}
void inserthead(int val)
{//插入链表
    listnode*newnode=new listnode(val);
    newnode->next= head;
    head=newnode;
    size++;
}
void insertback(int val)
{
    listnode*newnode=new listnode(val);
    if(head==nullptr)
    {//为空的时候新节点就是头结点
        head=newnode;
    }
    else{
        listnode*cur=head;//从头结点遍历
        while(cur->next)
        {
            cur=cur->next;//这里让cur遍历到最后一个节点
        }
        cur->next=newnode;//最后一个节点链接到新节点。
        size++;
    }

}
};
int main()
{
    linkedlist surui;
    //建立链表
   surui.insertback(1);
   surui.insertback(2);
   surui.insertback(6);
   surui.insertback(3);
   surui.insertback(6);
   surui.inserthead(9);
    cout<<"现在的链表"<<endl;
    surui.printlist();
    surui.remove(6);
    cout<<"删除后的链表"<<endl;
    surui.printlist();
    /*while(head!=nullptr)
    {
        listnode*tmp=head;
        head=head->next;
        delete tmp;
    }*///在类中析构函数自动释放内存
        return 0;
}

   
