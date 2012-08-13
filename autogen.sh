#! /bin/bash
cp README.md README
touch NEWS README.md AUTHORS ChangeLog
autoreconf --force --install
