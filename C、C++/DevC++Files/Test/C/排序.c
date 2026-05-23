#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 冒泡排序
void BubbleSort(int *arr, int len)
{
    _Bool flag;
    for (int i = 0; i < len && flag != 0;)
    {
        flag = 0;
        for (int j = 0; j < len - i;)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
            j++;
        }
        i++;
    }
}

// 插入排序
void InsertSort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int j = i, temp = arr[i];
        while (j > 0 && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

// 选择排序
void SelectSort(int arr[], int len)
{
    int tem = 0, _min = INT_MAX;
    while (tem != len)
    {
        for (int i = tem; i < len; i++)
        {
            if (arr[i] < _min)
            {
                swap(&_min, &arr[i]);
            }
        }
        swap(&arr[tem], &_min);
        tem++;
    }
}




int main()
{
    int arr[] = {1, 3, 2, 5, 7, 8, 9, 4, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]); // 使用%d输出整数
    }

    // BubbleSort(arr, length);
    // InsertSort(arr, length);
    SelectSort(arr, length);

    printf("\n排序后: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]); // 使用%d输出整数
    }
    puts("");
    return 0;
}
