#!/bin/bash

uNames=`uname -s`
osName=${uNames: 0: 4}
if [ "$osName" == "Darw" ] # Darwin
then
	echo "Mac OS X"
		echo "run ../bin/VideoManPlat"
  	../bin/VideoManPlat
elif [ "$osName" == "Linu" ] # Linux
then
	echo "GNU/Linux"
	echo "run ../bin/VideoManPlat"
	../bin/VideoManPlat
elif [ "$osName" == "MING" ] # MINGW, windows, git-bash
then
	echo "Windows, git-bash"
else
	echo "unknown os"
fi
