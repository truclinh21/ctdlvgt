#include <stdio.h>
typedef struct {
    int year;  
    int songuoi; 
}danhsach;

int main() {
    int n; 
    int i;
    printf("so nam:  ");
    scanf("%d", &n);
    danhsach M[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &M[i].year);
        scanf("%d", &M[i].songuoi);
    }
 
    int max_songuoi = M[0].songuoi;
    int min_songuoi = M[0].songuoi;
    int max_year = M[0].year;
    int min_year = M[0].year;
    
    for (i = 1; i < n; i++) {
        if (M[i].songuoi > max_songuoi) {
            max_songuoi = M[i].songuoi;
            max_year = M[i].year;
        }
        if (M[i].songuoi < min_songuoi) {
            min_songuoi = M[i].songuoi;
            min_year = M[i].year;
        }
    }
    
    printf("nam co so nguoi sinh ra nhieu nhat: %d \n", max_year);
    printf("nam co so nguoi sinh ra it nhat  : %d \n", min_year);
    
    return 0;
}
