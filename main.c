/*
 * main.c
 *
 *  Created on: 2020-4-10
 *      Author: lpk
 */
#include "stdio.h"
#include "util/lpk_util.h"
#include "util/lpk_type.h"
#include "slip/slip.h"

int main()
{
    // u8 data_in[512] = {0x23, 0x56, 0xdb, 0x55, 0xc0, 0x65, 0xaa, 0xdb, 0x55, 0xc0};
    u8 data_in[512] = {0xc0,	0x23,	0x56,	0xdb,	0xdd,	0x55,	0xdb,	0xdc,	0x65,	0xaa,	0xdb,	0xdd,	0x55,	0xdb,	0xdc,	0xc0};	
    u8 data_out[512] = {0};

    int i = 0;
    int size_out = 0;
    u8 *tmp = data_in;

    // size_out = SlipPacket(data_in, 10, data_out);//数据封包
    
    tmp = SlipUnpacket(data_in, 20, data_out, &size_out);

    printf("unpacket data size is %d \r\n", tmp - data_in);

    for(i = 0; i < size_out; i++){
        printf("%#.2x,\t", data_out[i]);
    }

    printf("\r\n");

    return 0;
}
