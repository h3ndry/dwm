
# dwm - dynamic window manager


###  Included Patches

##### ShiftView
This patches let you go the next or previous tag using `Mod H` and `Mod L`

##### Hide Vacant Tags
This patches let dwm to not draw tags without clietn int them

##### Hide boreder
This patch hide bordes when viewing a winodw in full screen or when the is only window
on a tag, make the window look nice

##### Fake fullscreen
Added Fake fullscreen patch, This patch add make let window occupy the full widow when
fullscreen instead of a fullscreen

##### Title Color patch
This patch let the window tittleto have a sepeate color configureateion
so that it can be set alne

##### Center Title Patche
This patch let the window name to be display on the
center of the space provied


##### Added Pertag
It allow you to have seperate layou pertag


##### Kill allw unselect windows
It allow you to have `Mod o` seperate layou pertag


##### Grid Layout
It allow you to have `Mod o` seperate layou pertag


##### B Stack Layout
It allow you to have `Mod o` seperate layou pertag



dwm is an extremely fast, small, and dynamic window manager for X.


Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
