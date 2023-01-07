############################################################
# Where to find important files
############################################################
LDLIB            =-Llib -lsfml-graphics -lsfml-window -lsfml-system
I_DIR            =include
O_DIR            =obj
SRC_DIR          =src
SCN_DIR          =src/scenes
# $(patsubst pattern, replacement, text)
# Finds whitespace-separated words in text that match pattern
# and replaces them with replacement.
# % acts as a wildcard matching any number of any characters withing
# a word.
_DEPS 			 =main.cpp scene.cpp text.cpp component.cpp button.cpp\
					utils.cpp
DEPS             =$(patsubst %,$(SRC_DIR)/%,$(_DEPS))
_OBJS            =main.o scene.o text.o button.o
OBJS             =$(patsubst %,$(O_DIR)/%, $(_OBJS))
_SCNS            =charsel_scn.cpp
SCNS             =$(patsubst %,$(SCN_DIR)/%, $(_SCNS))
EXEC             =main

############################################################
# Compiler specification
############################################################
CXX              =g++

# Flags

ABS_PATH         =-I
DEBUG_LEVEL      =-g
EXTRA_CCFLAGS    =-Wall
CXXFLAGS         =$(DEBUG_LEVEL) $(EXTRA_CCFLAGS)

# What flags should be passed to the pre-processor.
#	Include directories
DIRFLAGS         =-I$(I_DIR)

############################################################
# Rules
############################################################
# Default Rule
# all: $(OBJS) $(EXEC)

main: $(OBJS) $(SCNS)
	$(CXX) -o $@ $^ $(DIRFLAGS) $(LDLIB)

# Makes objects files in obj directory
$(O_DIR)/%.o: $(SRC_DIR)/%.cpp 
	$(CXX) -c -o $@ $< $(DIRFLAGS)

$(O_DIR)/%.o: $(SNC_DIR)/%.cpp
	$(CXX) -c -o $@ $< $(DIRFLAGS)

# Creates the executable
#$(EXEC): $(OBJS)
#	$(CXX) -o $@ $^ $(DIRFLAGS) $(LDLIB)

# Prevents misunderstandings between make and the program
.PHONY: clean

# Clean up after we are done
clean:
	rm -f $(O_DIR)/*.o *.exe