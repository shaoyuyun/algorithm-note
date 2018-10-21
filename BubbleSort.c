#include <stdio.h>
#include <stdlib.h>

static int compareNum = 0;
static int swapNum = 0;

void bubbleSort(int arr[], int num){
    int i,j,temp;
    for(i = 0; i < num; i++){
        for(j = i + 1; j < num; j++){
            compareNum++;
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swapNum++;
            }
        }
    }
}

int main(){
    printf("请输入要排序的数组队列（用空格分隔数组元素）：\n");
    int i = 0, num = 0;
    int *arr = (int*)malloc(num*sizeof(int));
    char s;
    do{
        arr = (int*)realloc(arr, ++num*sizeof(int));
        scanf("%d", &arr[i++]);
    }while((s = getchar() != '\n'));
    bubbleSort(arr, num);
    printf("冒泡排序后的数组：\n");
    for(i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }
    printf("\n比较的次数为：%d\n交换的次数为：%d\n", compareNum, swapNum);
    system("pause");
    return 0;
}
