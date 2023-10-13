//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/329103/problem/C
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
  
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
  
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
int main(){
int n,k;
scanf("%lld %lld",&n,&k);
int a[n];
for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
}
selectionSort(a,n);
int sum=0;
for(int i=n-1;i>=0;i--){
    if(k==0){break;}
    
    if(a[i]>=0){sum+=a[i];};
    k--;
}
printf("%lld",sum);
return 0;
}