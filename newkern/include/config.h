#define ARCH_I386
//4MB
#define CONFIG_KERNEL_INITIAL_SIZE		(0x400000)

#define CONFIG_PROCESS_MAX_NAME_LENGTH	((size_t)128)
#define CONFIG_SYSTEM_PROCESS_NAME		("system task")
#define CONFIG_MASKABLE_SIGNAL_BITMAP   (0xFFFFF7FF)
#define CONFIG_MAX_SYSCALL_COUNT		(128)
#define CONFIG_FILE_MAX_NAME_LENGTH		((size_t)128)
#define CONFIG_PIPE_BUFFER_SIZE			(4096)
#define CONFIG_MAX_PATH_RECURSION		(32)

#define CONFIG_MAX_ARGV_LEN				(4096)
#define CONFIG_MAX_ENV_LEN				(4096)

#define CONFIG_TTY_BUFFER				(4096)

#undef CONFIG_ATA_DEBUG		
#define CONFIG_INODE_CACHE_SIZE			(4096)
#define CONFIG_INODE_CACHE_TABLESIZE	(128)
#undef	HAVE_LIBGCC			

#ifdef ARCH_I386
#define CONFIG_FASTCRT
#endif

#undef CONFIG_DEBUG_ATAGS

#define CONFIG_SYSCALL_DEBUG

#define CONFIG_SERIAL_DEBUGGER_TRIG

#undef CONFIG_i386_NO_PCI

#define CONFIG_SYSV_MSG_SIZE_LIMIT	(65536)

#define CONFIG_EVDEV_QUEUE_SIZE		(128)
