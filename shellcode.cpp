unsigned char shellcode[] =
{
	0x00, //(when rax executed it will be 0x1)
	0x51, //push rcx (real entry)
	0x50, //push rax
	0x48, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //movabs rcx, 0x0 (base)
	0xBA, 0x01, 0x00, 0x00, 0x00, //mov edx, 0x1 (DLL_PROCESS_ATTACH)
	0x48, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //movabs rax, 0x0 (entrypoint)
	0x48, 0x83, 0xEC, 0x28, //sub rsp, 0x28
	0xFF, 0xD0, //call rax
	0xC6, 0x05, 0xD7, 0xFF, 0xFF, 0xFF, 0x01, //mov BYTE PTR [rip+0xffffffffffffffd7], 0x1
	0x48, 0x83, 0xC4, 0x28, //add rsp, 0x28
	0x58, //pop rax
	0x59, //pop rcx
	0xC3 //ret
};
