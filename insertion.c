#include<stdio.h>
int main(){
int arr[100]={10,15,25,30,35};
int size=5, capacity=100, index=2,element=20,i;
printf("before insertion\n");
for (i=0;i<=size -1;i++){
    printf("array = %d \n",arr[i]);
}
if (size>=capacity){
return -1;
}
for( i =size-1 ;i>=index;i--){
arr[i+1]=arr[i];

}

arr[index]=element;
printf("after insertion\n");

for (i=0;i<=size;i++){
    printf("array = %d \n",arr[i]);
}
return 0;
}