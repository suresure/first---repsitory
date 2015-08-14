edit: symtable.o UnitTest.o 
	gcc -o edit UnitTest.o symtable.o
symtable.o:  symtable.c symtable.h
	gcc -c  symtable.c
UnitTest.o: UnitTest.c  symtable.c   symtable.h
	gcc -c UnitTest.c  symtable.c
clean:
	rm -rf *.o edit
all:    UnitTest.o symtable.o   edit
compile:UnitTest.o symtable.o   edit
test :   edit  UnitTest.o  symtable.o




