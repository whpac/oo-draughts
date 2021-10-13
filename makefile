C_SOURCES = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp)
HEADERS = $(wildcard src/*.h) $(wildcard src/**/*.h) $(wildcard src/**/**/*.h)
OBJ = ${patsubst src/%.c,obj/%.o,$(C_SOURCES)}
OUTPUT = bin/draughts.exe

all: folders ${OUTPUT}
run: all
	./${OUTPUT}

run-text: all
	./${OUTPUT} text

${OUTPUT}: ${OBJ}
	g++ -o $@ $^
# Version with allegro library
#	g++ -o $@ $^ -lallegro -lallegro_font -lallegro_primitives

obj/%.o: src/%.cpp ${HEADERS}
	g++ -c $< -o $@

clean:
# Windows:
#	rmdir /q /s obj
# UNIX:
	rm -rf obj

# Ignores errors when bin and obj directories exist
# 2> NUL causes the error message to disappear forever in /dev/null
# || (exit 0) fools the shell that the command was successful
folders:
# Windows:
#	mkdir obj 2> NUL || (exit 0)
#	mkdir bin 2> NUL || (exit 0)
#	xcopy src obj /t /e
# UNIX:
	mkdir obj 2> /dev/null || (exit 0)
	mkdir bin 2> /dev/null || (exit 0)
	cd src && find . -type d -exec mkdir -p -- ../obj/{} \;