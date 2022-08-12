// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//�������� local variable
//�������� global variable
//static ���� static variable
//c++ : member variable

int globalVariable = 50;

void incrementStaticLocalVariable()
{
    static int staticLocalVariable = 50;
    staticLocalVariable++;
    printf("staticLocalVariable : %d\n", staticLocalVariable);
}

void incrementGlobalVariable()
{
    globalVariable++;
    printf("globalVariable : %d\n", globalVariable);
}

void incrementLocalVariable()
{
    int localVariable = 50;
    localVariable++;
    printf("localVariable : %d\n", localVariable);
}

int main()
{
    incrementStaticLocalVariable();
    incrementStaticLocalVariable();
    incrementStaticLocalVariable();
    incrementStaticLocalVariable();

    incrementGlobalVariable();
    incrementGlobalVariable();
    incrementGlobalVariable();
    incrementGlobalVariable();

    incrementLocalVariable();
    incrementLocalVariable();
    incrementLocalVariable();
    incrementLocalVariable();

}
