#include<iostream>
#include<vector>
//二分查找
bool binarySort(std::vector<int> &arr,int target)
{
    int n=arr.size();
    int left=0;
    int right=arr.size()-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(arr[mid]<target)
        {
            left=mid+1;
        }
        else if(arr[right]>target)
        {
            right=mid-1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
