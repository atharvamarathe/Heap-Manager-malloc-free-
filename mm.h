#ifndef MM_H
#define MM_H

#include <stdint.h>

#define TRUE 1
#define FALSE 0
#define MAX_PAGES 5
#define METABLOCK_SIZE sizeof(meta_data_block_)
#define BIN_SIZE 16
#define NUMBER_OF_BINS_PER_PAGE SYSTEM_PAGE_SIZE/(BIN_SIZE+METABLOCK_SIZE)
#define NUM_OF_CLASSES 17
#define CLASS_4      0
#define CLASS_8      1
#define CLASS_16     2
#define CLASS_24     3
#define CLASS_32     4
#define CLASS_40     5
#define CLASS_48     6
#define CLASS_56     7
#define CLASS_64     8
#define CLASS_72     9
#define CLASS_80     10
#define CLASS_88     11
#define CLASS_96     12
#define CLASS_104    13
#define CLASS_112    14
#define CLASS_120    15
#define CLASS_128    16

#define CLASS4_SIZE      4
#define CLASS8_SIZE      8
#define CLASS16_SIZE     16
#define CLASS24_SIZE     24
#define CLASS32_SIZE     32
#define CLASS40_SIZE     40
#define CLASS48_SIZE     48
#define CLASS56_SIZE     56
#define CLASS64_SIZE     64
#define CLASS72_SIZE     72
#define CLASS80_SIZE     80
#define CLASS88_SIZE     88
#define CLASS96_SIZE     96
#define CLASS104_SIZE    104
#define CLASS112_SIZE    112
#define CLASS120_SIZE    120
#define CLASS128_SIZE    128


typedef struct meta_data_block_ {

    int isFree;
    uint32_t blockSize;
    struct meta_data_block_ *prevBlock;
    struct meta_data_block_ *nextBlock;
    uint32_t offset;
}meta_data_block_;

typedef meta_data_block_ * meta_data_block;


typedef struct data_block_ {

    struct data_block_ *next;
    struct data_block_ *prev;
    char *data;
    meta_data_block metaData;
}data_block_;

typedef data_block_ * data_block;

// typedef struct page_list{

//     meta_data_block head;
//     struct page_list_ *next;
//     struct page_list_ *prev;

// }page_list;

typedef struct page_list {

    meta_data_block *head;
    uint32_t availableSize;
}page_list;

// void mm_init(data_block *d1);
int isPageEmpty(meta_data_block head);
void * getPages(int units);
void freePages(void* vm_page,int units);
void mmInit();
void initPageList();
void* Malloc(uint32_t size);
void createBinsList(meta_data_block *head);
int splitBins(meta_data_block m1,int size);
int mergeBins(meta_data_block m1);
meta_data_block getFreeBlock(meta_data_block *head);
void Free(void *ptr);
void createSizeClassBinsList(meta_data_block *head,int binSize);
void initSizeClassList();
// void freeDatablock(data_block d1);
// void pageInit(data_block *d1);
static data_block d1;
static page_list pageList[MAX_PAGES];
static size_t SYSTEM_PAGE_SIZE;
static int pageCount=0;
static int currentFreePage=0;
static page_list sizeClassList[NUM_OF_CLASSES][MAX_PAGES];


#endif