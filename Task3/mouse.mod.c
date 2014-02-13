#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x4a3dbd89, "module_layout" },
	{ 0x254481bc, "noop_llseek" },
	{ 0x6d044c26, "param_ops_uint" },
	{ 0x50484c0, "misc_register" },
	{ 0x211becee, "input_register_handler" },
	{ 0xcd0f61a2, "input_unregister_handler" },
	{ 0xabeebddb, "misc_deregister" },
	{ 0xa7a9c297, "device_del" },
	{ 0x7d11c268, "jiffies" },
	{ 0x3c02f8f2, "send_sig_info" },
	{ 0x737e0e35, "pid_task" },
	{ 0xfb089838, "find_vpid" },
	{ 0x49ebacbd, "_clear_bit" },
	{ 0x676bbc0f, "_set_bit" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x80d2c285, "input_class" },
	{ 0x415396c5, "input_unregister_handle" },
	{ 0x63d54ed7, "device_add" },
	{ 0xab183808, "input_register_handle" },
	{ 0x9e617688, "device_initialize" },
	{ 0x679e1ffe, "dev_set_name" },
	{ 0x275ef902, "__init_waitqueue_head" },
	{ 0xdd8bdd76, "__mutex_init" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0x9d669763, "memcpy" },
	{ 0x1cfb04fa, "finish_wait" },
	{ 0x1000e51, "schedule" },
	{ 0x499cb58c, "prepare_to_wait" },
	{ 0x5f754e5a, "memset" },
	{ 0x3507a132, "_raw_spin_lock_irq" },
	{ 0x28118cb6, "__get_user_1" },
	{ 0xd85cd67e, "__wake_up" },
	{ 0x7b0e61ba, "kill_fasync" },
	{ 0x27e1a049, "printk" },
	{ 0xe3cc56ec, "kmalloc_caches" },
	{ 0x8dd2508a, "kmem_cache_alloc_trace" },
	{ 0x3525065c, "get_device" },
	{ 0x86b327ae, "input_open_device" },
	{ 0xb6da1d6a, "mutex_lock_interruptible" },
	{ 0x81e46031, "mutex_unlock" },
	{ 0xf342554f, "input_close_device" },
	{ 0xb55642f1, "mutex_lock" },
	{ 0xc2cdbf1, "synchronize_sched" },
	{ 0x9c0bd51f, "_raw_spin_lock" },
	{ 0x37a0cba, "kfree" },
	{ 0xdd6ba4aa, "put_device" },
	{ 0xd54c9b8d, "fasync_helper" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("input:b*v*p*e*-e*1,*2,*k*110,*r*0,*1,*a*m*l*s*f*w*");
MODULE_ALIAS("input:b*v*p*e*-e*1,*2,*k*r*8,*a*m*l*s*f*w*");
MODULE_ALIAS("input:b*v*p*e*-e*1,*3,*k*14A,*r*a*0,*1,*m*l*s*f*w*");
MODULE_ALIAS("input:b*v*p*e*-e*1,*3,*k*145,*r*a*0,*1,*18,*1C,*m*l*s*f*w*");
MODULE_ALIAS("input:b*v*p*e*-e*1,*3,*k*110,*r*a*0,*1,*m*l*s*f*w*");

MODULE_INFO(srcversion, "72AD00AE702585CBE1FBD97");
