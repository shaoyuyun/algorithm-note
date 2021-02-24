#include <stdio.h>
#include <stdlib.h>

static int compareNum = 0, swapNum = 0;

void quickSort(int arr[], int num){
    int i = 0;
    int j = num - 1;
    int key =  arr[0];
    if(num > 1){
        while(i != j){
            for(; i < j; j--){
                compareNum++;
                if(key > arr[j]){
                    arr[i] = arr[j];
                    swapNum++;
                    break;
                }
            }
            for(; j > i; i++){
                compareNum++;
                if(key < arr[i]){
                    arr[j] = arr[i];
                    swapNum++;
                    break;
                }
            }
            arr[i] = key;
        }
        quickSort(arr, i);
        quickSort(arr + i + 1, num - i - 1);
    }

}

int main()
{
    printf("请输入要排序的数组队列（用空格分隔数组元素）：\n");
    int i = 0, num = 0;
    int *arr = (int*)malloc(num*sizeof(int));
    char s;
    do{
        arr = (int*)realloc(arr, ++num*sizeof(int));
        scanf("%d", &arr[i++]);
    }while((s = getchar() != '\n'));
    quickSort(arr, num);
    int k = 0;
    printf("快排后的数组：\n");
    for(k = 0; k < num; k++){
        printf("%d ", arr[k]);
    }
    printf("\n比较的次数为：%d \n交换的次数为：%d\n", compareNum, swapNum);
    free(arr);
    arr = NULL;
    system("pause");
    return 0;
}
