//sort_fun.c

#include <stdlib.h>
#include <time.h>
#include "enigmalib.h"

void quickSort (int *, int, int);

int sortFun (int *array, int size)
{
    quickSort (array, 0, size - 1);

    return EXIT_SUCCESS;
}

void quickSort (int array [], int first, int last)
{
    srand (time (NULL));

    int left = first;
    int right = last;
    int midle = array [left + rand () % (right - left + 1)];//выбор случайного элемента
    int temp = 0;

    while (left <= right) {
        while (array [left] < midle) {
            ++left;
        }
        while (array [right] > midle) {
            --right;
        }

        if (left <= right) {//если обнаружен элементы не соответствующие условиям
            temp = array [left];
            array [left] = array [right];
            array [right] = temp;//они переставляются
            ++left;
            --right;
        }
    }

    if (first < right) {//рекурсия
        quickSort (array, first, right);
    }

    if (last > left) {
        quickSort (array, left, last);
    }

    return;
}
