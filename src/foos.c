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
    printf("Введите команду для выполнения:\nБинарные операции.\n\t1. Сложение матриц\n\t2. Вычитание матриц\n\t3. Умножение матриц.\n");
    printf("Унарные операции.\n\t4. Транспонирование матрицы\n\t5. Возведение матрицы в степень\n\t6. Поиск определителя матрицы\n");
    printf("Номер команды соответствует номеру операции, введите целое число от 1 до 6, команда \"7\" завершает выполнение.\n");
}


void errorPrint(int errN)
{
    switch(errN)
    {
        case -1:
            printf("Ошибка. К вводу не допускаются буквенные выражения, только целые числа.\n");
            break;
        case -2:
            printf("Ошибка. Необходимо ввести как минимум одно число в качестве каждого из размеров матрицы.\n");
            break;
        case -3:
            printf("Ошибка. Необходимо ввести размеры матрицы в виде MxN, где M - натуральное число строк, N - натуральное число столбцов.\n");
            break;
        case -4:
            printf("Ошибка. Необходимо ввести матрицы ненулевого размера.\n");
            break;
        case -5:
            printf("Ошибка. Количество введенных элементов матрицы должно совпадать с предварительно введенными размерами.\n");
            break;
        case -6:
            printf("Ошибка. Операция нахождения определителя введена только для квадратных матриц, т. е. M = N.\n");
            break;
        case -7:
            printf("Ошибка. Для умножения необходимо, чтобы кол-во строк первой матрицы совпадало с кол-вом столбцов второй.\n");
            break;
        case -8:
            printf("Ошибка. К сложению или вычитанию допускаются матрицы одинакового размера.\n");
            break;
        case -9:
            printf("Ошибка. Возведение в степень определено только для квадратных матриц.\n");
            break;
        case -10:
            printf("Ошибка. Степень должна быть целым положительным числом.\n");
            break;
        case -11:
            printf("Ошибка. Возведение матрицы в степень выше 5 может повлечь переполнение диапазона int.\n");
            break;
    }
}


