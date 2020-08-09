//
// Created by 李金豪 on 2020/7/30.
//
#include <iostream>

/*
 * 选择排序
 */

//交换两个变量的值
void swap(int & i, int & j) {
    int temp = j;
    j = i;
    i = temp;
}

//简单选择排序
void SelectSort(int A[], int n) {
    for (int i = 0; i < n - 1; ++i) {

        int min = i; //记录最小元素的位置

        for (int j = i + 1; j < n; ++j) {
            if (A[min] > A[j]) {
                min = j; //更新最小元素的位置
            }
        }

        if (min != i) {
            swap(A[i], A[min]);
        }
    }

    for (int k = 0; k < n; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");
}

/*
 * 堆排序
 */

//将元素k为根的子树进行调整（小元素逐层“下坠”）
void MaxHeadAdjust(int A[], int k, int len) {
    A[0] = A[k]; //A[0]暂存子树的根结点

    for (int i = 2 * k; i <= len; i *= 2) { //沿k较大的子节点向下筛选
        if (i < len && A[i] < A[i + 1]) { //取较大的子节点的下标，满足i < len时，当前根结点k才有又孩子
            i++;
        }
        if (A[0] >= A[i]) { //将A[i]与双亲比较
            break;
        } else {
            A[k] = A[i]; //将A[i]调整到双亲节点上
            k = i; //修改k值，以便继续向下筛选
        }
    }
    A[k] = A[0]; //被筛选结点的值放在最终位置
}

//建立大根堆
void BuildMaxHeap(int A[], int len ) {
    for (int i = len / 2; i > 0; --i) {
        MaxHeadAdjust(A, i, len);
    }
}

//堆排序算法（大根堆）
void MaxHeapSort(int A[], int len) {
    BuildMaxHeap(A, len); //初始建堆

    for (int i = len; i > 1; i--) { //n - 1趟的交换和建堆过程
        swap(A[i], A[1]); //将堆顶和堆底元素互换
        MaxHeadAdjust(A, 1, i - 1); //调整，把剩余的i - 1个元素整理成堆
    }

    for (int k = 1; k <= len; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");
}

//将元素k为根的子树进行调整（大元素逐层“下坠”）
void MinHeadAdjust(int A[], int k, int len) {
    A[0] = A[k];

    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && A[i + 1] < A[i]) {
            i++;
        }
        if (A[0] <= A[i]) {
            break;
        } else {
            A[k] = A[i];
        }
        k = i;
    }
    A[k] = A[0];
}

//建立小根堆
void BuildMinHeap(int A[], int len) {
    for (int i = len / 2; i > 0; --i) {
        MinHeadAdjust(A, i, len);
    }
}

//堆排序算法（小根堆）
void MinHeapSort(int A[], int len) {
    BuildMinHeap(A, len);

    for (int i = len; i > 1; --i) {
        swap(A[1], A[i]);
        MinHeadAdjust(A, 1, i - 1);
    }

    for (int k = 1; k <= len; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");
}

int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int B[] = {-1, 49, 38, 65, 97, 76, 13, 27, 49};
    int len = 8;

    SelectSort(A, len);

    MaxHeapSort(B, len);
    MinHeapSort(B, len);

    return 0;
}

