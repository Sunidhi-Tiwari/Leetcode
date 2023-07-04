//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    
    unordered_set<int> numSet;

    for (int i = 0; i < size; i++) {
        // Check if arr[i] + N or arr[i] - N is already in the set
        if ((numSet.find(arr[i] + n) != numSet.end()) || (numSet.find(arr[i] - n) != numSet.end())) {
            return true; // Pair with difference N found
        }

        // Insert arr[i] into the set
        numSet.insert(arr[i]);
    }

    return false;
    
}