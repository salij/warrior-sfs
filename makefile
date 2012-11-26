#universals
default: all
clean: tool/cleandir.sh \
		clean-extras
	tool/cleandir.sh
	tool/cleandir.sh assets
	tool/cleandir.sh tests
	rm -f -r documentation
check: all clean
freshen: clean all
jdoc:	javadoc -d documentation \
		-sourcepath . \
		*.ja*
cdoc: doxyfile codefiles
	doxygen
	
#all
all: assets locals
locals: 
assets: \
		assets/blockio.o \
		assets/close_file.o \
		assets/create_file.o \
		assets/delete_file.o \
		assets/free_block_table.o \
		assets/get_size.o \
		assets/get_type.o \
		assets/globals.o \
		assets/initialize.o \
		assets/inode.o \
		assets/open_file.o \
		assets/read_dir.o \
		assets/read_file.o \
		assets/super_block.o \
		assets/write_file.o
tests: tests/sfstest

clean-extras:
	rm -f tests/sfstest

#locals


#assets
assets/blockio.o: assets/blockio.h assets/blockio.c \
		assets.h
	gcc -c assets/blockio.c -o assets/blockio.o

assets/close_file.o: assets/close_file.c \
		assets.h
	gcc -c assets/close_file.c -o assets/close_file.o
	
assets/create_file.o: assets/create_file.c \
		assets.h
	gcc -c assets/create_file.c -o assets/create_file.o
	
assets/delete_file.o: assets/delete_file.c \
		assets.h
	gcc -c assets/delete_file.c -o assets/delete_file.o
	
assets/free_block_table.o: assets/free_block_table.c \
		assets/free_block_table.h \
		assets.h
	gcc -c assets/free_block_table.c -o assets/free_block_table.o
	
assets/get_size.o: assets/get_size.c \
		assets.h
	gcc -c assets/get_size.c -o assets/get_size.o
	
assets/get_type.o: assets/get_type.c \
		assets.h
	gcc -c assets/get_type.c -o assets/get_type.o
	
assets/globals.o: assets/globals.c \
		assets.h
	gcc -c assets/globals.c -o assets/globals.o
	
assets/initialize.o: assets/initialize.c \
		assets.h
	gcc -c assets/initialize.c -o assets/initialize.o
	
assets/inode.o: assets/inode.c assets/inode.h \
		assets.h
	gcc -c assets/inode.c -o assets/inode.o
	
assets/open_file.o: assets/open_file.c \
		assets.h
	gcc -c assets/open_file.c -o assets/open_file.o
	
assets/read_dir.o: assets/read_dir.c \
		assets.h
	gcc -c assets/read_dir.c -o assets/read_dir.o
	
assets/read_file.o: assets/read_file.c \
		assets.h
	gcc -c assets/read_file.c -o assets/read_file.o
	
assets/super_block.o: assets/super_block.c assets/super_block.h \
		assets.h
	gcc -c assets/super_block.c -o assets/super_block.o
	
assets/write_file.o: assets/write_file.c \
		assets.h
	gcc -c assets/write_file.c -o assets/write_file.o

#tests
tests/sfstest.o: tests/sfstest.c \
		assets.h
	gcc -c tests/sfstest.c -o tests/sfstest.o

tests/sfstest: tests/sfstest.o \
		assets.h \
		assets
	gcc -o tests/sfstest tests/sfstest.o \
		assets/blockio.o \
		assets/close_file.o \
		assets/create_file.o \
		assets/delete_file.o \
		assets/free_block_table.o \
		assets/get_size.o \
		assets/get_type.o \
		assets/globals.o \
		assets/initialize.o \
		assets/inode.o \
		assets/open_file.o \
		assets/read_dir.o \
		assets/read_file.o \
		assets/super_block.o \
		assets/write_file.o
