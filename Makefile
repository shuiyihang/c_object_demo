FILE=c_object.o round.o Rect.o compile.o
build:$(FILE)
	gcc -o build.out $(FILE)
	@rm -rf *.o

c_object.o:c_object.h

round.o:round.h c_object.h

Rect.o:Rect.h c_object.h

compile.o:Rect.h c_object.h round.h

clean:
	@rm -rf build.out 

