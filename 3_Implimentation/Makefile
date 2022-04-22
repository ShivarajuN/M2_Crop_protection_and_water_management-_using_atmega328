PROJ_NAME = Virtul_fenser

BUILD_DIR = Build

# All Source code files
SRC = project_main.c\
src/led.c\
src/peizo.c\
src/motor.c

CPU= -DF_CPU=16000000UL
# All header file paths
INC = -I inc

CC= avr-gcc

AVR_OBJ_CPY= avr-objcopy

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif



all:run analysis

run:$(BUILD_DIR)
	$(CC) -g -Wall -Os -mmcu=atmega328 $(CPU) $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)
	$(AVR_OBJ_CPY) -j .text -j .data -O ihex $(BULID_DIR)/$(PROJECT_NAME).elf $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).hex))

analysis: $(SRC)
# Analyse the code using Cppcheck command line utility
	cppcheck --enable=all $^

doc:
# Build the code code documentation using Doxygen command line utility
	make -C ./doc 

clean:
# Remove all the build files and generated document files
	rm -rf $(BUILD_DIR)
	make -C ./doc clean

$(BUILD_DIR):
# Create directory to store the built files
	mkdir $(BUILD_DIR)
