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
		n = menuSelect();

#ifdef _DEBUG
		if(n == 1 || n == 3 || n == 4)
			readList(p, count);
#endif
	}
	return 0;
}
