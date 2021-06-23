#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        multiset<long long int>pos,neg;
        for(int i=0;i<n;i++){
            if(a[i]<0)
            neg.insert(a[i]);
            else
            pos.insert(a[i]);
        }
        while(k && !neg.empty()){
            long long int x = *(neg.begin());
            pos.insert(abs(x));
            neg.erase(neg.begin());
            k-=1;
        }
        long long int sum=0;
        if(!neg.empty()){
            for(auto it:neg)
            sum+=it;
        }
        long long int x = *(pos.begin());
        pos.erase(pos.begin());
        if(k%2)
        sum-=x;
        else
        sum+=x;
        for(auto it:pos)
        sum+=it;
        return sum;
    }
};

int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}