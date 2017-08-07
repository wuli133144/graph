#include "graph.h"



int main(int argc,char **argv){
    
    init_graph(VER_NUM);
    insert_graphnode(0,1);
    insert_graphnode(0,2);
    insert_graphnode(0,3);
    insert_graphnode(0,4);
    insert_graphnode(1,4);
    
    showall();
    int res=is_a(1,4);
    int res1=is_a(2,3);
    printf("is arrived=%d\n",res1);
    dfs(0);
    destroy();

    return 0;
}