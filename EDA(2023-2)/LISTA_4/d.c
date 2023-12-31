#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *v, int l, int m, int r){
    int tam = r + 1 - l;

    int *aux = malloc(sizeof(int)*tam);

    int i = l;
    int j = m+1;
    int k = 0;

    while(i <=m && j <=r)
    {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

    while (i <= m) aux[k++] = v[i++];
    while (j <= r) aux[k++] = v[j++];

    k = 0;

    for(i = l; i <= r; i++)
        v[i] = aux[k++];

    free(aux);
}

void merge_sort(int *v, int l, int r)
{
    if (l >= r) return;
    int m = (r+l)/2;

    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge(v, l, m, r);
}

int main()
{
    int t;
    scanf("%d", &t);

    int *v = (int *)malloc(sizeof(int)*t);

    for(int i = 0; i < t; i++)
        scanf("%d", &v[i]);

    merge_sort(v, 0, t-1);

    for(int j = 0; j < t; j++)
        printf("%d ", v[j]);

    printf("\n");
}