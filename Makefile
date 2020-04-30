TARGET = MazeRacing
default: $(TARGET)

BUILD_DIR = bin
SFML_DIR = /usr/include/SFML

#See if a wildcard or something can be made for this (idk)
SOURCES = main.cpp \
src/ArrowSign.cpp \
src/Camera.cpp \
src/CollisionData.cpp \
src/Entity.cpp \
src/Game.cpp \
src/Hole.cpp \
src/Level.cpp \
src/LevelData.cpp \
src/LevelShip.cpp \
src/Overworld.cpp \
src/OverworldData.cpp \
src/OverworldShip.cpp \
src/ResourceManager.cpp \
src/SaveFile.cpp \
src/SavePoint.cpp \
src/Screen.cpp \
src/Tutorial.cpp \
src/TutorialHole.cpp

INCLUDES = -Iinclude \
-I$(SFML_DIR)/include


CC = g++
OPT = -O1	#Basic/no optimization for right now
CFLAGS = $(INCLUDES) $(OPT) -Wall
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


DEBUG = 1
ifeq ($(DEBUG), 1)
	CFLAGS += -g -gdwarf-2	#May need to edit
endif


#Cargo cult for right now, actually learn what this does
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(SOURCES)))

$(BUILD_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@


clean:
	-rm -f $(BUILD_DIR)/*
	-rm $(TARGET)

