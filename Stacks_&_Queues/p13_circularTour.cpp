#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
   int s = 0,c = 0,d = 0;
   for(int i=0;i<n;i++)
   {
       c+=p[i].petrol-p[i].distance;
       if(c<0)
       {
           s=i+1;
           d+=c;
           c=0;
       }
   }
   return c+d>0?s:-1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}