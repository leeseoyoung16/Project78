#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 20


int sorted[MAX_SIZE];
int n;
int move, compare;


int min1(int x, int y) {
    return(x < y) ? x : y;
}
void print_array(int arr[], int size) { //과정 출력
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int list[], int left, int mid, int right, int print) {
    int i, j, k, l;
    
    i = left; j = mid + 1; k = left;

    while (i <= mid && j <= right) {
        compare++;
        if (list[i] <= list[j]) {
            sorted[k++] = list[i++];
        }
        else {
            sorted[k++] = list[j++];
        }
    }

    while (i <= mid) {
        sorted[k++] = list[i++];
    }

    while (j <= right) {
        sorted[k++] = list[j++];
    }

    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
        move++;
    }
    if (print == 0)
        print_array(list, n);
}

void merge_sort(int list[], int left, int right, int print) { //합병 정렬
    int mid;
    if (left < right) {
        mid = (right + left) / 2;
        merge_sort(list, left, mid, print);
        merge_sort(list, mid + 1, right, print);
        merge(list, left, mid, right, print);
    }

}


void merge_sort_iter(int list[], int left, int right, int print) { //반복적 방법
    for (int m = 1; m <= right - left; m = 2 * m) {
        for (int i = left; i < right; i += 2 * m) {
            int from = i;
            int mid = i + m - 1;  
            int to = min1(i + 2 * m - 1, right);

            merge(list, from, mid, to, print); 
        }
    }
}

int main(void) {
    int list[MAX_SIZE];
    int i, j;
    int move_count = 0;
    int compare_count = 0;
    int count = 1;
    n = MAX_SIZE;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    printf("Original list\n");
    print_array(list, n);

    printf("\nShell Sort\n");
    merge_sort(list, 0, n - 1, 0);
    //merge_sort_iter(list, 0, n - 1, 0); //반복적 합병 정렬
    

    move_count += move;
    compare_count += compare;
    

    for (j = 1; j <= 19; j++) {
        move = 0; compare = 0;
        for (i = 0; i < n; i++)
            list[i] = rand() % 100;

        merge_sort(list, 0, n - 1, 1);

        move_count += move;
        compare_count += compare;
        count++;

    }
    printf("Average Move Count: %d\n", move_count / count);
    printf("Average Compare Count: %d\n", compare_count / count);



    return 0;
}