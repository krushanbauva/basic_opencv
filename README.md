# basic_opencv
This repository acts as a practice ground for OpenCV library.
## Recquirements
These programs depend on OpenCV library.
## How to compile?
In order to compile any program, you need to type 'make' followed by the file-name without the extension. For example,
```bash
$ make edge_detection
```
Or else you can also do
```bash
$ g++ edge_detection.cpp -o edge_detection `pkg-config opencv --cflags --libs`
```
## Run
The compilation process will create a binary file which can be executed by ```./file-name``` For example,
```bash
$ ./edge_detection
```
## Contributing
Any contributions are more than welcome. Just **fork** the repo and start contributing.
