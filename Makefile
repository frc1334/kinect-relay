CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		kinect-relay.o KinectServer.o KinectServerConnection.o KinectFrameManager.o Mutex.o MagicBox/KinectDataGenerator.o

LIBS =      -lboost_system -lboost_filesystem -lpthread -lconfig++

TARGET =	kinect-relay

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
