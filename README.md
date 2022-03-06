## ELF(Executable and Linkable Format) 现代计算机一种重要的二进制格式

当我们在命令行终端执行./a.out 加载这种格式的文件就是调用execve()，从而进入内核空间，这个函数会调用search_binary_handler(), 后者会调用load_elf_binary()

<table>
    <tr>
        <th rowspan="1">头部</th>
		<td>    </td>
    </tr>
    <tr>
		<th rowspan="3">头部描述表</th>
		<th>PT_LOAD<br>描述运行内存分布</th>
	</tr>
	<tr><td>PT_INTERP<br>标识运行时链接器</td></tr>
	<tr><td>PT_GNU_STACK<br>程序堆栈是否可执行</td></tr>
</table>

##  html表格技巧
- 使用跨行或者跨列时，使用`th`标签
-  跨行： `rowspan`的的参数就是要跨的行数
-  跨列： `colspan`的参数就是要跨的列数

```html
<table><tbody>
    <tr>
        <th rowspan=3>合并行</th>
        <th>第一列</th>
        <th>第二列</th>
        <th>第三列</th>
    </tr>
    <tr>
        <td colspan=2>合并列</td>
        <td rowspan=2>第三列</td>
    </tr>
    <tr>
        <td><img src="http://latex.codecogs.com/gif.latex? \omega" /></td>
        <td><img src="http://latex.codecogs.com/gif.latex? 35*d_2" /></td>
    </tr>
</table>  
```
<table><tbody>
    <tr>
        <th rowspan=3>合并行</th>
        <th>第一列</th>
        <th>第二列</th>
        <th>第三列</th>
    </tr>
    <tr>
        <td colspan=2>合并列</td>
        <td rowspan=2>第三列</td>
    </tr>
    <tr>
        <td><img src="http://latex.codecogs.com/gif.latex? \omega" /></td>
        <td><img src="http://latex.codecogs.com/gif.latex? 35*d_2" /></td>
    </tr>
</table>  


![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306182308.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306190334.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306190437.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306190940.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306191010.png)
 ## the location of libc.so.6 In Centos
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306192034.png)

 ## the location of libc.so.6 In Ubuntu
 ![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306192410.png)
 
 # 静态链接库和动态连接库的区别
 ![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306194256.png)
 ![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306194407.png)
 静态链接器通常作为一项功能性模块包含在编译器内， 当程序使用静态链接方式时，静态链接库中的代码被拷贝到可执行文件。
 
 当使用静态链接时，顺序很重要。原则是越特殊的库越靠前，越通用的库越靠后。
在类Unix系统中，动态链接库文件以.so（表示“shared object:”）结尾。
我们可以用gcc的-shared选项生成动态库，例如：
>gcc -fPIC -shared -o libdynamic.so dynamic.c
其中：
> -fPIC表示生成与位置无关的代码，即加载动态库时，可以放在内存的任何位置
如果使用动态连接方式，只有链接库文件的引用给拷贝到可执行文件，动态链接库中的代码在运行时（利用成为动态链接器的程序）才通过这个引用被找到
共享库与静态库使用完全不同的方式和时间进行连接，他的链接过程发生在程序执行的时候。这个过程由成为动态链接器的系统来实施，通常时被预先设置为在/lib 和/usr.lib/目录中寻找共享库文件。



## 自行编译的链接库
自行编译的软件通常把头文件放在 /usr/local/include/目录。不过，头文件的位置没有硬性要求，他们可以被放在任何地方。如果你想查找头文件，可以试试locate和find这两个命令行工具。
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306200514.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306200620.png)

通常，编译器默认搜索路径包括/lib和/usr/lib/这两个目录。编译器还接受各种参数以控制如何连接和在何处链接库。其中最重要的两个选项：
> -L dir编译器在dir内搜索链接库

>-lname 在编译器默认所搜路径和-L指定路径内搜索么为linbname.a的静态链接库和名为libname.so的动态链接库

![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306201356.png)

![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306201537.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306201817.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306202045.png)


## 三原色静态库
 > gcc -c primary_additive.c
 >gcc -c primary_subtractive.c
 
 
 生成对象：
 >primary_additive.o  >primary_subtractive.o


 下面的命令用来生成静态库
 >ar cr libprimarycolors.a primary_additive.o primary_subtractive.o
 
 
 用下面的命令编译程序：
 >gcc -o app color_example.c -L. libprimarycolors.a 
 
 
 其中：
  -L选项指定在当前目录下搜索链接库

  ## 三原色的动态库
  自行编译的动态链接库通常放在<b>/usr/local/lib/</b>及其子目录。为此。我们在<b>/usr/local/lib/</b>下新建目录lettuce，用于存放自己的链接库。
  >$ sudo mkdir /usr/local/lib/lettuce
  
  
  用以下命令在当前目录下生成动态库：
   >gcc -fPIC -shared -o libprimarycolors.so primary_additive.c primary_subtractive.c
   
   
   然后拷贝到前面新建的目录下
   >sudo cp libprimarycolors.so /usr/local/lib/lettuce/
   
   
   用以下命令编译程序：
   >gcc -o app color_example.c -L/usr/local/lib/lettuce/ -lprimarycolors
   
   
   其中：
   -L选项指定在/usr/local/lib/lettuce/ 目录下搜索链接库

   但在运行app之前需要明确指定动态链接库的搜索位置。为此我们可以把以下的内容添加到用户目录下<b>.bashrc</b>文件的末尾，然后重新登录以加载新的配置。
   >export LD_LIBRARY_PATH=/usr/local/lib/lettuce/:$LD_LIBRARY_PATH


## 静态链接的细节
当使用静态链接时，GCC会使用复制的方式将连接库中的内容连接到可执行程序。那么，是复制库中所有的内容吗
