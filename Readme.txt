ToFroWin - Performs conversion between DOS and UNIX text formats
================================================================

Windows Shell extension that integrates itself into Explorer Context Menu
and provides quick & practical way to convert between text line endings of
UNIX (CR or "\n") and DOS (CRLF or "\r\n").
Actually this is a Win32 GUI port of Tofrodos Ver 1.7 by Christopher Heng.


 * Installation:
----------------

Extract archive to any directory ("C:\Program Files"). Then go to this
directory and execute "install.bat".
To uninstall execute "uninstall.bat" and simply delete ToFroWin files.


 * ChangeLog:
-------------

 - v0.1.0.0
	* first public release


 * TODO:
--------

 o Make it SMALLER. Damn, ATL is the fuckin' worst thing ever created by
   mankind; it's dependencies are unpredictable, version compiled under
   WinXP won't work on Win98 and vice-versa. And trade-off DLL is HUGE...
   100 Kb against 32 Kb of WinXP-specific or 36 Kb of Win98-specific >%E~
 o Better icons :P
 o Some progress dialog?


 * References:
--------------

 o Tofrodos Ver 1.7 by Christopher Heng. I use if for years, IMHO it's
   the best text format converter. I *really*  don't like dos2unix/unix2dos
   as they work through STDIN/OUT pipes and tofrodos converts in-place :)
 o Michael Dunn's "Complete Idiot's Guide to Shell Extension" or whatever is
   it's english name; I've read russian traduction by Inna Kiryushina &
   Aleksei Kiryushin. REALLY thank for such an awesome work!!!

 o Fuck-Offs:
   # C++ is a bunch of horse crap! Only lazy ass morons who have no competence
     to code in pure C and assembly are supposed to use this freakin' shit!!!
   # ATL stinks, COM stinks; whatever stupid ugly OOP-alike extension over
     clean DLL scheme must die of horryfying pain in rectum!!! Again; only
     morons are unable to LoadLibrary()/GetProcAddress() so they build & use
     such homossexual sex toys...
   # Windows Explorer sucks hard!


 * Author:
----------

Stanislaw Y. Pusep (a.k.a. Stas)

    E-Mail:	cr@cker.com.br
    Site:	http://sysd.org/
(here you can find this program & other cool things)
