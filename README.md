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
当使用静态链接时，GCC会使用复制的方式将连接库中的内容连接到可执行程序。那么，是复制库中所有的内容吗?
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306223457.png)
http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306223621.png
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306223715.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306223748.png)

由以上讨论可知，可执行程序只会链接静态库中源代码中引用的对象文件，而不是静态库的全部内容

## 静态链接与动态链接的相同与差别
### 共同点：
1. 他们都用头文件声明库中包含的函数；
2. 他们都实现了代码共享；
### 区别：
1. 


- 静态库在生成可执行文件之前进行连接，链接库的搜索路径通过绝对路径或者GCC的－L选项指定。连接顺序很重要，有可能产生依赖。
- 动态库在生成可执行文件之后，在运行时链接，链接库的搜索路径通过环境变量LD_LIBRARY_PATH或者配置文件/etc/ld.so.conf进行指定


2.

对于有相同内容构成的静态库与动态库，当分别运行使用静态链接和动态链接生成的可执行程序时：

静态链接：app稍快，占有内存多

动态链接：app稍慢，占有内存少

3. 

对于链接库的后期维护来说，如果链接库的内容由更新：

静态链接方式生成的可执行程序需要重新编译，链接；

动态链接方式生成的可执行程序可能会遇到运行时错误，但不需要重新编译，链接，只需要重新运行。


## 预处理器输出
当c预处理器用于C，C++或者Objective-C编译器时，他被集成到编译器内，并利用二进制标记符直接与编译器的解释器进行通信。不过，预处理器同样也可以用到更方便的独立模式，产生文本输出。

c预处理器的输出啃起来与输入非常类似，区别在于预处理指令行被替换为空行，所有注释内容被替换为空格。当生成的行非常长时，他们将被丢弃。

## 头文件搜索路径

![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306231522.png)

位置1：源代码所在目录，拥有最高优先级，here定义为"."
>gcc -o app -I../primiary include_path.c
>output: infile is in .

位置2：用-I选项指定的目录拥有次高优先级,当删除源代码所在目录的infile.h
就会读取指定目录的文件

>gcc -o app -I../primiary include_path.c
>output: infile is in my_include
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220306234244.png)

位置3：用环境变量C_INCLUDE_PATH或CPATH指定的目录，拥有次低优先级，HERE的定义为"c_include_path".如果删除（或重命名）位置1/2中的头文件，并用环境变量指明头文件位置，当重新编译示例程序并运行它后，我们可以在它的输出中找到头文件的位置
> gcc -o app -I../primiary/ include_path.c
> ./app
infile is in c_include_path


位置4：系统默认搜索目录*（通常是/usr/include/),拥有最低优先级，HERE的定义为"/usr/include/"。如果删除（或重命名）位置1/2中的头文件，并将环境变量C_INCLUDE_PATH和CPATH设置为空，当重新编译实例程序时，打印/usr/include/

换成尖括号包含头文件的话就是2341的优先级顺序


## 有趣的-I-选项
GCC的-I-选项把-Idir选项分成了两个部分。

左边的部分只会在-l选项指定的目录内搜索双引号括起来的文件，但是不搜索尖括号括起来的头文件。

右边的部分则是在-I选项指定的目录内搜索所有头文件。
我们看看下面一个例子：
```c
#include <stdio.h>
#include <ab.h>
#include "dq.h"

#ifndef RIGHT_AB //如果在right目录中找不到ab.h则打印错误信息
    #error AB not found in RIGHT
#endif

#ifndef LEFT_DQ //如果在left目录中找不到dq.h则打印错误信息
    #error DQ not found in LEFT
#endif

#ifdef RIGHT_DQ //如果在right目录中找到dq.h则打印警告信息
    #warning DQ found in RIGHT
#endif
```
这个例子用尖括号（Angle Brackets）包含头文件ab.h，用双引号（Double Quotes）包含dq.h。

在源代码文件目录中新建两个目录left和right，然后分别放置头文件ab.h, dq.h。
left中ab.h定义宏LEFT_AB
left中dq.h定义宏LEFT_DQ
right中ab.h定义宏RIGHT_AB
right中dq.h定义宏RIGHT_DQ
如果使用以下方式对示例程序进行预处理：
>$ gcc -E option-I-.c -o option-I-.i -Ileft -I- -Iright
>cc1: note: obsolete option ‘-I-’ used, please use ‘-iquote’ instead
根据-I-选项的含义，由于ab.h使用了尖括号，所以GCC不会在left目录下搜索改头文件，因此会包含right目录下的ab.h，那么将定义宏RIGHT_AB。同理，源文件将包含left目录下的dq.h并定义宏LEFT_DQ。
由此可见，源代码中的#error ab和#error dq指令将不会执行
然而， GCC的-I-选项已经过时了，我们最好使用-iquote选项来代替它


## C语言程序的编译过程
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220307185456.png)

1. 从源代码文件中读取字符，如果有必要的话，将字符转换成源代码字符集的字符。如果源代码中行尾字符与换行字符不一样，就进行替换

2. 只要反斜杠后面紧跟着换行字符，预处理器就会将两者都删除。因为预处理器的指令结束的地方就是行的结束字符，所以这个处理步骤会将反斜杠放在最后一行的结尾处，让预处理指令在下一行继续

3. 将源代码文件分解成预处理器的记号和空格。每个注释都被视为一个空格

4. 执行预处理指令将宏展开

5. “字符常量”和“字符串字面值”内的字符和行转义符被转换为“运行字符集”中对应的字符。

6. 相邻的字符串字面值被串接成一个字符串。

7. 开始实际的编译工作-编译器分析记号的序列并产生对应的机器码。

8. 链接器解析对外部对象和函数的引用，并生成可执行的文件

## 用make创建c程序
由c语言源代码生成可执行程序时，涉及很多步骤，每个步骤又涉及各种工具和选项，make工具可以简化上面的步骤

回顾一下三原色程序，他由3个.c源代码文件和一个头文件组成：
>.../clearn/primiary$ ls
color_example.c              primary.h
color_example_additive.c     primary_additive.c
color_example_subtractive.c  primary_subtractive.c

如果要生成可执行文件可以用下面的GCC命令：
>$ gcc -o app color_example.c primary_additive.c primary_subtractive.c

然后运行程序：./app

可以在源代码目录下新建一个名为makefile的文件
```makefile
CC = gcc
CFLAGS = -Wall -g

app : color_example.o primary_additive.o primary_subtractive.o
    $(CC) $(LDFLAGS) -o $@ $^

color_example.o : color_example.c
    $(CC) $(CFLAGS) -o $@ -c $<

primary_additive.o : primary_additive.c
    $(CC) $(CFLAGS) -o $@ -c $<

primary_subtractive.o : primary_subtractive.c
    $(CC) $(CFLAGS) -o $@ -c $<
```
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220307200421.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220307200714.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220307200954.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220307201128.png)

再精简：
OBJS = color_example.o primary_additive.o primary_subtractive.o

color_example: $(OBJS)

make 有两种变量，一种是“递归展开”的变量，一种是“简单展开”的变量

make中变量都是字符序列，而不是数值。变量所属类型有使用那种赋值运算符决定。 

递归展开的变量会被逐字符存储，直到变量的值被计算出来。

简单展开的变量在赋值时立即展开，并立即存储起来，而不是存储变量名称。

下面介绍make中4种变量赋值运算符：
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220307203511.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220307203609.png)
+= 递归从 ?=没有值才赋值

如果makefile中某个目标有特别的要求，可以使用目标专用的变量赋值
若要在makefile中把某个变量赋值给特定目标，可以添加如下一行

目标列表：[override] 赋值

当make构建这个目标时，目标专用的变量会取代makefile中其他地方定义的同名变量


make自动变量：
- $@: 指的是目标名称
- $*: 目标文件名的stem（词根），及匹配模式规则中%代表的部分。
- $<: 指的是第一个前提
- $^：指的是前提列表
- $?：比目标新的前提列表
- $+：前提的完整列表，包括重复项


make命令的语法：
make[options][命令行变量][target[target[target]]]
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308081450.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308081830.png)

### make递归
makefile规则可以包含任何可以在目标系统上执行的命令，这其中就包括make命令本身。
make最经典的递归用法就是构建“组织成子目录”的项目，每个子目录下都有自己的makefile
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308082237.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308082401.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308082551.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308082701.png)


#pragma预处理指令是“提供附加信息给编译器”的标准方法
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308083542.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308083635.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308083705.png)
![](http://cdn.jsdelivr.net/gh/MaoYuanxing/imgbed/20220308083753.png)


## Linux内核中的链表
在Linux内核中有大量的对象，对于那些动态对象来说，使用链表进行管理是十分方便的

Linux内核源代码有一个叫做list.h的文件位于/include/linux/ 下里面定义了各种链表操作的宏和函数（多为内联函数）。 