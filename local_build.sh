#!/usr/bin/bash

ENV_SH=env.sh
if [[ -f $ENV_SH && -x $ENV_SH ]]
then ./$ENV_SH
else echo WARNING: \$ENV_BAT is not found\! Global environment is used.
fi

BUILD_DIR_PREF=local_build
TEST_ENABLE=OFF

if [[ $2 = "test" ]]
then TEST_ENABLE=ON
     if ! [[ -d bin ]]
     then mkdir bin
     fi
     cd bin
     if ! [[ -d tests ]]
     then mkdir tests
     fi
     cd ..
fi

BUILD_TYPE=release
if [[ $1 = "debug" ]]
then BUILD_TYPE=debug
fi

BUILD_DIR="build"

if ! [[ -d $BUILD_DIR ]]
then mkdir $BUILD_DIR
fi
cd $BUILD_DIR
echo Clean solution: $BUILD_DIR
rm -r ./* > /dev/null

cmake ../ -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DTEST_ENABLE=$TEST_ENABLE
make && make install
cd ../