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
    printf("������Ҫ�����������У��ÿո�ָ�����Ԫ�أ���\n");
    int i = 0, num = 0;
    int *arr = (int*)malloc(num*sizeof(int));
    char s;
    do{
        arr = (int*)realloc(arr, ++num*sizeof(int));
        scanf("%d", &arr[i++]);
    }while((s = getchar() != '\n'));
    bubbleSort(arr, num);
    printf("ð�����������飺\n");
    for(i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }
    printf("\n�ȽϵĴ���Ϊ��%d\n�����Ĵ���Ϊ��%d\n", compareNum, swapNum);
    system("pause");
    return 0;
}
