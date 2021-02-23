-include profile/${PROFILE}.mk
-include arch/${ARCH}.mk
-include config/config.mk

CC 			?= gcc
CFLAGS		?= -W -Wall -ansi -pedantic
TARGET		:= app
RM			:= rm -rf
MKDIR		:= mkdir

BUILD_DIR	= build

INCLUDE_DIR	= -I./include
SOURCE_DIR	= src
SOURCES		= $(wildcard $(SOURCE_DIR)/*.c)
LIB_DIR		=
OBJS 		= $(pastsub $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

DEPENDENCIES = mysql
DEPENDENCIES += pthread
DEPENDENCIES += printf

.PHONY: all clean

all: dir $(BUILD_DIR)/$(TARGET).out

dir:
	$(MKDIR) -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET).out: $(OBJS)
	$(CC) $^ -o $@
	# $(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

$(OBJS): $(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c 
	$(CC) $(CFLAGS) $< -o $@
	# $(CC) -c $(INCLUDE_DIR) $< $(CFLAGS) -o $@

clean:
	$(RM) $(BUILD_DIR)

print_vars:
	@echo $(SOURCES)
	@echo "---------------------"
	@echo $(OBJS)
	@echo "---------------------"
	@echo $(shell `ls $(BUILD_DIR)/* `)

vars:	
	@echo $(DEPENDENCIES)

