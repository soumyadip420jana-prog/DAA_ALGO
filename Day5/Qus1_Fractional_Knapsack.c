#include<stdio.h>

struct Item{
    int weight;
    int profit;
    float ratio;
};

int main(){
int n;
int capacity;
float total;

printf("enter the number of items:");
scanf("%d",&n);

struct Item item[n];

printf("enter the capacity:");
scanf("%d",&capacity);

//taking input 
for(int i=0;i<n;i++){
printf("Enter profit and weight of item %d: ", i + 1);
scanf("%d %d", &item[i].profit, &item[i].weight);

 item[i].ratio=(float)item[i].profit/item[i].weight;
}

//sort
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){

        if(item[i].ratio<item[j].ratio){

            struct Item temp=item[i];
            item[i]=item[j];
            item[j]=temp;
        }

    }
}

for(int i=0;i<n;i++){

    if(capacity >=item[i].weight){
//fill full
capacity=capacity-item[i].weight;
total=total+item[i].profit;
    }else{
        total=total+item[i].ratio*capacity;//till the fill iteams

        capacity=0;
        break;
    }
}

    printf("\nMaximum Profit = %.2f\n", total);
    

}