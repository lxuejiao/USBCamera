# USBCamera
Use opencv to read the usb Camera data for Linux.

# requirement
opencv 3.4.3
GNU 5.4.0
cmake 3.12.0

# Run
```shell 
mkdir build && cd build
cmake ..
make -j7

mkdir pictures
./run_me pictures/
```

# Notice
capture.open("/dev/video1") need to use your own camera device path.

# see usb 
`lsusb`

# See usb camera device
```shell
cd /dev
ls | grep video

#see video0 detail info
udevadm info --query=all --name=/dev/video0
```

