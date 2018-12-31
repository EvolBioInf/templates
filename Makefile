all:
	make -C common
	make -C srcMakeCfile
	make -C srcMakeCproject
	mkdir -p build
	cp srcMakeCproject/makeCproject build
	cp srcMakeCfile/makeCfile       build
test:
	make -C srcMakeCfile    test
	make -C srcMakeCproject test
clean:
	make -C common          clean
	make -C srcMakeCfile    clean
	make -C srcMakeCproject clean
	make -C doc             clean
.PHONY:	doc
doc:	
	make -C doc
