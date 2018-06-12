# Shared-Library-Development
  Shared libraries are libraries that are loaded by programs when they start. 
When a shared library is installed properly, all programs that start afterwards
automatically use the new shared library. It's actually much more 
flexible and sophisticated than this, because the approach used by Linux permits you to:

    1. update libraries and still support programs that want to use older, non-backward-compatible versions of those libraries;

    2. override specific libraries or even specific functions in a library when executing a particular program.

    3. do all this while programs are running using existing libraries.
    
  How Libraries are Used 
    On GNU glibc-based systems, including all Linux systems, starting up an ELF binary 
    executable automatically causes the program loader to be loaded and run.
    On Linux systems, this loader is named /lib/ld-linux.so.X (where X is a version number).
    This loader, in turn, finds and loads all other shared libraries used by the program.
    
    
