CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -D SERVER

OBJS =		kinect-relay.o KinectServer.o KinectServerConnection.o KinectFrameManager.o Mutex.o MagicBox/KinectDataGenerator.o

LIBS =      -lboost_system -lboost_filesystem -lpthread -lboost_program_options -lboost_thread -lfreenect -I/usr/include/libfreenect -I/usr/include/libusb-1.0

TARGET =	kinect-relay

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all: $(OBJS) $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
