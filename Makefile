TARGET = MazeRacing
default: $(TARGET)

#See if a wildcard or something can be made for this (idk)
SOURCES = main.cpp \
src/ArrowSign.cpp \
src/Camera.cpp \
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

OPT = -O1	#Basic/no optimization for right now

CC = g++

INCLUDES = -Iinclude \
-I$(SFML_DIR)/include

BUILD_DIR = bin
SFML_DIR = /usr/include/SFML

DEBUG = 0
CFLAGS = $(INCLUDES) $(OPT) -Wall
ifeq ($(DEBUG), 1)
	CFLAGS += -g -gdwarf-2	#May need to edit
endif

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#Cargo cult for right now, actually learn what this does
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(SOURCES)))

$(BUILD_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@


clean:
	-rm -fR $(BUILD_DIR)
	-rm $(TARGET)
	mkdir $(BUILD_DIR)

