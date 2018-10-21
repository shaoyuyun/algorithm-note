#include <stdio.h>
#include <stdlib.h>

static int compareNum = 0;
static int insertNum = 0;

void insertSort(int arr[], int num){
    int i, j, temp;
    for(i = 1; i < num; i++){
        if(arr[i] < arr[i - 1]){
        //���� i ��Ԫ�ش��� i-1 Ԫ����ֱ�Ӳ��룻��֮����Ҫ�ҵ��ʵ��Ĳ���λ�ú��ڲ��롣
            j = i - 1;
            temp = arr[i];
            while(j > -1 && temp < arr[j]){
            //����˳����ҷ�ʽ�ҵ������λ�ã��ڲ��ҵ�ͬʱ���������е�Ԫ�ؽ��к��Ʋ�����������Ԫ���ڳ��ռ�
                arr[j + 1] = arr[j];
                j--;
                compareNum++;
            }
            arr[j + 1] = temp;      //���뵽��ȷλ��
            insertNum++;
        }
    }
}
void main()
{
    printf("������Ҫ�����������У��ÿո�ָ�����Ԫ�أ���\n");
    int i = 0, num = 0;
    int *arr = (int*)malloc(num*sizeof(int));
    char s;
    do{
        arr = (int*)realloc(arr, ++num*sizeof(int));
        scanf("%d", &arr[i++]);
    }while((s = getchar() != '\n'));
    insertSort(arr, num);
    printf("�������������飺\n");
    for (i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }
    printf("\n�ȽϵĴ���Ϊ��%d\n����Ĵ���Ϊ��%d\n", compareNum, insertNum);
    system("pause");
    return 0;
}
