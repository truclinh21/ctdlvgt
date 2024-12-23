#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool snt(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}


bool sntchia4du3(int p) {
    return (p % 4 == 3);
}


int nhohoncann(int M[], int m) {
    int a = 0;
    for (int i = 2; i <= m; i++) {
        if (snt(i) && sntchia4du3(i)) {
            M[a++] = i;
        }
    }
    return a;
}

int blum(int M2[], int M[], int n, int N) {
    int a = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int blum = M[i] * M[j];
            if (blum < N) {
                M2[a++] = blum;
            }
        }
    }
    return a;
}

bool ktrablum(int M2[], int n, int m) {
    for (int i = 0; i < n; i++) {
        if (M2[i] == m) return true;
    }
    return false;
}

void capblum(int M2[], int n, int N) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = M2[i] + M2[j];
            if (sum < N && ktrablum(M2, n, sum)) {
                printf("(%d, %d) Tong: %d\n", M2[i], M2[j], sum);
            }
        }
    }
}

int main() {
    int N, M;

    scanf("%d", &N);

    int M1[100];
    int snt = nhohoncann(M1, (int)sqrt(N));

    int Mblum[100];
    int blum1 = blum(Mblum, M1, snt, N);

    for (int i = 0; i < blum1; i++) {
        printf("%d ", Mblum[i]);
    }
    printf("\n");

    capblum(Mblum, blum1, N);

    printf("so Blum M: ");
    scanf("%d", &M);
    if (ktrablum(Mblum, blum1, M)) {
        printf("%d la so Blum!\n", M);
    } else {
        printf("%d khong phai la so Blum!\n", M);
    }

    return 0;
}
