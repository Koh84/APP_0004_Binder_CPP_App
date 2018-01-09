./test_server 1.txt &
ls -l /proc/6882/fd 
shell@tiny4412:/mnt/android_fs # ls -l /proc/6882/fd                                                  
lrwx------ root     root              2018-01-09 01:12 0 -> /dev/ttySAC0                              
lrwx------ root     root              2018-01-09 01:12 1 -> /dev/ttySAC0                              
lrwx------ root     root              2018-01-09 01:12 2 -> /dev/ttySAC0                              
lrwx------ root     root              2018-01-09 01:12 3 -> /mnt/android_fs/1.txt                     
lrwx------ root     root              2018-01-09 01:12 4 -> /dev/binder                               
l-wx------ root     root              2018-01-09 01:12 5 -> /dev/cpuctl/apps/tasks                    
l-wx------ root     root              2018-01-09 01:12 6 -> /dev/cpuctl/apps/bg_non_interactive/tasks 
lr-x------ root     root              2018-01-09 01:12 8 -> /dev/__properties__  
