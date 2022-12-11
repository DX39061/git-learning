### MyClone

#### Try 1

```bash
$ git clone https://github.com/DX39061/git-learning
Cloning into 'git-learning'...
fatal: unable to access 'https://github.com/DX39061/git-learning/': OpenSSL SSL_read: Connection was reset, errno 10054
```
- So it is "gitlearning" ?

#### Try 2
```bash
$ git clone https://github.com/DX39061/gitlearning
Cloning into 'gitlearning'...
fatal: 发送请求时出错。
fatal: 基础连接已经关闭: 接收时发生错误。
fatal: 无法从传输连接中读取数据: 由于连接方在一段时间后没有正确答复或连接的主机没有反应，连接尝试失败。。
fatal: 由于连接方在一段时间后没有正确答复或连接的主机没有反应，连接尝试失败。
fatal: unable to access 'https://github.com/DX39061/gitlearning/': OpenSSL SSL_read: Connection was reset, errno 10054
```
- It occurred that I haven't set my account and password!

#### An Episode
- I couldn't connect to Github again...
- Time goes by...
- ...
- ...
- Looks as if OK?

#### Try 3 Failed 
```bash
$ git clone https://github.com/DX39061/gitlearning
Cloning into 'gitlearning'...
fatal: unable to access 'https://github.com/DX39061/gitlearning/': Failed to connect to github.com port 443 after 21268 ms: Timed out
```
- Is it "gitlearning" or "git-learning" on earth ?

####  Try 4 Succeed
```bash
$ git clone https://github.com/DX39061/git-learning
Cloning into 'git-learning'...
remote: Enumerating objects: 23, done.
remote: Counting objects: 100% (23/23), done.
remote: Compressing objects: 100% (16/16), done.
remote: Total 23 (delta 1), reused 8 (delta 0), pack-reused 0
Receiving objects: 100% (23/23), 5.61 KiB | 1.87 MiB/s, done.
Resolving deltas: 100% (1/1), done.
```
