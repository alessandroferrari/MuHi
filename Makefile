BIN=./bin/
SOURCE=./source/
INC=./include/

OPENCV_LIB = $$(pkg-config --libs opencv)
OPENCV_INC = $$(pkg-config --cflags opencv)

TARGET=$(BIN)eyeTracking
SRC=$(SOURCE)eyeTracking.cpp $(SOURCE)findEyeCenter.cpp $(SOURCE)helpers.cpp $(SOURCE)jsoncpp.cpp $(SOURCE)settings.cpp $(SOURCE)Target.cpp
OBJ=SRC = $(BIN)eyeTracking.o $(BIN)findEyeCenter.o $(BIN)helpers.o $(BIN)json.o

all : $(TARGET)

$(TARGET) : $(OBJ)
	g++ $(OBJ) -o $(TARGET)  $(OPENCV_LIB)

$(OBJ) : $(SRC)
	g++ -I$(INC) $(OPENCV_CFLAGS) -std=c++11 $(SRC) $(OPENCV_CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(TARGET)
