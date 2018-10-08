#include <stack>
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int stacksortcheck(int *arr,int size) {
    stack<int> s;
    int lowerbound=0;
    for (int i = 0; i < size; i++) {
        if(lowerbound && arr[i]<lowerbound) {
            return 0;
        }
        while(!s.empty() && s.top()<arr[i]) {
            lowerbound=s.top();
            s.pop();
        }
        s.push(arr[i]);   
    }
    return 1;
}
int main() {
    int tcases;
    scanf("%d", &tcases);
    while (tcases--) {
        int i, size;
        scanf("%d", &size);
        int arr[size];
        for (i = 0; i < size; i++) scanf("%d", &arr[i]);
        if (stacksortcheck(arr,size)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
