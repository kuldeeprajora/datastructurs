#include<stdio.h>
int binarysearch(int arr[],int size,int element){
    int high , low , mid;
low=0;
high =size-1;
while(low<=high){
mid = (high+low)/2;
while(low<=high){
if(arr[mid]==element){
    return mid;
}
if (arr[mid]<element){
    low=mid+1;
}
else{
    high = mid-1;
}
}
return -1;
}}
int main(){
    int arr[]={1,8,54,65,86,89,99,100};
  int size=sizeof(arr)/sizeof(int);
  int element = 65;
  int searchindex=binarysearch(arr,size,element);
printf("the element %d you searched for is on %d index",element,searchindex);
return 0;
}