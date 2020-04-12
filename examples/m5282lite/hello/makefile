
##############################################################################################
# Start of default section
#

TRGT = m68k-elf-
CC   = $(TRGT)gcc
CP   = $(TRGT)objcopy
AS   = $(TRGT)gcc -x assembler-with-cpp
BIN  = $(CP) -O binary

# List all default C defines here, like -D_DEBUG=1
DDEFS =

# List all default ASM defines here, like -D_DEBUG=1
DADEFS =

# List all default directories to look for include files here
DINCDIR = 

# List the default directory to look for the libraries here
DLIBDIR =

# List all default libraries here
DLIBS = 

#
# End of default section
##############################################################################################

##############################################################################################
# Start of user section
#

# Define project name here
PROJECT = hello
PROJ_DIR = .

# Define linker script file here
LDSCRIPT = "m5282evb-ram.ld"

# List all user C define here, like -D_DEBUG=1
UDEFS = 

# Define ASM defines here
UADEFS = 

# List C source files here
SRC =	$(PROJ_DIR)/src/cf-crt1.c $(PROJ_DIR)/src/cf-isrs.c $(PROJ_DIR)/src/hello.c

# List ASM source files here
ASRC =	$(PROJ_DIR)/src/cf-crt0.S $(PROJ_DIR)/src/cf-isv.S

# List all user directories here
UINCDIR =	$(PROJ_DIR)/. \
			$(PROJ_DIR)/src \
			$(PROJ_DIR)/inc \

# List the user directory to look for the libraries here
ULIBDIR =

# List all user libraries here
ULIBS = 
#ULIBS = -lm

# Define optimisation level here
OPT = -O0

#
# End of user defines
##############################################################################################

INCDIR  = $(patsubst %,-I%,$(DINCDIR) $(UINCDIR))
LIBDIR  = $(patsubst %,-L%,$(DLIBDIR) $(ULIBDIR))
DEFS    = $(DDEFS) $(UDEFS)
ADEFS   = $(DADEFS) $(UADEFS)
OBJS    = $(ASRC:.S=.o) $(SRC:.c=.o)
LIBS    = $(DLIBS) $(ULIBS)

#INCDIR += -I"/tools/m68k-elf/lib/gcc/m68k-elf/4.1.1/include" \
#		  -I"/tools/m68k-elf/m68k-elf/include"
		  
MCFLAGS = -m528x

ASFLAGS = $(MCFLAGS) -g -Wa,--register-prefix-optional,-amhls=$(@:.o=.lst) $(ADEFS)
CPFLAGS = $(MCFLAGS) $(OPT) -g -fomit-frame-pointer 	\
			-fno-builtin -ffreestanding 				\
			-Wall -Wstrict-prototypes -fverbose-asm		\
			-Wa,-ahlms=$(@:.o=.lst) $(DEFS)
LDFLAGS = $(MCFLAGS) -T$(LDSCRIPT) \
			-fno-builtin -ffreestanding -nostdinc		\
			-Wl,-Map=$(PROJECT).map,--cref,--no-warn-mismatch $(LIBDIR)

# Generate dependency information
CPFLAGS += -MD -MP -MF .dep/$(@F).d

#
# makefile rules
#
.SECONDEXPANSION:

all: $(OBJS) $(PROJECT).elf $(PROJECT).bin

%o : %c
	$(CC) -c $(CPFLAGS) -I . $(INCDIR) $< -o $@

%o : %S
	$(AS) -c $(ASFLAGS) $< -o $@

%elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $@

%bin: %elf
	$(BIN) $< $@

version:
	echo $(CPFLAGS)

clean:
	-rm -f *.lst
	-rm -f $(OBJS)
	-rm -f $(PROJECT).elf
	-rm -f $(PROJECT).map
	-rm -f $(PROJECT).bin
	-rm -f $(SRC:.c=.c.bak)
	-rm -f $(SRC:.c=.lst)
	-rm -f $(ASRC:.S=.S.bak)
	-rm -f $(ASRC:.S=.lst)
	-rm .dep/*.d

# 
# Include the dependency files, should be the last of the makefile
#
-include $(shell mkdir .dep 2> nul) $(wildcard .dep/*)


# *** EOF ***