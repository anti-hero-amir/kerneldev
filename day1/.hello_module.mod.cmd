savedcmd_/home/amir/kerneldev/day1/hello_module.mod := printf '%s\n'   hello_module.o | awk '!x[$$0]++ { print("/home/amir/kerneldev/day1/"$$0) }' > /home/amir/kerneldev/day1/hello_module.mod
