
ToFroWinps.dll: dlldata.obj ToFroWin_p.obj ToFroWin_i.obj
	link /dll /out:ToFroWinps.dll /def:ToFroWinps.def /entry:DllMain dlldata.obj ToFroWin_p.obj ToFroWin_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ToFroWinps.dll
	@del ToFroWinps.lib
	@del ToFroWinps.exp
	@del dlldata.obj
	@del ToFroWin_p.obj
	@del ToFroWin_i.obj
