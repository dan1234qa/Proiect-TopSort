#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j,k,n,a[200][200],adag[200],link[200],adauga=0;

    printf("Introduceti numarul de noduri:\n");
    scanf("%d",&n);

    printf("Introduceti matricea de adiacenta:\n");
    for(i=0;i<n;i++){
        printf("Enter row %d\n",i+1);
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }

    for(i=0;i<n;i++){
        adag[i]=0;
        link[i]=0;
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adag[i]=adag[i]+a[j][i];

    printf("\n Ordinea topologica este:");

    while(adauga<n){
        for(k=0;k<n;k++){
            if((adag[k]==0) && (link[k]==0)){
                printf("%d ",(k+1));
              link[k]=1;
            }

            for(i=0;i<n;i++){
                if(a[i][k]==1)
                    adag[k]--;
            }
        }

        adauga++;
    }

    return 0;
}

