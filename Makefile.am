AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

AM_LDFLAGS = -lboost_system$(BOOST_LIB_SUFFIX) -lboost_filesystem$(BOOST_LIB_SUFFIX) -lboost_program_options$(BOOST_LIB_SUFFIX) -lboost_thread$(BOOST_LIB_SUFFIX) -lboost_iostreams$(BOOST_LIB_SUFFIX) -lboost_serialization$(BOOST_LIB_SUFFIX) -lpthread

bin_PROGRAMS = kinectd
kinectd_SOURCES = src/Shared/Mutex.h src/Shared/Mutex.cpp src/Server/KinectFrameManager.h src/Server/KinectFrameManager.cpp src/Server/KinectServerConnection.h src/Server/KinectServerConnection.cpp src/Server/KinectServer.h src/Server/KinectServer.cpp src/Server/kinect-relay.cpp
kinectd_LDADD = $(libfreenect_LIBS) $(opencv_LIBS)

dist_noinst_SCRIPTS = autogen.sh
