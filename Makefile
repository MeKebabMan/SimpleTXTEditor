Project_name=SimpleTXTEditor
Project_version=1.0.0
Project_toml_file=./src/toml_h/toml.c
Project_gtk_cflags=$(shell pkg-config --cflags --libs gtk4)
Project_cflags=-O3 -Oz -std=c2x -m64
Project_compiler=gcc 


All: Run Compile 

Run: Compile 
	@test -f ./build/$(Project_name)_$(Project_version) && ./build/$(Project_name)_$(Project_version)

Compile:
	@mkdir -p ./build/
	@test -f ./src/*.c && test -f ./src/_headers_/*.c && test -f $(Project_toml_file) && \
	 $(Project_compiler) ./src/*.c ./src/_headers_/*.c $(Project_toml_file) -o \
	  ./build/$(Project_name)_$(Project_version) $(Project_gtk_cflags) $(Project_cflags)


Install: Compile 
	@test -d /usr/bin/ && test -f ./build/$(Project_name)_$(Project_version) && \
	 echo "Sudo permission required.. (moving $(Project_name)_$(Project_version) to /usr/bin/)" && \
	  sudo cp ./build/$(Project_name)_$(Project_version) /usr/bin/ && \
	   echo "Successfully moved $(Project_name)_$(Project_version) to /usr/bin/" && \
	    echo "FILE_PATH: /usr/bin/$(Project_name)_$(Project_version)" && \
	    echo "Launch the application with ($(Project_name)_$(Project_version))"
	@test -d ~/.config/ && mkdir -p ~/.config/SimpleTXTEditor/ && \
	 touch ~/.config/SimpleTXTEditor/SimpleTXTEditor.toml && \
	  echo "[CSS]" >> ~/.config/SimpleTXTEditor/SimpleTXTEditor.toml && \
	   echo 'PATH="./config/CSS/SimpleTXTEditor.css"' >> ~/.config/SimpleTXTEditor/SimpleTXTEditor.toml && \
	    mkdir -p ~/.config/SimpleTXTEditor/CSS/ && test -f ./CSS/SimpleTXTEditor.css && \
	     cp ./CSS/SimpleTXTEditor.css ~/.config/SimpleTXTEditor/CSS/ && \
	      echo 'INSTALL="$(HOME)/.config/SimpleTXTEditor/CSS/SimpleTXTEditor.css"' >> ~/.config/SimpleTXTEditor/SimpleTXTEditor.toml

	    


Remove:
	@test -f /usr/bin/$(Project_name)_$(Project_version) && \
	 echo "Sudo permission required.. (Removing $(Project_name)_$(Project_version) from /usr/bin/)" && \
	  sudo rm /usr/bin/$(Project_name)_$(Project_version) && \
	   echo "Successfully removed $(Project_name)_$(Project_version) from /usr/bin/!"
	@test -d ~/.config/SimpleTXTEditor/ && rm -rf ~/.config/SimpleTXTEditor/
