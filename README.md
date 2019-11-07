# Polydeuces 

* Javascript 引擎
* 研究用项目, 不可用于生产


## 目标 

* 尽可能减少内存占用
* 支持系统原生线程
* 测试如果不执行任何优化其性能与专业引擎的差距


## 需要

* Windows 7+
* Java 1.7+


## 升级解析器代码

0. 安装依赖, 参看: deps/Readme.md
1. 运行 `pitch-garammars.cmd` 升级语法树描述文件
2. 运行 `generate-src.cmd` 生成最新解析器 cpp 代码
3. 复制 deps/javascript-grammars/javascript/Cpp 源码覆盖 generate 中的同名文件
4. 修复 这些文件的代码


# 引用

* [语言框架](https://github.com/antlr/antlr4)
* [JS语法树](https://github.com/antlr/grammars-v4/tree/master/javascript)
* [ECMAScript测试套件](https://github.com/tc39/test262)