#include <stdio.h>
#include <stdlib.h>

typedef struct Teacher{
		int age;
		char *name;
}Teacher;


typedef struct ListNode{
		int len;
		int max;
		struct ListNode **node;
}ListNode;

ListNode * list_create(ListNode *list,int max){
		int res = 0;
		ListNode *tmp;
		if(list ==NULL || max <=0){
			res =-1;
			printf("#list_create() ERROR:%d\n ",res);
			return NULL;
		}
		
		tmp = (ListNode *)list;
		tmp->len  = 0;
		tmp->max  = max;
		tmp->node =(ListNode **)malloc(sizeof(ListNode*)*max);
		return tmp;
}

ListNode * list_insert(ListNode *list,ListNode* node,int pos){
		int res = 0;
		int i=0;
		ListNode *tmp;
		if(list == NULL || node<=0 || pos <0 ){
				res = -1;
				printf("#list_insert(ListNode *list,int *node,int pos) ERROR: %d \n",res);
				return NULL;
		}
		tmp = (ListNode *)list;
		if((tmp->len+1) > (tmp->max)){
				res = -2;
				printf("#list_insert(ListNode *list,int *node,int pos) ERROR: %d \n",res);
				return NULL;
		}
		if(pos > tmp->len){
			pos =tmp->len+1; 	
		}
		for(i=tmp->len;i>pos;i--){
			tmp->node[i] = tmp->node[i-1];
		}
		//printf("ListNode* node= %d\n",node);
		tmp->node[i] = node;
		tmp->len++;
		return tmp;
}

ListNode * list_get(ListNode *list,int pos){
		ListNode *tmp;
		int res=0;
		if(list == NULL){
			res = -1;
			printf("#list_get(ListNode *list,int pos) ERROR: %d \n",res);
			return 0;
		}
		tmp = (ListNode*)list;
		if(pos > tmp->len){
			res = -2;
			printf("#list_get(ListNode *list,int pos) ERROR: %d \n",res);
			return 0;
		}
		return tmp->node[pos];
}

int list_delete(ListNode *list,int pos){		
		int res = 0;
		int i=0;
		ListNode *tmp;
		if(list == NULL || pos <0 ){
				res = -1;
				printf("#list_delete(ListNode *list,int pos) ERROR: %d \n",res);
				return res;
		}
		tmp = (ListNode *)list;
		if(pos > tmp->len){
				res = -2;
				printf("#list_delete(ListNode *list,int pos) ERROR: %d \n",res);
				return res;
		}
		for(i=pos; i<tmp->len;i++){
			tmp->node[i] = tmp->node[i+1];
		}
		tmp->len--;
		return 1;
}

void list_clear(ListNode *list){
		int res = 0;
		int i=0;
		ListNode *tmp;
		if(list == NULL){
				res = -1;
				printf("#list_clear(ListNode *list) ERROR: %d \n",res);
		}
		tmp = (ListNode *)list;
		tmp->len  = 0;
}


void list_destroy(ListNode *list){
		int res=0;
		int i=0;
		ListNode *tmp;
		if(list==NULL){
			res=-1;
			printf("#list_destroy(ListNode *list) ERROR: %d \n",res);
			return ;
		}
		tmp = (ListNode *)list;
		//printf("tmp->node=%d\n",tmp->node);
		if(tmp->node !=NULL){
			for(i=0;i<tmp->len;i++){
					if(tmp->node[i]!=NULL){
						//printf("tmp->node[]=%d\n",tmp->node[i]);
						//free(tmp->node[i]);
					}
			}
			free(tmp->node);
		}
		if(tmp !=NULL)
				free(tmp);
}





int main(int argc,char *argv[]){
		Teacher *t1,*t2,*t3,*t4,*t5,*tmp;
		ListNode *list;
		int res = 0;
		int i=0;
		list = (ListNode *)malloc(sizeof(ListNode));
		list = list_create(list,10);
		if(list == NULL){
				res = -1;
				printf("#list_create(list) ERROR:\n",res);
				return res;
		}
		t1 = (Teacher *)malloc(sizeof(Teacher));
		t2 = (Teacher *)malloc(sizeof(Teacher));
		t3 = (Teacher *)malloc(sizeof(Teacher));
		t4 = (Teacher *)malloc(sizeof(Teacher));
		t5 = (Teacher *)malloc(sizeof(Teacher));
		
		
		t1->age  = 31;
		t1->name = "zhangwu1";
		t2->age  = 32;
		t2->name = "zhangwu2";
		t3->age  = 33;
		t3->name = "zhangwu3";
		t4->age  = 34;
		t4->name = "zhangwu4";
		t5->age  = 35;
		t5->name = "zhangwu5";
		
		list_insert(list,(ListNode*)t1,0);
		list_insert(list,(ListNode*)t2,1);
		list_insert(list,(ListNode*)t3,2);
		list_insert(list,(ListNode*)t4,3);
		list_insert(list,(ListNode*)t5,4);
		
			
		for(i=0;i<list->len;i++){
				tmp = (Teacher*)list_get(list,i);
				if(tmp==NULL){
					printf("##(Teacher*)list_get(list,i) ERROR: %d\n",i);
					return i;
				}
				printf("老师姓名：%s 年龄：%d\n",tmp->name,tmp->age);
		}
		
		
		list_destroy(list);
	
		printf("hello....\n");
		return 0;
}


