/*
 * Module paths and setup messages referenced at fixed offsets by the PS2
 * startup routines (00418B50, 00418B80, 00418C70).
 */
typedef struct {
    char adx_module_path[0x20];
    char setup_host_message[0x20];
    char setup_dvd_message[0x20];
    char iop_root_path[0x10];
    char setup_dvd_cache_message[0x20];
    char file_list_name[0x10];
    char mcman_module_path[0x20];
    char mcserv_module_path[0x20];
} Mvc2BootResources;
Mvc2BootResources gMvc2BootResources_004BEE60 = {
    "cdrom0:\\MODULES\\CRI_ADXI.IRX;1",
    "Setup HOST file system.\n",
    "Setup CD/DVD file system.\n",
    "\\ps2",
    "Setup CD/DVD cache system.\n",
    "0flist.dir",
    "cdrom0:\\MODULES\\MCMAN.IRX;1",
    "cdrom0:\\MODULES\\MCSERV.IRX;1",
};
