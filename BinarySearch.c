#include <stdio.h>
#include <stdlib.h>

static int compareNum = 0;
static int insertNum = 0;

void binarySearch(int arr[], int num, int key){
    int low = 1;
    int high = num;//���������±�n-1
    int mid ;
    while(low <= high)
    {
        mid = (low + high) / 2 ;//�±��һ�룬int���ͳ���ȡ����
        if(key < arr[mid])
        {
            high = mid + 1;
            compareNum++;
        }
        if(key == arr[mid] )
        {
            printf("���ҵ�����%d��", key);
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
    printf("������Ҫ���ҵ�������У��ÿո�ָ�����Ԫ�أ���\n");
    int i = 0, num = 0, key = 0;
    int *arr = (int*)malloc(num*sizeof(int));
    char s;
    do{
        arr = (int*)realloc(arr, ++num*sizeof(int));
        scanf("%d", &arr[i++]);
    }while((s = getchar() != '\n'));
    printf("������Ҫ���ҵ����֣�\n");
    scanf("%d", &key);
    binarySearch(arr, num, key);
    printf("\n���ҵĴ���Ϊ��%d\n", compareNum);
    system("pause");
    return 0;
}
