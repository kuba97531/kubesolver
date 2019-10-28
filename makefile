###############################################################################
#   USAGE:                                                                    #
#       make               : debug build                                      #
#       make BUILD=RELEASE : slow release build (produces rsolver.exe)        #
#       make build_all     : builds all versions for release purposes         #
#       make clean         : removes object and default exe files             #
#       make NAME=piosolver: debug build producing piosolver.exe              #
#                                                                             #
#   REMARKS:                                                                  #
#       -When NAME is left as default make produces:                          #
#           solver.exe for debug build                                        #
#           rsolver.exe for release build                                     #
#       -When NAME is defined no prefix is added                              #
#       -To use multiple cores add MAKEFLAGS = j (number of cores + 1)        #
#        to enviromental variables                                            #
###############################################################################

BUILD   ?= DEBUG
NAME    ?= makesolver
CC       = gcc
OBJDIR   = obj
SRCDIR   = src/c

###############################################################################
#   GCC FLAGS                                                                 #
###############################################################################

COMMON_GCC_FLAGS=\
 -std=c99 \
 -fopenmp

MAIN_ARCH=\
 #-march=ivybridge

DEBUG_FLAGS=\
 -Og\
 -pedantic \
 -Wextra \
 -Wall \
 -Wredundant-decls \
 -Wunreachable-code \
 -Wstrict-prototypes \
 -Wshadow \
 -Wpointer-arith \
 -Wold-style-definition \
 -Wno-missing-braces \
 -Wno-missing-field-initializers

 RELEASE_FLAGS=\
 -Ofast \
 -funroll-loops \
 -fopenmp \
 -fno-asynchronous-unwind-tables \
 -fno-unwind-tables \
 -fschedule-insns \
 -fsched-pressure \
 -DNDEBUG

LINKER=\
 -static \
 -fopenmp 

###############################################################################
#   CLANG DEBUG FLAGS                                                         #
###############################################################################

###############################################################################
#   FILES                                                                     #
###############################################################################

SRC_FILES = \
 cube3.c\
 cube3r.c\
 cube_compression.c

SRC_ALWAYS_REBUILD_FILES = \
 solver.c

#LIB_FILES = \
# lib/win/TurboActivate.lib \
# lib/win/DbgHelp.Lib

###############################################################################
#   BUILD                                                                     #
###############################################################################

ifeq ($(BUILD),DEBUG)
	BUILD_POSTFIX = _d
	CC_OPTIONS   = $(COMMON_GCC_FLAGS) $(DEBUG_FLAGS) $(MAIN_ARCH)
else ifeq ($(BUILD),RELEASE)
	EXE_PREFIX   = r
	BUILD_POSTFIX = _r
	CC_OPTIONS   = $(COMMON_GCC_FLAGS) $(RELEASE_FLAGS) $(MAIN_ARCH)
	STRIP        = strip -s $(EXE_NAME)
else
	$(error BUILD variable is incorrect: $(BUILD))
endif

ALL_SRC_FILES = $(addprefix $(SRCDIR)/,$(SRC_FILES)) $(addprefix $(SRCDIR)/,$(SRC_ALWAYS_REBUILD_FILES))
OBJ_FILES  = $(SRC_FILES:%.c=$(OBJDIR)/%$(BUILD_POSTFIX).o)
DEP = $(OBJ_FILES:%.o=%.d)
OBJ_REBUILD_FILES = $(SRC_ALWAYS_REBUILD_FILES:%.c=$(OBJDIR)/%$(BUILD_POSTFIX).o)
ALL_OBJ_FILES = $(OBJ_FILES) $(OBJ_REBUILD_FILES)


ifeq ($(NAME),solver)
	EXE_NAME    = $(EXE_PREFIX)$(NAME).out
else
	EXE_NAME    = $(NAME).out
endif

.DEFAULT_GOAL := $(EXE_NAME)

$(EXE_NAME): $(OBJ_FILES) $(OBJ_REBUILD_FILES) $(REFRESH_EXE)
	@echo linking...
	@$(CC) $(LINKER) $(ALL_OBJ_FILES) $(LIB_FILES) -o$@
	@$(STRIP)
	@echo OK!

$(OBJ_FILES): $(OBJDIR)/%$(BUILD_POSTFIX).o: $(SRCDIR)/%.c
	#@$(CREATE_OBJ_DIR)
	@$(CC) $(CC_OPTIONS) -MMD -c $< -o $@
	@$(CC) -c $(CC_OPTIONS) $< -o$@
	@echo $(<:$(SRCDIR)/%=%)
	
-include $(DEP)
	
$(OBJ_REBUILD_FILES): $(OBJDIR)/%$(BUILD_POSTFIX).o: $(SRCDIR)/%.c
	@$(CREATE_OBJ_DIR)
	@$(CC) -c $(CC_OPTIONS) $< -o$@
	@echo $(<:$(SRCDIR)/%=%)
