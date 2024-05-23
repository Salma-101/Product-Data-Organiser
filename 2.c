#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_PRODUCTS = 100;
const int MAX_NAME_LENGTH = 100;

typedef struct product {
    int id;
    char *name;
    double price;
} Product;

int store_products(const char *filename, Product products[], int maxProducts) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    int count = 0;
    char line[1000];

    while (fgets(line, sizeof(line), fp)) {
        if (count >= maxProducts) {
            printf("Maximum number of products reached.\n");
            break;
        }

        products[count].name = malloc(MAX_NAME_LENGTH * sizeof(char));
        if (products[count].name == NULL) {
            printf("Memory allocation failed.\n");
            return -1;
        }

        if (sscanf(line, "%d %s %lf", &products[count].id, products[count].name, &products[count].price) == 3) {
            count++;
        } else {
            printf("Error reading line: %s", line);
        }
    }

    fclose(fp);
    return count;
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = store_products("products.txt", products, MAX_PRODUCTS);

    if (numProducts < 0) {
        printf("Error reading products\n");
        return 1;
    }

    printf("Number of products read: %d\n", numProducts);
    for (int i = 0; i < numProducts; i++) {
        printf("Product %d: ID=%d, Name=%s, Price=%.2f\n", i + 1, products[i].id, products[i].name, products[i].price);
        free(products[i].name);
    }

    return 0;
}
