savedcmd_/home/amir/kerneldev/day2/param_module.mod := printf '%s\n'   param_module.o | awk '!x[$$0]++ { print("/home/amir/kerneldev/day2/"$$0) }' > /home/amir/kerneldev/day2/param_module.mod
