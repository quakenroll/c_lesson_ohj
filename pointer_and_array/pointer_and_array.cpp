// pointer_and_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// 0. c++�� ���� ����ġ�� �ʾƼ� call by reference�� �ٷ��� �ʾ����� �߿��ϴ� �� ã�ƺ�����.
// 1. call by pointer, call by value�� ������ �� ���� ������ ��Ʃ�� ���°� ���� �ſ���. �� Ȯ���ϼ���.
// 2. ���� �޸� �Ҵ��� ã�ƺ��ð� malloc / free �� c�� ����ؾ��ϴ� ��Ȳ���� ���������� ����Ͻð�
//    c++������ ������ new/delete�� Ȱ���ϼ���.


void callByValue(int a)
{
    a = 3;
}

void callByPointer(int* address)// ���࿡ 100�� �ּҶ�� 100�̶�� ���� �Ѿ���� �״ϱ�
{
    // 100�̶�� �ּ��� ������ 3�� �ִ´�. * �����ڷ� address��� ������ ����ִ� 100�̶�� �ּ� ���� ����Ű�� ���� 3�� �����Ѵ�.
    *address = 3;
}

void callByPointer2(int* address)// ���࿡ 100�� �ּҶ�� 100�̶�� ���� �Ѿ���� �״ϱ�
{
    // 100�̶�� �ּ��� ������ 3�� �ִ´�. * �����ڷ� address��� ������ ����ִ� 100�̶�� �ּ� ���� ����Ű�� ���� 3�� �����Ѵ�.
    int temp = 5;
    address = &temp; // address��� �Ķ������ ���� temp�� �ּҰ��� �����Ѵ�. callByPointer2(&a) ȣ�� �� �Ѱ� �� ����� a�� ������ ������ ����.
}


int globalIntegerValue = 1;
void callByDoublePointer(int** addressOfAddress)
{
    int a = 5;
    *addressOfAddress = &globalIntegerValue; // addressOfAddress(�������� �ּ�) �� ����Ű�� ���� ��(int�� �ּ�)�� globalIntegerValue�� �ּҷ� �����Ѵ�.
}



void dynamicMemory()
{

    int width = 10;
    int height = 7;

    int** pp = (int**)malloc(sizeof(int*) * height);

    for (int row = 0; row < height; row++)
    {
        pp[row] = (int*)malloc(sizeof(int) * width);
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            pp[row][col] = row * 10 + col;
        }
    }

    for (int row = 0; row < height; row++)
    {
        printf("%d :", row);
        for (int col = 0; col < width; col++)
        {
            printf("%d", pp[row][col]);
            int test = *(*(pp + row) + col);
            printf("(%d)", test);
            printf(" ");
        }
        printf("\n");
    }

    for (int row = 0; row < height; row++)
    {
        free(pp[row]);
    }

    free(pp);

}

void _2dimArray()
{
    int arr[3][4] = { {0, 1 }, {20, 21, 23}, {30, 31, 32, 34} };

    for (int i = 0; i < 3; i++)
    {
        printf("sizeof(arr[%d]): %lld\n", i, sizeof(arr[i]));

        for (int j = 0; j < 4; j++)
        {
            printf("arr[%d][%d]: %d\n", i, j, arr[i][j]);
        }
    }

    /*
    typedef decltype(arr) newType ;
    newType abc = {{1, 1}};
    printf("sizeof abc = {{1, 1}} : %lld \n", sizeof(abc));
    */
}

void doublePointer()
{
    printf("doublePointer\n");
    int arr[3][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34 }
    };

    int* parrs[4] = { arr[0], arr[1], arr[2] };
    int** pparrs = parrs;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", pparrs[i][j]);
        printf("\n");
    }
    printf("\n");


    for (int i = 0; i < 3; i++)
    {
        printf("%p \n", pparrs + i);
    }

    printf("\n");
}

void arrayOfPointers()
{
    int arr[3][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34 }
    };

    int* array_of_pointers[3];
    array_of_pointers[0] = arr[0];

    for (int i = 0; i < 3; i++)
    {
        array_of_pointers[i] = arr[i];
    }

    printf("array_of_pointers\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", array_of_pointers[i][j]);
        }
        printf("\n");
    }

    printf("a pointer to array_of_pointers\n");
    int** pointerToArrayOfPointers = array_of_pointers;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", pointerToArrayOfPointers[i][j]);
        }
        printf("\n");
    }
}

void arrayPointer()
{
    int arr[3][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34 }
    };

    int(*parr)[4];
    parr = arr;

    for (int i = 0; i < 3; i++)
        printf("%x\n", (int)(parr + i));


    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", parr[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int main()
{
    int b = 0; // �ּ� : 100
    int* p = &b;

    callByDoublePointer(&p);
    callByPointer(p);

    printf(" b: %d ", b);
    return 0;




    callByValue(b);
    printf(" a: %d ", b);
    return 0;








    {
        int a = 4;
        int* pInteger0 = NULL;
        int* pInteger1 = nullptr;

        int* pInteger2 = &a;




        int arr[] = { 1, 4, 5, 7 };
        //int arr1[4] = {};
        //int arr2[4] = { 1, 2, };

        int* p = arr;

        int i  = *arr;
        int ii =  arr[0];
        int* pArr = &(arr[0]);
        int* pArrr = &arr[1];
        int test = *arr;
        

        int j = *(arr + 1);
        int jj = arr[1];

        if(false)
        {
			int arr[] = { 1, 4, 5, 7 };
			int* p = arr;

            int a = p[0];
            int b = *(p + 1);

            int count = 4;
            int last_index = 3;


            for (int i = 0; i < count-1; i++)
            {

            }

            for(int i = 0 ; i < 4 ; i++ ) // i�� 10 ���� ���� "����"
            {
                printf("%d ", arr[i]);
            }
        }



        // 2���� �迭

        {
            int arr[3][4] = { 
                {1,   2,   3,   4}, 
                {11,  22,  33,  44}, 
                {111, 222, 333, 444} 
            };

            //int* p = arr[1];
            int* p = *(arr+1);

            //for (int j = 0; j < 4; j++)
            //    printf("%d ", p[j]);


            if(0)
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                    printf("%d ", arr[i][j]);
                
                printf("\n");
            }

            if(0)
            {
                int* p = (int*)arr;
                int* pSecondaryRow = p + 4;

                for(int i = 0; i<4; i++)
					printf("%d ", pSecondaryRow[i]);

            }


            {
				int arr[3][4] = { 
					{1,   2,   3,   4}, 
					{11,  22,  33,  44}, 
					{111, 222, 333, 444} 
				};

               int(*arrp)[4] = arr;

               for (int i = 0; i < 3; i++)
               {
                   for (int j = 0; j < 4; j++)
                       printf("%d ", arrp[i][j]);

				   printf("\n");
               }

				int* parr[3] = { arr[0], arr[1], arr[2] };

			   for (int i = 0; i < 3; i++)
			   {
				   for (int j = 0; j < 4; j++)
					   printf("%d ", parr[i][j]);

				   printf("\n");
			   }



            }



            /*
            for( int i = 0; i < 3; i++ )
            {
                arr[0]
            }
            */


        }
    }

}
