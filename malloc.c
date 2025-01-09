#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr ;
    int num , i;

    printf("Enter number of elements :");
    scanf("%d",&num);
    printf("Entered number of elements: %d\n", num);

    ptr = (int*)malloc(num * sizeof(int));

    if (ptr == NULL){
        printf("Memory not allocated.\n");
        return 0;
    }
    else{
        printf("Memory allocated.\n");

        for (i = 0; i < num; ++i){
            ptr[i] = i+1;
        }

        printf("The number of elements of the array :");
        for (i = 0; i < num; ++i){
            printf("%d ", ptr[i]);
        }
    }

    return 0;
}