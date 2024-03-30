

#include <stdio.h>
#include <stdlib.h>
#include "product.h"

Product *create_product()
{
    char name[128];
    float price;
    int qtd, sales;

    scanf(" %[^\n]", name);
    scanf(" %f", &price);
    scanf(" %d", &qtd);
    scanf(" %d", &sales);

    return product_constructor(name, price, qtd, sales);
}

int(*compare_functions)(const void* product_1, const void* product_2);

void perform_operation(Product **product_vector, int n_products)
{
    char operation;
    scanf("\n%c", &operation);

    if (operation == 'N'){
        compare_functions = product_compare_name;
        qsort(product_vector, n_products, sizeof(Product*), compare_functions);
    }
    else if (operation == 'P')
    {
        compare_functions = product_compare_price;
        qsort(product_vector, n_products, sizeof(Product*), compare_functions);
    }
    else if (operation == 'S')
    {
        compare_functions = product_compare_sales;
        qsort(product_vector, n_products, sizeof(Product*), compare_functions);
    }
    else
        printf("Operacao invalida.\n");
}

int main()
{

    int n_products = 0;
    scanf("%d", &n_products);
    Product** product_vector = (Product**)malloc(sizeof(Product*) * n_products);

    for (int i = 0; i < n_products; ++i)
        product_vector[i] = create_product();

    perform_operation(product_vector, n_products);

    for (int i = 0; i < n_products; ++i)
        product_print(product_vector[i]);

    for (int i = 0; i < n_products; ++i)
        product_destructor(product_vector[i]);

    free(product_vector);

    return 0;
}
