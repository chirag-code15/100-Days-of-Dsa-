// Pair sum closest to 0 
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std; 
int main(){
    int n = 6 ; 
    int arr[] = {-21, -67, -37, -18, 4, -65} ; 
    // int arr[] = {-8,-66,-60} ; 
    sort(arr,arr+n) ; 
    int low = 0 ;
    int high = n-1 ; 
    int closest_sum = INT_MAX ; 
    while(low<high){
        int sum = arr[low]+arr[high] ;
        if(abs(sum)<abs(closest_sum)){
            closest_sum = sum ; 
        } 
        else if(abs(sum)==abs(closest_sum)){
            closest_sum = max(sum,closest_sum) ; 
        }
        if(sum<0){
            low++ ; 
        }
        else{
            high-- ; 
        }
    }
    cout<<closest_sum ; 
    return 0 ; 
}
