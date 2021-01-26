#ifndef CSV_ROW_H
#define CSV_ROW_H

#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 10

/**********************/
/*     DATARRAY      */
/*********************/

typedef struct CsvRow
{
    void **data_ptr; // random array {int, int, char*}
    unsigned int capactiy;
    unsigned int length;
} CsvRow;

CsvRow *create_csv_row();

void push_csv_row(CsvRow *csv_row, void *val);

void pop_csv_row(CsvRow *csv_row);

void expand_csv_row(CsvRow *csv_row);

void shrink_csv_row(CsvRow *csv_row);

void free_csv_row(CsvRow *csv_row);

void print_str_row(CsvRow *csv_row);

#endif