#include "product.h"
#include "manager.h"

void readList(Product *p, int num) {
	printf("No\t%s\t\t\t무게\t가격\t별점\n", "이름");
	for(int i = 0; i < num; i++)
		if(*p[i].name != 0) {
			printf("%d\t", i+1);
			readProduct(p[i]);
		}
}

int updateList(Product *p, int num) {
	readList(p, num);

	int idx;
	printf("수정할 번호는? (0: 취소)");
	scanf("%d", &idx);

	if(idx == 0)
		return 0;
	updateProduct(&p[idx-1]);
	return 1;
}

int deleteList(Product *p, int num) {
	readList(p, num);

	int idx;
	printf("삭제할 번호는? (0: 취소)");
	scanf("%d", &idx);

	if(idx == 0)
		return 0;
	deleteProduct(&p[idx-1]);
	return 1;
}

int loadList(char *file, Product *p) {
	FILE *fp = fopen(file, "r");
	if(fp == NULL)
		return 0;
	int i;
	for(i = 0; fscanf(fp, " %d", &p[i].weight) != EOF; i++) {
		fscanf(fp, " %d %d %d %[^\n]", &p[i].price, &p[i].star_rating, &p[i].star_count, p[i].name);
	}

	return i;
}

void saveList(char *file, Product *p, int num) {
	FILE *fp = fopen(file, "w");

	for(int i = 0; i < num; i++) {
		if(*p[i].name != 0)
			fprintf(fp, "%d %d %d %d %s\n", p[i].weight, p[i].price, p[i].star_rating, p[i].star_count, p[i].name);
	}

	printf("정보를 저장했습니다\n");
}

void searchName(Product *p, int count) {

}

void searchPrice(Product *p, int count) {

}

void searchStar(Product *p, int count) {

}

int menuSelect() {
	int n;
	printf("\n0: 사용종료\n1: 상품추가\n2: 상품조회\n3: 상품수정\n4: 상품삭제\n5: 목록저장\n6: 이름검색\n7: 가격검색\n8: 별점검색\n\n");
	scanf("%d", &n);

	return n;
}
