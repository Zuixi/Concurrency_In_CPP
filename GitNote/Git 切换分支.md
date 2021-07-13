#### 查看远程分支
1. 输入命令**git branch -a**;

2. 查看输出结果，示意如下所示

    ```
    * master
    remotes/origin/HEAD -> origin/master
    remotes/origin/master
    remotes/origin/work_note
    ```
    这表示当前在master分支

#### 查看本地分支
1. 输入命令**git branch**

2. 查看输出结果，示意如下：
    ```
    * master
    ```

#### 切换分支
1. 输入命令**git checkout -b work_note origin/work_note**;

2. 查看输出结果，如下所示：
    ```
    Switched to a new branch 'work_note'
    Branch 'work_note' set up to track remote branch 'work_note' from 'origin'.
    ```
    表示当前已经切换到work_note分支

3. 切换回master分支，使用命令**git checkout master**