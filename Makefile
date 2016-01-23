BIN=./bin/
SOURCE=./source/
INC=./include/

OPENCV_LIB = /usr/local/lib
OPENCV_INC = /usr/local/include

TARGET=$(BIN)eyeTracking
SRC=$(SOURCE)eyeTracking.cpp $(SOURCE)findEyeCenter.cpp $(SOURCE)helpers.cpp $(SOURCE)settings.cpp $(SOURCE)Target.cpp
OBJ=SRC = $(BIN)eyeTracking.o $(BIN)findEyeCenter.o $(BIN)helpers.o

all : $(TARGET)

$(TARGET) : $(SRC)
	g++ -I$(INC) -o $(TARGET) $(SRC) `pkg-config --cflags --libs opencv`

clean:
	rm -f $(TARGET)
