#!/bin/bash
mkdir Debug
cd ./Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
mv testServ ../
