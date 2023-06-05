CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS =

TARGET = bin/myprogram
SRCDIR = src
OBJDIR = obj

SOURCES := $(wildcard $(SRCDIR)/**/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
VPATH := $(sort $(dir $(SOURCES)))

all: directories $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	if not exist $(OBJDIR) mkdir $(OBJDIR)
	for %%i in ($(OBJECTS)) do if not exist %%~dpi mkdir %%~dpi

clean:
	rm -rf $(OBJDIR) $(TARGET)
