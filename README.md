Welcome to my 64 bit kernel

I'll be trying my best to document this.

To build this:

1. Install docker.
2. Run command "docker build buildenv -t myos-buildenv".
3. Run the container by doing "docker run --rm -it -v %cd%:/root/env/ myos-buildenv" on Windows Command prompt, "docker run --rm -it -v $PWD/root/env/ myos-buildenv" on Windows PowerShell.
4. Run command in the container "make build-x86_64".
5. You will get an iso in the dist/x86_64 folder. Use a VM like QEMU or VirtualBox to test it.

If you have any suggestions, please be sure to tell me about them.