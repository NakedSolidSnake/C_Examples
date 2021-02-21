TARGET		:= registry.out

all: $(TARGET)

$(TARGET): menu.o main.o repository.o list.o product.o
	gcc -o $(TARGET) menu.o main.o repository.o list.o product.o

menu.o: menu.c
	gcc -g -c menu.c -o menu.o

repository.o: repository.c
	gcc -g -c repository.c -o repository.o

main.o: main.c
	gcc -g -c main.c -o main.o

list.o: list.c
	gcc -g -c list.c -o list.o

product.o: product.c
	gcc -g -c product.c -o product.o

clean:
	rm -rf *.o $(TARGET)

run:
	./$(TARGET)

