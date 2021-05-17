# example makefile, it's not a good one though
ZU=zimbu
CC=gcc
#CC=clang
ENDCFLAGS=-llua -lm -ldl -L./lua/ -I./lua/
CFLAGS=
ZUFLAGS=--ccarg "$(CFLAGS)" --ccendarg "$(ENDCFLAGS)"

all:
	mkdir -p target/bin/
	-cp src/lua_scripts/*.lua .
	cref src/main.zu
	mv out.zu src/out.zu
	$(ZU) $(ZUFLAGS) src/out.zu -o target/bin/venci
	cp src/ZUDIR/out.c target/c/

c:
	mkdir -p target/bin/
	$(CC) $(CFLAGS) target/c/out.c -o target/bin/venci $(ENDCFLAGS)

