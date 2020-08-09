//
// Created by 李金豪 on 2020/8/2.
//
#include <iostream>

/*
 * 归并排序
 */

int * B = (int *) malloc(sizeof(int) * 8 + 1); //辅助队列B

//将前后相邻的两个有序表归并为一个有序表
void Merge(int A[], int low, int mid, int high) {
    for (int k = low; k <= high; ++k) {
        B[k] = A[k]; //将A中中所有元素复制到B中
    }

    int i, j, k;
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; ++k) {
        if (B[i] <= B[j]) { //比较B中左右两段中的元素大小
            A[k] = B[i++]; //将较小值复制到A中
        } else {
            A[k] = B[j++];
        }
    }

    while (i <= mid) { //若第一个表未检查完，复制剩余元素
        A[k++] = B[i++];
    }

    while (j <= high) { //若第二个表未检查完，复制剩余元素
        A[k++] = B[j++];
    }

}

//二路归并排序
void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }

    for (int k = 0; k < 8; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");
}

int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};

    MergeSort(A, 0, 7);

    return 0;
}
