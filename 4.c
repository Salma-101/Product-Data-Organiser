// Write a function that searches for a product by its ID in file "products.txt".
// If product is found, function should print its details.
// If not, it should print "Product not found."

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void search_product_by_id(int product_id) {
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("The file products.txt does not exist.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        int id;
        char name[MAX_LINE_LENGTH];
        float price;
        int quantity;
        if (sscanf(line, "%d %s %f %d", &id, name, &price, &quantity) == 4) {
            if (id == product_id) {
                printf("Product ID: %d\n", id);
                printf("Product Name: %s\n", name);
                printf("Product Price: %.2f\n", price);
                printf("Product Quantity: %d\n", quantity);
                fclose(file);
                return;
            }
        }
    }

    printf("Product not found.\n");
    fclose(file);
}

int main() {
    int product_id;
    printf("Enter the product ID to search: ");
    scanf("%d", &product_id);
    search_product_by_id(product_id);
    return 0;
}
