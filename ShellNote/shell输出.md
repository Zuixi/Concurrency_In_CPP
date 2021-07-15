### SHELL环境
**常见的Shell种类**
* Bourne Shell（/usr/bin/sh或/bin/sh）
* Bourne Again Shell（/bin/bash）
* C Shell（/usr/bin/csh）
* K Shell（/usr/bin/ksh）
* Shell for Root（/sbin/sh）

**注意**
> **#!** 告诉系统其后路径所指定的程序即是解释此脚本文件的Shell程序

**代码示例**
```
#!/bin/bash
echo "Hello World !"
```

### 运行shell的方法
1. 作为可执行程序，例如：
    ```
    chmod +x ./hello.sh  #使脚本具有执行权限
    ./hello.sh  #执行脚本
    ```
2. 作为解释器参数，参数就是文件名，例如：
    ```
    /bin/sh test.sh
    ```