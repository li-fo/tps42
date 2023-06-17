# TPS42

![https://raw.githubusercontent.com/crehmann/TPS42/main/Assets/wired_top.jpg]()

TPS42 is a 42/36 keys ergonomic split keyboard. 

* Keyboard Maintainer: [crehmann](https://github.com/crehmann)  
* Hardware Supported: Pro Micro 5V/16MHz and compatible.
* Hardware Availability: https://github.com/crehmann/TPS42

## Some Features:

- Integrated TrackPoint reset circuit and with a positions to mount a TrackPoint to the bottom of the PCB. 
- Hot Swapping support (except for two switches around the TrackPoint position)
- I2C interface for an OLED display
- Wireless Ready (however, without TrackPoint / linear actuator support):
  - Battery switch / connector
  - Option to use a battery friendly Sharp memory display instead of an OLED display
- Choc-spaced

## Building the Firmware

Make example for this keyboard (after setting up your build environment):

    make tps42/rev1:crehmann

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

A build guide for the Buzzard keyboard can be found at [https://github.com/crehmann/Buzzard](https://github.com/crehmann/TPS42)