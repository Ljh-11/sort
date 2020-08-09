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

//冒泡排序（从前往后），使结果递增
void Bubble_Sort(int A[], int n) {
    for (int i = n - 1; i > 0; --i) {
        bool flag = false;

        for (int j = 0; j < i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
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

/*
 * 快速排序
 */

//一趟划分操作
int Partition(int A[], int low, int high) {
    int pivot = A[low]; //将当前表中第一个元素设为枢轴

    while (low < high) {
        while (low < high && A[high] >= pivot) {
            high--;
            }
        A[low] = A[high]; //将比枢轴小的元素左移到左端

        while (low < high && A[low] <= pivot) {
            low++;
        }
        A[high] = A[low]; //将比枢轴大的元素右移到右端
    }
    A[low] = pivot;

    return low;
}

//快速排序算法
void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }

    for (int k = 0; k < 4; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");

}

int main() {
    int A[] = {1, 4, 2, 3};
    int len = 8;

    //BubbleSort(A, len);

    //Bubble_Sort(A, len);

    QuickSort(A, 0, 3);

    return 0;
}
