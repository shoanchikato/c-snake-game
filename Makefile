build:
	gcc -std=c18 -Wall -Werror -g -I./include -I. -L./lib -lraylib -o ./bin/app -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL ./*.c

clean:
	rm ./bin/app

run: build
	./bin/app

debug:
	gdb ./bin/app

mem:
	# valgrind --leak-check=yes --show-reachable=no --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --log-file=./bin/valgrind-log.txt ./bin/app 
	valgrind --suppressions=./suppressions.supp --leak-check=full --track-origins=yes --log-file=./bin/valgrind-log.txt ./bin/app

