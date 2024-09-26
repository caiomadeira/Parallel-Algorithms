# Where is your OpenCV locally installed?
OCV_DIR=../../scripts/opencv-2.4.13.6/

PKG_CONFIG=`pkg-config --cflags --libs $(PWD)/$(OCV_DIR)/lib/pkgconfig/opencv.pc`
OCV_FLAGS=-I $(PWD)/$(OCV_DIR)/include/ -L $(PWD)/$(OCV_DIR)/lib/
CFLAGS= -std=c++1y -Wall -O3 

all: sequential

sequential: seq_video.cpp
	g++ $(CFLAGS) $(OCV_FLAGS) seq_video.cpp -o rgb-select.exe $(PKG_CONFIG)

clean:
	rm -f rgb-select.exe