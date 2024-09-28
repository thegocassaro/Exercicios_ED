#include "doc_freq.h"
#include <stdlib.h>
#include <string.h>

struct DocFreq
{
    char doc_name[MAX_DOCUMENT_NAME_SIZE];
    int frequency;
};

DocFreq *df_construct(char* nome)
{
    DocFreq *df = calloc(1, sizeof(DocFreq));

    strcpy(df->doc_name, nome);
    df->frequency = 1;

    return df;
}

void df_destroy(DocFreq *df)
{
    free(df);
    df = NULL;
}

char* df_get_name(DocFreq *df)
{
    return df->doc_name;
}

int df_get_frequency(DocFreq *df)
{
    return df->frequency;
}

int cmp_df(DocFreq* a, DocFreq* b)
{
    return strcmp(a->doc_name, b->doc_name);
}

void df_set_frequency(DocFreq *df, int freq)
{
    df->frequency = freq;
}

void df_add_frequency(DocFreq *df)
{
    df->frequency++;
}