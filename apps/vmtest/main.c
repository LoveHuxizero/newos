/* 
** Copyright 2001, Travis Geiselbrecht. All rights reserved.
** Distributed under the terms of the NewOS License.
*/
#include <types.h>
#include <libc/string.h>
#include <libc/printf.h>
#include <libsys/syscalls.h>
#include <libsys/stdio.h>

int main()
{
	int fd;
	size_t len;
	char c;
	int rc = 0;

	printf("VM test\n");

	printf("my thread id is %d\n", sys_get_current_thread_id());
#if 1
	printf("doing some region tests\n");
	{
		region_id region;
		region_id region2;
		vm_region_info info;
		void *ptr, *ptr2;
		
		region = sys_vm_create_anonymous_region("foo", &ptr, REGION_ADDR_ANY_ADDRESS,
			16*4096, REGION_WIRING_LAZY, LOCK_RW);
		printf("region = 0x%x @ 0x%x\n", region, (unsigned int)ptr);
		region2 = sys_vm_clone_region("foo2", &ptr2, REGION_ADDR_ANY_ADDRESS,
			region, LOCK_RW);
		printf("region2 = 0x%x @ 0x%x\n", region2, (unsigned int)ptr2);
		
		sys_vm_get_region_info(region, &info);
		printf("info.base = 0x%x info.size = 0x%x\n", (unsigned int)info.base, (unsigned int)info.size);
		
		sys_vm_delete_region(region);
		sys_vm_delete_region(region2);
		printf("deleting both regions\n");
	}
#endif

	printf("vmtest: exiting w/return code %d\n", rc);
	return rc;
}

