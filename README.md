ToFroWin - Performs conversion between DOS and UNIX text formats
================================================================

![screenshot](http://sysd.org/stas/files/active/0/tofrowin.png)

Windows Shell extension that integrates itself into Explorer Context Menu
and provides quick & practical way to convert between text line endings of
UNIX (CR or `"\n"`) and DOS (CRLF or `"\r\n"`).
Actually this is a Win32 GUI port of [Tofrodos Ver 1.7 by Christopher Heng](http://www.thefreecountry.com/tofrodos/).

Installation:
-------------

Extract archive to any directory (`C:\Program Files`). Then go to this
directory and execute  install.bat`.

To uninstall execute `uninstall.bat` and simply delete ToFroWin files.

Installation on Vista:
----------------------

Symptoms: during the install/registering the DLL, RegSvr32 pops up an error:

    The module "ToFroWin.dll" was loaded but the call to Dll RegisterServer
    failed with error code 0x80070005. For more information about this problem,
    search online using the error code as a search term.

Or, running as Administrator:

    The module "ToFroWin.dll" failed to load. Make sure the binary is stored
    at the specified path or debug it to check for problems with the binary
    or dependent .DLL files.  The specified module could not be found.

Solution: go to Start, Programs, Accessories, right-click on Command Prompt, run as Administrator, go to the folder you extracted ToFroWin to, and type `install`.

Great thanks for [Monk](http://rq3.com/) for discovering/fixing this :D

ChangeLog:
----------

 - v0.1.0.0
	* first public release

TODO:
-----

 * Make it SMALLER. Damn, ATL is the fuckin' worst thing ever created by
   mankind; it's dependencies are unpredictable, version compiled under
   WinXP won't work on Win98 and vice-versa. And trade-off DLL is HUGE...
   100 Kb against 32 Kb of WinXP-specific or 36 Kb of Win98-specific >%E~
 * Better icons :P
 * Some progress dialog?

References:
-----------

 - [Tofrodos Ver 1.7 by Christopher Heng]((http://www.thefreecountry.com/tofrodos/)). I use if for years, IMHO it's
   the best text format converter. I **really**  don't like `dos2unix`/`unix2dos`
   as they work through STDIN/OUT pipes and tofrodos converts in-place :)
 - Michael Dunn's "Complete Idiot's Guide to Shell Extension" or whatever is
   it's english name; I've read russian traduction by Inna Kiryushina &
   Aleksei Kiryushin. REALLY thank for such an awesome work!!!

 - Fuck-Offs:
	* C++ is a bunch of horse crap! Only lazy ass morons who have no competence
     to code in pure C and assembly are supposed to use this freakin' shit!!!
	* ATL stinks, COM stinks; whatever stupid ugly OOP-alike extension over
     clean DLL scheme must die of horryfying pain in rectum!!! Again; only
     morons are unable to LoadLibrary()/GetProcAddress() so they build & use
     such homossexual sex toys...
	* Windows Explorer sucks hard!

Author:
-------

Stanislaw Y. Pusep (a.k.a. Stas)

    E-Mail:	stas@sysd.org
    Site:	http://sysd.org/
