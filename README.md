# QTools
## 1 项目计划
项目现计划开发串口、TCP服务端、TCP客户端、UDP网络调试、文本加密解密调试5个功能模块，项目后期根据实际情况酌情修改。
## 2 项目代码目录结构示例
  Qtools  
    │   
    ├──TcpServer  
    │　　　└──tcpserver.cpp  
    │　　　└──tcpserver.h  
    │　　　└──tcpserver.ui  
    │  
    ├──TcpClient  
    │　　　└──tcpclient.cpp  
    │　　　└──tcpclient.h  
    │　　　└──tcpclient.ui  
    
    ....  
    
## 3 开发须知
1 原则上开发使用驼峰命名法，类名使用大驼峰命名法（例：TcpServer），对象名，函数名，变量名使用小驼峰命名法（例：winTcpServer）。槽函数可以使用下划线命名法。

2 各模块的开发应在独立的分支中进行，建议分支以模块名进行命名。

3 模块代码应放入独立的目录下，参照2 项目代码目录结构示例