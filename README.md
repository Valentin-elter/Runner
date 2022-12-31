# Runner

First year project student. A runner game taking a txt file to generate a level. Made with C-SFML lib. (yes you can finish my level !)

## Build with linux (ubuntu)

Realised with SFML 2.5

### 1. Install the dependencies:

	sudo apt-get install build-essential libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libglew-dev libjpeg8-dev libsndfile1-dev libopenal-dev
	sudo apt-get install libsfml-dev

### 2. Download the CSFML source code and extract it:
	https://www.sfml-dev.org/download/csfml/

### 3. Build and install CSFML:

	mkdir build
	cd build
	cmake ..
	make
	sudo make install

### 4. Build my_runner from my repo:
	make
	./my_runner map.txt


## Screenshots

![Alt text](screenshots/1.png?raw=true "1")
![Alt text](screenshots/2.png?raw=true "2")
![Alt text](screenshots/3.png?raw=true "3")