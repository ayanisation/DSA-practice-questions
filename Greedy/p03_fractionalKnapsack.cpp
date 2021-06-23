#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool sortVal(Item a,Item b){
    double x = (double)a.value/a.weight;
    double y = (double)b.value/b.weight;
    return x>y;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,sortVal);
        double val = 0,wt=0;
        int i;
        for(i=0;i<n&&wt+arr[i].weight<=W;i++){
            wt+=arr[i].weight;
            val+=arr[i].value;
        }
        double left = W-wt;
        if(i!=n){
            val+=(left*arr[i].value)/arr[i].weight;
        }
        return val;
    }
        
};


int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
} 