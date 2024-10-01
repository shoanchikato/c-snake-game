# Compiler and Flags
CC = gcc
CFLAGS_DEV = -fsanitize=$(ASAN) -std=c18 -g -O1 -Wall -Werror
CFLAGS_REL = -std=c18 -Wall -Werror

ENV = ASAN_OPTIONS=detect_leaks=1

# AddressSanitizer checks
# leak & memory not supported on macos
# Choose one: address, thread
ASAN = address,undefined,bounds,alignment,null,shift,signed-integer-overflow,object-size,vla-bound,float-divide-by-zero,return

# Frameworks and Libraries
FRAMEWORKS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
LDFLAGS = -L./lib -lraylib 

# Directories and Files
BIN = ./bin/app
SRC = ./*.c
INCLUDES = -I./include

# Targets
.PHONY: build release clean run debug mem

build: 
	$(ENV) $(CC) $(CFLAGS_DEV) $(INCLUDES) $(LDFLAGS) -o $(BIN) $(FRAMEWORKS) $(SRC)

release: 
	$(CC) $(CFLAGS_REL) $(INCLUDES) $(LDFLAGS) -o $(BIN) $(FRAMEWORKS) $(SRC)

clean:
	rm -rf ./bin/*

run: build
	./$(BIN)

debug:
	gdb $(BIN)

mem:
	valgrind --leak-check=full --show-reachable=no --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --log-file=./bin/valgrind-log.txt $(BIN)
