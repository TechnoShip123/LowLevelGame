# LowLevelGame

## About

An opportunity to do more with C++ by creating a game with SDL2. I just love coding at a low level XD 

(I have not yet experienced the p̷̜͈̞̻̪͑̀̓͋͝ã̸͓̯̗̲̮͒i̸̥̣̮̠̔̓̀̓͗ṅ̷͙̗̮̹ of writing a physics engine from scratch)

## Dev Environment

> **Note**
> 
> Make sure to first setup the project with the `make setup` command.

### MacOS 

#### M1 / Apple Silicon

- `brew install sdl2 sdl2_image` — Install libraries with brew.
- That's it! The [`Makefile`](./Makefile) is intended for M1 users, so it uses the `/opt/homebrew` path.

#### Intel

Automatic support coming soon™️, will need to change homebrew path to `/usr/include` and etc.

In the meantime, use the same steps as M1 but change the -L and -I paths to `/usr/include`

### Windows

Coming Soon™️

### Linux

#### `apt` Users (e.g. Ubuntu & Debian)

```bash
# Make sure to `sudo apt update` first!
# Install build-essential and clang if you don't already have clang++ and make
sudo apt install build-essential clang
# Install SDL2 dependencies
sudo apt install libsdl2-dev libsdl2-image-dev
```

#### `yum` Users (e.g. Fedora & CentOS)

```bash
# Make sure to install build-essential and clang if you don't already have clang++ and make
yum install SDL2-devel SDL2_image-devel
```

#### Randoms without a package manager

Download the source zip from the latest [SDL release](https://github.com/libsdl-org/SDL/releases) and [SDL_image](https://github.com/libsdl-org/SDL_image/releases) release. 

Then extract and build both folders.

```bash
cd <sdl or sdl_iamge folder>
# Configure the install
./configure
# Compile and install with make
make all
make install
```

## Having Issues?

~~Sounds like a skill issue ;)~~ Have fun debugging!
