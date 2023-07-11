mython:		lex.yy.c mython.tab.c mython.tab.h
	gcc -o mython -g mython.tab.c lex.yy.c -ly -ll

lex.yy.c:	mython.l
	flex mython.l

mython.tab.c:	mython.y
	bison -vd mython.y

clean:
	rm -rf mython.tab.* lex.yy.* mython.output mython
