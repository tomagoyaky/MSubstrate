@echo off

set base=%~dp0

cd /d %base%
call _clean.cmd
call _build.cmd
adb push ../libs/armeabi/Tester /data/local/tmp/
adb shell su -c "chmod 777 /data/local/tmp/Tester"

echo.
echo.
echo ===========================================
adb shell "/data/local/tmp/Tester"
echo ===========================================
pause