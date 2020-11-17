#include <stdio.h>
#include <stdlib.h>

int* aye(int a[],int b[], int n, int k)
{
    int i, j, m=-1, t=1;
    int* c;
    c = (int*) malloc((n+k)*sizeof(int));
    for(i=0; i<n;i++)
    {
        for(j=m+1-i; j<k; j++)
        {
            m++;
            if (b[j]<=a[i])
                {c[m]=b[j];
                t=1;
                printf("c[%d]=%d\n", m, c[m]);}
            else
            {
                c[m]=a[i];
                t=0;
                printf("c[%d]=%d\n", m, c[m]);
                break;
            }
        }
        if((m+1-i>=k) && t)
        {
            t=2;
            break;
        }
    }
    printf("%d\n", m);
    if (t!=2)
        for(j=m-n+1; j<k; j++)
            c[j+n]=b[j];
    else
        for(j=m-k+1; j<n; j++)
            c[j+k]=a[j];
    return c;
}

int main()
{
    int n, k, i;
    printf("vvedite kol-vo elemetov v massivah a b\n");
    scanf("%d%d", &n, &k);
    int* a;
    a = (int*) malloc(n*sizeof(int));
    int* b;
    b = (int*) malloc(k*sizeof(int));
    for (i=0; i<n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", a+i);
    }
    for (i=0; i<k; i++)
    {
        printf("b[%d]=", i);
        scanf("%d", b+i);
    }
    int* c = aye(a, b, n, k);
    for (i=0; i<n+k; i++)
        printf("%d ", c[i]);
    return 0;
}
