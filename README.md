kinect-relay
============

Overview
--------

kinect-relay is a simple program designed to process data from a Kinect and transmit it over TCP.  This is useful for embedded systems that are not capable of interfacing with the kinect on their own.


Dependencies
------------

+  boost (asio, serialization, program_options)
+  libfreenect

Cross-Compiling for Beagleboards Running the Angstrom Distribution
------------------------------------------------------------------

First, ensure the Angstrom toolchain is installed on the build machine.  Toolchains can be found here :

http://www.angstrom-distribution.org/toolchains/

Then run:

        $ . /usr/local/angstrom/arm/environment-setup
        $ opkg-target update
        $ opkg-target install libfreenect libfreenect-dev boost boost-serialization boost-program-options
        $ ./configure --host=arm-angstrom-linux-gnueabi --prefix=~/beagleboard_files
        $ make
        $ make install