#include "CsvRow.h"

CsvRow *create_csv_row()
{
    CsvRow *csv_row = (CsvRow *)malloc(sizeof(CsvRow));
    void **new_data_ptr = (void **)malloc(sizeof(void *) * INIT_CAPACITY);

    csv_row->length = 0;
    csv_row->capactiy = INIT_CAPACITY;
    csv_row->data_ptr = new_data_ptr;

    return csv_row;
}

void push_csv_row(CsvRow *csv_row, void *val)
{
    if (!csv_row || !csv_row->data_ptr)
        return;
    csv_row->data_ptr[csv_row->length] = val;
    csv_row->length++;

    if (csv_row->length == csv_row->capactiy)
        expand_csv_row(csv_row);
}

void pop_csv_row(CsvRow *csv_row)
{
    if (!csv_row || !csv_row->data_ptr)
        return;
    free(csv_row->data_ptr[csv_row->length - 1]);
    csv_row->data_ptr[csv_row->length - 1] = NULL;
    csv_row->length--;

    if (csv_row->length < (csv_row->capactiy / 2u))
        shrink_csv_row(csv_row);
}

void expand_csv_row(CsvRow *csv_row)
{
    if (!csv_row || !csv_row->data_ptr)
        return;

    csv_row->capactiy *= 2u;
    csv_row->data_ptr = realloc(csv_row->data_ptr, sizeof(void *) * csv_row->capactiy);
}

void shrink_csv_row(CsvRow *csv_row)
{
    if (!csv_row || !csv_row->data_ptr)
        return;

    csv_row->capactiy /= 2u;
    csv_row->data_ptr = realloc(csv_row->data_ptr, sizeof(void *) * csv_row->capactiy);
}

void free_csv_row(CsvRow *csv_row)
{
    if (!csv_row || !csv_row->data_ptr)
        return;

    for (unsigned int i = 0; i < csv_row->capactiy; ++i)
    {
        if (csv_row->data_ptr[i] == NULL)
            continue;
        free(csv_row->data_ptr[i]);
        printf("freeing");
    }
    free(csv_row->data_ptr);
    csv_row->data_ptr = NULL;
}

void print_str_row(CsvRow *csv_row)
{
    if (!csv_row || !csv_row->data_ptr)
        return;

    printf("{ ");
    for (unsigned int i = 0; i < csv_row->length; ++i)
    {
        if (i == csv_row->length - 1)
            printf("'%s' ", (char *)csv_row->data_ptr[i]);
        else
            printf("'%s', ", (char *)csv_row->data_ptr[i]);
    }
    printf("};\n");
}