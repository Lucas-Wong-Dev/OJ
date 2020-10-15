# Astyle

Project Page:http://astyle.sourceforge.net/		——这个网站相当于Astyle的官网

SourceForge:http://sourceforge.net/projects/astyle/

# Dev-C++

@from：sourceforge https://sourceforge.net/projects/orwelldevcpp/

- A free, portable, fast and simple C/C++ IDE
- Brought to you by: [orwelldevcpp](https://sourceforge.net/u/orwelldevcpp/)
- Last Update: [2016-11-29](https://sourceforge.net/p/orwelldevcpp/activity) // 本机中的Dev-C++下载于2020-10-14

## Summary

A new and improved fork of Bloodshed Dev-C++

### Features

- TDM-GCC 4.9.2 32/64bit
- Syntax highlighting
- Code completion
- Code insight
- Editable shortcuts
- GPROF profiling
- GDB debugging
- AStyle code formatting
- Devpak IDE extensions
- External tools

# Dev-C++ 2020

@from：sourceforge https://sourceforge.net/projects/dev-cpp-2020/

- Brought to you by: [royqh1979](https://sourceforge.net/u/royqh1979/)
- Last Update: [1 day ago](https://sourceforge.net/p/dev-cpp-2020/activity) // 今天是2020-10-14

## Summary

Dev-CPP 2020 is ==a fork of Orwell Dev-CPP== (https://sourceforge.net/p/orwelldevcpp)

The sourcecode can be found at https://github.com/royqh1979/Dev-CPP

### Features

- [Mingw.org](http://mingw.org/) GCC 9.2
- Greatly improved "Auto symbol completion"
- Greatly improved Auto Code Completion
- Fix auto-indent
- Greatly improved Debugger & Debugger console
- UTF-8 File encoding support
- Rename symbol (using clang-rename)
- -Wall -Wextra -Werror is turn on by default( in the default Debug profile)
- redirect STDIN to a data file while running or debuging

# Dev-C++的使用技巧

@from：博客：jeddd https://www.jeddd.com/article/dev-cpp-beginner.html

## 支持新标准（-std）

Dev C++ 5.11 版本支持较新的 C 和 C++ 标准，但是默认没有开启。许多 C 语言初学者在写以下代码的时候会对编译器给出的报错感到困惑：

```c
for(int i = 0; i < 10; i++) {
    printf("%d", i);
}
```

这是因为**在 for 循环内部声明变量的语法是在 C99 标准以后才支持的**。

所以先别急着骂编译器垃圾。依次到【**工具**】-【**编译选项**】-【**代码生成 / 优化**】-【**代码生成**】。在【**语言标准**】中选择 “==**ISO C99**==” 或 “**IOS C++11**”，此后在编译的时候就可以使用 C99 或 C++ 11 标准了。

[![img](%E5%B7%A5%E5%85%B7.assets/dev-cpp-ios-std-cpp-11.png)](https://img.jeddd.com/2018/07/dev-cpp-ios-std-cpp-11.png)

## 显示所有警告（-Wall）

Warn­ing 与 Er­ror 不同，程序遇到 Er­ror 就不能正常运行了（甚至都不能通过编译），而 Warn­ing 是说明你的程序有不严谨的地方。新手程序员们应该认真对待 Warn­ing，从而提升代码质量。

在 Dev C++ 中开启显示所有警告的方法如下：【**工具**】-【**编译选项**】-【**代码生成 / 优化**】-【**代码生成**】，在【**代码警告**】中将 “**显示最多警告信息 (-Wall)**” 设置为 Yes 即可。



[![img](%E5%B7%A5%E5%85%B7.assets/dev-cpp-enable-wall.png)](https://img.jeddd.com/2018/07/dev-cpp-enable-wall.png)

上述设置其实是在编译时加入了 -Wall 参数。Wall 不是墙的意思，而是 Warn­ing all，即显示所有警告。开启了 Wall 之后，在某种意义上你应该像对待 Er­ror 那样对待 Warn­ing。

## ==产生调试信息（-g3）==

有些版本的 Dev C++ 在刚刚安装完成后默认情况下是不能进行调试的，一旦点击调试按钮，会提示 “没有调试信息”，随后程序崩溃或闪退。

[![img](%E5%B7%A5%E5%85%B7.assets/dev-cpp-no-debugging-info.png)](https://img.jeddd.com/2018/07/dev-cpp-no-debugging-info.png)

这是因为在编译源代码的时候没有加入调试信息。解决方法如下：【**工具**】-【**编译选项**】-【**代码生成 / 优化**】-【**代码生成**】，在【**连接器**】中将 “**产生调试信息**” 设置为 Yes。



[![img](%E5%B7%A5%E5%85%B7.assets/dev-cpp-add-debugging-info.png)](https://img.jeddd.com/2018/07/dev-cpp-add-debugging-info.png)



只有产生了调试信息才能对程序进行断点调试。要开始调试，按下[![img](%E5%B7%A5%E5%85%B7.assets/2018-07-06_114057.png)](https://img.jeddd.com/2018/07/2018-07-06_114057.png)按钮或键盘快捷键`F5`。

## 格式化源代码

Dev C++ 中有一个叫做 **AStyle** 的工具，可以快速格式化代码。点击顶部菜单栏的【**AStyle**】-【**格式化当前文件**】，或按下快捷键 `Ctrl`+`Shift`+`A`，代码马上变得能看了。

[![img](%E5%B7%A5%E5%85%B7.assets/123-1530849455.gif)](https://img.jeddd.com/2018/07/123-1530849455.gif)

这是 Dev C++ 中我最喜欢的功能了。AStyle 的全称是 “Artis­tic Style”，它是一个第三方工具，并不依赖 Dev C++