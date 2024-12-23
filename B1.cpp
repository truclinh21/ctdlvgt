#include <stdio.h>

void sapxep(int arr[], int n) {
    int red = 0, white = 0, blue = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            red++;
        else if (arr[i] == 1)
            white++;
        else
            blue++;
    }

    int m = 0;

    for (int i = 0; i < red; i++) {
        arr[m++] = 0;
    }

    for (int i = 0; i < white; i++) {
        arr[m++] = 1;
    }

    for (int i = 0; i < blue; i++) {
        arr[m++] = 2;
    }
}

int main() {
	
    int arr[] = {2, 0, 2, 0, 0, 1, 0, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sapxep(arr, n);

    printf(" ");
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            printf("do ");
        else if (arr[i] == 1)
            printf("trang ");
        else
            printf("xanh ");
    }

    return 0;
}
