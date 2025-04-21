给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res;
            int starthan = 0, endhan = matrix.size() - 1;
            int startbian = 0, endbian = matrix[0].size() - 1;
            while (starthan <= endhan && startbian <= endbian) {
                // 上层遍历：从左到右
                for (int i = startbian; i <= endbian; ++i) {
                    res.push_back(matrix[starthan][i]);
                }
                starthan++;
                if (starthan > endhan) break; // 检查行越界，及时终止
    
                // 右边遍历：从上到下
                for (int i = starthan; i <= endhan; ++i) {
                    res.push_back(matrix[i][endbian]);
                }
                endbian--;
                if (startbian > endbian) break; // 检查列越界，及时终止
    
                // 下边遍历：从右到左
                for (int i = endbian; i >= startbian; --i) {
                    res.push_back(matrix[endhan][i]);
                }
                endhan--;
                if (starthan > endhan) break; // 检查行越界，及时终止
    
                // 左边遍历：从下到上
                for (int i = endhan; i >= starthan; --i) {
                    res.push_back(matrix[i][startbian]);
                }
                startbian++;
                if (startbian > endbian) break; // 检查列越界，及时终止
            }
            return res;
        }
    };
    给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

    class Solution {
        public:
            vector<vector<int>> generateMatrix(int n) {
                 vector<vector<int>> matrix(n, vector<int>(n, 0)); // 初始化n x n矩阵
                int startrow = 0, endrow = n - 1; // 当前层的行边界
                int startcol = 0, endcol = n - 1; // 当前层的列边界
                int current_num = 1; // 当前填充的数字 
                while(startrow <= endrow && startcol <= endcol) 
                {
                    //1.上边边界
                    for(int col=startcol;col<=endcol;col++)//row行，col列
                    {
                       matrix[startrow][col] = current_num++;
                    }
                    //2.右边边界
                      for(int row=startrow+1;row<=endrow;row++)
                    {
                       matrix[row][endcol] = current_num++;
                    }
                    if (startrow < endrow && startcol < endcol)
                    {
                    //3.下边界
                    for(int col=endcol-1;col>=startcol;col--)
                    {
                        matrix[endrow][col]=current_num++;
                    }
                    //4左边界
                    for(int row=endrow-1;row>startrow;row--)
                    {
                       matrix[row][startcol]=current_num++;
                    }
                    }
                    startrow++;
                    endrow--;
                    startcol++;
                    endcol--;
        
        
        
                }
                return matrix;
                
            }
        };
        给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int left=0;
            int sum=0;
            int minlen =INT_MAX;
            for(int right=0;right<nums.size();right++)
            {
                sum+=nums[right];
                while(sum>=target)
                {
                    int nowlen=right-left+1;
                    if(nowlen<minlen)
                    {
                        minlen=nowlen;
                       
                    }
                     sum-=nums[left];
                        left++;
    
                }
            }
            return minlen==INT_MAX?0:minlen;
            
        }
    };
    给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
    class Solution {
        public:
            vector<int> sortedSquares(vector<int>& nums) {
              int n=nums.size();
              int left =0; int right= n-1; int max=n-1;
              vector<int>result(n);
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
        