TARGET		:= out
RM 			:= rm

all: $(TARGET)

$(TARGET): main.o get_value.o 
	gcc main.o get_value.o -o out 

main.o: main.c 
	gcc -c main.c -o main.o 

get_value.o: get_value.asm 
	nasm -f elf64 get_value.asm -o get_value.o

clean:
	$(RM) -rf *.o $(TARGET)

run:
	./$(TARGET) 50