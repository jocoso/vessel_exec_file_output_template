############################################################
# Where to find important files
############################################################
LDLIB            =-Llib -lsfml-graphics -lsfml-window -lsfml-system
I_DIR            =include
O_DIR            =obj
SRC_DIR          =src
SCN_DIR          =src/scenes
PCS_DIR          =src/pieces
# $(patsubst pattern, replacement, text)
# Finds whitespace-separated words in text that match pattern
# and replaces them with replacement.
# % acts as a wildcard matching any number of any characters withing
# a word.
_DEPS 			 =main.cpp scene.cpp component.cpp button.cpp\
					utils.cpp input_text.cpp
DEPS             =$(patsubst %,$(SRC_DIR)/%,$(_DEPS))
_OBJS            =main.o scene.o input_text.o button.o
OBJS             =$(patsubst %,$(O_DIR)/%, $(_OBJS))
_SCNS            =charsel_scn.cpp
SCNS             =$(patsubst %,$(SCN_DIR)/%, $(_SCNS))
_PECS            =topmenu_charsel.cpp
PECS             =$(patsubst %,$(PCS_DIR)/%, $(_PECS))
EXEC             =main

############################################################
# Compiler specification
############################################################
CXX              =g++

# Flags

ABS_PATH         =-I
DEBUG_LEVEL      =-g
EXTRA_CCFLAGS    =-Wall -std=c++11
CXXFLAGS         =$(DEBUG_LEVEL) $(EXTRA_CCFLAGS)

# What flags should be passed to the pre-processor.
#	Include directories
DIRFLAGS         =-I$(I_DIR)

############################################################
# Rules
############################################################
# Default Rule
# all: $(OBJS) $(EXEC)

main: $(OBJS) $(SCNS) $(PECS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(DIRFLAGS) $(LDLIB)

# Makes objects files in obj directory
$(O_DIR)/%.o: $(SRC_DIR)/%.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(DIRFLAGS)

$(O_DIR)/%.o: $(SNC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(DIRFLAGS)

$(O_DIR)/%.o: $(PCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(DIRFLAGS)

# Creates the executable
#$(EXEC): $(OBJS)
#	$(CXX) -o $@ $^ $(DIRFLAGS) $(LDLIB)

# Prevents misunderstandings between make and the program
.PHONY: clean

# Clean up after we are done
clean:
	rm -f $(O_DIR)/*.o *.exe