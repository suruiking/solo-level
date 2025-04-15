给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int slow=0;
            for (int fast=0;fast<nums.size();fast++)
            {
                if(nums[fast]!=val)
                {
                  nums[slow] =nums[fast];
                  slow++;
                }
            }
            return slow;
        }
    };
    给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
    class Solution {
        public:
            int removeDuplicates(vector<int>& nums) {
                int slow=0;
                for(int fast=1;fast<nums.size();fast++)
                {
                    if(nums[fast]!=nums[slow])
                    {
                        
                        slow++;
                        nums[slow]=nums[fast];
                        
                    }
                }
                return slow+1;
            }
        };
        给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
        请注意 ，必须在不复制数组的情况下原地对数组进行操作。
        class Solution {
            public:
                void moveZeroes(vector<int>& nums) {
                    int slow=0;
                    for(int fast=0;fast<nums.size();fast++)
                    {
                        if(nums[fast]!=0)
                        {
                          nums[slow]=nums[fast];
                          slow++;
                        }
                    }
                    for(int i=slow;i<nums.size();i++)
                    {
                        nums[i]=0;
                    }
                }
            };
            给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n=nums.size();
           vector<int>result(n);
           int left=0;int right=n-1;int max=n-1;
           while(left<=right)
           {
            int maxleft=nums[left]*nums[left];
            int maxright=nums[right]*nums[right];
            if(maxleft>maxright)
            {
                result[max]=maxleft;
                max--;
                left++;
            }
            else
            {
                result[max]=maxright;
                max--;
                right--;
            }
           }
           return result;
            
        }
    };