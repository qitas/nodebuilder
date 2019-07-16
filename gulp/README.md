# [web file builder](https://github.com/Qitas/webtool) 

用于将常规的网络文件转换为C语言可用数组，涉及压缩解压过程。

本工程所包括的执行文件适用于window平台，配置文件可以通用。

### gulp配置

```
npm install gulp -g
```
全局安装 -g：将会安装在C:\Users\Administrator\AppData\Roaming\npm，并且写入系统环境变量；

非全局安装：将会安装在当前定位目录；  全局安装可以通过命令行在任何地方调用它，本地安装将安装在定位目录的node_modules文件夹下，通过require()调用。

本工程中不需要全局配置gulp。

* 不要使用cnpm进行安装，测试无法正常执行。

### 文件说明

package.json是基于nodejs项目必不可少的配置文件，它是存放在项目根目录的普通json文件，package.json是一个普通json文件，所以不能添加任何注释。

