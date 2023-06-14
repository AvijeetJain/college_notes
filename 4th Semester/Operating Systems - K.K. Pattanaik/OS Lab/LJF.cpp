#include<iostream>
 #include <bits/stdc++.h>
using namespace std;
int main()
{
    int at[10];
    int bt[10];
    for(int i=0;i<=4;i++)
    {
        cout<<"Enter the Arrival TIme and BURST TIME\n";
        cin>>at[i];
        cin>>bt[i];
        cout<<endl;

    }
    int tat=0,wt=0,ct=0;
    for(int j=0;j<=4;j++)

    {
        if(j==0)
        {
              tat=bt[j];
              wt=0;
              ct=bt[j];
     
        }
        else 
        {
            int count=0;
            int temp=0;
            if(j==1)
            {
                for( int k=j;k<=bt[0];k++)
            {
                if(bt[j]<=bt[k])
                {
                temp=bt[j];
                bt[j]=bt[k];
                bt[k]=temp;
                count=at[j];
                at[j]=at[k];
                at[k]=count;
                }
             
            } 
            }
            else
            {
            for( int k=j;k<=4;k++)
            {
                if(bt[j]<=bt[k])
                {
                temp=bt[j];
                bt[j]=bt[k];
                bt[k]=temp;
                count=at[j];
                at[j]=at[k];
                at[k]=count;
                }
             
            } 
            }
              wt=ct-at[j];
            ct=ct+bt[j];
            tat=ct-at[j];
        }
        cout<<"   "<<"Arrival Time"<<"   "<<"   "<<"Brust time"<<"  "<<"Completetion time"<<"  "<<"Total Around time"<<"  "<<"Waittime\n"<<"  ";
        cout<<"  "<<at[j]<<"   "<<bt[j]<<"   "<<ct<<"  "<<tat<<" "<<wt<<"   ";
        cout<<endl;
    }
    return 0;

}