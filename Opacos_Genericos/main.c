

#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "vector.h"

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

// int(*compare_functions)(const void* product_1, const void* product_2);

void perform_operation(Product **product_vector, int n_products)
{
    char operation;
    scanf("\n%c", &operation);

    if (operation == 'N'){
        qsort(product_vector, n_products, sizeof(Product*), product_compare_name);
    }
    else if (operation == 'P')
    {
        qsort(product_vector, n_products, sizeof(Product*), product_compare_price);
    }
    else if (operation == 'S')
    {
        qsort(product_vector, n_products, sizeof(Product*), product_compare_sales);
    }
    else
        printf("Operacao invalida.\n");
}

int main()
{

    int n_products = 0;
    scanf("%d", &n_products);

    Vector* product_vector = vector_construct(product_destructor);

    for (int i = 0; i < n_products; ++i){

        Product* new_product = create_product();
        vector_push_back(product_vector, new_product);
    }

    perform_operation(product_vector, n_products);

    for (int i = 0; i < n_products; ++i){

        product_print(product_vector[i]);
    }

    vector_destroy(product_vector);

    return 0;
}
