#include<bits/stdc++.h>
using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}

int main(){
    vector<vector<int>> input = {
        {1,0,3},
        {2,2,2}
    };
    sort(input.begin(),input.end(),sortcol);
    int size= input.size();
    int ct[size],tat[size],wt[size];
    ct[0]=input[0][1]+input[0][2];


    // cout<<"the completion time for process "<<input[0][0]<<" is "<<ct[0]<<"\n";
    for(int i=1;i<size;i++)
    {
        ct[i]=max(ct[i-1]+input[i][2]  , input[i][1]+input[i][2] );
        // cout<<"the completion time for process "<<input[i][0]<<" is "<<ct[i]<<"\n";
    }

    cout<<endl;

    tat[0]=ct[0]-input[0][1];
    // cout<<"the turn around time for process "<<input[0][0]<<" is "<<tat[0]<<"\n";
    for(int i=1;i<size;i++)
    {
        tat[i]=ct[i]-input[i][1];
        // cout<<"the turn around time for process "<<i<<" is "<<tat[i]<<"\n";
    }

    cout<<endl;

    wt[0]= tat[0]-input[0][2];
    // cout<<"the wait time for process "<<input[0][0]<<" is "<<wt[0]<<"\n";
    for(int i=1;i<size;i++)
    {
                wt[i]=tat[i]-input[i][2];
            // cout<<"the wait time for process "<<i<<" is "<<wt[i]<<"\n";
    }
    for (int i = 0; i < size; i++)
    {
        cout<<input[i][0]<<" "<<input[i][1]<<" "<<input[i][2]<<" "<<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<endl;
    }
    

    cout<<endl;
    return 0;
}