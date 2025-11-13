//Set Operations-Union,Intersection and Difference using Bitstring

#include<stdio.h>
#define MAX 10

int u[Max],bita[MAX],bitb[MAX],r[MAX];

void convert(int a[],int bitstr[],int size,int n){
    for(int i=0;i<size;i++){
        bitstr[i]=0;
        for(int j=0;j<n;j++){
            if(u[i]==a[j]){
                bitstr[i]=1;
                break;
            }
        }
    }
}

void displaySet(int a[],int n){
    printf("{ ");
    for(int i=0;i<n;i++){
        if(a[i] == 1){
            printf("%d ",u[i]);
        }
    }
    printf("}\n");
}

void displayBit(int bitstr[],int n){
    printf("{ ");
    for(int i=0;i<n;i++){
        printf("%d ",bitstr[i]);
    }
    printf("}\n");
}

void union(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        r[i] = a[i] | b[i];
    }
    displaySet(r, n);
}

void intersection(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        r[i] = a[i] & b[i];
    }
    displaySet(r, n);
}

void difference(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        r[i] = a[i] & (b[i]==0);
    }
    displaySet(r, n);
}

int main() {
    int a[MAX], b[MAX],k,m,n;
    int ch;
    printf("Enter the size of the universal set(max %d): ", MAX);
    scanf("%d", &k);
    printf("Enter the elements of the universal set: ");
    for(int i=0;i<k;i++){
        scanf("%d", &u[i]);
    }
    printf("Enter the size of set A(max %d): ", MAX);
    scanf("%d", &m);
    printf("Enter the elements of set A: ");
    for(int i=0;i<m;i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the size of set B(max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter the elements of set B: ");
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
    }
    
    convert(a, bita, k, m);
    convert(b, bitb, k, n);

    do{
        printf("\n---Set Operations---\n 1.Display Bit Representation\n 2.Union\n 3.Intersection\n 4.Difference(A-B)\n 5.Difference(B-A)\n 6.Exit\n Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Bit representation of Set A: ");
                displayBit(bita, k);
                printf("Bit representation of Set B: ");
                displayBit(bitb, k);
                break;
            case 2:
                printf("Union of A and B: ");
                union(bita, bitb, k);
                break;
            case 3:
                printf("Intersection of A and B: ");
                intersection(bita, bitb, k);
                break;
            case 4:
                printf("Difference A - B: ");
                difference(bita, bitb, k);
                break;
            case 5:
                printf("Difference B - A: ");
                difference(bitb, bita, k);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(ch != 6);
    return 0;
}
