#include "CsvData.h"

CsvRow *split_str(char *to_split, char delimiter)
{
    CsvRow *new_array = create_csv_row();
    char delim_array[] = {delimiter, '\0'};
    char *ptr = strtok(to_split, delim_array);

    while (ptr != NULL)
    {
        push_csv_row(new_array, ptr);
        ptr = strtok(NULL, delim_array);
    }
    return new_array;
}

CsvData *create_csv_data(char *csv_text, char delimiter)
{
    CsvData *new_data = (CsvData *)malloc(sizeof(CsvData));
    new_data->delimiter = delimiter;
    new_data->csv_data = create_csv_row(); // { { "", "" }, {"", ""} }
    CsvRow *csv_lines = split_str(csv_text, '\n');

    for (unsigned int i = 0; i < csv_lines->length; ++i)
    {
        CsvRow *spl_line = split_str(csv_lines->data_ptr[i], new_data->delimiter);
        push_csv_row(new_data->csv_data, spl_line);
    }

    return new_data;
}

void free_csv_data(CsvData *to_free)
{
    if (!to_free)
        return;

    for (unsigned int i = 0; i < to_free->csv_data->length; ++i)
    {
        if (to_free->csv_data->data_ptr[i] == NULL)
            continue;
        free(to_free->csv_data->data_ptr[i]);
        to_free->csv_data->data_ptr[i] = NULL;
    }
    free(to_free->csv_data->data_ptr);
    to_free->csv_data->data_ptr = NULL;
    free(to_free);
    to_free = NULL;
}

void print_csv_data(CsvData *to_print)
{
    printf("{\n");
    for (unsigned int i = 0; i < to_print->csv_data->length; ++i)
    {
        printf("    ");
        print_str_row(to_print->csv_data->data_ptr[i]);
    }
    printf("}\n");
}