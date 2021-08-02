### 情形描述
1. 使用命令`git remote add Demo git@gitee.com:wqzhappy/NoteOfCurrencyInCpp.git`

2. 输入命令`git remote -v`查看是否添加成功
    ```
    Demo      git@gitee.com:wqzhappy/NoteOfCurrencyInCpp.git (fetch)
    Demo      git@gitee.com:wqzhappy/NoteOfCurrencyInCpp.git (push)
    ```

3. 添加成功后，输入命令`git pull Demo`，会有如下提示
    ```
    You asked to pull from the remote 'Demo', but did not specify a branch. Because this is not the default configured remote
    for your current branch, you must specify a branch on the command line.
    ```
    
    大致意思就是说我们**未在这个Demo仓库指定分支**
---

### 解决方法
1. 在仓库中**指定分支名**，输入命令`git pull giteeClone master`,输出结果如下
    ```
    From gitee.com:wqzhappy/NoteOfCurrencyInCpp
    * branch            master     -> FETCH_HEAD
    Updating 390ee3c..6fd90dc
    Fast-forward
    ...
    ```

