#include <stdio.h>
int main() {
    int arr[7]={10,20,30,40,50,60,70}, n=5, key=40, i, flag=0;
    for(i=0;i<n;i++){
        if(arr[i]==key){ printf("Found at %d\n",i); flag=1; break; }
    }
    if(!flag) printf("Not Found\n");
    return 0;
}
