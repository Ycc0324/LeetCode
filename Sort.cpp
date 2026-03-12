#include <iostream>
#include <vector>
// 二分查找
bool binarySearch(std::vector<int> &arr, int target)
{
    int n = arr.size();
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else if (arr[right] > target)
        {
            right = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
// 归并排序
void mergeSort(std::vector<int> &arr, int left, int mid, int right)
{
    int leftArrSize=mid-left+1;
    int rightArrSize=right-mid;
    std::vector<int> leftArr(leftArrSize);
    std::vector<int> rightArr(rightArrSize);
    for (int i = 0; i <leftArrSize; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightArrSize; i++)
    {
        rightArr[i] = arr[mid + 1 + i]; 
    }
    int leftIndex = 0;
    int rightIndex = 0;
    int arrIndex = left;
    while (leftIndex < leftArrSize && rightIndex < rightArrSize)
    {

        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[arrIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[arrIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        arrIndex++;
    }
    while (leftIndex < leftArrSize)
    {
        arr[arrIndex] = leftArr[leftIndex];
        leftIndex++;
        arrIndex++;
    }
    while (rightIndex < rightArrSize)
    {
        arr[arrIndex] = rightArr[rightIndex];
        rightIndex++;
        arrIndex++;
    }
}
void merge(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge(arr, left, mid);
        merge(arr, mid + 1, right);
        mergeSort(arr, left, mid, right);
    }
}
int main()
{
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    merge(arr, 0, arr.size() - 1);
    std::cout<<"排序后"<<std::endl;
    for (auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout<<std::endl;
    return 0;
}