#ifndef CSV_LIB_H
#define CSV_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CsvData.h"

CsvData *read_csv(const char *file_name, char delimiter, char *file_content);

void write_csv(const char *out_file, CsvData *csv_data);

long get_file_size(FILE *file);

#endif