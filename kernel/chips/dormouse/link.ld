/*
 * Copyright 2024 Mosaic SoC Ltd. All rights reserved.
 * Authors: Luca Rufer, luca@mosaic-soc.com
 */

OUTPUT_ARCH(riscv)
ENTRY( _start )

/* Instruction Memory (IMEM) starts at BASE_ADDR + ADDR_RANGE - IMEM_SIZE
   and is allowed to overflow into L2. */

MEMORY
{
  L1       (rw)  : ORIGIN = 0x04000000, LENGTH = 0x4000
  DMEM     (rw)  : ORIGIN = 0x0C000000, LENGTH = 0x4000
  IMEM     (rwx) : ORIGIN = 0x0FFFC000, LENGTH = 0x1004000
  L2       (rwx) : ORIGIN = 0x10000000, LENGTH = 0x1000000
}

SECTIONS
{

  __stack_size = DEFINED(__stack_size) ? __stack_size : 0x800;

  .bss (NOLOAD) : {
    . = ALIGN(8);
    _bss_start = .;
    *(.bss)
    *(.bss.*)
    *(.sbss)
    *(.sbss.*)
    *(.shbss)
    *(.shbss.*)
    *(COMMON)
    . = ALIGN(4);
    _bss_end = .;
  } > L1

  .vectors :
  {
    . = ALIGN(256);
    __irq_vector_base = .;
    KEEP(*(.vectors))
  } > IMEM

  .init :
  {
    . = ALIGN(4);
    KEEP( *(.init) )
  } > IMEM


  .fini :
  {
    . = ALIGN(4);
    KEEP( *(.fini) )
  } > IMEM


  .preinit_array : {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } > IMEM


  .init_array : {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__init_array_start = .);
    __CTOR_LIST__ = .;
    LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2)
    KEEP(*(.ctors.start))
    KEEP(*(.ctors))
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array ))
    LONG(0)
    __CTOR_END__ = .;
    PROVIDE_HIDDEN (__init_array_end = .);
  } > IMEM


  .fini_array : {
    . = ALIGN(4);
    PROVIDE_HIDDEN (__fini_array_start = .);
    __DTOR_LIST__ = .;
    LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2)
    KEEP(*(.dtors.start))
    KEEP(*(.dtors))
    LONG(0)
    __DTOR_END__ = .;
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array ))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } > IMEM

  .boot : {
    . = ALIGN(4);
    *(.boot)
    *(.boot.data)
  } > IMEM

  .text :
  {
    . = ALIGN(4);
    _stext = .;
    *(.text)
    *(.text.*)
    _etext  =  .;
    *(.lit)
    *(.shdata)
    _endtext = .;
    . = ALIGN(4);
  } > IMEM


  .rodata : {
    . = ALIGN(4);
    *(.rodata);
    *(.rodata.*)
    *(.srodata);
    *(.srodata.*)
    *(.eh_frame*)
  } > IMEM


  .got : {
    . = ALIGN(4);
    *(.got.plt) * (.igot.plt) *(.got) *(.igot)
  } > IMEM

  .talias : {
  } > L1

  .gnu.offload_funcs : {
    . = ALIGN(4);
    KEEP(*(.gnu.offload_funcs))
  } > IMEM

  .gnu.offload_vars : {
    . = ALIGN(4);
    KEEP(*(.gnu.offload_vars))
  } > IMEM

  _sidata = LOADADDR(.data);

  .data : {
    . = ALIGN(4);
    sdata  =  .;
    _sdata  =  .;
    *(.data_fc)
    *(.data_fc.*)
    *(.data);
    *(.data.*)
    *(.sdata);
    *(.sdata.*)
    *(.heapl2ram)
    *(.fcTcdm)
    *(.fcTcdm.*)
    *(.fcTcdm_g)
    *(.fcTcdm_g.*)
    . = ALIGN(4);
    edata  =  .;
    _edata  =  .;
  } > L1 AT > IMEM

  /* Stack goes into the L1 last */

  .stack (NOLOAD) : {
    . = ORIGIN(L1) + LENGTH(L1) - __stack_size;
    stack_start = .;
    . += __stack_size;
    stack = .;
  } > L1

  /*
   * L2 SHARED MEMORY
   */

  /* Place the location counter . to the last item put into L1 */
  .imem_end : { . = ALIGN(4); } > IMEM

  __l2_priv0_end = ALIGN(4);
  __l2_priv1_end = ALIGN(4);

  /* As IMem is allowed to overflow into L2, start L2 at the location counter */
  .l2_data MAX(ORIGIN(L2), .) :
  {
    . = ALIGN(4);
    *(.l2_data)
    *(.l2_data.*)
    *(.data_fc_shared)
    *(.data_fc_shared.*)
    . = ALIGN(4);
  } > L2

  __l2_shared_end = ALIGN(4);

}
