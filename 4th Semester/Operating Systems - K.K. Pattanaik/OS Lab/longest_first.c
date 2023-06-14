#include<stdio.h>
int main()
{
    int n,i,j;
    n=5;
    int Arr[5],BT[5];

    printf("Arrival times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&Arr[i]);
    }
    
    printf("Burst times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&BT[i]);
    }
    
    int Bt[5],Ct[5];
    for(i=0;i<n;i++){
        Bt[i]=BT[i];
    }

    int count=0;
    j=0;

    while(j<n)
    {
        int max=-1,ind=-1;
        for(i=0;i<n;i++)
        {
            if(Bt[i]==max)
            {
                if(Arr[i]<Arr[ind])
                ind=i;
            }
            
            else if(Bt[i]>max)
            {
                if(Arr[i]<=count)
                {
                    max=Bt[i];
                    ind=i;
                }
            }
            
        }
        if(ind!=-1)
        {
            Ct[ind]=BT[ind]+count;
            count+=BT[ind];
            j++;
            Bt[ind]=-2;
        }
        else
        count++;
    }
    
    int TAT[5],WT[5];
    
    for(i=0;i<n;i++){
        TAT[i]=Ct[i]-Arr[i];
    }
    
    for(i=0;i<n;i++){
        WT[i]=TAT[i]-BT[i];
    }
    
    printf("\nProcess Table:\nPid\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),Arr[i],BT[i],Ct[i],TAT[i],WT[i]);
    }
    
    
    float avgtat=0;
    for(i=0;i<n;i++)   avgtat+=(float)TAT[i];
    printf("\nAverage TAT: %f",avgtat/n);
    float avgwt=0;
    for(i=0;i<n;i++)   avgwt+=(float)WT[i];
    printf("\nAverage WT: %f",avgwt/n);
    return 0;
}