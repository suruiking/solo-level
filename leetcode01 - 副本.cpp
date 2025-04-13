class Solution {
    public://给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
        int search(vector<int>& nums, int target) {
            int left =0;
            int right =nums.size()-1;//1定义左右范围
            while(left<=right){         //2开始循环，左小于右的时候。中间值是必需品。
            int middle=(left+right)/2;
            if(nums[middle]>target)      //3大于中间值 left变成mid+1，进行下一次取中间值，再比较。
                                         // 小于中间值 right变成mid-1，进行下一次取中间值，再比较
            {                            // 等于中间值 中间值等于目标，返回中间值
                                           //2，3其实就是对二分的实现。
              right=middle-1;            //4right<left时，或者不符合算法循环的时候，return-1。
            }
            else if(nums[middle]<target)
            {
                left=middle+1;
            }
            else 
           {return middle;}                   
        }
        return -1;
        }
       
    };
    class Solution {
        public://给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
            int searchInsert(vector<int>& nums, int target) {
                int left=0;
                int right=nums.size()-1; //1
                while(left<=right)
                {
                    int middle=(left+right)/2;//23满足条件的时候
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
                return right+1;//4 不满住条件
                
            }
        };
        //给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

        //如果数组中不存在目标值 target，返回 [-1, -1]。
        class Solution {
            public:
                vector<int> searchRange(vector<int>& nums, int target) {
                     int left=0;
                    int right=nums.size()-1;
                    int rightmax=-1;               //1
                    while(left<=right)
                    {//寻找右边界
                        int middle=(left+right)/2;     //23
                        if(nums[middle]<target)
                        {
                            left=middle+1;
                        }
                        else if(nums[middle]>target)
                        {
                            right=middle-1;
                        }
                        else
                        { 
                             rightmax=middle;//当前最大，然后继续往右扩张。mid=target才会取代这次的rightmax，不然只会执行上面直到
                             left=middle+1;   //left>right
                        
                        }
                    }
               
                     left=0;
                     right=nums.size()-1;
                    int leftmax=-1;
                    while(left<=right)
                    {//左边界                          //123
                         int middle=(left+right)/2;
                        if(nums[middle]<target)
                        {
                            left=middle+1;
                        }
                        else if(nums[middle]>target)
                        {
                            right=middle-1;
                        }
                        else
                        {
                            right=middle-1;
                            leftmax=middle;
                             
                            
                        }
                    }
                  
                    return {leftmax,rightmax};//当left>right的时候，left跟right的max都已经最大了，所以直接取就好了
            
                }
            };
            //给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
            //由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
            class Solution {
                public:
                    int mySqrt(int x) {
                     if(x<=1)
                     return x;
                     int left=0;
                     int right=x;
                     int target=0;
                     while(left<=right)
                     {
                        long mid=(left+right)/2;
                        long result=mid*mid;
                        if(result>x)
                        {
                            right=mid-1;
                            
                        }
                        else if(result<x)
                        {
                            
                            left=mid+1;
                            target=mid;
                        }
                        else
                       { return mid;}
                        
                     }
                        return target;
                    }
                };
                //给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

                //完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
                class Solution {
                    public:
                        bool isPerfectSquare(int num) {
                            int left=0;
                            int right=num;
                            int result =0;
                            while(left<=right)
                            {
                                
                                long mid=(left+right)/2;
                                long z=mid*mid;
                                if(num<z)
                                {
                                   right=mid-1;
                                   result=false;
                                }
                                else if(num>z)
                                {
                                    left=mid+1;
                                    result=mid;
                                }
                               
                                else
                                {return mid;}
                            }
                    
                            return false;
                        }
                    };