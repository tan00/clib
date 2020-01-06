//
// Created by a8398 on 2020/1/3.
//

#include <stdio.h>
#include "testhelp.h"
#include "limits.h"


#include <stdlib.h>
#include <string.h>
#include "sds.h"
#include "adlist.h"


int main(void) {
    list* ins = listCreate();
    listSetFreeMethod(ins, sdsfree);
    listSetDupMethod(ins,sdsdup);

    test_cond("empyt list len", listLength(ins)==0 );

    sds* sds1 =  sdsnew("1234");
    listAddNodeHead(ins,sds1);
    listInsertNode(ins,listFirst(ins),"5678",1);
    listAddNodeTail(ins,"90");

    struct listIter* iter =  listGetIterator(ins,AL_START_HEAD);

    sds* sds2 = sdsnew(NULL);
    listNode* node = NULL;
    while((node = listNext(iter))!=NULL){
        sdscat(sds2,node->value);
    }

    printf("sds2=%s\n",sds2);
    test_cond("list insert node", memcmp(sds2,"1234567890",10)==0 );

    test_report();
    return 0;
}