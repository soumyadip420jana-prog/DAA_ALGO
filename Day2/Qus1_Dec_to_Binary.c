
#include<stdio.h>
#include<time.h>

void binary(int n,int bits){
if(bits==0) return;

binary(n>>1 ,bits-1);
printf("%d",n&1);
}

int main(){
    int n;
    clock_t st,end;
    double time;

    st=clock();

    printf("enter a decimal number: ");
    scanf("%d",&n);

    binary(n,16);
  
    end=clock();

time=(double)(end-st) / CLOCKS_PER_SEC;

printf("\nthe execution time is %d\n",time);
    return 0;
}