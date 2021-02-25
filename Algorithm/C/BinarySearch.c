#include <stdio.h>
#include <stdlib.h>

static int compareNum = 0;
static int insertNum = 0;

void binarySearch(int arr[], int num, int key){
    int low = 1;
    int high = num;//数组的最大下标n-1
    int mid ;
    while(low <= high)
    {
        mid = (low + high) / 2 ;//下标的一半，int类型除法取整。
        if(key < arr[mid])
        {
            high = mid + 1;
            compareNum++;
        }
        if(key == arr[mid] )
        {
            printf("已找到数字%d。", key);
            break;
        }
        else
        {
            low = mid - 1;
            compareNum++;
        }
    }
}

int main()
{
    printf("请输入要查找的数组队列（用空格分隔数组元素）：\n");
    int i = 0, num = 0, key = 0;
    int *arr = (int*)malloc(num*sizeof(int));
    char s;
    do{
        arr = (int*)realloc(arr, ++num*sizeof(int));
        scanf("%d", &arr[i++]);
    }while((s = getchar() != '\n'));
    printf("请输入要查找的数字：\n");
    scanf("%d", &key);
    binarySearch(arr, num, key);
    printf("\n查找的次数为：%d\n", compareNum);
    free(arr);
    arr = NULL;
    system("pause");
    return 0;
}
