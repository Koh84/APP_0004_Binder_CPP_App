busybox mount -t nfs -o nolock,vers=2 192.168.0.10:/work/nfs_root /mnt
cd mnt

logcat HelloService:* GoodbyeService:* TestService:* *:S & 

./test_server &
ls -l /proc/xxxx/fd

example:
shell@tiny4412:/mnt/android_fs # ls -l /proc/3859/fd                                                  
lrwx------ root     root              2018-01-09 02:22 0 -> /dev/ttySAC0                              
lrwx------ root     root              2018-01-09 02:22 1 -> /dev/ttySAC0                              
lrwx------ root     root              2018-01-09 02:22 2 -> /dev/ttySAC0                              
lrwx------ root     root              2018-01-09 02:22 3 -> socket:[12311]                            
lrwx------ root     root              2018-01-09 02:22 4 -> socket:[12312]                            
lrwx------ root     root              2018-01-09 02:22 5 -> /dev/binder                               
l-wx------ root     root              2018-01-09 02:22 6 -> /dev/cpuctl/apps/tasks                    
l-wx------ root     root              2018-01-09 02:22 7 -> /dev/cpuctl/apps/bg_non_interactive/tasks 
lr-x------ root     root              2018-01-09 02:22 8 -> /dev/__properties__                       
lrwx------ root     root              2018-01-09 02:24 9 -> socket:[12484]  


./test_client readfile &
ls -l /proc/xxxx/fd

example:
shell@tiny4412:/mnt/android_fs # ls -l /proc/4547/fd                                                  
lrwx------ root     root              2018-01-09 02:27 0 -> /dev/ttySAC0                              
lrwx------ root     root              2018-01-09 02:27 1 -> /dev/ttySAC0                              
lrwx------ root     root              2018-01-09 02:27 2 -> /dev/ttySAC0                              
lrwx------ root     root              2018-01-09 02:27 3 -> /dev/binder                               
lrwx------ root     root              2018-01-09 02:27 4 -> socket:[13562]                            
lrwx------ root     root              2018-01-09 02:27 5 -> socket:[12312]                            
lr-x------ root     root              2018-01-09 02:27 8 -> /dev/__properties__  
