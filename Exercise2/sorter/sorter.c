#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void print_usage(void);
void bubble_sort(int arr[], int len);
void element_sort(int arr[], int len);

int main(int argc, char *argv[]) {
    int b_flag = 0;
    int q_flag = 0;
    int i;

    /*always 1 less b/c most impl. cnt cmd exec. itslef*/
    int arr[32] = {0};
    int arr_index = 0;
    int len;

    if (argc == 1) {
        fprintf(stderr, "No arguments provided\n");
        print_usage();
        return 1;
    }

    /*parse integers and flags*/
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-b") == 0) {
            b_flag = 1;
        }
        else if (strcmp(argv[i], "-q") == 0) {
            q_flag = 1;
        }
        else {
            arr[arr_index] = atoi(argv[i]);
            arr_index++;
            if (arr_index > 32) {
                fprintf(stderr, "Too many arguments\n");
                print_usage();
                return 1;
            }
        }
    }

    if (arr_index == 0) {
        fprintf(stderr, "No integers given\n");
        print_usage();
        return 1;
    }

    len = arr_index;

    

    if (b_flag == 1)
        bubble_sort(arr, len);
    else
        element_sort(arr, len);

    /*print sorted array*/
    if(q_flag!=1) {
        int j;
        for (j = 0; j < len; j++) {
            printf("%d\n", arr[j]);;
        }
    }
    
    return 0;
}

void element_sort(int arr[], int num_elements) {
    int start = 0;
    int temp;
    int j;
    do {
        int smallest = start;
        int i;
        for (i = start; i < num_elements; i++) {
            if (arr[i] < arr[smallest]) {
                smallest = i;
            }
        }
        /*swap smallest with start*/
        temp = arr[start];
        arr[start] = arr[smallest];
        arr[smallest] = temp;
        start++;
    } while (start < num_elements);
    for (j = 0; j < num_elements; j++) {
        assert(arr[j] <= arr[j + 1] || j == num_elements - 1);
    }
}

void bubble_sort(int arr[], int len) {
    int i, j, temp;
    int k;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                /*swap arr[j] and arr[j+1]*/
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (k = 0; k < len; k++) {
        assert(arr[k] <= arr[k + 1] || k == len - 1);
    }
}

void print_usage() {
    printf("Usage info: sorter [-b] [-q] number1 [number2 ... ] (maximum 32 numbers) \n"); /*BNF-like usage info*/
}