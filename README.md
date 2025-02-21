# wxTestPad

A test program written in C++ with wxWidgets x Meson build system

This project should be work on Windows, Linux, and hopefully MacOS

## Building

You need a C++ compiler, Meson and at least version 3 of wxWidgets

You may need to install wxFormBuilder to edit / modify the [GUI](/gui/wxTestPadGUI.fbp)

Be super careful before running it, it always depends on your system!
> Install libraries in Arch Linux
```console
pacman -Syu
pacman -S meson wxgtk3
```
> Install libraries in MSYS2 on Windows (It depends on your environment!)
```console
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-meson mingw-w64-ucrt-x86_64-wxwidgets3.2-msw
```
> Build... (In the same diretory where [meson.build](/meson.build) is located)
```console
meson setup builddir
meson compile -C builddir
```
> Run...
```console
./builddir/wxTestPad
```
