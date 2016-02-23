@echo off

set base=%~dp0

cd /d %base%
adb push ../libs/armeabi/gdb.setup /data/local/tmp/
adb push ../libs/armeabi/gdbserver /data/local/tmp/
adb shell su -c "chmod 777 /data/local/tmp/gdbserver"

echo.
echo.
echo ===========================================
adb forward tcp:2345 tcp:2345
adb shell su -c "/data/local/tmp/gdbserver 127.0.0.1:2345 /data/local/tmp/mshook"
echo ===========================================

pause