cd /d %~dp0
setx LIBWARE %cd%
@echo off
ping -n 3 127.0.0.1 > nul
