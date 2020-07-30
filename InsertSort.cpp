//
// Created by 李金豪 on 2020/7/28.
//
#include <iostream>

/*
 * 插入排序
 */

//直接插入排序
void Insert_Sort(int A[], int n) {
    int i, j, temp;

    for (i = 1; i < n; ++i) {
        if (A[i] < A[i - 1]) {
            temp = A[i];

            for (j = i - 1; A[j] > temp && j >= 0; --j) {
                A[j + 1] = A[j];
            }
            A[j + 1] = temp;
        }
    }

    for (int k = 0; k < n; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");
}

//直接插入排序（带哨兵）
void InsertSort(int A[], int n) {
    int i, j;

    for (i = 2; i <= n; ++i) {
        if (A[i] < A[i - 1]) {
            A[0] = A[i]; //复制为哨兵，A[0]原先不存放元素

            for (j = i - 1; A[0] < A[j]; --j) { //从后往前查找待插入位置
                A[j + 1] = A[j];
            }
            A[j + 1] = A[0];
        }
    }

    for (int k = 1; k <= n; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");
}

//折半插入排序
void HalfInsertSort(int A[], int n) {
    int i, j, low, high, mid;

    for (i = 2; i <= n; i++) {
        A[0] = A[i];
        low = 1, high = i - 1;

        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] > A[0]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        for (j = i - 1; j >= high + 1; j--) {
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }

    for (int k = 1; k <= n; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");
}

//希尔排序
void ShellSort(int A[], int n) {
    //这里的A[0]不是哨兵，只是暂存单元
    int d, i, j;
    for (d = n / 2; d >= 1; d = d / 2) { //最后一个步长为1
        for (i = d + 1; i <= n; ++i) {
            if (A[i] < A[i - d]) {
                A[0] = A[i]; //暂存在A[0]
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d) {
                    A[j + d] = A[j];
                }
                A[j + d] = A[0];
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");
}

int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int B[] = {-1, 49, 38, 65, 97, 76, 13, 27, 49};
    int len1 = 8, len2 = 8;

    Insert_Sort(A, len1);
    InsertSort(B, len2);

    HalfInsertSort(B, len2);

    ShellSort(B, len2);

    return 0;
}
