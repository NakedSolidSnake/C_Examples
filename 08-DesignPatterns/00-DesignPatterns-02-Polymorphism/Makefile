################ Makefile ################

-include config.mk

#workspace directory
WORKSPACE := $(shell pwd)

#output dir
OUTPUT_DIR  := .build 

# Toolchain
CC = gcc

# Compiler Flags
CFLAGS = -Wall -g 

# Create Dir
MD	:= mkdir

# Libraries
LDFLAGS := -lm -lpthread -lrt

# Wildcard to get all source files in current directory
SOURCES := $(shell find $(WORKSPACE) -name "*.c")

# Objects files
OBJS := $(SOURCES:.c=.o)

# includes
INCLUDES := \
  	   -I$(WORKSPACE)/Core/Common \
	   -I$(WORKSPACE)/Core/Framework/Device_IOCTL \
	   -I$(WORKSPACE)/Core/Framework/Fileoperation \
	   -I$(WORKSPACE)/Core/Framework/HW_Descriptor \
	   -I$(WORKSPACE)/Core/Framework/IDriver \
	   -I$(WORKSPACE)/Core/Hardware/Device_Driver


# Target 
TARGET := prog

#recipes
all: md_dir $(TARGET)

#Linking all libs and objects
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)


# compile all .c file and becomes a .o file
#%.o: %.c
#	$(CC) $(INCLUDES) -c $(CFLAGS) $^
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
#	mv $@ $(OUTPUT_DIR)

# Remove all .o files and TARGET
clean: rmproper
	rm -rf .build

rmproper: clean
	rm -rf $(TARGET) $(OBJS)
	

run:
	./$(TARGET)

md_dir:
#	$(MD) $(OUTPUT_DIR)

print-vars:
	@echo "Includes: $(INCLUDES)"
	@echo "------------------------------------------------------------------------------"
	@echo "sources: $(SOURCES)"
	@echo "------------------------------------------------------------------------------"
	@echo "objects: $(OBJS)"
	@echo "------------------------------------------------------------------------------"
	@echo "workspace directory: $(WORKSPACE)"
	@echo "------------------------------------------------------------------------------"
