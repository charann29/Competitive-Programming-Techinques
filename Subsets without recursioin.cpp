#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void solve();
void merge(int a[],int s,int e);
void merge_sort(int a[],int s,int e);
int indexSearcher(int a[],int b[],int h,int i);
int main() {
int t;
    scanf("%d",&t);/* This is for printing testcases*/
    while(t--)
    {
        solve();
        printf("\n");
    }
    return 0;
}
    int compare(const void *a, const void *b) {
return(*(int*)a > *(int*)b);
}
void solve()
{
    int n;
    scanf("%d",&n);
    int a[n+1],main_a[n];
    a[n]=-1;



for(int i=0;i<n;i++)
{
    scanf("%d",&main_a[i]);

}
qsort(main_a, n, sizeof(int), compare);//for sorting
    /* loading all the elements to another array so that it won't miss its original  
      sorted order and it is used as reference*/
    for(int e=0;e<n;e++){
        a[e]=main_a[e];
    }


int j=0;
int i=0;
for( j=0;j<n;j++){
for( i=0;i<=j;i++)
printf("%d ",a[i]);//This can be optimized also.
    printf("\n");
}
    a[i]=-1;// the invalid value is replaced by -1 every time
    int u=i;//assigning or updating u to last valid index every time

    while(a[0]!=main_a[n-1]){    
if(a[u-1]==main_a[n-1]) 
 /* If we reach last index every time the penultimate index is updated to it's corresponding consecutive index (successor).*/
{
    u=0;
    while(a[u]!=-1)
    u++;


    a[u-2]=indexSearcher(a,main_a,a[u-2],n);//gives the successor of the penultimate index
    a[u-1]=-1;
    for (j=0;j<=u-2;j++){
        printf("%d ",a[j]);
    }
     u=0;
    while(a[u]!=-1)
    u++;
    //printer(a,i-1);
    printf("\n");
}

else if(a[u-1]!=main_a[n-1])
  /*If we don't reach the last index we print until we get there every time in a  new line by updating the index by 1 */
{
    u=0;
    while(a[u]!=-1)
    u++;
    a[u]=indexSearcher(a,main_a,a[u-1],n);/*here we get the correct lexical value
      i.e., the element which should come after the current element in lexical order.*/
    a[u+1]=-1;
    for (j=0;j<u+1;j++){
        printf("%d ",a[j]);
    }
     u=0;
    while(a[u]!=-1)
    u++;

    printf("\n");
}
}

}

int indexSearcher(int a[],int main_a[],int s,int n)
{
    for(int i=0;i<n;i++){
    if(s==main_a[i]){
    return main_a[i+1];
    }
    }
    return 0; 
}
