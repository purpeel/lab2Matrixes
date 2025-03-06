#include "structure.h"
#include "foos.h"
#include "unary.h"


void transpose(struct mat_structure mtrx)
{
    int *buff = (int *) malloc(sizeof(int) * mtrx.matrixHeight * mtrx.matrixLength), temp;
    for (short i = 0; i < mtrx.matrixHeight; i++)
    {
        for (short j = 0; j < mtrx.matrixLength; j++)
        {
            *(buff + j * mtrx.matrixHeight + i) = mtrx.contents[mtrx.matrixLength * i + j];
        }
    }
    mtrx.contents = buff;
    temp = mtrx.matrixHeight;
    mtrx.matrixHeight = mtrx.matrixLength;
    mtrx.matrixLength = temp;
    printMatrix(mtrx);
    free(buff);
}


int determinant(struct mat_structure mtrx, int *D)
{
    int count = 0, subDeterminant;
    struct mat_structure buff;
    if (mtrx.matrixLength != mtrx.matrixHeight)
    {
        return -6;
    }
    if (mtrx.matrixLength == 2)
    {
        *D += mtrx.contents[0] * mtrx.contents[3] - mtrx.contents[1] * mtrx.contents[2];
    }
    else
    {
        for (short i1 = 0; i1 < mtrx.matrixLength; i1++)
        {
            buff.contents = malloc(sizeof(int) * (mtrx.matrixLength - 1) * (mtrx.matrixHeight - 1));
            for(short i = 1; i < mtrx.matrixHeight; i++)
            {
                for (short j = 0; j < mtrx.matrixLength; j++)
                {
                    if (j == i1) { continue; }
                    else
                    {
                        buff.contents[count++] = mtrx.contents[i * mtrx.matrixLength + j];
                    }
                }
            }
            subDeterminant = 0;
            buff.matrixLength = mtrx.matrixLength - 1;
            buff.matrixHeight = mtrx.matrixHeight - 1;
            determinant(buff, &subDeterminant);
            if (i1 % 2 == 0)
            {
                *D += *(mtrx.contents + i1) * subDeterminant;
            }
            else
            {
                *D -= *(mtrx.contents + i1) * subDeterminant;
            }
            free(buff.contents);
            count = 0;
        }
    }
    return 0;
}


int powerMatrix(struct mat_structure* mtrx, struct mat_structure mtrxBase, int pow)
{
    if (pow <= 0)
    {
        return -10;
    }
    else if (pow > 5)
    {
        return -11;
    }
    else if ((*mtrx).matrixLength != (*mtrx).matrixHeight)
    {
        return -9;
    }
    else
    {
        struct mat_structure buff;
        buff.contents = calloc((*mtrx).matrixHeight * (*mtrx).matrixLength, sizeof(int));
        buff.matrixLength = (*mtrx).matrixLength;
        buff.matrixHeight = (*mtrx).matrixHeight;
        for (short i = 0; i < (*mtrx).matrixHeight; i++)
        {
            for (short j = 0; j < (*mtrx).matrixLength; j++)
            {
                for (short k = 0; k < (*mtrx).matrixHeight; k++)
                {
                    *(buff.contents + i * (*mtrx).matrixLength + j) += (*mtrx).contents[i * (*mtrx).matrixLength + k] * mtrxBase.contents[k * mtrxBase.matrixLength + j];
                }
            }
        }
        powerMatrix(&buff, mtrxBase, pow - 1);
        (*mtrx) = buff;
    }
    return 0;
}