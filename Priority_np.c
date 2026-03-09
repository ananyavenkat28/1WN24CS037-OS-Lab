#include <stdio.h>

int main() {
    int n,i,j,time=0,highest,pos;
    int at[20],bt[20],pr[20],wt[20],tat[20],ct[20],done[20]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT Priority of P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    }

    int completed=0;

    while(completed<n){
        highest=9999;
        pos=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                if(pr[i]<highest){
                    highest=pr[i];
                    pos=i;
                }
            }
        }

        if(pos==-1)
            time++;
        else{
            time+=bt[pos];
            ct[pos]=time;
            tat[pos]=ct[pos]-at[pos];
            wt[pos]=tat[pos]-bt[pos];

            done[pos]=1;
            completed++;
        }
    }

    printf("\nP\tAT\tBT\tPR\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],wt[i],tat[i]);
}
