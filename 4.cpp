#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> array = merge(nums1, nums2, nums1.size(), nums2.size());
    int arraySize = array.size();
    return arraySize % 2 == 1 ? array[arraySize / 2] : (double(array[arraySize / 2 - 1] + array[arraySize / 2]) / 2);
  }

  vector<int> merge(vector<int> leftArray, vector<int> rightArray, int leftArrayLength, int rightArrayLength)
  {
    vector<int> array;
    int i = 0, j = 0;

    //比较这两个数组的值，哪个小，就往数组上放
    while (i < leftArrayLength && j < rightArrayLength)
    {
      //谁比较小，谁将元素放入大数组中,移动指针，继续比较下一个
      if (leftArray[i] < rightArray[j])
      {
        array.push_back(leftArray[i]);
        i++;
      }
      else
      {
        array.push_back(rightArray[j]);
        j++;
      }
    }

    //如果左边的数组还没比较完，右边的数都已经完了，那么将左边的数抄到大数组中(剩下的都是大数字)
    while (i < leftArrayLength)
    {
      array.push_back(leftArray[i]);
      i++;
    }
    //如果右边的数组还没比较完，左边的数都已经完了，那么将右边的数抄到大数组中(剩下的都是大数字)
    while (j < rightArrayLength)
    {
      array.push_back(rightArray[j]);
      j++;
    }
    return array;
  }
};

int main()
{
  Solution *s = new Solution();
  vector<int> data1{};
  vector<int> data2{2,3};

  cout << s->findMedianSortedArrays(data1, data2) << endl;
  return 0;
}