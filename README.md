# LowLevelGame

## ℹ️ About

An opportunity to do more with C++ by creating a game with SDL2. I just love coding at a low level XD 

(I have not yet experienced the p̷̜͈̞̻̪͑̀̓͋͝ã̸͓̯̗̲̮͒i̸̥̣̮̠̔̓̀̓͗ṅ̷͙̗̮̹ of writing a physics engine from scratch)

## 💻 Dev Environment

> **Note**
> 
> Make sure to first setup the project with the `make setup` command.

### 🍎 MacOS (Universal)

- `brew install sdl2 sdl2_image` — Install libraries with Homebrew.

That's it! The [`Makefile`](./Makefile) is intended for M1 and Intel users by using both the `/opt/homebrew` and `/usr/local` Homebrew paths, so this should work automagically.

### 🪟 Windows

Coming Soon™️

### 🐧 Linux

> **Note**
> 
> Don't forget to install build-essential and clang if you for some reason don't have `make` or `clang++` yet:
> 
> `sudo apt install build-essential clang`

#### `apt` Users (e.g. Ubuntu & Debian)

```bash
# Make sure to `sudo apt update` first! Then install SDL2 dependencies:
sudo apt install libsdl2-dev libsdl2-image-dev
```

#### `yum` Users (e.g. Fedora & CentOS)

```bash
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
