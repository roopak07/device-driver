cmd_/home/roopak/practice/basic_kernal_module/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/roopak/practice/basic_kernal_module/"$$0) }' > /home/roopak/practice/basic_kernal_module/hello.mod