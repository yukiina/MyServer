#!/bin/bash
mkdir Release
cd ./Release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
mv testServ ../
