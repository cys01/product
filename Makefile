CC = gcc
TARGET = product
DTARGET = product_debug
DEPENDENCY = main.c product.o manager.c
DCODE = _DEBUG

$(TARGET) : $(DEPENDENCY)
	$(CC) $^ -o $@

$(DTARGET) : $(DEPENDENCY)
	$(CC) $^ -o $@ -D=$(DCODE)

cls :
	rm -f $(TARGET) $(DTARGET) *.o
	clear
