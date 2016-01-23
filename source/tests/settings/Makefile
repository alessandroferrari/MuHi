SOURCE=../../
INC=../../../include/

TARGET=testjson
SRC=$(SOURCE)settings.cpp json_test.cpp

all : $(TARGET)

$(TARGET) : $(SRC)
	g++ $(OBJ) -I$(INC) $(SRC) -o $(TARGET) 

clean:
	rm -f $(TARGET)
