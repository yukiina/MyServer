#!/bin/bash
-rm testServ
cd ./build
cmake ..
make
mv testServ ../
