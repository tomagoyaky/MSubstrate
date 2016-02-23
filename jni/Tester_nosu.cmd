@echo off

set base=%~dp0
cd /d %base%
adb push "..\libs\x86\Tester" /data/local/tmp
adb shell "chmod 777 /data/local/tmp/Tester"
adb shell "/data/local/tmp/Tester"

pause
