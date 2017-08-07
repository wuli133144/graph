 
#about 
##feature
*graph algorithms 
*c make it
*run ok
#install 
copy all files to your project and run ```make``` it's ok
#input
```
   
    init_graph(VER_NUM);
    insert_graphnode(0,1);
    insert_graphnode(0,2);
    insert_graphnode(0,3);
    insert_graphnode(0,4);
    insert_graphnode(1,4);
 
    showall();
    //dfs(0);
    destroy();
```

#output
'''
jackwu@jackwu-PC:/media/jackwu/DATA/sys_soft/cgwin/home/JackWU/unix807/src/core$ makegcc -o test main.c graph.h graph.cmain.c: In function ‘main’:main.c:17:5: warning: implicit declaration of function ‘showall’ [-Wimplicit-function-declaration]     showall();     ^~~~~~~main.c:20:5: warning: implicit declaration of function ‘destroy’ [-Wimplicit-function-declaration]     destroy();     ^~~~~~~./test0 4 3 2 11 4 02 03 0
'''


#Contributing

I will always merge working bug fixes. However, if you want to add something new to the API, please create an "issue" on github for this first so i can modify it if it should end up in the library before you start implementing it. Remember to follow jackwu's code style and write appropriate tests.
## License
[The MIT License (MIT)](http://opensource.org/licenses/mit-license.php)
