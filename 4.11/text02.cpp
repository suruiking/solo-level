#include<iostream>
#include<vector>
#include "solution.h"
using namespace std;
int main()
{
    vector<int>nums={1,2,4,6,9};
    int target =4;
    solution surui;
    int result=surui.search(nums,target);
    if(result!=-1)
    {
        cout<<"����ǵ�������"<<target<<"�������е�������"<<result<<endl;
    }
    else{
        cout<<"�����û��"<<target<<endl;
    }
    return 0;
}
