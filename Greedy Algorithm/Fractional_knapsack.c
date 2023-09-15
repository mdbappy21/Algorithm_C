#include <stdio.h>

struct knapsack{
    float weight;
    float profit;
    float dencity;
};

int main(){
    int n;
    float Sack_Capacity;

    float Max_weight=0,Max_profit=0;

    printf("Enter how much weight : ");
    scanf("%d",&n);
    struct knapsack p[n];
    float x[n];
    for(int i=0;i<n;i++){
        printf("Enter Weight and Profit : ");
        scanf("%f",&p[i].weight);
        scanf("%f",&p[i].profit);
        p[i].dencity=(p[i].profit)/(p[i].weight);
        printf("%d\t%d\t%d\n",p[i].weight,p[i].profit,p[i].dencity);
    }

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n;j++){
            if(p[i].dencity<p[j].dencity){
                struct knapsack temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }


    printf("Enter Sack capacity : ");
    scanf("%d",&Sack_Capacity);


    while(Sack_Capacity!=0){
        int i=0;
        if(p[i].weight<Sack_Capacity){
            x[i]=1;
            Sack_Capacity-=p[i].weight;
        }
        else{
            x[i]=Sack_Capacity/p[i].weight;
            Sack_Capacity-=p[i].weight*x[i];
        }
        i++;
    }

    for(int i=0;i<n;i++){
        Max_weight+=x[i]*p[i].weight;
        Max_profit+=x[i]*p[i].profit;
    }
    printf("Max Weight : %f\n",Max_weight);
    printf("Max profit : %f\n",Max_profit);

}
