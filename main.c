#include <stdio.h>

#include "CsvLib.h" // Header

int main()
{
    /*
        Simple Example for reading csv, changing the delimiter and 
        writing it into a new file
    */

    char *file_content = NULL; // Buffer for string
    CsvData *csv_data = read_csv("./tests/100.csv", ',', file_content);

    csv_data->delimiter = ';';
    write_csv("./tests/new.csv", csv_data); // rewriing csv

    free_csv_data(csv_data); // freeing the csv_data
    free(file_content);      // freeing the buffer
    file_content = NULL;

    return 0;
}