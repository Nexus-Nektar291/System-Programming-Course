all : myexe

myexe : myadd.o mysub.o mymul.o mydiv.o prog1.o ./d1/mymod.o
	gcc myadd.o mysub.o mymul.o mydiv.o prog1.o ./d1/mymod.o -o myexe

myadd.o : myadd.c
	gcc -c myadd.c
mysub.o : mysub.c
	gcc -c mysub.c
mymul.o : mymul.c
	gcc -c mymul.c
mydiv.o : mydiv.c
	gcc -c mydiv.c

prog1.o : prog1.c  
	gcc -c prog1.c -I.

include ./d1/makefile

clean :
	rm -f *.o

install : myexe
	cp myexe /usr/bin/
	chmod a+x /usr/bin/myexe
	chmod og-w /usr/bin/myexe
	@echo "myexe installed successfully in /usr/bin"

uninstall : 
	rm -f /usr/bin/myexe
	@echo "myexe successfully uninstalled from /usr/bin"
