/*
create the function void update(int *a,int *b), which reads two integers as argument, 
and sets a with the sum of them, 
and b with the absolute difference of them.
*/

#include <stdio.h>
#include <cstdlib> 

void update(int *a,int *b) {
    //a is the sum
    int tempA = (*a) + (*b);
    //b is the absolute difference
    int tempB = abs( *a - *b );  
    //update both
    (*a) = tempA;
    (*b) = tempB;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
