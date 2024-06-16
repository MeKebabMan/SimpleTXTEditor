# SimpleTXTEditor

A simple text editor built with C & GTK4

# Install

### WARNING: LINUX ONLY!

Build tools required:
gcc / ANY C COMPILER
make 
bash / BE ABLE TO RUN BASH SCRIPTS

```bash
git clone https://github.com/MeKebabMan/SimpleTXTEditor && cd SimpleTXTEditor && \
 make Install 
```

### WARNING: WINDOWS ONLY!

Window users will have to compile by them selfs

# INSTALL WITHOUT INSTALL SCRIPT

- 1: First compile everything in the **src** directory (Any compiler)
- 2: Make sure to have GTK4 installed on your system


### GO TO https://www.gtk.org/ FOR MORE INFORMATION!


### FEDORA 40 GTK4 INSTALL EXAMPLE


```bash
sudo dnf install gtk4-devel
```

- 3: After installing GTK4 compile with the following Cflags: <code>`pkg-config --cflags --libs gtk4`, -O3, -Oz</code>

### COMPILE EXAMPLE!

```bash
gcc ./src/main.c ./src/_headers_/_headers_.c ./src/_headers_/_GUI_.c ./src/toml_h/toml.c -o SIMPLE_TXT_EDITOR.o `pkg-config --cflags --libs gtk4` -O3 -Oz
```

- 4: After compiling you need to create the following directories & files


```diff
- CREATE DIR
+ COMMAND EXAMPLE: mkdir -p $HOME/.config/SimpleTXTEditor/
+ PATH: $HOME/.config/SimpleTXTEditor/

- CREATE FILE
+ COMMAND EXAMPLE: touch $HOME/.config/SimpleTXTEditor/SimpleTXTEditor.toml
+ PATH: $HOME/.config/SimpleTXTEditor/SimpleTXTEditor.toml

- CREATE DIR
+ COMMAND EXAMPLE: mkdir -p $HOME/.config/SimpleTXTEditor/CSS/
+ PATH: $HOME/.config/SimpleTXTEditor/CSS/

- CREATE FILE
+ COMMAND EXAMPLE: touch $HOME/.config/SimpleTXTEditor/CSS/SimpleTXTEditor.css
+ PATH: $HOME/.config/SimpleTXTEditor/CSS/SimpleTXTEditor.css
```

- 5: After creating the directories & files, you will need to edit the SimpleTXTEditor.toml file
- 6: Add the following to **$HOME/.config/SimpleTXTEditor/SimpleTXTEditor.toml**


```toml
[CSS]
# PATH IS USED FOR TESTING & DEVELOPMENT ONLY!
PATH="./config/CSS/SimpleTXTEditor.css"
# INSTALL IS THE PATH TO YOUR CSS FILE!
INSTALL="/home/ !!REPLACE_WITH_USERNAME!! /.config/SimpleTXTEditor/CSS/SimpleTXTEditor.css"
```

**KEEP IN NOTE THAT YOU CAN CHANGE THE LOOK OF THE PROGRAM WITH THE CSS FILE!**

- 7: After that you can just launch the compiled application..
- 8: You can create a .desktop file for it aswell!

# Remove

```bash
git clone https://github.com/mekebabman/simpletxteditor && cd simpletxteditor && \
 make remove
```

# Reinstall

```bash
git clone https://github.com/mekebabman/simpletxteditor && cd simpletxteditor && \
 make Reinstall
```

# Customize

### WARNING: UNDER DEVELOPMENT

You can customize the text editor..

- CSS DIR: $HOME/.config/SimpleTXTEditor/CSS/

You can use a toml file to customize the text editor even more!

- TOML FILE: $HOME/.config/SimpleTXTEditor/SimpleTXTEditor.toml 

# NOTE 

This project is stil being worked on!

# TO DO LIST 

- Save file 
- Open file 
- More toml config options

# License

Copyright 2024 TheMuslimPerson

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

