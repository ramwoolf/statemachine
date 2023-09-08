#!/usr/bin/bash

BUILD_SH=local_build.sh
OPTIONS="debug tests"
if [[ -f $BUILD_SH && -x $BUILD_SH ]]
then ./$BUILD_SH OPTIONS
else echo WARNING: \$BUILD_SH is not found\!Tests building and running did not occure\!
fi