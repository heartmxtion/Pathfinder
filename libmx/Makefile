NAME_LIB = libmx.a

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc

all: create_obj LIBMX create_lib

create_obj:
	mkdir obj

LIBMX:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -c src/*.c
	mv *.o obj/

create_lib:
	ar -rc $(NAME_LIB) obj/*.o
	ranlib $(NAME_LIB)

clean:
	rm -rf obj

uninstall:
	rm -rf obj
	rm -rf $(NAME_LIB)

reinstall:
	make uninstall
	make
