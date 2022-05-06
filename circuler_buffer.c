#define BUFFER_SIZE     8    // max size of buffer
#define TRUE            1
#define FALSE           0

int buffer_length = 0;      // number for data in buffer
int rd_index = 0;
int wr_index = 0;
int buffer[BUFFER_SIZE];   // array to store data;

int is_buffer_full(void)
{
	if(buffer_length == BUFFER_SIZE)
	{
		return TRUE;
	}
	return FALSE;
}

int is_buffer_empty(void)
{
	if(buffer_length == 0)
	{
		return TRUE;
	}
	return FALSE;
}

void write_buffer(int data)
{
	if(is_buffer_full())
	{
	   return;
	}
	buffer[wr_index] = data;
	wr_index++;
	buffer_length++;
	if(wr_index == BUFFER_SIZE)
	{
		wr_index = 0;
	}
}

void read_buffer(void)
{
	if(is_buffer_empty())
	{
	    return;
	}
	printf("%d",buffer[rd_index])
	buffer_length--;
	rd_index++;
	if(rd_index == BUFFER_SIZE)
	{
		rd_index = 0;
	}
}

