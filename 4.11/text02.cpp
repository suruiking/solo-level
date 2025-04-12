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
        cout<<"苏睿智的数字是"<<target<<"在数组中的索引是"<<result<<endl;
    }
    else{
        cout<<"苏睿智没了"<<target<<endl;
    }
    return 0;
}
