#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int a;
    scanf("몇 킬로그램 %d", &a);
    for (int i = 0; i < 5; i++) {
        if (a - (3 * i) >= 0) {
            if ((a - (3 * i)) % 5 == 0) {
                printf("%d", i + (a - (3 * i)) / 5);
                return 0;
            }
        }
        
    }
    printf("%d", -1);
}
