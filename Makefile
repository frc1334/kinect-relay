CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		kinect-relay.o KinectServer.o KinectServerConnection.o

LIBS =      -lboost_system -lboost_filesystem -lpthread

TARGET =	kinect-relay

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
