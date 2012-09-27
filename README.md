kinect-relay
============

Overview
--------

kinect-relay is a simple program designed to process data from a Kinect and tra-
nsmit it over TCP


Dependencies
------------

+  boost (asio, serialization, program_options)
+  libfreenect

Cross-Compiling for Beagleboards Running the Angstrom Distrobution
------------------------------------------------------------------

First, ensure the Angstrom toolchain is installed on the build machine.  Tolcha-
ains can be found here :

http://www.angstrom-distribution.org/toolchains/

Then run:

  $ ./usr/local/angstrom/arm/environment-setup
  $ opkg-target update
  $ opkg-target install libfreenect boost boost-serialization \
    boost-program-options
  $ ./configure --host=arm-angstrom-linux-gnueabi --prefix=~/beagleboard_files
  $ make
  $ make install