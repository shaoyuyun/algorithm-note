#include <stdio.h>
#include <stdlib.h>

static int compareNum = 0;
static int insertNum = 0;

void insertSort(int arr[], int num){
    int i, j, temp;
    for(i = 1; i < num; i++){
        if(arr[i] < arr[i - 1]){
        //若第 i 个元素大于 i-1 元素则直接插入；反之，需要找到适当的插入位置后在插入。
            j = i - 1;
            temp = arr[i];
            while(j > -1 && temp < arr[j]){
            //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                arr[j + 1] = arr[j];
                j--;
                compareNum++;
            }
            arr[j + 1] = temp;      //插入到正确位置
            insertNum++;
        }
    }
}
void main()
{
    printf("请输入要排序的数组队列（用空格分隔数组元素）：\n");
    int i = 0, num = 0;
    int *arr = (int*)malloc(num*sizeof(int));
    char s;
    do{
        arr = (int*)realloc(arr, ++num*sizeof(int));
        scanf("%d", &arr[i++]);
    }while((s = getchar() != '\n'));
    insertSort(arr, num);
    printf("插入排序后的数组：\n");
    for (i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }
    printf("\n比较的次数为：%d\n插入的次数为：%d\n", compareNum, insertNum);
    system("pause");
    return 0;
}
