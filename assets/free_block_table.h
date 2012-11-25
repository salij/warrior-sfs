#define BLOCK_FREE 1
#define BLOCK_USED 0

int set_free(int block_num);//set the block indexed by block_num to free
int set_used(int block_num);//set the block indexed by block_num to used
int find_free(int size);//size in blocks
