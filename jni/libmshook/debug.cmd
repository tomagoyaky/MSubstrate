@echo off

@rem 设置本地变量
set base=%~dp0
set toolDir="E:\Android\android-ndk-r10\toolchains\arm-linux-androideabi-4.6\prebuilt\windows-x86_64\bin"
set symbolsDir="..\obj\local\armeabi\objs-debug\mshook"
set gdb="%toolDir%\arm-linux-androideabi-gdb-orig.exe"
set objcopy="%toolDir%\arm-linux-androideabi-objcopy.exe"
set symbolFile="%symbolsDir%\symbol.dbg"
set gdb_config="%toolDir%\.gdbinit"
cd /d %base%

@rem 生成符号表
%objcopy% --only-keep-debug %symbolsDir%\Tester.o %symbolFile%

@rem 开启gdb服务
start /B _runGdbServer.cmd

@rem 模拟休眠3s
ping 127.0.0.1 -n 3s > nul

@rem 生成自动加载脚本
echo target remote 127.0.0.1:2345 > %gdb_config%
echo break 2 >> %gdb_config%
echo info b >> %gdb_config%
echo set debug-file-directory %symbolsDir% >> %gdb_config%

@rem 开始调试连接
echo gdb connecting ...
%gdb% -x %gdb_config% -symbol=%symbolFile%