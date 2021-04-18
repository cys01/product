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
