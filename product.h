#include <stdio.h>

typedef struct{
    char name[30];          // name of Product
    int weight;             // weight of Product
    int price;              // price of Product
    int star_rating;        // star_rating of Product
    int star_count;         // the number of who evaluated star_rating
} Product;

int createProduct(Product *p);                          // add new product information on last index
void readProduct(Product p);                            // print a information of product in format
int updateProduct(Product *p);                          // change the values of a product
int deleteProduct(Product *p);                          // make the value of product useless
