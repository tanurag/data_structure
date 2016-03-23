#include<stdlib.h>
#include<stdio.h>
#include<limit.h>
#include<string.h>

struct entry_s{
	char *key;
	char *value;
	struct entry_s *next;
}

typedef struct entry_s entry_t;

struct hashtable_s{
	int size;
	struct entry_s **table;
};

typedef struct hashtable_s hashtable_e;

/*create a new hash table*/
hashtable_t *ht_create(int size)
{
	hashtable_t *hashtable = NULL;
	int i;

	if(size<1) 
		return NULL;
	/*Allocate the table itself*/
	if((hashtable->table=malloc(sizeof(entry_t*)*size))==NULL){
		return NULL;
	}
	for(i=0;i<size;i++)
		hashtable->table[i]=NULL;
	hashtable->size=NULL;
	return hashtable;
}

/*hash a string for particular hash table*/
int ht_hash(hashtable_t *hashtable,char *key)
{
	unsigned long int hashval;
	int i=0;
	/*Convert your string to an integer*/
	while(hashval <ULONG_MAX && i < strlen(key)){
		hashvak=hashval<<8;
		hashval+=key[i];
		i++;
	}

	return hashval%hashtable->size;
}


