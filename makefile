C_SOURCES = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp)
HEADERS = $(wildcard src/*.hpp) $(wildcard src/**/*.hpp) $(wildcard src/**/**/*.hpp)
OBJ = ${patsubst src/%.c,obj/%.o,$(C_SOURCES)}
OUTPUT = bin/draughts.exe

ifeq ($(OS),Windows_NT)
	DEV_NULL = NUL
	COPY_DIRS = xcopy src obj /t /e
	RM_DIRS = rmdir /q /s obj
else
	DEV_NULL = /dev/null
	COPY_DIRS = cd src && find . -type d -exec mkdir -p -- ../obj/{} \;
	RM_DIRS = rm -rf obj
endif

all: folders ${OUTPUT}
run: all
	./${OUTPUT}

${OUTPUT}: ${OBJ}
	g++ -o $@ $^

obj/%.o: src/%.cpp ${HEADERS}
	g++ -c $< -o $@

clean:
	${RM_DIRS}

# Ignores errors when bin and obj directories exist
# 2> NUL causes the error message to disappear forever in /dev/null
# || (exit 0) fools the shell that the command was successful
folders:
	mkdir obj 2> ${DEV_NULL} || (exit 0)
	mkdir bin 2> ${DEV_NULL} || (exit 0)
	${COPY_DIRS}
