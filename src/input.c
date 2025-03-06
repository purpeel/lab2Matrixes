#include "structure.h"
#include "foos.h"
#include "input.h"


int inputSize(struct mat_structure *mtrx)
{
    char string[16], buff[] = {'\0', '\0', '\0', '\0', '\0'};
    int buffIndex = 0;
    unsigned code, twoValuesFlag = 1;
    printf("¬ведите размер матрицы.\nMxN, где M - кол-во строк, N - кол-во столбцов.\n");
    fgets(string, 16, stdin);
    fflush(stdin);
    for (short i = 0; i < 16; i++)
    {
        code = string[i]; 
        if (code == ' ') 
        { 
            continue; 
        }
        else
        {
            if (isDigit(code) == 1)
            {
                buff[buffIndex] = string[i];
                buffIndex++;
            }
            else if (code == 'x')
            {
                if (buff[0] == '\0') { return -2; }
                if (charToInt(buff) == 0) { return -4; }
                else 
                {
                    (*mtrx).matrixHeight = charToInt(buff);
                    clear(buff, 5);
                    buffIndex = 0;
                    twoValuesFlag = 2;
                }
            }
            else if (code == '\n')
            {
                if (twoValuesFlag == 1) { return -2; }
                if (buff[0] == '\0') { return -2; }
                if (charToInt(buff) == 0) { return -4; }
                else 
                {
                    (*mtrx).matrixLength = charToInt(buff);
                    clear(buff, 5);
                    buffIndex = 0;
                }
            }
        }
    }
    fflush(stdin);
    return 0;
}


int inputMatrix(struct mat_structure *mtrx)
{
    unsigned code;
    short buffIndex = 0, quantity = 0;
    char buff[5], input[128];
    clear(buff, 5);
    printf("¬ведите элементы матрицы, раздел€€ пробелами.\n");
    fgets(input, 128, stdin);
    fflush(stdin);
    (*mtrx).contents = malloc(sizeof(int) * (mtrx->matrixHeight) * (mtrx->matrixLength));
    for (short i = 0; i < 128; i++)
    {
        code = input[i];
        if (quantity > (*mtrx).matrixHeight * (*mtrx).matrixLength) { return -5; }
        if (isDigit(code) == 1)
        {
            buff[buffIndex] = input[i];
            buffIndex++;
        }
        else if (code == ' ')
        {
            if (buff[0] == '\0') { return -5; }
            *((*mtrx).contents + quantity) = charToInt(buff);
            quantity++; 
            clear(buff, 5);
            buffIndex = 0;
        }
        else if (code == '\n')
        {
            *((*mtrx).contents + quantity) = charToInt(buff);
            quantity++;
            clear(buff, 5);
            buffIndex = 0;
            break;
        }
        else 
        {
            return -1;
        }
    }
    if (quantity < (*mtrx).matrixLength * (*mtrx).matrixHeight) { return -5; }
    fflush(stdin);
    return 0;
}
