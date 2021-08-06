# yaOS (yet another OS)
This branch is the developpement one.

This OS is a microkernel base one, and aim to be a simple and lightweight one. However it's good to notice that it is made by two students who want to improve their knowledges in computer science, and in this case, in a more "hardware view" of it. Thus, the code should be sometimes a little weird, and should be far to be perfect !

But we try to do the best that we can :-)

It aims to be usable under x86, x64 and aarch64 computers, and is more design for embeded systems. At least, I don't think that we can make a lot of driver, but I hope that we can add basic network and graphical (at least with vga) support. So at least, it should support, for either x86, x64 and aarch64 computers :
- multi user
- multi task
- multi threading
- parrallel processing
- file systems
- network
- (c compiler. Maybe, it seems hard to port gcc on a newly created OS)
- python
- vga graphics
- full mmu support
- syscalls

For now, it is just an x86 system with segmentation, mono user and syscall support.
If you see some ways to improve it, or if you want to contribute, please send us an email at "newos2345@gmail.com".

# USAGE

## Under LINUX:

To make the source and test the os:
```sh
$ git clone https://github.com/Dalejosne/OS/tree/master
$ cd OS/all
$ make
$ qemu testOs.flp
```
To make the doc :
<<<<<<< HEAD
```sh
$ cd OS/doc
$ make html
$ cd build/html
$ firefox index.html
```
## OVER
If someone know how to do it under macos or windows, if he(she) could tell us how to do it would be nice.

