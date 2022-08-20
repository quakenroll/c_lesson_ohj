#include <stdio.h>
// * literals : 
//   e.g. 1, 2, 3, 0.1, 0.1f, -1, 0xffff

// * constants (symbolic 상수):
//	 변수 앞에 const 를 붙이면 상수가 됨. 

// * macro 상수
//   #define 매크로명 값
//   세미콜론을 구문의 끝에 붙이지 않음

// MACRO 상수나 symbolic 상수를 사용하는 이유
//   유통기한이라는 값을 어떤 변수에 저장하고 그 값이 90일이라고 가정하면
//   int a = 90; 처럼 literal을 직접 a라는 변수에 저장하는 것 보다 
//   int a = EXPIRY_DATE; 처럼 저장했을 때 의미가 명확히 전달될 수 있음
//   또, 소스의 수많은 코드에서 a = 90; b = 90; 과 같이 사용했을 경우 
//   향후 유통기한의 정의를 90이 아닌 다른 수로 변경해야할 경우
//   수정이 용이하지 않음. a = EXPIRY_DATE; b = EXPIRY_DATE; 이라고 사용한 경우 EXPIRY_DATE의 정의 부를 찾아 해당일로 변경하면 됨.

void testConstantVariable()
{
	const int a = 5;

	// a는 정수형 상수이므로 값을 변경할 수 없음. 아래와 같이 작성 시 compile error 발생함
	//a = 4; 
}


void testMacro()
{
#define MINIMUM_AGE 5 // FIVE라는 를 5로 정의 함.  
#define SOME_UNSIGNED_VALUE 5u  
#define SOME_HEX_VALUE 0xffff
#define SOME_FLOAT_VALUE 0.05f
#define SOME_DOUBLE_VALUE 0.05

	int a = MINIMUM_AGE;
	float f = SOME_FLOAT_VALUE;
	int hex = SOME_HEX_VALUE;
	double d = SOME_DOUBLE_VALUE;
}


// 함수
// 함수는 선언과 정의가 있는데
// 선언은 여러번 중복할 수 있지만 정의는 한번만 있어야 함.

// 선언은 보통 header file( .h) 에, 정의는 보통 source file( .c )에 작성함.
// 정의는 어디에 존재해도 상관 없지만 선언부는 사용 위치 위에 있어야 함.
// 함수의 정의나 선언이 해당 함수를 사용하는 소스코드와 다른 파일에 작성되어 있다면
// 해당 함수가 선언된 header 파일을 사용하는 소스코드에서 include 해줘야 함.
// 
// 함수 선언 방법
// 반환형식 함수이름(파라미터형식 파라미터이름);

/* 함수 정의 방법
	반환형식 함수이름(파라미터형식 파라미터이름)
	{
		내용
		return 반환값;
	}

	반환값이 없다면 반환형식은 void로 지정하고 return문을 쓰지 않거나 값을 지정하지 않은 채 return; 이라고 사용할 수 있음.
*/

int function(int b); // 함수 선언



extern int globalVariable; // 변수의 extern 선언

int main()
{
	int b = function(5);

	int a = 5;
	int t = 4;

	a = b;

	int ab = (int)1.5;
	double bc = ab;


	// 초기값

	int localVariable; // 지역 변수는 초기값으로 쓰레기값이 들어 있음. (어떤 값이 들어 있어야하는지 표준에서 정의하지 않았음)
					   // 따라서 지역변수는 값을 읽기 전에 항상 초기화해야 함.
	static int staticVariable; // static 변수나 global 변수는 항상 0으로 초기화 되어 있음.


	// 연산자

	// 산술연산자
	   // +, -, /, %, *, ++, --

	{// 후위 연산자
		int  i = 0; //  0
		i++;        //  1
		++i;        //  2

		int test = i++; // i가 test에 저장되고 난 후 i의 값이 1 증가 됨.
		printf("test : %d\n", test);
		printf("i    : %d\n", i);
	}

	{// 전위 연산자
		int  i = 0; //  0
		i++;        //  1
		++i;        //  2

		int test = ++i; // i의 값이 1 증가된 후 test에 증가된 i의 값이 저장 됨.        
		printf("test : %d\n", test);
		printf("i    : %d\n", i);
	}





	int aaaa = 5 - 1;
	double d = 4.0 / 3.0;
	d = aaaa / 3.0;

	int result = aaaa % 2;
	result = 5 % 2;

	if (result == 0) // %2 == 0
	{
	}

	// 대입연산자
	// +=, -=, %=, /=, ^= != &=  


	// 관계연산자의 결과 값 : 0 아니면 1 (c++: bool true, false )
	//>, >=, <, <=, ==


	// 논리연산자
	// 비트연산자

	// &, | , 









	return 0;
}

int function(int b)
{
	return 0;
}

int globalVarible = -1; // 0

