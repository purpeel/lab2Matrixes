#include "structure.h"
#include "foos.h"
#include "unary.h"
#include "input.h"
#include "binary.h"
#include <windows.h>


void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct mat_structure Matrix1, Matrix2, buff;
    int pow = 0, n = 0, D = 0, breakFlag = 0, command = 0;
    char input[5];
    while (breakFlag == 0)
    {
        menuPrint();
        scanf("%d", &command);
        fflush(stdin);
        switch(command)
        {
            case 1:
                fflush(stdin);
                printf("Первая матрица:\n");
                n = inputSize(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = inputMatrix(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                printf("Вторая матрица:\n");
                n = inputSize(&Matrix2);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = inputMatrix(&Matrix2);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n =  add_substract(Matrix1, Matrix2, 0, &buff);
                if (n == 0) 
                {   
                    printf("Результат сложения:\n");
                    printMatrix(buff); 
                }
                else { errorPrint(n); }
                break;
            case 2:
                fflush(stdin);
                printf("Первая матрица:\n");
                n = inputSize(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = inputMatrix(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                printf("Вторая матрица:\n");
                n = inputSize(&Matrix2);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = inputMatrix(&Matrix2);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = add_substract(Matrix1, Matrix2, 1, &buff);
                if (n == 0) 
                {
                    printf("Результат вычитания:\n");
                    printMatrix(buff);
                }
                else { errorPrint(n); }
                break;
            case 3:
                fflush(stdin);
                printf("Первая матрица:\n");
                n = inputSize(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = inputMatrix(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                printf("Вторая матрица:\n");
                n = inputSize(&Matrix2);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = inputMatrix(&Matrix2);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = multiplier(Matrix1, Matrix2, &buff);
                if (n == 0) 
                {
                    printf("Результат умножения:\n");
                    printMatrix(buff);
                }
                else { errorPrint(n); }
                break;
            case 4:
                fflush(stdin);
                n = inputSize(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = inputMatrix(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                printf("Оригинальная матрица:\n");
                printMatrix(Matrix1);
                printf("Транспонированная матрица:\n");
                transpose(Matrix1);
                break;
            case 5:
                fflush(stdin);
                n = inputSize(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = inputMatrix(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                printf("Введите степень - целое число.\n");
                scanf("%d", &pow);
                Matrix2 = Matrix1;
                n = powerMatrix(&Matrix2, Matrix1, pow - 1);
                if (n == 0) 
                {
                    printf("Матрица в степени %d:\n", pow);
                    printMatrix(Matrix2);
                }
                else
                {
                    errorPrint(n);
                }
                break;
            case 6:
                fflush(stdin);
                n = inputSize(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = inputMatrix(&Matrix1);
                if (n != 0) 
                {
                    errorPrint(n);
                    break;
                }
                n = determinant(Matrix1, &D);
                if (n == 0)
                {
                    printf("Определитель матрицы равен %d\n", D);
                }
                D = 0;
                break;
            case 7:
                printf("Выполнение завершено.\n");
                breakFlag = 1;
                break;
            default:
                printf("Некорректная команда, попробуйте еще раз.\n");
                break;
        }
    }
}