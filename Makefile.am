AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

BUILT_SOURCES = src/MagicBox/KinectDataGenerator.h

noinst_PROGRAMS = testclient
testclient_SOURCES = src/Client/Kinect.h src/Client/Kinect.cpp src/Client/KinectTestProgram.cpp
testclient_LDADD = -lboost_system$(BOOST_LIB_SUFFIX) -lboost_thread$(BOOST_LIB_SUFFIX) -lboost_iostreams$(BOOST_LIB_SUFFIX) -lboost_serialization$(BOOST_LIB_SUFFIX) -lpthread

TESTS = testclient

bin_PROGRAMS = kinectd
kinectd_SOURCES = src/Server/KinectFrameManager.h src/Server/KinectFrameManager.cpp src/Server/KinectServerConnection.h src/Server/KinectServerConnection.cpp src/Server/KinectServer.h src/Server/KinectServer.cpp src/Server/kinect-relay.cpp
kinectd_LDADD = $(libfreenect_LIBS) $(opencv_LIBS) -lboost_system$(BOOST_LIB_SUFFIX) -lboost_filesystem$(BOOST_LIB_SUFFIX) -lboost_program_options$(BOOST_LIB_SUFFIX) -lboost_thread$(BOOST_LIB_SUFFIX) -lboost_iostreams$(BOOST_LIB_SUFFIX) -lboost_serialization$(BOOST_LIB_SUFFIX) -lboost_date_time$(BOOST_LIB_SUFFIX) -lpthread
kinectd_CXXFLAGS = -DSERVER -Wextra -Weffc++

dist_noinst_SCRIPTS = autogen.sh

src/MagicBox/KinectDataGenerator.h: src/MagicBox
	rm -f src/MagicBox/KinectDataGenerator.h
	ln @link_header@ src/MagicBox/KinectDataGenerator.h

src/MagicBox:
	mkdir src/MagicBox

clean-local:
	rm -rf src/MagicBox
