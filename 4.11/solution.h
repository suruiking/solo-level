
#include<vector>
using namespace std;
class solution
{
    public:
    int search(vector<int>&nums,int target);
};
int solution::search(vector<int>&nums,int target)
//这是对solution类中search成员函数的定义，在头文件中是对他的声明。
{
    int left=0;
    int right =nums.size()-1;
    
    while(left<=right)
    {
        int middle = left + (right - left) / 2;
        if(nums[middle]<target)
        {
            left=middle+1;
        }
        else if(nums[middle]>target)
        {
            right=middle-1;
        }
        else return middle;
    }
    return -1;
}