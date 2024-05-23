#include <stdio.h>
#include <stdlib.h>

void add_product() {
    FILE* fp = fopen("products.txt", "a");
    if (fp == NULL) {
        printf("Error in opening the file\n");
        return;
    }

    char id[50];
    char product_name[50];
    char quantity[50];
    char price[50];

    printf("Enter id: ");
    scanf("%49s", id); // Limit input to avoid buffer overflow
    printf("Enter product name: ");
    scanf("%49s", product_name); // Limit input to avoid buffer overflow
    printf("Enter quantity: ");
    scanf("%49s", quantity); // Limit input to avoid buffer overflow
    printf("Enter price: ");
    scanf("%49s", price); // Limit input to avoid buffer overflow

    fprintf(fp, "%s %s %s %s\n", id, product_name, price, quantity); // Add a newline for better formatting
    fclose(fp);
    printf("Product added successfully.\n");
}

int main() {
    add_product();
    return 0;
}
