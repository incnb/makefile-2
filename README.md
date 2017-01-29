# makefile

A target file is rebuilt when a target file it depends on is newer that it. A global int is used to keep track of the age of files
(increments by 1 every time a touch command is issued). 
** A file may depend on at most 10 other files **
** There may be at most 20 files in the system **

main.cc test harness accepts the following commands:

target: source — adds dependency such that file 'target' depends on file 'source'

touch file — indicates that the file called file has been updated at time n where n the global int clock

make file — rebuilds 'file' by rebuilding all files it is dependent on that have been updated.
