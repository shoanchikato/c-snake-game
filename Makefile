build:
	gcc -g -I./include -I. -L./lib -lraylib -o ./bin/app -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL ./*.c

clean:
	rm ./bin/app

run: build
	./bin/app

debug:
	gdb ./bin/app