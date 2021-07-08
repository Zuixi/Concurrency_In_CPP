### SSH介绍

**SSH协议可以连接远程服务器和服务并向它们验证**。利用SSH密钥可以连接GitHub，而无需在每次访问时都提供用户名和个人访问令牌。

#### 检查现有SSH密钥是否存在
在使用SSH密钥连接Github之前，我们可以检查本地是否已经存在SSH密钥，步骤如下：

1. 打开Git Bash
2. 输入**ls -al ~/.ssh**查看是否存在现有SSH密钥
3. 查看列表中是否已经有SSH密钥, 默认公密钥文件名如下:
    * id_rsa.pub
    * id_ecdsa.pub
* id_ed25519.pub

#### 生成新的SSH密钥
1. 打开Git Bash
2. 输入以下命令（其中的邮件地址替换成自己的地址）
    > ssh-keygen -t ed25519 -C "your_email@example.com"

    **注意**
    如果系统不支持Ed25529算法，则使用如下命令：
    > ssh-keygen -t rsa -b 4096 -C "your_email@example.com"

    输入上述命令之后，将会创建以提供的Email为标签的SSH密钥
    >  Generating public/private ed25519 key pair.

3. 提示输入**Enter a file in which to save the key**(要保存密钥的文件)时，我们只需要按**Enter**键，使用默认的文件位置
    > Enter a file in which to save the key (/c/Users/you/.ssh/id_ed25519):[Press enter]

4. 提示输入密码的时候，我们也可以只按**Enter**键
    > Enter passphrase (empty for no passphrase): [Type a passphrase]
    > Enter same passphrase again: [Type passphrase again]

#### 将生成的SSH密钥放到Github账户上

#### 测试SSH连接是否成功
1. 打开Git Bash
2. 输入命令
    > ssh -T git@github.com