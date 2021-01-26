#include "CsvLib.h"

CsvData *read_csv(const char *file_name, char delimiter, char *file_content)
{
    FILE *csv_file = fopen(file_name, "r");

    if (!csv_file)
    {
        fclose(csv_file);
        return NULL;
    }

    long fsize = get_file_size(csv_file);
    file_content = (char *)calloc(1, fsize + 1);

    if (!file_content)
    {
        fclose(csv_file);
        return NULL;
    }

    fread(file_content, sizeof(char), fsize, csv_file);
    CsvData *new_data = create_csv_data(file_content, delimiter);

    fclose(csv_file);
    return new_data;
}

void write_csv(const char *out_file, CsvData *csv_data)
{
    FILE *csv_file = fopen(out_file, "w");
    char outformat[] = {'%', 's', csv_data->delimiter, '\0'};

    if (!csv_file)
    {
        fclose(csv_file);
        return;
    }

    for (unsigned int i = 0; i < csv_data->csv_data->length; ++i)
    {
        for (unsigned int j = 0; j < ((CsvRow *)csv_data->csv_data->data_ptr[i])->length; ++j)
        {
            if (j == ((CsvRow *)csv_data->csv_data->data_ptr[i])->length - 1)
                fprintf(csv_file, "%s", ((CsvRow *)csv_data->csv_data->data_ptr[i])->data_ptr[j]);
            else
                fprintf(csv_file, outformat, ((CsvRow *)csv_data->csv_data->data_ptr[i])->data_ptr[j]);
        }
        fprintf(csv_file, "\n");
    }

    fclose(csv_file);
}

long get_file_size(FILE *file_ptr)
{
    fseek(file_ptr, 0L, SEEK_END);
    long lSize = ftell(file_ptr);
    rewind(file_ptr);
    return lSize;
}