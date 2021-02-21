################ Makefile ################

-include config.mk

#output dir
OUTPUT_DIR  := .build 


# Wildcard to get all source files in current directory
SOURCES := $(shell find $(WORKSPACE) -name "*.c")

# Objects files
OBJS := $(SOURCES:.c=.o)

# Target 
TARGET := prog

#recipes

all: md_dir $(TARGET)

#Linking all libs and objects
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# compile all .c file and becomes a .o file
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Remove all .o files and TARGET
clean: rmproper
	$(RM) .build

rmproper: clean
	$(RM) $(TARGET) $(OBJS)
	

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
