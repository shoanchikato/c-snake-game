build:
	gcc -g -std=c18 -Wall -Werror -I./include -I. -L./lib -lraylib -o ./bin/app -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL ./*.c

clean:
	rm -rf ./bin/*

run: build
	./bin/app

debug:
	gdb ./bin/app

mem:
	valgrind --leak-check=full --show-reachable=no --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --log-file=./bin/valgrind-log.txt ./bin/app 

