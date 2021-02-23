# includes 
-include cpu/${CPU}.mk
-include src_path/${MODE}.mk 
-include mode/${MODE}.mk


# alias definition
MD				:= mkdir -p 
RM				:= rm -rf 

# define output directories
BUILD_DIR		:= build
BUILD_LIB_DIR	:= lib
BUILD_BIN_DIR   := bin
INSTALL_DIR		:= ${MODE}
CPU_DIR			:= ${CPU}

# project name definition
PROJECT			:= ${PROJECT_NAME}

# toolchain definition
CC              := $(TOOLCHAIN_PREFIX)gcc
AR              := $(TOOLCHAIN_PREFIX)ar
OBJCPY          := $(TOOLCHAIN_PREFIX)objcpy
OBJDUMP         := $(TOOLCHAIN_PREFIX)objdump
STRIP           := $(TOOLCHAIN_PREFIX)strip
NM              := $(TOOLCHAIN_PREFIX)nm



OBJECTS			:= $(patsubst $(SOURCE_DIR)/%,$(BUILD_DIR)/%,$(addsuffix .o,$(basename $(SOURCES))))
LIBRARIES		:= ${LIBS}
INCLUDE			:= -I${HEADERS}
TARGET			:= ${BUILD_DIR}/${INSTALL_DIR}/${CPU_DIR}/${PROJECT}

.PHONY: clean dirs 

all: dirs ${TARGET}

dirs:	
	${MD} ${BUILD_DIR}/${BUILD_BIN_DIR}/${CPU_DIR}
	${MD} ${BUILD_DIR}/${BUILD_LIB_DIR}


${TARGET}: ${OBJECTS}	
	@mkdir -p $(@D)
	${COMPILE}


$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c	
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(LIBRARIES)

clean:
	${RM} ${BUILD_DIR} 

print-vars:
	@echo ${SOURCES}
	@echo ${HEADERS}
	@echo ${OBJECTS}
	@echo ${LIBRARIES}
	@echo ${TARGET}
	@echo ${TOOLCHAIN_PREFIX}
	@echo ${CC}
	@echo ${COMPILE}
	@echo ${SRC_PATH}
	