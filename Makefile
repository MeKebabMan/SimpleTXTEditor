Project_name=SimpleTXTEditor
Project_version=1.0
Project_toml_file=./src/toml_h/toml.c
Project_gtk_cflags=$(shell pkg-config --cflags --libs gtk4)
Project_cflags=-O3 -Oz -std=c2x -m64
Project_GUI_file=./src/_headers_/_GUI_.c
Project_tomlconfig_file=./src/_headers_/_TOMLCONFIG_.c 
Project_GTKFILEDIALOG_file=./src/_headers_/gtk_file_dialog.c 
Project_compiler=gcc 
Project_install_path=/usr/bin/
Project_desktop_install=$(HOME)/.local/share/applications

All: Run Compile 

Run: Compile
	@test -f ./build/$(Project_name)_$(Project_version) && ./build/$(Project_name)_$(Project_version)

Compile:
	@mkdir -p ./build/
	@test -f ./src/main.c && test -f ./src/_headers_/_headers_.c && test -f $(Project_GUI_file) && \
	 test -f $(Project_toml_file) && \
	  $(Project_compiler) ./src/main.c ./src/_headers_/_headers_.c  $(Project_GUI_file) \
	   $(Project_toml_file) $(Project_tomlconfig_file) $(Project_GTKFILEDIALOG_file) -o \
	    ./build/$(Project_name)_$(Project_version) $(Project_gtk_cflags) $(Project_cflags)

Load_Desktop_app:
	@test -f $(Project_desktop_install)/$(Project_name).desktop && rm $(Project_desktop_install)/$(Project_name).desktop || true
	@test -f ./build/$(Project_name).desktop && rm ./build/$(Project_name).desktop || true
	@test -f ./build/$(Project_name).desktop || touch ./build/$(Project_name).desktop
	@echo "[Desktop Entry]" >> ./build/$(Project_name).desktop && \
	 echo "Type=Application" >> ./build/$(Project_name).desktop && \
	  echo "Version=$(Project_version)" >> ./build/$(Project_name).desktop && \
	   echo "Name=$(Project_name)" >> ./build/$(Project_name).desktop && \
	    echo "Comment=A $(Project_name)" >> ./build/$(Project_name).desktop && \
		 echo "Path=$(Project_install_path)" >> ./build/$(Project_name).desktop && \
		  echo "Exec=$(Project_name)_$(Project_version)" >> ./build/$(Project_name).desktop && \
		   echo "Icon=$(Project_name)" >> ./build/$(Project_name).desktop && \
		    echo "Terminal=false" >> ./build/$(Project_name).desktop && \
			 desktop-file-validate ./build/$(Project_name).desktop && \
			  desktop-file-install --dir=$(Project_desktop_install) ./build/$(Project_name).desktop
			 

Reinstall: Remove Install

Install: Compile Load_Desktop_app 
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
	   echo "Successfully removed $(Project_name)_$(Project_version) from /usr/bin/!" || true
	@test -d ~/.config/SimpleTXTEditor/ && rm -rf ~/.config/SimpleTXTEditor/
	@test -f $(Project_desktop_install)/$(Project_name).desktop && rm $(Project_desktop_install)/$(Project_name).desktop
