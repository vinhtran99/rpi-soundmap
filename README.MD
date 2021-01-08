# Live Sound Visualisation Project


This is the project for the course "Application Development" at VAMK 2018. The program records sound via microphone and displays the sound levels inside the terminal and updates regurlaly, creating a live visualization. It also has an option to view the visualiztion in a browser by sending over the data to our school web server for rendering.


## 0. Device Configuration 

By default the Pi does not have a Line In port, so we opt to use an USB sound card. The configuration of the device is as follows:

1. Check for connection of the sound card and thew microphone jack.
2. In terminal, run command `lsusb` and look if your sound card is listed 
3. Open the file `/etc/asound.conf` with elevated permission and add the following lines at the end of the file
	```
	pcm.!default {
		type plug
		slave {
			pcm "hw:1,0"
		}
	}
	ctl.!default {
		type hw
		card 1
	}
	```
4. Run `alsamixer` and you should be albe to see that the USB sound card is the default audio device.

**Note :** The newest version of Raspbian (a.k.a. Jessie) comes with a new version of alsa-utils (1.0.28), which has a bug while recording: it doesn’t stop even a ‘—duration' switch is given, and generates lots of useless audio files. To fix this problem, we have to downgrade alsa-util to an earlier version (1.0.25) :

  1. Run `sudo nano /etc/apt/sources.list` command and add these lines to last of the file:
```
deb http://mirrordirector.raspbian.org/raspbian/ jessie main contrib non-free rpi
deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi
```
  2. Run `sudo apt-get update`.
  3. Run `sudo aptitude versions alsa-utils` to check if version 1.0.25 of alsa-util is available:
```
pi@raspberrypi:~ $ sudo aptitude versions alsa-utils
Package alsa-utils:
i   1.0.25-4                                                     oldstable                                 500
p   1.0.28-1                                                     stable                                    500
```
  4. Run `sudo apt-get install alsa-utils=1.0.25-4` to downgrade.
  5. Reboot (if necessary).
  6. Run `arecord -r44100 -c1 -f S16_LE -d5 test.wav` to test that your microphone is working. You should see a _“test.wav”_ file in the current folder.
  7. Put your earphone on. Run “aplay test.wav” to check that your recording is okay.
## 1. Install

The program required _libcurl_ to connect to the server. Run
	1. `sudo apt update`
	2. `sudo apt install libcurl3`
	3. `sudo apt install libcurl4-openssl-dev`

Clone the project and run `make` to build the program. After the build is completed and successful, run `./sound.a` to run the program.

**Note** If you want to see the rendering in browser, edit line `#define URL `  in the file `comm.h` to your own web server. The program requires PHP to run. Copy the file `sound.php` to your destination server.

## 2. Acknowledgement

This project is finished under the provision of Dr. Gao Chao, the teacher of course. We would like to thank him for this project.

## 3. License

GNU General Public Licesing ver. 3.0

## 4. Contact

Vinh Tran <e1700689@edu.vamk.fi>

