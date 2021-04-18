#include "product.h"

int createProduct(Product *p) {
	printf("추가할 상품에 대한 정보를 입력해 주세요\n");
	printf("이름은? ");
	scanf(" %[^\n]", p->name);
	printf("무게는? ");
	scanf("%d", &p->weight);
	printf("가격은? ");
	scanf("%d", &p->price);
	printf("별점은? ");
	scanf("%d", &p->star_rating);
	printf("별점을 입력한 사람들의 수는? ");
	scanf("%d", &p->star_count);
	return 1;		
}

void readProduct(Product p) {
	printf("%s\t", p.name);
	int len;
	for(len = 0; p.name[len] != 0; len++);
	if(len <= 8) printf("\t");
	if(len <= 24) printf("\t");
	printf("%dg\t%d원\t", p.weight, p.price);
	for(int i = 0; i < p.star_rating; i++)
		printf("★");
	printf(" (%d개)\n", p.star_count);
}

int updateProduct(Product *p) {
	printf("변경할 상품에 대한 정보를 입력해 주세요\n");
	printf("이름은? ");
	scanf(" %[^\n]", p->name);
	printf("무게는? ");
	scanf("%d", &p->weight);
	printf("가격은? ");
	scanf("%d", &p->price);
	printf("별점은? ");
	scanf("%d", &p->star_rating);
	printf("별점을 입력한 사람들의 수는? ");
	scanf("%d", &p->star_count);
	return 1;		
}

int deleteProduct(Product *p) {
	if(*p->name != 0) {
		*p->name = 0;
		p->weight = -1;
		p->price = -1;
		p->star_rating = -1;
		p->star_count = -1;
		return 1;
	}
	return 0;
}
