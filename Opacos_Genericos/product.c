#include "product.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product{

    char name[MAX_NAME_LENGTH];
    float price; //preco (float positivo),
    float discount; //desconto (float entre 0 e 1),
    int qtd; //quantidade em estoque (inteiro não negativo)
    int sales; //numero de vendas (inteiro não negativo).
};

Product* product_constructor(const char* name, float price, int qtd, int sales){

    if(price <= 0 || qtd < 0 || sales < 0){
        printf("VALOR INVALIDO\n");
        return NULL;
    }

    Product* p = (Product*)calloc(1, sizeof(Product));

    strcpy(p->name, name);
    p->price = price;
    p->qtd = qtd;
    p->sales = sales;

    return p;
}

const char *product_get_name(Product *product){

    return product->name;
}

float product_get_price(Product *product){

    return product->price;
}

float product_get_discount(Product *product){

    return product->discount;
}

int product_get_qtd(Product *product){

    return product->qtd;
}

int product_get_sales(Product *product){

    return product->sales;
}

void product_set_name(Product *product, const char *name){

    if(strlen(name) > MAX_NAME_LENGTH){
        printf("VALOR INVALIDO\n");
        return;
    }

    strcpy(product->name, name);
}

void product_set_price(Product *product, float price){

    if(price < 0){
        printf("VALOR INVALIDO\n");
        return;
    }

    product->price = price;
}

void product_set_discount(Product *product, float discount){

    if(discount < 0 || discount > 1){
        printf("VALOR INVALIDO\n");
        return;
    }

    product->discount = discount;
}

void product_sell(Product *product, int quantity){

    if(quantity <= 0){
        printf("QUANTIDADE INVALIDA\n");
        return;
    }

    if(quantity > product->qtd){
        printf("ESTOQUE INSUFICIENTE\n");
        return;
    }

    product->qtd -= quantity;
    product->sales += quantity;
}

void product_buy(Product *product, int quantity){

    if(quantity <= 0){
        printf("QUANTIDADE INVALIDA\n");
        return;
    }

    product->qtd += quantity;
}

float product_get_price_with_discount(Product *product){

    return (product->price - product->discount * product->price);
}

void product_print(Product *product){

    printf("Product(");
    printf("%s, ", product->name);
    printf("%.2f, ", product->price);
    printf("%.2f, ", product->discount);
    printf("%.2f, ", product_get_price_with_discount(product));
    printf("%d, ", product->qtd);
    printf("%d)\n", product->sales);
}

void product_destructor(Product *product){

    free(product);
    product = NULL;
}

int product_compare_name(const void* product_1, const void* product_2){

    Product *p1 = *((Product **)product_1);
    Product *p2 = *((Product **)product_2);

    return strcmp(p1->name, p2->name);
}

int product_compare_price(const void* product_1, const void* product_2){

    Product *p1 = *((Product **)product_1);
    Product *p2 = *((Product **)product_2);

    if(p1->price < p2->price) return -1;
    else if(p1->price > p2->price) return 1;
    return 0;
}

int product_compare_sales(const void* product_1, const void* product_2){

    Product *p1 = *((Product **)product_1);
    Product *p2 = *((Product **)product_2);

    if(p1->sales < p2->sales) return -1;
    else if(p1->sales > p2->sales) return 1;
    return 0;
}