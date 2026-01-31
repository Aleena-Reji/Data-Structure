//Disjoint set

#include<stdio.h>
#define Max 10

int parent[MAX];
void create(int n){
    for(int i=0;i<n;i++)
    parent[i]=i;
}

int search(int u){
    if(parent[u]!=u)
     parent[u]=search(parent[u]);
    return parent[u];
}

void union(int u,int v){
    int parentu = search(u), parentv = search(v);
    if(parentu == parentv)
    printf("Cycle detected");
    parent[parentu] = parentv;
}

void dispaly(int n){
    printf("Node representation:");
    for(int i=0;i<n;i++)
    printf("%d:%d\n",i,search(i));
}

void main(){
    int n,count,u,v;
    printf("Enter number of elements:");
    scanf("%d",&n);
    create(n);
    printf("Enter number of union operations to perform:");
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        printf("Enter the edge pairs:");
        scanf("%d %d",&u,&v);
        union(u,v);
    }
    dispaly(n);

}

