
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para fusionar dos arreglos en uno solo
void Merge(int* nums1, int m, int* nums2, int n, int* merged)
{
	int i;
	
    for (i = 0; i < m; i++)
	{
        merged[i] = nums1[i];
    }
    
    for (i = 0; i < n; i++)
	{
        merged[m + i] = nums2[i];
    }
}

int Comparador(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


double Mediana(int* arr, int size)
{
    if (size % 2 == 1)
	{
        return arr[size / 2];
    }
	else
	{
        return (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
    }
}


void Arreglos(int* arr, int size, int min_val, int max_val)
{
	int i;
	
    for (i = 0; i < size; i++)
	{
        arr[i] = rand() % (max_val - min_val + 1) + min_val;
    }
}

int main()
{
    srand(time(NULL));

    int m = rand() % 1001;
    int n = rand() % 1001;

    int* nums1 = (int*)malloc(m * sizeof(int));
    int* nums2 = (int*)malloc(n * sizeof(int));

    Arreglos(nums1, m, -106, 106);
    Arreglos(nums2, n, -106, 106);

    int* merged = (int*)malloc((m + n) * sizeof(int));

    Merge(nums1, m, nums2, n, merged);

    qsort(merged, m + n, sizeof(int), Comparador);

    clock_t start = clock();

    double mediana = Mediana(merged, m + n);

    clock_t end = clock();
    
    double TiempoEjecucion = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n Mediana: %.2f\n", mediana);
    printf("\n Tiempo de ejecucion: %.5f segundos\n", TiempoEjecucion);

    free(nums1);
    free(nums2);
    free(merged);

    return 0;
}
