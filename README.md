# Shared-Library-Development
  A shared library is a file containing object code that several a.out files may use 
simultaneously while executing. When a program is link edited with a shared library, the 
library code that defines the program's external references is not copied into the program's 
object file. Instead, a special section called .lib that identifies the library code is created 
in the object file. When the UNIX system executes the resulting a.out file, it uses the 
information in this section to bring the required shared library code into the address space of the process. 

  The implementation behind these concepts is a shared library with two pieces. 
The first, called the host shared library, is an archive that the link editor searches to 
resolve user references and to create the .lib section in a.out files. The structure and 
operation of this archive is the same as any archive without shared library members. 
It must be present on the system when the a.out files are link edited.

  The second part of a shared library is the target shared library. This is the file 
that the UNIX system uses when running a.out files built with the host shared library. 
It contains the actual code for the routines in the library. It must be present on the the 
system where the a.out files will be run. 


  Shared libraries are libraries that are loaded by programs when they start. 
When a shared library is installed properly, all programs that start afterwards
automatically use the new shared library. It's actually much more 
flexible and sophisticated than this, because the approach used by Linux permits you to:

    1. update libraries and still support programs that want to use older, non-backward-compatible versions of those libraries;

    2. override specific libraries or even specific functions in a library when executing a particular program.

    3. do all this while programs are running using existing libraries.


A shared library offers several benefits by not copying code into a.out files. It can:

    1. Save disk storage space. Shared library code is not copied into all the a.out files 
    that use that code. a.out files are smaller and use less disk space.

    2. Save memory. By sharing library code at run time the dynamic memory needs of the processes are reduced.

    3. Make executable files using library code easier to maintain. 

   At run time shared library code is brought into the processes' address space. 
Therefore, updating a shared library effectively updates all executable files that use the library. 
If an error in shared library code is fixed, all processes automatically use the corrected code. 

	Non-shared libraries cannot offer this benefit: changes to archive libraries do not affect executable files, 
because code from the libraries is copied to the files during link editing, not during execution. 