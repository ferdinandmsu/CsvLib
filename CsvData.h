#ifndef CSV_DATA_H
#define CSV_DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CsvRow.h"

/**********************/
/*      CSVDATA       */
/*********************/

typedef struct CsvData
{
    CsvRow *csv_data; // an array storing multiply rows also CsvRows
    char delimiter;
} CsvData;

CsvRow *split_str(char *to_split, char delimiter);

CsvData *create_csv_data(char *csv_text, char delimiter);

void free_csv_data(CsvData *to_free);

void print_csv_data(CsvData *csv_data);

#endif