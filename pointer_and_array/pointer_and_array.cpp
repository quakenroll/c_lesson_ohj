// pointer_and_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// 0. c++을 아직 가르치지 않아서 call by reference는 다루지 않았지만 중요하니 꼭 찾아보세요.
// 1. call by pointer, call by value는 저보다 더 쉽게 설명한 유튜브 강좌가 많을 거에요. 꼭 확인하세요.
// 2. 동적 메모리 할당을 찾아보시고 malloc / free 는 c언어만 사용해야하는 상황에서 제한적으로 사용하시고
//    c++에서는 가급적 new/delete을 활용하세요.


void callByValue(int a)
{
    a = 3;
}

void callByPointer(int* address)// 만약에 100이 주소라면 100이라는 값이 넘어왔을 테니까
{
    // 100이라는 주소의 공간에 3을 넣는다. * 연산자로 address라는 변수에 들어있는 100이라는 주소 값이 가리키는 곳에 3을 저장한다.
    *address = 3;
}

void callByPointer2(int* address)// 만약에 100이 주소라면 100이라는 값이 넘어왔을 테니까
{
    // 100이라는 주소의 공간에 3을 넣는다. * 연산자로 address라는 변수에 들어있는 100이라는 주소 값이 가리키는 곳에 3을 저장한다.
    int temp = 5;
    address = &temp; // address라는 파라미터의 값을 temp의 주소값을 저장한다. callByPointer2(&a) 호출 시 넘겨 준 사용한 a의 값에는 영향이 없음.
}


int globalIntegerValue = 1;
void callByDoublePointer(int** addressOfAddress)
{
    int a = 5;
    *addressOfAddress = &globalIntegerValue; // addressOfAddress(포인터의 주소) 가 가리키는 곳의 값(int의 주소)을 globalIntegerValue의 주소로 변경한다.
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
    int b = 0; // 주소 : 100
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

            for(int i = 0 ; i < 4 ; i++ ) // i가 10 보다 작은 "동안"
            {
                printf("%d ", arr[i]);
            }
        }



        // 2차원 배열

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
