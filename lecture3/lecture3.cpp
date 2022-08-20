#include <stdio.h>
// * literals : 
//   e.g. 1, 2, 3, 0.1, 0.1f, -1, 0xffff

// * constants (symbolic ���):
//	 ���� �տ� const �� ���̸� ����� ��. 

// * macro ���
//   #define ��ũ�θ� ��
//   �����ݷ��� ������ ���� ������ ����

// MACRO ����� symbolic ����� ����ϴ� ����
//   ��������̶�� ���� � ������ �����ϰ� �� ���� 90���̶�� �����ϸ�
//   int a = 90; ó�� literal�� ���� a��� ������ �����ϴ� �� ���� 
//   int a = EXPIRY_DATE; ó�� �������� �� �ǹ̰� ��Ȯ�� ���޵� �� ����
//   ��, �ҽ��� ������ �ڵ忡�� a = 90; b = 90; �� ���� ������� ��� 
//   ���� ��������� ���Ǹ� 90�� �ƴ� �ٸ� ���� �����ؾ��� ���
//   ������ �������� ����. a = EXPIRY_DATE; b = EXPIRY_DATE; �̶�� ����� ��� EXPIRY_DATE�� ���� �θ� ã�� �ش��Ϸ� �����ϸ� ��.

void testConstantVariable()
{
	const int a = 5;

	// a�� ������ ����̹Ƿ� ���� ������ �� ����. �Ʒ��� ���� �ۼ� �� compile error �߻���
	//a = 4; 
}


void testMacro()
{
#define MINIMUM_AGE 5 // FIVE��� �� 5�� ���� ��.  
#define SOME_UNSIGNED_VALUE 5u  
#define SOME_HEX_VALUE 0xffff
#define SOME_FLOAT_VALUE 0.05f
#define SOME_DOUBLE_VALUE 0.05

	int a = MINIMUM_AGE;
	float f = SOME_FLOAT_VALUE;
	int hex = SOME_HEX_VALUE;
	double d = SOME_DOUBLE_VALUE;
}


// �Լ�
// �Լ��� ����� ���ǰ� �ִµ�
// ������ ������ �ߺ��� �� ������ ���Ǵ� �ѹ��� �־�� ��.

// ������ ���� header file( .h) ��, ���Ǵ� ���� source file( .c )�� �ۼ���.
// ���Ǵ� ��� �����ص� ��� ������ ����δ� ��� ��ġ ���� �־�� ��.
// �Լ��� ���ǳ� ������ �ش� �Լ��� ����ϴ� �ҽ��ڵ�� �ٸ� ���Ͽ� �ۼ��Ǿ� �ִٸ�
// �ش� �Լ��� ����� header ������ ����ϴ� �ҽ��ڵ忡�� include ����� ��.
// 
// �Լ� ���� ���
// ��ȯ���� �Լ��̸�(�Ķ�������� �Ķ�����̸�);

/* �Լ� ���� ���
	��ȯ���� �Լ��̸�(�Ķ�������� �Ķ�����̸�)
	{
		����
		return ��ȯ��;
	}

	��ȯ���� ���ٸ� ��ȯ������ void�� �����ϰ� return���� ���� �ʰų� ���� �������� ���� ä return; �̶�� ����� �� ����.
*/

int function(int b); // �Լ� ����



extern int globalVariable; // ������ extern ����

int main()
{
	int b = function(5);

	int a = 5;
	int t = 4;

	a = b;

	int ab = (int)1.5;
	double bc = ab;


	// �ʱⰪ

	int localVariable; // ���� ������ �ʱⰪ���� �����Ⱚ�� ��� ����. (� ���� ��� �־���ϴ��� ǥ�ؿ��� �������� �ʾ���)
					   // ���� ���������� ���� �б� ���� �׻� �ʱ�ȭ�ؾ� ��.
	static int staticVariable; // static ������ global ������ �׻� 0���� �ʱ�ȭ �Ǿ� ����.


	// ������

	// ���������
	   // +, -, /, %, *, ++, --

	{// ���� ������
		int  i = 0; //  0
		i++;        //  1
		++i;        //  2

		int test = i++; // i�� test�� ����ǰ� �� �� i�� ���� 1 ���� ��.
		printf("test : %d\n", test);
		printf("i    : %d\n", i);
	}

	{// ���� ������
		int  i = 0; //  0
		i++;        //  1
		++i;        //  2

		int test = ++i; // i�� ���� 1 ������ �� test�� ������ i�� ���� ���� ��.        
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

	// ���Կ�����
	// +=, -=, %=, /=, ^= != &=  


	// ���迬������ ��� �� : 0 �ƴϸ� 1 (c++: bool true, false )
	//>, >=, <, <=, ==


	// ��������
	// ��Ʈ������

	// &, | , 









	return 0;
}

int function(int b)
{
	return 0;
}

int globalVarible = -1; // 0

