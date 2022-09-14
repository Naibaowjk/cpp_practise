#include<iostream>
using namespace std;

const int N = 1000010;
int a[N], temp[N], n;

void Sorttest(int a[], int l, int r) {
    if (l >= r) {
        return;
    }
//判断数据集
    int mid = l + r >> 1;
//取中间值
    Sorttest(a, l, mid);
    Sorttest(a, mid + 1, r);
//递归左右两边
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
//排序：比较大小，将较小的数据放入temp数组中
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
//判断某一个序列是否未放入temp数组中，并将其放入
    for (i = l, j = 0; i <= r; i++, j++) {
        a[i] = temp[j];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Sorttest(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}