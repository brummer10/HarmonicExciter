# HarmonicExciter.lv2
The HarmonicExciter is based on a half wave clipper, allow to add harmonics to the source by mix them in. 

![HarmonicExciter](https://github.com/brummer10/HarmonicExciter/blob/main/HarmonicExciter.png?raw=true)


## Dependencys

- libcairo2-dev
- libx11-dev

## Build

- git submodule init
- git submodule update
- make
- make install # will install into ~/.lv2 ... AND/OR....
- sudo make install # will install into /usr/lib/lv2
