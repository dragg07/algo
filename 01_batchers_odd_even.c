//BaTchERs OdD EvEn MErGe
#include<stdio.h>
#include<stdlib.h>

#define n 10

typedef struct batchers_odd_even
{
    int odd[n], even[n];
    int odd_count, even_count;
} BOE;

void insertion_sort(int arr[], int size){
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void divide_array(int arr[], int size, BOE *result) {
    result->even_count = 0;
    result->odd_count = 0;

    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            result->even[result->even_count++] = arr[i];
        } else {
            result->odd[result->odd_count++] = arr[i];
        }
    }
}

void merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d | ", arr[i]);
    }
}

int main(){
    int size = 10;
    int arr[] = {3,56,0,-4,55,100,-33,4,10,10};

    printf("Original Array : \n");
    display(arr,size);

    BOE result;
    divide_array(arr, size, &result);
    printf("\n\nOdd Array : \n");
    display(result.odd,result.odd_count);
    printf("\nEven Array : \n");
    display(result.even,result.even_count);

    insertion_sort(result.odd, result.odd_count);
    printf("\n\nSorted Odd Array :\n");
    display(result.odd, result.odd_count);
    insertion_sort(result.even, result.even_count);
    printf("\nSorted Even Array :\n");
    display(result.even, result.even_count);

    int merged_size = result.odd_count + result.even_count;
    int merged[merged_size];
    
    merge_sorted_arrays(result.odd, result.odd_count, result.even, result.even_count, merged);

    printf("\n\nMerged Sorted Array:\n");
    display(merged, merged_size);

    return 0;
}