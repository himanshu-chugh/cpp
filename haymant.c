#include<stdio.h>
#include<stdlib.h>
int main()
{
	int testCase;
	scanf ("%d",&testCase);
	while(testCase--){
	    int size;
	    scanf("%d" , &size);
	    int *a = (int*) malloc( sizeof(int)*size );
	    for(int i=0;i<size;i++){
            scanf ("%d",(a+i));
        }
        int i;
        int flag;
	    for( i = 0; i < size-1; i++) {
	        flag = 0;
            int j;
            for(j = i+1; j < size; j++){
                if(a[i] < a[j]){
                    flag = 1;
                }
	        }
            if(flag == 0){
                printf( "%d " , *(a+i) );
            }
	    }
        printf( "%d \n" , *(a+i) );
        free(a);
	}
	return 0;
}