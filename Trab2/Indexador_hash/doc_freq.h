#ifndef DOC_FREQ_H_
#define DOC_FREQ_H_

#define MAX_WORD_SIZE 100
#define MAX_DOCUMENT_NAME_SIZE 50

typedef struct DocFreq DocFreq;

DocFreq* df_construct(char* d_name);
void df_destroy(DocFreq *df);

int cmp_df(DocFreq* a, DocFreq* b);

char* df_get_name(DocFreq *df);
int df_get_frequency(DocFreq *df);
void df_set_frequency(DocFreq *df, int freq);

void df_add_frequency(DocFreq *df);

#endif