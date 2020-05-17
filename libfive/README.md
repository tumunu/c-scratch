
```bash
$ git clone https://github.com/libfive/libfive

$ cd libfive
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cp libfive/src/libfive.so /usr/local/lib
$ cd ..
$ cp libfive/include/ /usr/local/include
```

Required packages
```bash
$ sudo apt-get install freeglut3-dev
$ sudo apt-get install libglew-dev
```

Flags required in the Makefile
```bash
$ pkg-config --libs --static glew
-lGLEW -lGLU -lm -lGL
```

Lightweight 3D viewer for Libfive written in C (Pentane)
```bash
$ git clone https://gitlab.com/kavalogic-inc/C5H12.git

$ cd C5H12
$ autoreconf --install
$ mkdir build
$ cd build
$ ../configure
$ make
$ sudo make install
```
