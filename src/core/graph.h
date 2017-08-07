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


#ifndef  __GRAPH__H
#define  __GRAPH__H

#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>

#define VER_NUM    5

#define ALLOC_GRAPH_NODE       alloc_graphnode
#define INSERT_GRAPH_NODE      insert_graphnode


typedef enum{nomarked,marked}ismark;

typedef struct __node_graph{
    int vertex;
    ismark mark;//is marked 
    struct __node_graph *next;
}vertex_t;

typedef  struct __graph__type{
    int count;
    int edge;
    vertex_t vertex[VER_NUM];
}graph_t ;



static graph_t *graph=NULL;


vertex_t *alloc_graphnode(int );

void insert(vertex_t *head,int v);
    
void init_graph(int v_count/*vertex numbers*/);

void insert_graphnode(int ,int );




#endif 