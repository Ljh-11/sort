//
// Created by ���� on 2020/7/30.
//
#include <iostream>

/*
 * ѡ������
 */

//��������������ֵ
void swap(int & i, int & j) {
    int temp = j;
    j = i;
    i = temp;
}

//��ѡ������
void SelectSort(int A[], int n) {
    for (int i = 0; i < n - 1; ++i) {

        int min = i; //��¼��СԪ�ص�λ��

        for (int j = i + 1; j < n; ++j) {
            if (A[min] > A[j]) {
                min = j; //������СԪ�ص�λ��
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
 * ������
 */

//��Ԫ��kΪ�����������е�����СԪ����㡰��׹����
void MaxHeadAdjust(int A[], int k, int len) {
    A[0] = A[k]; //A[0]�ݴ������ĸ����

    for (int i = 2 * k; i <= len; i *= 2) { //��k�ϴ���ӽڵ�����ɸѡ
        if (i < len && A[i] < A[i + 1]) { //ȡ�ϴ���ӽڵ���±꣬����i < lenʱ����ǰ�����k�����ֺ���
            i++;
        }
        if (A[0] >= A[i]) { //��A[i]��˫�ױȽ�
            break;
        } else {
            A[k] = A[i]; //��A[i]������˫�׽ڵ���
            k = i; //�޸�kֵ���Ա��������ɸѡ
        }
    }
    A[k] = A[0]; //��ɸѡ����ֵ��������λ��
}

//���������
void BuildMaxHeap(int A[], int len ) {
    for (int i = len / 2; i > 0; --i) {
        MaxHeadAdjust(A, i, len);
    }
}

//�������㷨������ѣ�
void MaxHeapSort(int A[], int len) {
    BuildMaxHeap(A, len); //��ʼ����

    for (int i = len; i > 1; i--) { //n - 1�˵Ľ����ͽ��ѹ���
        swap(A[i], A[1]); //���Ѷ��Ͷѵ�Ԫ�ػ���
        MaxHeadAdjust(A, 1, i - 1); //��������ʣ���i - 1��Ԫ������ɶ�
    }

    for (int k = 1; k <= len; ++k) {
        printf("%d\t", A[k]);
    }
    printf("\n");
}

//��Ԫ��kΪ�����������е�������Ԫ����㡰��׹����
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

//����С����
void BuildMinHeap(int A[], int len) {
    for (int i = len / 2; i > 0; --i) {
        MinHeadAdjust(A, i, len);
    }
}

//�������㷨��С���ѣ�
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

