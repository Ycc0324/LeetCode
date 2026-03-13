#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
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
template <typename T>
void mergeSort(std::vector<T> &arr, int left, int mid, int right)
{
    int leftArrSize = mid - left + 1;
    int rightArrSize = right - mid;
    // 用临时数组存储分半后的数组
    std::vector<T> leftArr(leftArrSize);
    std::vector<T> rightArr(rightArrSize);
    for (int i = 0; i < leftArrSize; i++)
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
    // 排序这个分区的数组，并存入原数组arr
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
// 递归分区
template <typename T>
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

// Insertion Sort
template <typename T>
void insertSort(std::vector<T> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] <= arr[j])
            {
                T temp = 0;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
// Bad Time complexity:O(n²);
// Good Time complexity:O(n);
// Average Case：O(n²);
// Space complexity:O(1);

// Quick Sort
template <typename T>
int paritition(std::vector<T> &arr, int low, int high)
{
    T pivot = arr[low];
    while (low < high)
    {
        // From left to right, find the values bigger than the pivot value and place them in the right slot.
        while (low < high && arr[high] >= pivot)
        {
            high--;
        }
        arr[low] = arr[high];
        // From right to left, find values smaller than the pivot and put them in the left slot.
        while (low < high && arr[low] <= pivot)
        {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}
template <typename T>
void quickSort(std::vector<T> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = paritition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
// Bad Time complexity:O(n²);
// Average Case：O(n&logn);
// Space complexity:O(1);

// Heap Sort

// In data structures, there is a fixed mathematical formula to find the position of the last non-leaf node: n/2 - 1
void heapSort(std::vector<int> &arr, int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
    {
        //Note the situation where there is only a left child and no right child.
        if (son + 1 <= end && arr[son] < arr[son + 1])
        {
            son++;
        }
        if (arr[dad] <= arr[son])
        {
            std::swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
        else
            return;
    }
}
void adjustHeap(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapSort(arr, i, n - 1);
    }
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapSort(arr, 0, i - 1);
    }
}
// Adjustment time complexity: O(n)
// Sorting time complexity: O(logn)
// Total time complexity: O(nlogn)
int main()
{
#ifdef InsertSort
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    insertSort(arr);
    std::cout << "InsertSOrt->排序后" << std::endl;
    for (auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#elif MergeSort
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeArr(arr, 0, arr.size() - 1);
    std::cout << "MergeSort->排序后" << std::endl;
    for (auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#elif QuickSort
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    quickSort(arr, 0, arr.size() - 1);
    std::cout << "quickSort->排序后" << std::endl;
    for (auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#elif HeapSort
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    adjustHeap(arr);
    std::cout << "HeapSort->排序后" << std::endl;
    for (auto e : arr)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

#endif

    return 0;
}