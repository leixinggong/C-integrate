//
//  main.c
//  Array
//
//  Created by Zac on 2018/12/1.
//  Copyright © 2018 gonglx. All rights reserved.
//

#include <stdio.h>

/// 数组的本质 概念
void array1(void)
{
    int a[5][5]; //[5][5]
    int (*p) [4]; //[7][4]  数组指针
    p =(int(*)[4]) a;  /// 将a赋值给b 因为二维数组是逻辑二维  物理结构是线性的
    
    /// 取出地址 地址相减
    printf("%ld \n",&p [4][2] - &a [4][2]);
    
    
    int b[5] = {1,2,3,4,5};
    
    /// 将数组转换成为数组指针 &b+1 +1的步长为 int[5] ,因为 int[5] 是b的类型
    int *ptr = (int*)(&b + 1);
    ///b+1  加一个数组的步长 一个int(4byte)
    ///ptr - 1  ptr是 int 指针减1的步长是一个 int
    printf("%d,%d \n", *(b+1),*(ptr-1));
}

/// 归并排序
void array2(void)
{
    /// 数组归并算法
    int a[] = {1,3,12,29,43};
    int b[] = {2,4,6,11};
    
    int la = sizeof(a) / sizeof(a[0]);
    int lb = sizeof(b) / sizeof(b[0]);
    int k = 0;
    int i = 0 , j= 0;
    
    int c[la+lb];
    
    while (i < la && j < lb)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        
        else if (a[i] > b[j])
        {
            c[k++] = b[j++];
        }
        
        else
        {
            c[k++] = a[j++];
            c[k++] = b[j++];
        }
    }
    
    /// 代表 a[] 已经将全部的数据 写入到数组c中  那么将b数组中的数据写到数组c中
    if (la == i)
    {
        while (j < lb)
        {
            c[k++] = b[j++];
        }
    }
    
    /// 代表 b[] 已经将所有的数据 写入c[] 中,那么将a数组中的数据写到数组c中
    if (lb == j)
    {
        while (i < la)
        {
            c[k++] = a[i++];
        }
    }
    
    for (int n = 0; n < k; n++)
    {
        printf("%d  ",c[n]);
    }
    
    putchar(10);
    
}


///求最大值 最次值
void array3(void)
{
    int arr[10] = {10,10,10,10,0,12,4,9};
    int max;
    int smax;
    max = arr[0];
    smax = arr[1];
    
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] > max)
        {
            smax = max;
            max = arr[i];
        }
        else if (smax == max)
        {
            smax = arr[i];
        }
        else if (arr[i] > smax)
        {
            smax = arr[i];
        }
    }
    putchar(10);
}

///冒泡排序
void popsortArray(int * arr , int len)
{
    for (int i = 0; i < len; i++)
    {
        int flag = 1;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                flag = 0;
                arr[j] ^= arr[j+1];
                arr[j+1] ^= arr[j];
                arr[j] ^= arr[j+1];
            }
        }
        
        if (flag == 1)
        {
            break;
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    putchar(10);
}

///选择排序
void selectSortArray(int * array , int len)
{
    int idx = 0;
    
    for (int i = 0; i < len - 1; i++)
    {
        idx = i;
        for (int j = i+1; j < len; j++)
        {
            if (array[idx] > array[j])
            {
                idx = j;
            }
        }
        
        if (i != idx )
        {
            array[i] ^= array[idx];
            array[idx] ^= array[i];
            array[i] ^= array[idx];
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        printf("%d ",array[i]);
    }
    putchar(10);
}

///快速排序
void quickeSort(int * array, int low , int height)
{
    if (low < height)
    {
        int l = low;
        int h = height;
        int pivot = array[low];
        
        while (l < h)
        {
            while (pivot < array[h] && l < h)
                h--;
            array[l] = array[h];
            
            while (pivot > array[l] && l < h)
                l++;
            array[h] = array[l];
        }
        
        array[h] = pivot;
        
        quickeSort(array, l + 1,height);
        quickeSort(array, low, h - 1);
    }
}

int search2find(int * array,int len,int find)
{
    int l = 0;
    int h = len - 1;
    int mid = 0;
    
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (find == array[mid])
        {
            return mid;
        }
        else if (find > array[mid])
        {
            l = mid + 1;
        }
        else if (find < array[mid])
        {
            h = mid - 1;
        }
    }
    return -1;
    
}

int main(int argc, const char * argv[]) {
    
    int array[10] = {100,1,40,29,45,22,98,2,83,75};
    int len = sizeof(array) / sizeof(array[0]);
    //popsortArray(array, len);
    //selectSortArray(array, len);
    
    quickeSort(array, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d ",array[i]);
    }
    putchar(10);
    
    int index = search2find(array, len, 98);
    
    if (index < 0)
    {
        printf("find none");
        return -1;
    }
    printf("find = %d \n",index);
    
    return 0;
}
