//
// Created by 李金豪 on 2020/7/30.
//
#include <iostream>

/*
 * 交换排序
 */

//交换两个变量的值
void swap(int & i, int & j) {
    int temp = j;
        j = i;
        i = temp;
}

//冒泡排序（从后往前），使结果递增
void BubbleSort(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        bool flag = false; //表示本趟冒泡是否发生交换的标志

        for (int j = n - 1; j > i; --j) { //一趟冒泡过程
            if (A[j] < A[j - 1]) { //若为逆序就交换；当两个值相等时，不交换，保证稳定性
                swap(A[j], A[j - 1]); //交换
                flag = true;
            }
        }

        if (flag == false) {
            for (int k = 0; k < n; ++k) {
                printf("%d\t", A[k]);
            }
            printf("\n");

            return;
        }
    }
}

int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int len = 8;

    BubbleSort(A, len);

    return 0;
}
