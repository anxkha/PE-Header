@ECHO OFF

cl /c /TP /Zi /W3 /ML /GS /EHsc /FD /D "WIN32" /Wp64 /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /O2 /Fo"peheader.obj" peheader.cpp

link /INCREMENTAL:NO /SUBSYSTEM:CONSOLE /NOLOGO /RELEASE /MACHINE:X86 /OUT:"peheader.exe" "peheader.obj" kernel32.lib
