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
char target[30];
	printf("찾을 이름은? ");
	scanf(" %[^\n]", target);

	for(int i = 0; i < count; i++) {
		int isFound = 0;
		for(int j = 0; p[i].name[j] != 0 && !isFound; j++) {
			if(p[i].name[j] == target[0]) {
				int same = 1;
				for(int k = 1; target[k] != 0 && same; k++) {
					if(p[i].name[j + k] != target[k])
						same = 0;
				}
				if(same)
					isFound = 1;
			}
		}
		if(isFound)
			readProduct(p[i]);
	}	
}

void searchPrice(Product *p, int count) {
	int target;
	printf("찾을 가격대는? ");
	scanf("%d", &target);

	for(int i = 0; i < count; i++) {
		if(p[i].price == target) {
			readProduct(p[i]);
		}
	}
}

void searchStar(Product *p, int count) {
	int target;
	printf("찾을 별점대는? ");
	scanf("%d", &target);

	for(int i = 0; i < count; i++) {
		if(p[i].star_rating == target) {
			readProduct(p[i]);
		}
	}	
}

int menuSelect(Product *p, int *count) {
	int n;
	printf("\n0: 사용종료\n1: 상품추가\n2: 상품조회\n3: 상품수정\n4: 상품삭제\n5: 목록저장\n6: 이름검색\n7: 가격검색\n8: 별점검색\n\n");
	scanf("%d", &n);

	switch(n) {
		case 1:
			*count += createProduct(&p[*count]);
			break;
		case 2:
			readList(p, *count);
			break;
		case 3:
			if(updateList(p, *count) == 1)
				printf("수정 완료!\n\n");
			else	
				printf("수정 취소\n\n");
			break;
		case 4:
			if(deleteList(p, *count) == 1)
				printf("삭제 완료!\n\n");
			else
				printf("삭제 취소\n\n");
			break;
		case 5:
			saveList("product.txt", p, *count);
			break;
		case 6:
			searchName(p, *count);
			break;
		case 7:
			searchPrice(p, *count);
			break;
		case 8:
			searchStar(p, *count);
	}


#ifdef _DEBUG
		if(n == 1 || n == 3 || n == 4)
			readList(p, *count);
#endif
	
	return n;
}
