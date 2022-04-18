
Debian
====================
This directory contains files used to package bltgd/bltg-qt
for Debian-based Linux systems. If you compile bltgd/bltg-qt yourself, there are some useful files here.

## bltg: URI support ##


bltg-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install bltg-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your bltg-qt binary to `/usr/bin`
and the `../../share/pixmaps/bltg128.png` to `/usr/share/pixmaps`

bltg-qt.protocol (KDE)

