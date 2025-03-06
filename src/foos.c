#include "structure.h"
#include "foos.h"


int power(int a, int n)
{
    int res = 1;
    for (short i = 0; i < n; i++)
    {
        res *= a;
    }
    return res;
}


int isDigit(unsigned code)
{
    int n = (code >= (unsigned) '0' && code <= (unsigned) '9') ? 1 : 0;
    return n;
}


void clear(char array[], int size)
{
    for (short i = 0; i < size; i++)
    array[i] = '\0';
}


int charToInt(char string[])
{
    int res = 0, count = 0;
    unsigned code;
    for (short i = 0; i < 5; i++)
    {
        code = string[i];
        if (isDigit(code) == 1)
        {
            count++;
        }
        else if (code != '\0' && code != ' ')
        {
            errorPrint(-1);
            break;
        }
        else
        {
            break;
        }
    }
    for (short i = 0; i < 4; i++)
    {
        if ((unsigned) string[i] != '\0' && (unsigned) string[i] != ' ')
        {
            count--;
            res += (((unsigned) string[i] - '0') * power(10, count));
        }
    }
    return res;
}


void printMatrix(struct mat_structure mtrx)
{
    for (short i = 0; i < mtrx.matrixHeight * mtrx.matrixLength; i++)
    {
        if (i % mtrx.matrixLength == 0) { printf("\n"); }
        printf("%-5d", *(mtrx.contents + i));
    }
    printf("\n");
}


void menuPrint()
{
    printf("������� ������� ��� ����������:\n�������� ��������.\n\t1. �������� ������\n\t2. ��������� ������\n\t3. ��������� ������.\n");
    printf("������� ��������.\n\t4. ���������������� �������\n\t5. ���������� ������� � �������\n\t6. ����� ������������ �������\n");
    printf("����� ������� ������������� ������ ��������, ������� ����� ����� �� 1 �� 6, ������� \"7\" ��������� ����������.\n");
}


void errorPrint(int errN)
{
    switch(errN)
    {
        case -1:
            printf("������. � ����� �� ����������� ��������� ���������, ������ ����� �����.\n");
            break;
        case -2:
            printf("������. ���������� ������ ��� ������� ���� ����� � �������� ������� �� �������� �������.\n");
            break;
        case -3:
            printf("������. ���������� ������ ������� ������� � ���� MxN, ��� M - ����������� ����� �����, N - ����������� ����� ��������.\n");
            break;
        case -4:
            printf("������. ���������� ������ ������� ���������� �������.\n");
            break;
        case -5:
            printf("������. ���������� ��������� ��������� ������� ������ ��������� � �������������� ���������� ���������.\n");
            break;
        case -6:
            printf("������. �������� ���������� ������������ ������� ������ ��� ���������� ������, �. �. M = N.\n");
            break;
        case -7:
            printf("������. ��� ��������� ����������, ����� ���-�� ����� ������ ������� ��������� � ���-��� �������� ������.\n");
            break;
        case -8:
            printf("������. � �������� ��� ��������� ����������� ������� ����������� �������.\n");
            break;
        case -9:
            printf("������. ���������� � ������� ���������� ������ ��� ���������� ������.\n");
            break;
        case -10:
            printf("������. ������� ������ ���� ����� ������������� ������.\n");
            break;
        case -11:
            printf("������. ���������� ������� � ������� ���� 5 ����� ������� ������������ ��������� int.\n");
            break;
    }
}


