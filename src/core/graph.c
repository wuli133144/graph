/**************************************************************************
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/
#include "graph.h"
#include "queue.h"

#define TEST(A)       do{     \
  fprintf(stderr,"%-60s-",#A);\
  if(A){                      \
      puts("OK!");            \
 }else {                      \
        puts("FAILED!");      \
 }                             \
}while(0)



vertex_t *alloc_graphnode(int v){
      vertex_t*item=(vertex_t *)malloc(sizeof(vertex_t));
      item->next=NULL;
      item->vertex=v;
      item->mark=nomarked;
      return item;
}

/*head insert*/
void insert(vertex_t *head,int v){
        //TEST(head==NULL);
        vertex_t *item=alloc_graphnode(v);
        item->next=head->next;
        head->next=item;
}

/*show element value*/
void show(vertex_t *head){
    vertex_t *item=head;
    while(item!=NULL){
        printf("%d ",item->vertex);
        item=item->next;
    }
}


void showall(){
      int i=0;
      for(;i<VER_NUM;i++){
          show(&graph->vertex[i]);
          printf("\n");
      }
}


//v--->w
void insert_graphnode(int v,int w){
        insert(&graph->vertex[v],w);//add edge v->w
        insert(&graph->vertex[w],v);
        graph->edge++;
}

/*init graph struct*/
void init_graph(int v_count/*vertex numbers*/){
       int i=0;
       if(graph==NULL){
           graph=(graph_t *)malloc(sizeof(graph_t));
       }
       graph->count=v_count;
       graph->edge=0;
       for(;i<VER_NUM;i++){
           graph->vertex[i].vertex=i;
           graph->vertex[i].mark=nomarked;
       }
}


/*depth search*/

 void dfs(int v){
          vertex_t *item=NULL;
          printf("current node--%d--\n",v);
          graph->vertex[v].mark=marked;//mark it

          for(item=&graph->vertex[v];item;item=item->next)
          {       
                  int i=item->vertex;
                  if(graph->vertex[i].mark==nomarked){
                          dfs(graph->vertex[i].vertex);
                  }
          }
}



void free_list(vertex_t *head){
    vertex_t *cur,*pre;
    pre=head;
    cur=head->next;
    if(head==NULL){
        return;
    }
    pre=cur;
    while(cur!=NULL){    
         cur=cur->next;
         free(pre);
         pre=cur;
    }
}

//判断一个节点能否达到另一个节点
int is_a(int v,int m){

       vertex_t *item=NULL;
       graph->vertex[v].mark=marked;
       for(item=&graph->vertex[v];item;item=item->next){
             int i=item->vertex;
             if(graph->vertex[i].mark==nomarked){
                  is_a(i,m);
                  if(graph->vertex[i].vertex==m){
                      return 0;
                  
                 }
             }
           
       }
}



/*wide travel*/

void bfs(int v){
         
         //vertex_t *item=NULL;
         queue_t queue;
         enqueue(&queue,graph->vertex[v]);

         vertex_t *item=NULL;
         while(1){
               outqueue(&queue,item);
               printf("%d ",item->vertex);               
               enqueue(&queue,item.next);
         }
         


}




 
void destroy(){
    int i=0;
    for(i=0;i<VER_NUM;i++){
        free_list(&graph->vertex[i]);
    }
    free(graph);
    graph=NULL;
}
