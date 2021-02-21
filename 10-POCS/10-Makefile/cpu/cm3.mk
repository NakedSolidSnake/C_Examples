# CROSS_TOOLCHAIN        ?= $(subst \,/,$(TOOLCHAIN_HOME))bin/arm-linux-androideabi-
TOOLCHAIN_PREFIX       = arm-linux-gnueabihf-

# CFLAGS                 := -std=c99 -fPIE -fPIC -I$(subst \,/,$(TOOLCHAIN_HOME))../opt/include
CFLAGS                 := -std=c99 -fPIE -fPIC 


# cpuRequisites:
# ifeq (, $(CC))
# 	$(error Compiler not found "$(CC)", set variable TOOLCHAIN_HOME or put it on the path)
# endif	