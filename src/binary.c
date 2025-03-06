#include "structure.h"
#include "foos.h"
#include "binary.h"


int add_substract(struct mat_structure mtrx1, struct mat_structure mtrx2, int substractionFlag, struct mat_structure* buff)
{
    (*buff).contents = malloc(sizeof(int) * mtrx1.matrixHeight * mtrx1.matrixLength);
    (*buff).matrixLength = mtrx1.matrixLength;
    (*buff).matrixHeight = mtrx1.matrixHeight;
    if ((mtrx1.matrixLength == mtrx2.matrixLength) && (mtrx1.matrixHeight == mtrx2.matrixHeight))
    {
        for (short i = 0; i < mtrx1.matrixHeight; i++)
        {
            for (short j = 0; j < mtrx1.matrixLength; j++)
            {
                (*buff).contents[mtrx1.matrixLength * i + j] = *(mtrx1.contents + mtrx1.matrixLength * i + j) + *(mtrx2.contents + mtrx1.matrixLength * i + j) * power(-1, substractionFlag);
            }
        }
    }
    else
    {
        return -8;
    }
    return 0;
}


int multiplier(struct mat_structure mtrx1, struct mat_structure mtrx2, struct mat_structure* buff)
{
    if (mtrx1.matrixLength == mtrx2.matrixHeight)
    {
        (*buff).contents = calloc(mtrx1.matrixHeight * mtrx2.matrixLength, sizeof(int));
        (*buff).matrixLength = mtrx2.matrixLength;
        (*buff).matrixHeight = mtrx1.matrixHeight;
        for (short i = 0; i < mtrx1.matrixHeight; i++)
        {
            for (short j = 0; j < mtrx2.matrixLength; j++)
            {
                for (short k = 0; k < mtrx2.matrixHeight; k++)
                {
                    *((*buff).contents + i * mtrx2.matrixLength + j) += mtrx1.contents[i * mtrx1.matrixLength + k] * mtrx2.contents[k * mtrx2.matrixLength + j];
                }
            }
        }
    }
    else 
    {
        return -7;
    }
    return 0;
}