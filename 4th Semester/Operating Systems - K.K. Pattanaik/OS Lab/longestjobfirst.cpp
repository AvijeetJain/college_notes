#include<iostream>

using namespace std;
int main()
{
      int n=0,temp,tt=0,max,d,i,j;
      float atat=0,awt=0,stat=0,swt=0;

      
      n=5;
      int a[5],b[5],e[5],tat[5],wt[5];
  
      for(i=0;i<n;i++)
      {
            cout<<"enter arrival time ";       //input
            cin>>a[i];
      }
      for(i=0;i<n;i++)
      {
            cout<<"enter burst time ";      //input
            cin>>b[i];
      }
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
                if(b[i]<b[j])
                {
                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;

                      temp=b[i];
                      b[i]=b[j];
                      b[j]=temp;
                }
          }
      }
      max=a[0];
      for(i=0;i<n;i++)
      {
            if(max<a[i])
            {
                  max=a[i];
                  d=i;
            }
      }
      tt=max;
      e[d]=tt+b[d];
      tt=e[d];

      for(i=0;i<n;i++)
      {
            if(a[i]!=max)
            {
                  e[i]=b[i]+tt;
                  tt=e[i];
            }
      }
      for(i=0;i<n;i++)
      {

            tat[i]=e[i]-a[i];
            stat=stat+tat[i];
            wt[i]=tat[i]-b[i];
            swt=swt+wt[i];
      }
      atat=stat/n;
      awt=swt/n;
      cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0;i<n;i++)
    {
    cout<<"P"<<i+1<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wt[i]<<"               "<<tat[i]<<endl;
    }

    cout<<"awt="<<awt<<" atat="<<atat;  //average waiting time and turn around time
}