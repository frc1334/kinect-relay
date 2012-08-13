CXXFLAGS     = -O2 -g -Wall -fmessage-length=0 -D SERVER

OBJS         = src/Server/kinect-relay.o src/Server/KinectServer.o src/Server/KinectServerConnection.o src/Server/KinectFrameManager.o src/Shared/Mutex.o

LIBS         = -lboost_system -lboost_filesystem -lpthread -lboost_program_options -lboost_thread -lfreenect -lboost_iostreams -lboost_serialization

TARGET       = kinectd

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all: $(OBJS) $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)