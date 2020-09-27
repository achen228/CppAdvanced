class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.empty())
        {
            return -1;
        }
        if(numbers.size() == 1)
        {
            return numbers[0];
        }

        for(int i = 0; i < numbers.size(); i++)
        {
            if(i + 1 < numbers.size())
            {
                //如果第 i + 1位比第 i位小，则第 i 位就是旋转部分的最后一个元素，第 i + 1位就是数组中最小的元素
                if(numbers[i + 1] < numbers[i])
                {
                    return numbers[i + 1];
                }
            }
            else
            {
                break;
            }
        }
        return numbers[0];
    }
};
