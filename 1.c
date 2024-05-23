#include <stdio.h>

struct Product {
    int id;
    char name[100];
    float price;
    int quantity;
};

void writeprodtofile(struct Product products[], int count) {
    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error in opening file\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    fclose(file);
}

int main() {
    struct Product products[] = {
        {1, "Tomato", 70.00, 50},
        {2, "Potato", 35.00, 100},
        {3, "Carrot", 52.50, 80},
        {4, "Spinach", 84.00, 40},
        {5, "Onion", 56.00, 70},
        {6, "Cucumber", 105.00, 60},
        {7, "Capsicum", 87.50, 45},
        {8, "Broccoli", 140.00, 30},
        {9, "Lettuce", 122.50, 35},
        {10, "Zucchini", 91.00, 55}
    };

    int count = sizeof(products) / sizeof(products[0]);
    writeprodtofile(products, count);
    printf("Product details written to products.txt");
    return 0;
}
