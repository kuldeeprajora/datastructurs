#include<stdio.h>
void printarr(int arr[] , int size){
for (int a=0; a< size; a++){
    printf(" %d",arr[a]);
}
}
void deletion(int arr[],int size ,int index){
for (int i=index;i<size-1;i++){
arr[i]=arr[i+1];
}
}
int main(){
int arr[100]={5,15,10,15,20}; 
int size = 5,index = 1;
printf("array before deletion");
printarr(arr , size);
deletion(arr, size ,index);
printf("\n");
size--;
printf("array after deletion");
printarr(arr , size);
    return 0;
}