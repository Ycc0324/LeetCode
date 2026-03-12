#include <iostream>
#include <vector>
#include <list>
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
// 数组归并排序，典型的分治思想
// 分解（Divide）：将待排序的数组分成两个子数组，每个子数组包含大约一半的元素。
// 解决（Conquer）：递归地对每个子数组进行排序。
// 合并（Combine）：将两个已排序的子数组合并成一个有序的数组。
template<typename T>
void mergeSort(std::vector<T> &arr, int left, int mid, int right)
{
    int leftArrSize=mid-left+1;
    int rightArrSize=right-mid;
    //用临时数组存储分半后的数组
    std::vector<T> leftArr(leftArrSize);
    std::vector<T> rightArr(rightArrSize);
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
    //排序这个分区的数组，并存入原数组arr
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
//递归分区
template<typename T>
void mergeArr(std::vector<T> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeArr(arr, left, mid);
        mergeArr(arr, mid + 1, right);
        mergeSort(arr, left, mid, right);
    }
}

//Insertion Sort
template<typename T>
void insertSort(std::vector<T> &arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]<=arr[j])
            {
                T temp=0;
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
}
//Bad Time complexity:O(n²);
//Good Time complexity:O(n);
//Average Case：O(n²);
//Space complexity:O(1);
int main()
{
    #ifdef InsertSort
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    insertSort(arr);
    std::cout<<"InsertSOrt->排序后"<<std::endl;
    for (auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout<<std::endl;
    #elif MergeSort
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeArr(arr,0,arr.size()-1);
    std::cout<<"MergeSort->排序后"<<std::endl;
    for (auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout<<std::endl;
    #endif
    return 0;
}