CC						:= gcc
CFLAGS					:= -g -O0 -Wall

TARGET_SERVER			:= server
TARGET_CLIENT			:= client

TARGET_SERVER_SRC		:= server.c
TARGET_CLIENT_SRC		:= client.c

TARGET_SERVER_OBJ		:= server.o
TARGET_CLIENT_OBJ		:= client.o

LIBS					:= -lpthread

all: $(TARGET_SERVER) $(TARGET_CLIENT)


$(TARGET_SERVER): $(TARGET_SERVER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)


$(TARGET_CLIENT): $(TARGET_CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


$(TARGET_SERVER_OBJ): $(TARGET_SERVER_SRC)
	$(CC) $(CFLAGS) -c $< -o $@


$(TARGET_CLIENT_OBJ): $(TARGET_CLIENT_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(TARGET_SERVER) $(TARGET_CLIENT) $(TARGET_SERVER_OBJ) $(TARGET_CLIENT_OBJ)

info:
	@echo "Build server type 'make server' "
	@echo "Build client type 'make client' "
