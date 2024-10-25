@echo off
cl /nologo /EHsc /Zi /O2 /volatile:ms /FAsc "Main.cpp" "PerformOperation.cpp" /Fe:"Main" && "Main"
