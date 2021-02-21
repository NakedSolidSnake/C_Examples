CC 						:= gcc
RMDIR 					:= rm -rf
MD						:= mkdir

WORKSPACE_DIR			:= $(shell pwd)

CORE_DIR				:= $(WORKSPACE_DIR)/Core/Devices

C_FILES_PATH			:=  $(WORKSPACE_DIR) \
							$(WORKSPACE_DIR)/rtos \
							$(WORKSPACE_DIR)/rtos/tasks \
							$(WORKSPACE_DIR)/Algorithm \
							$(WORKSPACE_DIR)/FileOperation \
							$(WORKSPACE_DIR)/BSP \
							$(CORE_DIR)/ADC \
							$(CORE_DIR)/Outputs \
							$(CORE_DIR)/Bluetooth\
							$(CORE_DIR)/KeyBoard \
							$(CORE_DIR)/LCD16 \
							$(CORE_DIR)/LCD_Graphics \
							$(CORE_DIR)/Serial \
							$(CORE_DIR)/Timers \
							$(CORE_DIR)/ZigBee

LIBS 				:= 	pthread

TARGET				:= weigh_system
OUTPUT_DIR			:= build

#INC_DIR 			:= $(shell find $(WORKSPACE_DIR) -type d)

INC_DIR				+= $(WORKSPACE_DIR) \
					   $(WORKSPACE_DIR)/rtos \
					   $(WORKSPACE_DIR)/rtos/tasks \
					   $(WORKSPACE_DIR)/Algorithm \
					   $(WORKSPACE_DIR)/BSP \
					   $(WORKSPACE_DIR)/FileOperation \
					   $(CORE_DIR)/ADC \
					   $(CORE_DIR)/Outputs \
					   $(CORE_DIR)/Bluetooth\
					   $(CORE_DIR)/KeyBoard \
					   $(CORE_DIR)/LCD16 \
					   $(CORE_DIR)/LCD_Graphics \
					   $(CORE_DIR)/Serial \
					   $(CORE_DIR)/Timers \
					   $(CORE_DIR)/ZigBee

C_FILES				:= $(shell find $(C_FILES_PATH) -type f -name "*.c")
#C_FILES				:= $(wildcard $(WORKSPACE_DIR)/*.c)
#C_FILES             := $(wildcard $(C_FILES_PATH)/*.c)
	
CFLAGS				+= $(addprefix -I, $(C_FILES))

OBJECTS				:= $(addprefix $(OUTPUT_DIR)/, $(C_FILES))
OBJECTS				:= $(C_FILES:.c=.o)
#OBJECTS				:= $(patsubst %.c, %.o, $(wildcard *.c))

LD_FLAGS			+= $(addprefix -l, $(LIBS))

#LD_FLAGS			+= $(addprefix -L, $(LIBS_DIR))

INC_FLAGS			:= $(addprefix -I, $(INC_DIR))

.PHONY: all clean info




all: $(OUTPUT_DIR)/$(TARGET)

$(OUTPUT_DIR)/$(TARGET): $(OBJECTS)
	@$(MD) -p $(dir $@)
	@echo "linking $@"
	$(CC)  -o $@ $^ $(LD_FLAGS) 


$(OUTPUT_DIR)/%.o: %.c
	@$(MD) -p $(dir $@)
	@echo "compiling $<..."
	$(CC) -c $(CFLAGS) $(INC_FLAGS) $< -o $@ 

clean: 
	@echo "Cleaning..."
	${RMDIR} *.o $(TARGET)
	${RMDIR} $(OUTPUT_DIR)

info:
	@echo "Compiler $(CC)"
	@echo "----------------------------------------------------------------"
	@echo "Libraries $(LIBS)"
	@echo "----------------------------------------------------------------"
	@echo "CFLAGS $(CFLAGS)"
	@echo "----------------------------------------------------------------"	
	@echo "INC_DIR $(INC_DIR)"
	