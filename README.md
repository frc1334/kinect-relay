kinect-relay
============

Overview
--------

  kinect-relay is a simple program designed to process data from a Kinect and transmit it over TCP.  This is useful for embedded systems that are not capable of interfacing with the kinect on their own.  kinect-relay is designed to offload maximum work to the server, under the assumption most of the time, the server will be more powerful than the client, and will likely be entirely dedicated to running the server.


Dependencies
------------

The following dependencies are _required_:

+  [boost][1] ([asio][2], [serialization][3], [program_options][4])
+  [openkinect][5]
+  [opencv][6]

Cross-Compiling for Beagleboards Running the Angstrom Distribution
------------------------------------------------------------------

First, ensure the Angstrom toolchain is installed on the build machine.  Toolchains can be downloaded [here][7]

Then run:

        $ . /usr/local/angstrom/arm/environment-setup
        $ export CROSS_OUTPUT="path to output directory"
        $ opkg-target update
        $ opkg-target install libfreenect libfreenect-dev boost boost-serialization boost-program-options opencv-dev
        $ ./configure --host=arm-angstrom-linux-gnueabi --prefix=$CROSS_OUTPUT
        $ make
        $ make install

### Notice

  At the time of writing, Angstrom's libfreenect is out of date and __will not work__.  You will need to custom cross-compile libfreenect for Angstrom.  A guide to compiling libfreenect for Linux is [here][8].  In order to cross compile, create a file called `angstrom_toolchain.cmake` with contents as follows.

        SET(CMAKE_SYSTEM_NAME Linux)
        include(CMakeForceCompiler)
        CMAKE_FORCE_C_COMPILER(arm-angstrom-linux-gnueabi-gcc GNU)

When compiling, change

        $ cmake ..
        $ make
        $ sudo make install

To

        $ cmake -DCMAKE_TOOLCHAIN_FILE=../angstrom_toolchain.cmake -DCMAKE_INSTALL_PREFIX=$CROSS_OUTPUT
        $ make
        $ sudo make install

Ensure that libfreenect is cross-compiled _after_ all `opkg` commands are finished in the above instructions

### Testing

  This program includes a small test suite.  It is recommended that it is compiled and run on the host system.  It can be used as follows:

        $ ./configure
        $ make check

  The test suite will prompt for the target address and port.

Implementation Guide
--------------------

  All the implementation is stored in `src/MagicBox/KinectDataGenerator.h`.  This is still unfinished.....


[1]: http://www.boost.org/                                                  "Boost Website"
[2]: http://www.boost.org/doc/libs/1_51_0/doc/html/boost_asio.html          "Boost Asio Documentation"
[3]: http://www.boost.org/doc/libs/1_51_0/libs/serialization/doc/index.html "Boost Serialization Documentation"
[4]: http://www.boost.org/doc/libs/1_51_0/doc/html/program_options.html     "Boost Program Options Documentation"
[5]: http://openkinect.org/wiki/Main_Page                                   "OpenKinect Wiki"
[6]: http://opencv.willowgarage.com/wiki/                                   "OpenCV Wiki"
[7]: http://www.angstrom-distribution.org/toolchains/                       "Angstrom Toolchain Listing"
[8]: http://openkinect.org/wiki/Getting_Started#Manual_Build_on_Linux       "Building libfreenect for Linux"