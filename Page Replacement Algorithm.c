#include <stdio.h>

int findLRU(int time[], int n) {
    int pos=0; for(int i=1;i<n;i++) if(time[i]<time[pos]) pos=i; return pos;
}

int main() {
    int f,p; printf("Frames: "); scanf("%d",&f);
    printf("Pages: "); scanf("%d",&p);
    int page[p],frame[f],time[f],faults,j;
    for(int i=0;i<p;i++) scanf("%d",&page[i]);

    // FIFO
    faults=0; for(int i=0;i<f;i++) frame[i]=-1; j=0;
    printf("\nFIFO:\n");
    for(int i=0;i<p;i++){
        int hit=0; for(int k=0;k<f;k++) if(frame[k]==page[i]) hit=1;
        if(!hit){ frame[j]=page[i]; j=(j+1)%f; faults++; }
        for(int k=0;k<f;k++) printf("%d ",frame[k]==-1?-1:frame[k]); printf("\n");
    } printf("Faults=%d\n",faults);

    // LRU
    faults=0; for(int i=0;i<f;i++) frame[i]=-1;
    printf("\nLRU:\n");
    for(int i=0;i<p;i++){
        int hit=0,pos=-1;
        for(j=0;j<f;j++) if(frame[j]==page[i]){hit=1; time[j]=i;}
        if(!hit){ for(j=0;j<f;j++) if(frame[j]==-1){pos=j;break;}
            if(pos==-1) pos=findLRU(time,f);
            frame[pos]=page[i]; time[pos]=i; faults++;
        }
        for(j=0;j<f;j++) printf("%d ",frame[j]==-1?-1:frame[j]); printf("\n");
    } printf("Faults=%d\n",faults);

    // Optimal
    faults=0; for(int i=0;i<f;i++) frame[i]=-1;
    printf("\nOptimal:\n");
    for(int i=0;i<p;i++){
        int hit=0; for(j=0;j<f;j++) if(frame[j]==page[i]) hit=1;
        if(!hit){ int pos=-1,farthest=i;
            for(j=0;j<f;j++){ int found=0;
                for(int k=i+1;k<p;k++) if(frame[j]==page[k]){found=1;if(k>farthest){farthest=k;pos=j;}break;}
                if(!found){pos=j;break;}
            }
            if(pos==-1) pos=0; frame[pos]=page[i]; faults++;
        }
        for(j=0;j<f;j++) printf("%d ",frame[j]==-1?-1:frame[j]); printf("\n");
    } printf("Faults=%d\n",faults);
}
