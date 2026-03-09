#include <stdio.h>

int main() {
    int n, i, time=0, smallest, completed=0;
    int at[20], bt[20], rt[20], wt[20], tat[20], finish;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT and BT of P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(completed!=n){
        smallest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(smallest==-1 || rt[i]<rt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1){
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0){
            completed++;
            finish=time;

            tat[smallest]=finish-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];
        }
    }

    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
}
