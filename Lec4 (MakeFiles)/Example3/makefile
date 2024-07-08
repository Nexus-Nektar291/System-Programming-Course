myexe : myadd.o mysub.o mymul.o mydiv.o prog1.o
	gcc myadd.o mysub.o mymul.o mydiv.o prog1.o -o myexe
mydiv.o : mydiv.c
	gcc -c mydiv.c
mymul.o : mymul.c
	gcc -c mymul.c
mysub.o : mysub.c
	gcc -c mysub.c
myadd.o : myadd.c
	gcc -c myadd.c
prog1.o : prog1.c
	gcc -c prog1.c -I.

clean : 
	rm -f *.o
install : myexe
	@cp myexe /usr/bin
	@chmod a+x /usr/bin/myexe 
	@chmod og-w /usr/bin/myexe
	@echo "myexe successfully installed in /usr/bin"
uninstall : install
	@rm -f /usr/bin/myexe
	@echo "myexe successfully uninstalled in /usr/bin"
