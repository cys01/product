#include "product.h"
#include "manager.h"

int main() {
#ifdef _DEBUG
	printf("==> DEBUG MODE\n");
#endif
	Product p[10];
	
	int n = -1;
	int count = loadList("product.txt", p);

	if(count)
		printf("%d개의 데이터를 가져왔습니다..!\n", count);
	else
		printf("데이터가 존재하지 않습니다.\n");

#ifdef _DEBUG
	if(count)
		readList(p, count);
#endif

	while(n != 0) {
		printf("\n0: 사용종료\n1: 상품추가\n2: 상품조회\n3: 상품수정\n4: 상품삭제\n5: 목록저장\n6: 이름검색\n7: 가격검색\n8: 별점검색\n\n");
		scanf("%d", &n);

		switch(n) {
			case 1:
				count += createProduct(&p[count]);
				break;
			case 2:
				readList(p, count);
				break;
			case 3:
				if(updateList(p, count) == 1)
					printf("수정 완료!\n\n");
				else
		
					printf("수정 취소\n\n");
				break;
			case 4:
				if(deleteList(p, count) == 1)
					printf("삭제 완료!\n\n");
				else
					printf("삭제 취소\n\n");
				break;
			case 5:
				saveList("product.txt", p, count);
				break;
			case 6:
				searchName(p, count);
				break;
			case 7:
				searchPrice(p, count);
				break;
			case 8:
				searchStar(p, count);
		}
#ifdef _DEBUG
		if(n == 1 || n == 3 || n == 4)
			readList(p, count);
#endif
	}
	return 0;
}
