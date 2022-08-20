# M53 Correct Output
Script started on Mon 20 Jun 2022 08:16:11 PM EDT
==126654== Memcheck, a memory error detector
==126654== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==126654== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==126654== Command: ws
==126654== 
Loading Data
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 3
Checkout publication from the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
No matches found!

Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 3
Checkout publication from the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Web
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | Z192 | Charlotte's Web............... |  N/A  | 2022/07/17 | E. B. White; il |
> X (to Exit)
> Row Number(select publication)
> 1
| Z192 | Charlotte's Web............... |  N/A  | 2022/07/17 | E. B. White; il |
Check out publication?
 1- Yes
 0- Exit
> 1
Enter Membership number: 12345
Publication checked out

Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 0
Changes have been made to the data, what would you like to do?
 1- Save changes and exit
 2- Cancel and go back to the main menu
 0- Exit
> 1
Saving Data

-------------------------------------------
Thanks for using Seneca Library Application
B	1001	C544	The Hobbit	35277	2022/07/14	J. R. R. Tolkien
B	1002	D208	Harry Potter and the Philosopher's Stone	72685	2022/07/19	J. K. Rowling
P	1018	P002	The Toronto SUN	85176	2022/07/17
P	1019	P002	The Toronto SUN	0	2022/07/11
B	1048	N518	The Bridges of Madison County	15467	2022/07/14	Robert James Waller
B	1061	Z192	Charlotte's Web	12345	2022/08/10	E. B. White; illustrated byGarth Williams
B	1062	V718	The Tale of Peter Rabbit	0	2022/07/12	Beatrix Potter
P	1093	P008	Canadian Running Magazine	77051	2022/07/25
P	1094	P008	Canadian Running Magazine	0	2022/07/18
==126654== 
==126654== HEAP SUMMARY:
==126654==     in use at exit: 0 bytes in 0 blocks
==126654==   total heap usage: 54 allocs, 54 frees, 100,402 bytes allocated
==126654== 
==126654== All heap blocks were freed -- no leaks are possible
==126654== 
==126654== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Script done on Mon 20 Jun 2022 08:16:34 PM EDT
