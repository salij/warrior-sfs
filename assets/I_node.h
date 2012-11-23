typedef struct
{
	char * iName;
	char * iType;
	char * iFileSize;
	char * iBlockSpan;
	char * iNodeBlockNumber;
	char * iParent;
	char * iChild;
} inode;

extern int get_empty_block(int * free_block_no);

extern int release_block(int release_block_no);
