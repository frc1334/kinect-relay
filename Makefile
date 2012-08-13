CXXFLAGS  = -O2 -g -Wall -fmessage-length=0 -D SERVER

OBJS      = kinect-relay.o KinectServer.o KinectServerConnection.o KinectFrameManager.o Mutex.o

LIBS      = -lboost_system -lboost_filesystem -lpthread -lboost_program_options -lboost_thread -lfreenect -lboost_iostreams -lboost_serialization

TARGET    = kinect-relay

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all: $(OBJS) $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
