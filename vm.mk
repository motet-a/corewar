##
## vm.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Thu Mar  3 10:29:22 2016 antoine
## Last update Sun Mar 27 22:28:13 2016 Valentin Pichard
##

VM_SOURCES_NAMES	= \
			usage.c \
			option_extend.c \
			option.c \
			vm_initialize.c \
			vm_free.c \
			vm_create_process.c \
			vm_kill_process.c \
			vm_load_program.c \
			vm_instr_read_int.c \
			vm_instr_write_int.c \
			vm_instr_ld.c \
			vm_instr_st.c \
			vm_instr_add_sub.c \
			vm_instr_and_or_xor.c \
			vm_instr_zjmp.c \
			vm_instr_aff.c \
			vm_edit_value_carry.c \
			vm_cycle.c \
			vm_parsing.c \

VM_SOURCES		= $(foreach file,$(VM_SOURCES_NAMES), \
			corewar/$(file))

VM_OBJECTS		= $(VM_SOURCES:.c=.o)
