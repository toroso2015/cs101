#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hanoi(int n, char A, char B, char C) {
    if(n != 1) {
        hanoi(n-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n-1, B, A, C);
    }
}
int main() {
    
    clock_t begin,end;
    double cost;
    begin=clock();
    
    int n;
    printf("請輸入盤數：");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    
    end=clock();
    cost=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("花費%lf秒\n",cost);
    return 0;
} 