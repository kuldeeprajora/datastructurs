#include<stdio.h>
int linear(int arr[],int size, int element){
for (int i=0;i<size;i++){
if(arr[i]==element){
return i;
}
};
    return -1;


}
int main(){
int arr[]={10,122,20,25,15,154,56,1,464,446,};
int size = sizeof(arr)/sizeof(int);
int element = 154;
int searchindex = linear(arr,size,element);
printf("searched element %d is found at index %d",element,searchindex);
return 0;
}