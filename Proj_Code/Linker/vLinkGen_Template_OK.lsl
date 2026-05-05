architecture TC
{
        endianness
        {
                little;
        }

        space linear
        {
                id = 1;
                mau = 8;
                map (src_offset=0x00000000, dest_offset=0x00000000, size=4G,      dest=bus:fpi_bus);
        }
        space abs24
        {
                id = 2;
                mau = 8;
                map (src_offset=0x00000000, dest_offset=0x00000000, size=2M, dest=space:linear);
                map (src_offset=0x10000000, dest_offset=0x10000000, size=2M, dest=space:linear);
                map (src_offset=0x20000000, dest_offset=0x20000000, size=2M, dest=space:linear);
                map (src_offset=0x30000000, dest_offset=0x30000000, size=2M, dest=space:linear);
                map (src_offset=0x40000000, dest_offset=0x40000000, size=2M, dest=space:linear);
                map (src_offset=0x50000000, dest_offset=0x50000000, size=2M, dest=space:linear);
                map (src_offset=0x60000000, dest_offset=0x60000000, size=2M, dest=space:linear);
                map (src_offset=0x70000000, dest_offset=0x70000000, size=2M, dest=space:linear);
                map (src_offset=0x80000000, dest_offset=0x80000000, size=2M, dest=space:linear);
                map (src_offset=0x90000000, dest_offset=0x90000000, size=2M, dest=space:linear);
                map (src_offset=0xa0000000, dest_offset=0xa0000000, size=2M, dest=space:linear);
                map (src_offset=0xb0000000, dest_offset=0xb0000000, size=2M, dest=space:linear);
                map (src_offset=0xc0000000, dest_offset=0xc0000000, size=2M, dest=space:linear);
                map (src_offset=0xd0000000, dest_offset=0xd0000000, size=2M, dest=space:linear);
                map (src_offset=0xe0000000, dest_offset=0xe0000000, size=2M, dest=space:linear);
                map (src_offset=0xf0000000, dest_offset=0xf0000000, size=2M, dest=space:linear);
        }
        space abs18
        {
                id = 3;
                mau = 8;
                map (src_offset=0x00000000, dest_offset=0x00000000, size=16k, dest=space:linear);
                map (src_offset=0x10000000, dest_offset=0x10000000, size=16k, dest=space:linear);
                map (src_offset=0x20000000, dest_offset=0x20000000, size=16k, dest=space:linear);
                map (src_offset=0x30000000, dest_offset=0x30000000, size=16k, dest=space:linear);
                map (src_offset=0x40000000, dest_offset=0x40000000, size=16k, dest=space:linear);
                map (src_offset=0x50000000, dest_offset=0x50000000, size=16k, dest=space:linear);
                map (src_offset=0x60000000, dest_offset=0x60000000, size=16k, dest=space:linear);
                map (src_offset=0x70000000, dest_offset=0x70000000, size=16k, dest=space:linear);
                map (src_offset=0x80000000, dest_offset=0x80000000, size=16k, dest=space:linear);
                map (src_offset=0x90000000, dest_offset=0x90000000, size=16k, dest=space:linear);
                map (src_offset=0xa0000000, dest_offset=0xa0000000, size=16k, dest=space:linear);
                map (src_offset=0xb0000000, dest_offset=0xb0000000, size=16k, dest=space:linear);
                map (src_offset=0xc0000000, dest_offset=0xc0000000, size=16k, dest=space:linear);
                map (src_offset=0xd0000000, dest_offset=0xd0000000, size=16k, dest=space:linear);
                map (src_offset=0xe0000000, dest_offset=0xe0000000, size=16k, dest=space:linear);
                map (src_offset=0xf0000000, dest_offset=0xf0000000, size=16k, dest=space:linear);
        }
        space csa
        {
                id = 4;
                mau = 8;

                //
                // CSA area should be mapped on dsprn
                map (src_offset=0xd0000000, dest_offset=0xd0000000, size=4M, dest=space:linear);
        }
        bus fpi_bus
        {
                mau = 8;
                width = 32;
        }
}

architecture TC1V1.6.X extends TC
{
}

processor mpe
{
        derivative = tc27x;
}

#define DF_EEPROM_SIZE     384k
#define DF_UCB_SIZE            16k
#define DF_EEPROM_ADDR    0xaf000000
#define DF_UCB_ADDR          0xaf100000  

derivative tc27x
{
        core tc0
        {
                architecture = TC1V1.6.X;
                space_id_offset = 100;  // add 100 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }
        core tc1
        {
                architecture = TC1V1.6.X;
                space_id_offset = 200;  // add 100 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }
        core tc2
        {
                architecture = TC1V1.6.X;
                space_id_offset = 300;  // add 100 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core vtc
        {
                architecture = TC1V1.6.X;
                import tc0;                      // add all address spaces of core tc0 to core vtc for linking and locating
                import tc1;                      // add all address spaces of core tc0 to core vtc for linking and locating
                import tc2;                      // add all address spaces of core tc0 to core vtc for linking and locating
        }


        bus sri
        {
                mau = 8;
                width = 32;

                // map shared addresses one-to-one to real cores and virtual cores
                map (dest=bus:tc0:fpi_bus, src_offset=0, dest_offset=0, size=0x50000000 + 0*0x10000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0, dest_offset=0, size=0x50000000 + 0*0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0, dest_offset=0, size=0x50000000 + 0*0x10000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0, dest_offset=0, size=0x50000000 + 0*0x10000000);

                // map shared addresses one-to-one to real cores and virtual cores
                map (dest=bus:tc0:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);

                // map shared addresses one-to-one to real cores and virtual
                map (dest=bus:tc0:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                
                // map local memory
                map (dest=bus:tc0:fpi_bus, src_offset=0x70000000, dest_offset=0x70000000, size=0x00100000, priority=1, exec_priority=0);
                map (dest=bus:tc1:fpi_bus, src_offset=0x60000000, dest_offset=0x60000000, size=0x00100000, priority=1, exec_priority=0);
                map (dest=bus:tc2:fpi_bus, src_offset=0x50000000, dest_offset=0x50000000, size=0x00100000, priority=1, exec_priority=0);
                map (dest=bus:tc0:fpi_bus, src_offset=0x70100000, dest_offset=0x70100000, size=0x10000000-0x00100000, exec_priority=1);
                map (dest=bus:tc1:fpi_bus, src_offset=0x60100000, dest_offset=0x60100000, size=0x10000000-0x00100000, exec_priority=1);
                map (dest=bus:tc2:fpi_bus, src_offset=0x50100000, dest_offset=0x50100000, size=0x10000000-0x00100000, exec_priority=1);
                map (dest=bus:vtc:fpi_bus, src_offset=0x50000000 + 0*0x10000000, dest_offset=0x50000000 + 0*0x10000000, size=3*0x10000000);
                map (dest=bus:tc0:fpi_bus, src_offset=0x60000000, dest_offset=0x60000000, size=0x10000000);
                map (dest=bus:tc0:fpi_bus, src_offset=0x50000000, dest_offset=0x50000000, size=0x10000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x70000000, dest_offset=0x70000000, size=0x10000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x50000000, dest_offset=0x50000000, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x70000000, dest_offset=0x70000000, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x60000000, dest_offset=0x60000000, size=0x10000000);
        }

       section_setup :vtc:linear
        {
                copytable
                (
                        align = 4,
                        dest = linear,
                        table
                        {
                                symbol = "_lc_ub_table";
                                space = :tc0:linear,:tc0:abs18;
                        }
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc1";
                                space = :tc1:linear,:tc1:abs18;
                        }
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc2";
                                space = :tc2:linear, :tc2:abs18;
                        }
                );
               start_address
               (
                   run_addr = (0xA0000020),
                   symbol = "brsStartupEntry"
               );
        }

      memory dspr0 // Data Scratch Pad Ram
        {
                mau = 8;
                size = 112k;
                type = ram;
                map (dest=bus:tc0:fpi_bus, dest_offset=0xd0000000, size=112k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x70000000, size=112k);
        }

        memory pspr0 // Program Scratch Pad Ram
        {
                mau = 8;
                size = 24k;
                type = ram;
                map (dest=bus:tc0:fpi_bus, dest_offset=0xc0000000, size=24k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x70100000, size=24k);
        }

        memory dspr1 // Data Scratch Pad Ram
        {
                mau = 8;
                size = 120k;
                type = ram;
                map (dest=bus:tc1:fpi_bus, dest_offset=0xd0000000, size=120k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x60000000, size=120k);
        }

        memory pspr1 // Program Scratch Pad Ram
        {
                mau = 8;
                size = 32k;
                type = ram;
                map (dest=bus:tc1:fpi_bus, dest_offset=0xc0000000, size=32k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x60100000, size=32k);
        }

        memory dspr2 // Data Scratch Pad Ram
        {
                mau = 8;
                size = 120k;
                type = ram;
                map (dest=bus:tc2:fpi_bus, dest_offset=0xd0000000, size=120k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x50000000, size=120k);
        }

        memory pspr2 // Program Scratch Pad Ram
        {
                mau = 8;
                size = 32k;
                type = ram;
                map (dest=bus:tc2:fpi_bus, dest_offset=0xc0000000, size=32k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x50100000, size=32k);
        }

        memory pflash0
        {
                mau = 8;
                size = 2M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80000000,           size=2M);
                map not_cached (dest=bus:sri, dest_offset=0xa0000000, reserved, size=2M);
        }

        memory pflash1
        {
                mau = 8;
                size = 2M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80200000,           size=2M);
                map not_cached (dest=bus:sri, dest_offset=0xa0200000, reserved, size=2M);
        }

        memory brom
        {
                mau = 8;
                size = 32k;
                type = reserved rom;
                map     cached (dest=bus:sri, dest_offset=0x8fff8000,           size=32k);
                map not_cached (dest=bus:sri, dest_offset=0xafff8000, reserved, size=32k);
        }

        memory dflash0
        {
                mau = 8;
                size = DF_EEPROM_SIZE + DF_UCB_SIZE;
                type = reserved nvram;
                map (dest=bus:sri, src_offset=0, dest_offset=DF_EEPROM_ADDR, size=DF_EEPROM_SIZE);
                map (dest=bus:sri, src_offset=DF_EEPROM_SIZE, dest_offset=DF_UCB_ADDR, size=DF_UCB_SIZE);
        }

        memory dflash1
        {
                mau = 8;
                size = 64k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xaf110000, size=64k);
        }

        memory lmuram
        {
                mau = 8;
                size = 32k;
                type = ram;
                priority = 2;
                map     cached (dest=bus:sri, dest_offset=0x90000000,           size=32k);
                map not_cached (dest=bus:sri, dest_offset=0xb0000000, reserved, size=32k);
        }
}



#ifndef INTTAB
#define INTTAB          0xa00f0000              /* start address of interrupt table */
#endif
#ifndef TRAPTAB
#define TRAPTAB         (INTTAB + 0x6000)      /* start address of trap table */
#endif

#ifndef TRAPTAB0
#define TRAPTAB0        (TRAPTAB)
#endif

#ifndef TRAPTAB1
#define TRAPTAB1        (TRAPTAB0 + 0x100)
#endif
#ifndef TRAPTAB2
#define TRAPTAB2        (TRAPTAB1 + 0x100)
#endif

section_layout :vtc:linear
{

  "_lc_u_trap_tab_tc0" = (TRAPTAB0);
  "_lc_u_trap_tab_tc1" = (TRAPTAB1);
  "_lc_u_trap_tab_tc2" = (TRAPTAB2);
  "_lc_u_trap_tab" = "_lc_u_trap_tab_tc0"; /* common cstart interface for first or single core */

  // trapvector tables
  group trap_tab_tc0 (ordered)
  {
      #include "traptab0.lsl"
  }
  group trap_tab_tc1 (ordered)
  {
      #include "traptab1.lsl"           
  }
  group trap_tab_tc2 (ordered)
  {
      #include "traptab2.lsl"           
  }
 }

#ifndef CSA_START_TC0
#define CSA_START_TC0   0xd0004000              /* start address of CSA tc0 */
#endif

#ifndef CSA_START_TC1
#define CSA_START_TC1   0xd0004000              /* start address of CSA tc1 */
#endif

#ifndef CSA_START_TC2
#define CSA_START_TC2   0xd0004000              /* start address of CSA tc2 */
#endif

#ifndef CSA_TC0
#define CSA_TC0         64                      /* number of context blocks tc0 */
#endif

#ifndef CSA_TC1
#define CSA_TC1         64                      /* number of context blocks tc1 */
#endif

#ifndef CSA_TC2
#define CSA_TC2         64                      /* number of context blocks tc2 */
#endif

#ifndef INTTAB0
#define INTTAB0         (INTTAB)
#endif
#ifndef INTTAB1
#define INTTAB1         (INTTAB0 + 0x2000)
#endif
#ifndef INTTAB2
#define INTTAB2         (INTTAB1 + 0x2000)
#endif
section_layout :vtc:linear
{
   "_lc_u_int_tab_tc0" = (INTTAB0);
   "_lc_u_int_tab_tc1" = (INTTAB1);
   "_lc_u_int_tab_tc2" = (INTTAB2);
   "_lc_u_int_tab" = "_lc_u_int_tab_tc0"; /* common cstart interface for first or single core */

  // interrupt vector tables
  group int_tab_tc0 (ordered)
  {
      #include "inttab0.lsl"
  }
  group int_tab_tc1 (ordered)
  {
      #include "inttab1.lsl"
  }
  group int_tab_tc2 (ordered)
  {
      #include "inttab2.lsl"
  }
}

section_layout :tc0:csa
{
        group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC0)) 
                reserved "csa_tc0" (size = 64 * (CSA_TC0));
        "_lc_ub_csa_01" := "_lc_ub_csa_tc0"; /* common cstart interface for first or single core */
        "_lc_ue_csa_01" := "_lc_ue_csa_tc0"; /* common cstart interface for first or single core */
}

section_layout :tc1:csa
{
        group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC1)) 
                reserved "csa_tc1" (size = 64 * (CSA_TC1));
}

section_layout :tc2:csa
{
        group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC2)) 
                reserved "csa_tc2" (size = 64 * (CSA_TC2));
}

section_layout :tc0:linear
{
                "_lc_ue_ustack" := "_lc_ue_ustack_tc0"; /* common cstart interface for first or single core */
                "_lc_ue_istack" := "_lc_ue_istack_tc0"; /* common cstart interface for first or single core */
}

section_layout mpe:vtc:linear
{
  /* RegionBlock_0_BMHD0 (32 Byte) */
  group RegionBlock_0_BMHD0(ordered, run_addr = 0xA0000000)
  {
    group BMHD0(ordered, contiguous, fill, align=32)
    {
      select ".rodata.BMHD0";
    }
    "_BMHD0_START" = "_lc_gb_BMHD0";
    "_BMHD0_END" = ("_lc_ge_BMHD0" == 0) ? 0 : "_lc_ge_BMHD0" - 1;
    "_BMHD0_LIMIT" = "_lc_ge_BMHD0";

  }
  "_RegionBlock_0_BMHD0_START" = "_lc_gb_RegionBlock_0_BMHD0";
  "_RegionBlock_0_BMHD0_END" = ("_lc_ge_RegionBlock_0_BMHD0" == 0) ? 0 : "_lc_ge_RegionBlock_0_BMHD0" - 1;
  "_RegionBlock_0_BMHD0_LIMIT" = "_lc_ge_RegionBlock_0_BMHD0";

/* RegionBlock_0_BMHD1 (32 Byte) */
  group RegionBlock_0_BMHD1(ordered, run_addr = 0xA0020000)
  {
    group BMHD1(ordered, contiguous, fill, align=32)
    {
      select ".rodata.BMHD1";
    }
    "_BMHD1_START" = "_lc_gb_BMHD1";
    "_BMHD1_END" = ("_lc_ge_BMHD1" == 0) ? 0 : "_lc_ge_BMHD1" - 1;
    "_BMHD1_LIMIT" = "_lc_ge_BMHD1";

  }
  "_RegionBlock_0_BMHD1_START" = "_lc_gb_RegionBlock_0_BMHD1";
  "_RegionBlock_0_BMHD1_END" = ("_lc_ge_RegionBlock_0_BMHD1" == 0) ? 0 : "_lc_ge_RegionBlock_0_BMHD1" - 1;
  "_RegionBlock_0_BMHD1_LIMIT" = "_lc_ge_RegionBlock_0_BMHD1";

/* RegionBlock_0_BMHD2 (32 Byte) */
  group RegionBlock_0_BMHD2(ordered, run_addr = 0xA000FFE0)
  {
    group BMHD2(ordered, contiguous, fill, align=32)
    {
      select ".rodata.BMHD2";
    }
    "_BMHD2_START" = "_lc_gb_BMHD2";
    "_BMHD2_END" = ("_lc_ge_BMHD2" == 0) ? 0 : "_lc_ge_BMHD2" - 1;
    "_BMHD2_LIMIT" = "_lc_ge_BMHD2";

  }
  "_RegionBlock_0_BMHD2_START" = "_lc_gb_RegionBlock_0_BMHD2";
  "_RegionBlock_0_BMHD2_END" = ("_lc_ge_RegionBlock_0_BMHD2" == 0) ? 0 : "_lc_ge_RegionBlock_0_BMHD2" - 1;
  "_RegionBlock_0_BMHD2_LIMIT" = "_lc_ge_RegionBlock_0_BMHD2";

/* RegionBlock_0_BMHD3 (32 Byte) */
  group RegionBlock_0_BMHD3(ordered, run_addr = 0xA001FFE0)
  {
    group BMHD3(ordered, contiguous, fill, align=32)
    {
      select ".rodata.BMHD3";
    }
    "_BMHD3_START" = "_lc_gb_BMHD3";
    "_BMHD3_END" = ("_lc_ge_BMHD3" == 0) ? 0 : "_lc_ge_BMHD3" - 1;
    "_BMHD3_LIMIT" = "_lc_ge_BMHD3";

  }
  "_RegionBlock_0_BMHD3_START" = "_lc_gb_RegionBlock_0_BMHD3";
  "_RegionBlock_0_BMHD3_END" = ("_lc_ge_RegionBlock_0_BMHD3" == 0) ? 0 : "_lc_ge_RegionBlock_0_BMHD3" - 1;
  "_RegionBlock_0_BMHD3_LIMIT" = "_lc_ge_RegionBlock_0_BMHD3";
}

section_layout mpe:vtc:linear
{
  /* RegionBlock_0_DSPR_Core2 (120 KiB) */
  group RegionBlock_0_DSPR_Core2(ordered, run_addr = 0x50000000)
  {
    group OS_DATA_CORE2_NOINIT(ordered, contiguous, fill, align=4)
    {
      section "OS_CORE2_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORE2_VAR_NOCACHE_NOINIT";
      }
      section "OS_CORE2_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORE2_VAR_NOINIT";
      }
      section "OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_SystemApplication_OsCore2_VAR_NOCACHE_NOINIT";
      }
      section "OS_SystemApplication_OsCore2_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_SystemApplication_OsCore2_VAR_NOINIT";
      }
    }
    "_OS_DATA_CORE2_NOINIT_START" = "_lc_gb_OS_DATA_CORE2_NOINIT";
    "_OS_DATA_CORE2_NOINIT_END" = ("_lc_ge_OS_DATA_CORE2_NOINIT" == 0) ? 0 : "_lc_ge_OS_DATA_CORE2_NOINIT" - 1;
    "_OS_DATA_CORE2_NOINIT_LIMIT" = "_lc_ge_OS_DATA_CORE2_NOINIT";

    "_OS_DATA_CORE2_VAR_ALL_START" = "_OS_DATA_CORE2_NOINIT_START";
    "_OS_DATA_CORE2_VAR_ALL_END" = "_OS_DATA_CORE2_NOINIT_END";
    "_OS_DATA_CORE2_VAR_ALL_LIMIT" = "_OS_DATA_CORE2_NOINIT_LIMIT";

    group OS_STACKS_CORE2_NOINIT(ordered, contiguous, fill, align=4)
    {
      select "[.]bss.OS_STACK_OSCORE2_ERROR_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE2_INIT_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE2_ISR_CORE_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE2_KERNEL_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSTASK_APP10MS_CORE2_VAR_NOINIT";
    }
    "_OS_STACKS_CORE2_NOINIT_START" = "_lc_gb_OS_STACKS_CORE2_NOINIT";
    "_OS_STACKS_CORE2_NOINIT_END" = ("_lc_ge_OS_STACKS_CORE2_NOINIT" == 0) ? 0 : "_lc_ge_OS_STACKS_CORE2_NOINIT" - 1;
    "_OS_STACKS_CORE2_NOINIT_LIMIT" = "_lc_ge_OS_STACKS_CORE2_NOINIT";

    "_OS_STACKS_CORE2_VAR_ALL_START" = "_OS_STACKS_CORE2_NOINIT_START";
    "_OS_STACKS_CORE2_VAR_ALL_END" = "_OS_STACKS_CORE2_NOINIT_END";
    "_OS_STACKS_CORE2_VAR_ALL_LIMIT" = "_OS_STACKS_CORE2_NOINIT_LIMIT";

    group istack_tc2(ordered, contiguous, fill, align=4)
    {
      reserved "istack_tc2" (size = 1024);
    }
    "_istack_tc2_START" = "_lc_gb_istack_tc2";
    "_istack_tc2_END" = ("_lc_ge_istack_tc2" == 0) ? 0 : "_lc_ge_istack_tc2" - 1;
    "_istack_tc2_LIMIT" = "_lc_ge_istack_tc2";
    reserved ".pad.istack_tc2" (size=32);

    group istack_tc2_ZERO_INIT(ordered, contiguous, fill, align=4)
    {
      select "[.]data.istack_tc2_ZERO_INIT";
    }
    "_istack_tc2_ZERO_INIT_START" = "_lc_gb_istack_tc2_ZERO_INIT";
    "_istack_tc2_ZERO_INIT_END" = ("_lc_ge_istack_tc2_ZERO_INIT" == 0) ? 0 : "_lc_ge_istack_tc2_ZERO_INIT" - 1;
    "_istack_tc2_ZERO_INIT_LIMIT" = "_lc_ge_istack_tc2_ZERO_INIT";
    reserved ".pad.istack_tc2_ZERO_INIT" (size=32);

    "_istack_tc2_VAR_ALL_START" = "_istack_tc2_START";
    "_istack_tc2_VAR_ALL_END" = "_istack_tc2_ZERO_INIT_END";
    "_istack_tc2_VAR_ALL_LIMIT" = "_istack_tc2_ZERO_INIT_LIMIT";

    group ustack_tc2(ordered, contiguous, fill, align=4)
    {
      reserved "ustack_tc2" (size = 1024);
    }
    "_ustack_tc2_START" = "_lc_gb_ustack_tc2";
    "_ustack_tc2_END" = ("_lc_ge_ustack_tc2" == 0) ? 0 : "_lc_ge_ustack_tc2" - 1;
    "_ustack_tc2_LIMIT" = "_lc_ge_ustack_tc2";
    reserved ".pad.ustack_tc2" (size=32);

    group ustack_tc2_ZERO_INIT(ordered, contiguous, fill, align=4)
    {
      select "[.]data.ustack_tc2_ZERO_INIT";
    }
    "_ustack_tc2_ZERO_INIT_START" = "_lc_gb_ustack_tc2_ZERO_INIT";
    "_ustack_tc2_ZERO_INIT_END" = ("_lc_ge_ustack_tc2_ZERO_INIT" == 0) ? 0 : "_lc_ge_ustack_tc2_ZERO_INIT" - 1;
    "_ustack_tc2_ZERO_INIT_LIMIT" = "_lc_ge_ustack_tc2_ZERO_INIT";
    reserved ".pad.ustack_tc2_ZERO_INIT" (size=32);

    "_ustack_tc2_VAR_ALL_START" = "_ustack_tc2_START";
    "_ustack_tc2_VAR_ALL_END" = "_ustack_tc2_ZERO_INIT_END";
    "_ustack_tc2_VAR_ALL_LIMIT" = "_ustack_tc2_ZERO_INIT_LIMIT";

    group Bss_Default_Core2(ordered, contiguous, fill, align=8)
    {
      
    }
    "_Bss_Default_Core2_START" = "_lc_gb_Bss_Default_Core2";
    "_Bss_Default_Core2_END" = ("_lc_ge_Bss_Default_Core2" == 0) ? 0 : "_lc_ge_Bss_Default_Core2" - 1;
    "_Bss_Default_Core2_LIMIT" = "_lc_ge_Bss_Default_Core2";

    "_Bss_Default_Core2_VAR_ALL_START" = "_Bss_Default_Core2_START";
    "_Bss_Default_Core2_VAR_ALL_END" = "_Bss_Default_Core2_END";
    "_Bss_Default_Core2_VAR_ALL_LIMIT" = "_Bss_Default_Core2_LIMIT";

  }
  "_RegionBlock_0_DSPR_Core2_START" = "_lc_gb_RegionBlock_0_DSPR_Core2";
  "_RegionBlock_0_DSPR_Core2_END" = ("_lc_ge_RegionBlock_0_DSPR_Core2" == 0) ? 0 : "_lc_ge_RegionBlock_0_DSPR_Core2" - 1;
  "_RegionBlock_0_DSPR_Core2_LIMIT" = "_lc_ge_RegionBlock_0_DSPR_Core2";

  /* RegionBlock_0_PSPR_Core2 (8 KiB) */
  group RegionBlock_0_PSPR_Core2(ordered, run_addr = 0x50100000)
  {
  }
  "_RegionBlock_0_PSPR_Core2_START" = "_lc_gb_RegionBlock_0_PSPR_Core2";
  "_RegionBlock_0_PSPR_Core2_END" = ("_lc_ge_RegionBlock_0_PSPR_Core2" == 0) ? 0 : "_lc_ge_RegionBlock_0_PSPR_Core2" - 1;
  "_RegionBlock_0_PSPR_Core2_LIMIT" = "_lc_ge_RegionBlock_0_PSPR_Core2";

  /* RegionBlock_0_DSPR_Core1 (120 KiB) */
  group RegionBlock_0_DSPR_Core1(ordered, run_addr = 0x60000000)
  {
    group OS_DATA_CORE1_NOINIT(ordered, contiguous, fill, align=4)
    {
      section "OS_CORE1_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORE1_VAR_NOCACHE_NOINIT";
      }
      section "OS_CORE1_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORE1_VAR_NOINIT";
      }
      section "OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_SystemApplication_OsCore1_VAR_NOCACHE_NOINIT";
      }
      section "OS_SystemApplication_OsCore1_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_SystemApplication_OsCore1_VAR_NOINIT";
      }
    }
    "_OS_DATA_CORE1_NOINIT_START" = "_lc_gb_OS_DATA_CORE1_NOINIT";
    "_OS_DATA_CORE1_NOINIT_END" = ("_lc_ge_OS_DATA_CORE1_NOINIT" == 0) ? 0 : "_lc_ge_OS_DATA_CORE1_NOINIT" - 1;
    "_OS_DATA_CORE1_NOINIT_LIMIT" = "_lc_ge_OS_DATA_CORE1_NOINIT";

    "_OS_DATA_CORE1_VAR_ALL_START" = "_OS_DATA_CORE1_NOINIT_START";
    "_OS_DATA_CORE1_VAR_ALL_END" = "_OS_DATA_CORE1_NOINIT_END";
    "_OS_DATA_CORE1_VAR_ALL_LIMIT" = "_OS_DATA_CORE1_NOINIT_LIMIT";

    group OS_STACKS_CORE1_NOINIT(ordered, contiguous, fill, align=4)
    {
      select "[.]bss.OS_STACK_OSCORE1_ERROR_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE1_INIT_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE1_ISR_CORE_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE1_KERNEL_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSTASK_APP10MS_CORE1_VAR_NOINIT";
    }
    "_OS_STACKS_CORE1_NOINIT_START" = "_lc_gb_OS_STACKS_CORE1_NOINIT";
    "_OS_STACKS_CORE1_NOINIT_END" = ("_lc_ge_OS_STACKS_CORE1_NOINIT" == 0) ? 0 : "_lc_ge_OS_STACKS_CORE1_NOINIT" - 1;
    "_OS_STACKS_CORE1_NOINIT_LIMIT" = "_lc_ge_OS_STACKS_CORE1_NOINIT";

    "_OS_STACKS_CORE1_VAR_ALL_START" = "_OS_STACKS_CORE1_NOINIT_START";
    "_OS_STACKS_CORE1_VAR_ALL_END" = "_OS_STACKS_CORE1_NOINIT_END";
    "_OS_STACKS_CORE1_VAR_ALL_LIMIT" = "_OS_STACKS_CORE1_NOINIT_LIMIT";

    group istack_tc1(ordered, contiguous, fill, align=4)
    {
      reserved "istack_tc1" (size = 1024);
    }
    "_istack_tc1_START" = "_lc_gb_istack_tc1";
    "_istack_tc1_END" = ("_lc_ge_istack_tc1" == 0) ? 0 : "_lc_ge_istack_tc1" - 1;
    "_istack_tc1_LIMIT" = "_lc_ge_istack_tc1";
    reserved ".pad.istack_tc1" (size=32);

    group istack_tc1_ZERO_INIT(ordered, contiguous, fill, align=4)
    {
      select "[.]data.istack_tc1_ZERO_INIT";
    }
    "_istack_tc1_ZERO_INIT_START" = "_lc_gb_istack_tc1_ZERO_INIT";
    "_istack_tc1_ZERO_INIT_END" = ("_lc_ge_istack_tc1_ZERO_INIT" == 0) ? 0 : "_lc_ge_istack_tc1_ZERO_INIT" - 1;
    "_istack_tc1_ZERO_INIT_LIMIT" = "_lc_ge_istack_tc1_ZERO_INIT";
    reserved ".pad.istack_tc1_ZERO_INIT" (size=32);

    "_istack_tc1_VAR_ALL_START" = "_istack_tc1_START";
    "_istack_tc1_VAR_ALL_END" = "_istack_tc1_ZERO_INIT_END";
    "_istack_tc1_VAR_ALL_LIMIT" = "_istack_tc1_ZERO_INIT_LIMIT";

    group ustack_tc1(ordered, contiguous, fill, align=4)
    {
      reserved "ustack_tc1" (size = 1024);
    }
    "_ustack_tc1_START" = "_lc_gb_ustack_tc1";
    "_ustack_tc1_END" = ("_lc_ge_ustack_tc1" == 0) ? 0 : "_lc_ge_ustack_tc1" - 1;
    "_ustack_tc1_LIMIT" = "_lc_ge_ustack_tc1";
    reserved ".pad.ustack_tc1" (size=32);

    group ustack_tc1_ZERO_INIT(ordered, contiguous, fill, align=4)
    {
      select "[.]data.ustack_tc1_ZERO_INIT";
    }
    "_ustack_tc1_ZERO_INIT_START" = "_lc_gb_ustack_tc1_ZERO_INIT";
    "_ustack_tc1_ZERO_INIT_END" = ("_lc_ge_ustack_tc1_ZERO_INIT" == 0) ? 0 : "_lc_ge_ustack_tc1_ZERO_INIT" - 1;
    "_ustack_tc1_ZERO_INIT_LIMIT" = "_lc_ge_ustack_tc1_ZERO_INIT";
    reserved ".pad.ustack_tc1_ZERO_INIT" (size=32);

    "_ustack_tc1_VAR_ALL_START" = "_ustack_tc1_START";
    "_ustack_tc1_VAR_ALL_END" = "_ustack_tc1_ZERO_INIT_END";
    "_ustack_tc1_VAR_ALL_LIMIT" = "_ustack_tc1_ZERO_INIT_LIMIT";

    group Bss_Default_Core1(ordered, contiguous, fill, align=8)
    {
      
    }
    "_Bss_Default_Core1_START" = "_lc_gb_Bss_Default_Core1";
    "_Bss_Default_Core1_END" = ("_lc_ge_Bss_Default_Core1" == 0) ? 0 : "_lc_ge_Bss_Default_Core1" - 1;
    "_Bss_Default_Core1_LIMIT" = "_lc_ge_Bss_Default_Core1";

    "_Bss_Default_Core1_VAR_ALL_START" = "_Bss_Default_Core1_START";
    "_Bss_Default_Core1_VAR_ALL_END" = "_Bss_Default_Core1_END";
    "_Bss_Default_Core1_VAR_ALL_LIMIT" = "_Bss_Default_Core1_LIMIT";

  }
  "_RegionBlock_0_DSPR_Core1_START" = "_lc_gb_RegionBlock_0_DSPR_Core1";
  "_RegionBlock_0_DSPR_Core1_END" = ("_lc_ge_RegionBlock_0_DSPR_Core1" == 0) ? 0 : "_lc_ge_RegionBlock_0_DSPR_Core1" - 1;
  "_RegionBlock_0_DSPR_Core1_LIMIT" = "_lc_ge_RegionBlock_0_DSPR_Core1";

  /* RegionBlock_0_PSPR_Core1 (8 KiB) */
  group RegionBlock_0_PSPR_Core1(ordered, run_addr = 0x60100000)
  {
  }
  "_RegionBlock_0_PSPR_Core1_START" = "_lc_gb_RegionBlock_0_PSPR_Core1";
  "_RegionBlock_0_PSPR_Core1_END" = ("_lc_ge_RegionBlock_0_PSPR_Core1" == 0) ? 0 : "_lc_ge_RegionBlock_0_PSPR_Core1" - 1;
  "_RegionBlock_0_PSPR_Core1_LIMIT" = "_lc_ge_RegionBlock_0_PSPR_Core1";

  /* RegionBlock_0_DSPR_Core0 (112 KiB) */
  group RegionBlock_0_DSPR_Core0(ordered, run_addr = 0x70000000)
  {
    group OS_DATA_CORE0_NOINIT(ordered, contiguous, fill, align=4)
    {
      section "OS_CORE0_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORE0_VAR_NOCACHE_NOINIT";
      }
      section "OS_CORE0_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORE0_VAR_NOINIT";
      }
      section "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT";
      }
      section "OS_SystemApplication_OsCore0_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_SystemApplication_OsCore0_VAR_NOINIT";
      }
    }
    "_OS_DATA_CORE0_NOINIT_START" = "_lc_gb_OS_DATA_CORE0_NOINIT";
    "_OS_DATA_CORE0_NOINIT_END" = ("_lc_ge_OS_DATA_CORE0_NOINIT" == 0) ? 0 : "_lc_ge_OS_DATA_CORE0_NOINIT" - 1;
    "_OS_DATA_CORE0_NOINIT_LIMIT" = "_lc_ge_OS_DATA_CORE0_NOINIT";

    "_OS_DATA_CORE0_VAR_ALL_START" = "_OS_DATA_CORE0_NOINIT_START";
    "_OS_DATA_CORE0_VAR_ALL_END" = "_OS_DATA_CORE0_NOINIT_END";
    "_OS_DATA_CORE0_VAR_ALL_LIMIT" = "_OS_DATA_CORE0_NOINIT_LIMIT";

    group OS_DATA_SHARED_NOINIT(ordered, contiguous, fill, align=4)
    {
      section "OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
      }
      section "OS_BARRIER_CORE0_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_BARRIER_CORE0_VAR_NOINIT";
      }
      section "OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT";
      }
      section "OS_BARRIER_CORE1_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_BARRIER_CORE1_VAR_NOINIT";
      }
      section "OS_BARRIER_CORE2_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_BARRIER_CORE2_VAR_NOCACHE_NOINIT";
      }
      section "OS_BARRIER_CORE2_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_BARRIER_CORE2_VAR_NOINIT";
      }
      section "OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
      }
      section "OS_CORESTATUS_CORE0_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORESTATUS_CORE0_VAR_NOINIT";
      }
      section "OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT";
      }
      section "OS_CORESTATUS_CORE1_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORESTATUS_CORE1_VAR_NOINIT";
      }
      section "OS_CORESTATUS_CORE2_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORESTATUS_CORE2_VAR_NOCACHE_NOINIT";
      }
      section "OS_CORESTATUS_CORE2_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_CORESTATUS_CORE2_VAR_NOINIT";
      }
      section "OS_GLOBALSHARED_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_GLOBALSHARED_VAR_NOCACHE_NOINIT";
      }
      section "OS_GLOBALSHARED_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_GLOBALSHARED_VAR_NOINIT";
      }
      section "OS_PUBLIC_CORE0_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_PUBLIC_CORE0_VAR_NOCACHE_NOINIT";
      }
      section "OS_PUBLIC_CORE0_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_PUBLIC_CORE0_VAR_NOINIT";
      }
      section "OS_PUBLIC_CORE1_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_PUBLIC_CORE1_VAR_NOCACHE_NOINIT";
      }
      section "OS_PUBLIC_CORE1_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_PUBLIC_CORE1_VAR_NOINIT";
      }
      section "OS_PUBLIC_CORE2_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_PUBLIC_CORE2_VAR_NOCACHE_NOINIT";
      }
      section "OS_PUBLIC_CORE2_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_PUBLIC_CORE2_VAR_NOINIT";
      }
      section "OS_VAR_NOCACHE_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_VAR_NOCACHE_NOINIT";
      }
      section "OS_VAR_NOINIT" (blocksize=2, attributes=rw)
      {
        select "[.]bss.OS_VAR_NOINIT";
      }
    }
    "_OS_DATA_SHARED_NOINIT_START" = "_lc_gb_OS_DATA_SHARED_NOINIT";
    "_OS_DATA_SHARED_NOINIT_END" = ("_lc_ge_OS_DATA_SHARED_NOINIT" == 0) ? 0 : "_lc_ge_OS_DATA_SHARED_NOINIT" - 1;
    "_OS_DATA_SHARED_NOINIT_LIMIT" = "_lc_ge_OS_DATA_SHARED_NOINIT";

    group OS_DATA_SHARED_INIT(ordered, contiguous, fill, copy, align=4)
    {
      section "OS_BARRIER_CORE0_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE0_VAR";
      }
      section "OS_BARRIER_CORE0_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE0_VAR_NOCACHE";
      }
      section "OS_BARRIER_CORE1_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE1_VAR";
      }
      section "OS_BARRIER_CORE1_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE1_VAR_NOCACHE";
      }
      section "OS_BARRIER_CORE2_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE2_VAR";
      }
      section "OS_BARRIER_CORE2_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE2_VAR_NOCACHE";
      }
      section "OS_CORESTATUS_CORE0_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE0_VAR";
      }
      section "OS_CORESTATUS_CORE0_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE0_VAR_NOCACHE";
      }
      section "OS_CORESTATUS_CORE1_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE1_VAR";
      }
      section "OS_CORESTATUS_CORE1_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE1_VAR_NOCACHE";
      }
      section "OS_CORESTATUS_CORE2_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE2_VAR";
      }
      section "OS_CORESTATUS_CORE2_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE2_VAR_NOCACHE";
      }
      section "OS_GLOBALSHARED_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_GLOBALSHARED_VAR";
      }
      section "OS_GLOBALSHARED_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_GLOBALSHARED_VAR_NOCACHE";
      }
      section "OS_PUBLIC_CORE0_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE0_VAR";
      }
      section "OS_PUBLIC_CORE0_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE0_VAR_NOCACHE";
      }
      section "OS_PUBLIC_CORE1_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE1_VAR";
      }
      section "OS_PUBLIC_CORE1_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE1_VAR_NOCACHE";
      }
      section "OS_PUBLIC_CORE2_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE2_VAR";
      }
      section "OS_PUBLIC_CORE2_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE2_VAR_NOCACHE";
      }
      section "OS_VAR" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_VAR";
      }
      section "OS_VAR_NOCACHE" (blocksize=8, fill=0, attributes=rw)
      {
        select "[.]data.OS_VAR_NOCACHE";
      }
    }
    "_OS_DATA_SHARED_INIT_START" = "_lc_gb_OS_DATA_SHARED_INIT";
    "_OS_DATA_SHARED_INIT_END" = ("_lc_ge_OS_DATA_SHARED_INIT" == 0) ? 0 : "_lc_ge_OS_DATA_SHARED_INIT" - 1;
    "_OS_DATA_SHARED_INIT_LIMIT" = "_lc_ge_OS_DATA_SHARED_INIT";

    group OS_DATA_SHARED_ZERO_INIT(ordered, contiguous, fill, align=4)
    {
      section "OS_BARRIER_CORE0_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE0_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_BARRIER_CORE0_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE0_VAR_ZERO_INIT";
      }
      section "OS_BARRIER_CORE1_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE1_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_BARRIER_CORE1_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE1_VAR_ZERO_INIT";
      }
      section "OS_BARRIER_CORE2_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE2_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_BARRIER_CORE2_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_BARRIER_CORE2_VAR_ZERO_INIT";
      }
      section "OS_CORESTATUS_CORE0_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE0_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_CORESTATUS_CORE0_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE0_VAR_ZERO_INIT";
      }
      section "OS_CORESTATUS_CORE1_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE1_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_CORESTATUS_CORE1_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE1_VAR_ZERO_INIT";
      }
      section "OS_CORESTATUS_CORE2_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE2_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_CORESTATUS_CORE2_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_CORESTATUS_CORE2_VAR_ZERO_INIT";
      }
      section "OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_GLOBALSHARED_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_GLOBALSHARED_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_GLOBALSHARED_VAR_ZERO_INIT";
      }
      section "OS_PUBLIC_CORE0_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE0_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_PUBLIC_CORE0_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE0_VAR_ZERO_INIT";
      }
      section "OS_PUBLIC_CORE1_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE1_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_PUBLIC_CORE1_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE1_VAR_ZERO_INIT";
      }
      section "OS_PUBLIC_CORE2_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE2_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_PUBLIC_CORE2_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_PUBLIC_CORE2_VAR_ZERO_INIT";
      }
      section "OS_VAR_NOCACHE_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_VAR_NOCACHE_ZERO_INIT";
      }
      section "OS_VAR_ZERO_INIT" (blocksize=2, attributes=rw)
      {
        select "[.]data.OS_VAR_ZERO_INIT";
      }
    }
    "_OS_DATA_SHARED_ZERO_INIT_START" = "_lc_gb_OS_DATA_SHARED_ZERO_INIT";
    "_OS_DATA_SHARED_ZERO_INIT_END" = ("_lc_ge_OS_DATA_SHARED_ZERO_INIT" == 0) ? 0 : "_lc_ge_OS_DATA_SHARED_ZERO_INIT" - 1;
    "_OS_DATA_SHARED_ZERO_INIT_LIMIT" = "_lc_ge_OS_DATA_SHARED_ZERO_INIT";

    "_OS_DATA_SHARED_VAR_ALL_START" = "_OS_DATA_SHARED_NOINIT_START";
    "_OS_DATA_SHARED_VAR_ALL_END" = "_OS_DATA_SHARED_ZERO_INIT_END";
    "_OS_DATA_SHARED_VAR_ALL_LIMIT" = "_OS_DATA_SHARED_ZERO_INIT_LIMIT";

    group OS_STACKS_CORE0_NOINIT(ordered, contiguous, fill, align=4)
    {
      select "[.]bss.OS_STACK_OSCORE0_ERROR_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE0_INIT_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE0_ISR_CORE_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE0_KERNEL_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO30_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSTASK_APP10MS_CORE0_VAR_NOINIT";
      select "[.]bss.OS_STACK_OSTASK_BSW5MS_CORE0_VAR_NOINIT";
    }
    "_OS_STACKS_CORE0_NOINIT_START" = "_lc_gb_OS_STACKS_CORE0_NOINIT";
    "_OS_STACKS_CORE0_NOINIT_END" = ("_lc_ge_OS_STACKS_CORE0_NOINIT" == 0) ? 0 : "_lc_ge_OS_STACKS_CORE0_NOINIT" - 1;
    "_OS_STACKS_CORE0_NOINIT_LIMIT" = "_lc_ge_OS_STACKS_CORE0_NOINIT";

    "_OS_STACKS_CORE0_VAR_ALL_START" = "_OS_STACKS_CORE0_NOINIT_START";
    "_OS_STACKS_CORE0_VAR_ALL_END" = "_OS_STACKS_CORE0_NOINIT_END";
    "_OS_STACKS_CORE0_VAR_ALL_LIMIT" = "_OS_STACKS_CORE0_NOINIT_LIMIT";

    group csa_tc0(ordered, contiguous, fill, align=64)
    {
      reserved "csa_tc0" (size = 64 * 64);
    }
    "_csa_tc0_START" = "_lc_gb_csa_tc0";
    "_csa_tc0_END" = ("_lc_ge_csa_tc0" == 0) ? 0 : "_lc_ge_csa_tc0" - 1;
    "_csa_tc0_LIMIT" = "_lc_ge_csa_tc0";

    "_csa_tc0_VAR_ALL_START" = "_csa_tc0_START";
    "_csa_tc0_VAR_ALL_END" = "_csa_tc0_END";
    "_csa_tc0_VAR_ALL_LIMIT" = "_csa_tc0_LIMIT";

    group istack_tc0(ordered, contiguous, fill, align=4)
    {
      reserved "istack_tc0" (size = 1024);
    }
    "_istack_tc0_START" = "_lc_gb_istack_tc0";
    "_istack_tc0_END" = ("_lc_ge_istack_tc0" == 0) ? 0 : "_lc_ge_istack_tc0" - 1;
    "_istack_tc0_LIMIT" = "_lc_ge_istack_tc0";
    reserved ".pad.istack_tc0" (size=32);

    group istack_tc0_ZERO_INIT(ordered, contiguous, fill, align=4)
    {
      select "[.]data.istack_tc0_ZERO_INIT";
    }
    "_istack_tc0_ZERO_INIT_START" = "_lc_gb_istack_tc0_ZERO_INIT";
    "_istack_tc0_ZERO_INIT_END" = ("_lc_ge_istack_tc0_ZERO_INIT" == 0) ? 0 : "_lc_ge_istack_tc0_ZERO_INIT" - 1;
    "_istack_tc0_ZERO_INIT_LIMIT" = "_lc_ge_istack_tc0_ZERO_INIT";
    reserved ".pad.istack_tc0_ZERO_INIT" (size=32);

    "_istack_tc0_VAR_ALL_START" = "_istack_tc0_START";
    "_istack_tc0_VAR_ALL_END" = "_istack_tc0_ZERO_INIT_END";
    "_istack_tc0_VAR_ALL_LIMIT" = "_istack_tc0_ZERO_INIT_LIMIT";

    group ustack_tc0(ordered, contiguous, fill, align=4)
    {
      reserved "ustack_tc0" (size = 0x4000);
    }
    "_ustack_tc0_START" = "_lc_gb_ustack_tc0";
    "_ustack_tc0_END" = ("_lc_ge_ustack_tc0" == 0) ? 0 : "_lc_ge_ustack_tc0" - 1;
    "_ustack_tc0_LIMIT" = "_lc_ge_ustack_tc0";
    reserved ".pad.ustack_tc0" (size=32);

    group ustack_tc0_ZERO_INIT(ordered, contiguous, fill, align=4)
    {
      select "[.]data.ustack_tc0_ZERO_INIT";
    }
    "_ustack_tc0_ZERO_INIT_START" = "_lc_gb_ustack_tc0_ZERO_INIT";
    "_ustack_tc0_ZERO_INIT_END" = ("_lc_ge_ustack_tc0_ZERO_INIT" == 0) ? 0 : "_lc_ge_ustack_tc0_ZERO_INIT" - 1;
    "_ustack_tc0_ZERO_INIT_LIMIT" = "_lc_ge_ustack_tc0_ZERO_INIT";
    reserved ".pad.ustack_tc0_ZERO_INIT" (size=32);

    "_ustack_tc0_VAR_ALL_START" = "_ustack_tc0_START";
    "_ustack_tc0_VAR_ALL_END" = "_ustack_tc0_ZERO_INIT_END";
    "_ustack_tc0_VAR_ALL_LIMIT" = "_ustack_tc0_ZERO_INIT_LIMIT";

    group Bss_Default(ordered, contiguous, fill, align=8)
    {
          select "[.]bss.*";
    select "[.]zbss.*";
    select ".bss.CPU0.Private*";
    select ".bss.CPU0_DSPR_RAM_NOINIT";  
    }
    "_Bss_Default_START" = "_lc_gb_Bss_Default";
    "_Bss_Default_END" = ("_lc_ge_Bss_Default" == 0) ? 0 : "_lc_ge_Bss_Default" - 1;
    "_Bss_Default_LIMIT" = "_lc_ge_Bss_Default";

    "_Bss_Default_VAR_ALL_START" = "_Bss_Default_START";
    "_Bss_Default_VAR_ALL_END" = "_Bss_Default_END";
    "_Bss_Default_VAR_ALL_LIMIT" = "_Bss_Default_LIMIT";



    group Data_Default_INIT(ordered, contiguous, fill, align=4)
    {
     // section "data" (blocksize=8, fill=0, attributes=rw)
     // {
          select "[.]data.Can.canConfigInitFlag";
          select "[.]data.Mcu.Mcu_kConfigPtr";
          select "[.]data.Mcal_TcLib.Mcal_IntDisableCounterRedn";
          select "[.]data.Mcal_TcLib.Mcal_IntDisableCounter";          
          select "[.]data.Mcal_TcLib.Mcal_SavedIntStateRedn";            
          select "[.]data.Mcal_TcLib.Mcal_SavedIntState";                 
          select "[.]data.Mcal_WdgLib.Mcal_ResetEndInitCounterRedn";   
          select "[.]data.Mcal_WdgLib.Mcal_ResetEndInitCounter";         
          select "[.]data.Mcal_WdgLib.Mcal_SafetyResetEndInitCounterRedn";
          select "[.]data.Mcal_WdgLib.Mcal_SafetyResetEndInitCounter";  
          select "[.]data.Mcal_WdgLib.Mcal_WdgSafetyEndInitSemRedn";     
          select "[.]data.Mcal_WdgLib.Mcal_WdgSafetyEndInitSem";          
          select "[.]data.Mcu.Mcu_ResetStatusVal";                       
          select "[.]data.CanNm_Cfg.CanNm_ModuleInitialized";           
          select "[.]data.CanSM.CanSM_IsInitialized";                    
          select "[.]data.ComM.ComM_InitStatus";                      
          select "[.]data.Com_Lcfg.Com_Initialized";                     
          select "[.]data.Det.detModuleInit";                            
          select "[.]data.Nm.Nm_Initialized";  
          select "[.]data.PduR_Lcfg.PduR_Initialized"; 
   
        
     // }
    }
    "_Data_Default_INIT_START" = "_lc_gb_Data_Default_INIT";
    "_Data_Default_INIT_END" = ("_lc_ge_Data_Default_INIT" == 0) ? 0 : "_lc_ge_Data_Default_INIT" - 1;
    "_Data_Default_INIT_LIMIT" = "_lc_ge_Data_Default_INIT";

    "_Data_Default_VAR_ALL_START" = "_Data_Default_START";
    "_Data_Default_VAR_ALL_END" = "_Data_Default_INIT_END";
    "_Data_Default_VAR_ALL_LIMIT" = "_Data_Default_INIT_LIMIT";

    group Data_Default(ordered, contiguous, fill, align=4)
    {
      select "[.]data.*";
      select "[.]zdata.*";
    }
    "_Data_Default_START" = "_lc_gb_Data_Default";
    "_Data_Default_END" = ("_lc_ge_Data_Default" == 0) ? 0 : "_lc_ge_Data_Default" - 1;
    "_Data_Default_LIMIT" = "_lc_ge_Data_Default";



  }
  "_RegionBlock_0_DSPR_Core0_START" = "_lc_gb_RegionBlock_0_DSPR_Core0";
  "_RegionBlock_0_DSPR_Core0_END" = ("_lc_ge_RegionBlock_0_DSPR_Core0" == 0) ? 0 : "_lc_ge_RegionBlock_0_DSPR_Core0" - 1;
  "_RegionBlock_0_DSPR_Core0_LIMIT" = "_lc_ge_RegionBlock_0_DSPR_Core0";

  /* RegionBlock_0_PSPR_Core0 (8 KiB) */
  group RegionBlock_0_PSPR_Core0(ordered, run_addr = 0x70100000)
  {
  }
  "_RegionBlock_0_PSPR_Core0_START" = "_lc_gb_RegionBlock_0_PSPR_Core0";
  "_RegionBlock_0_PSPR_Core0_END" = ("_lc_ge_RegionBlock_0_PSPR_Core0" == 0) ? 0 : "_lc_ge_RegionBlock_0_PSPR_Core0" - 1;
  "_RegionBlock_0_PSPR_Core0_LIMIT" = "_lc_ge_RegionBlock_0_PSPR_Core0";

  /* RegionBlock_0_PFlash0_Cached (2 MiB) */
  group RegionBlock_0_PFlash0_Cached(ordered, run_addr = 0x80006000)
  {
  }
  "_RegionBlock_0_PFlash0_Cached_START" = "_lc_gb_RegionBlock_0_PFlash0_Cached";
  "_RegionBlock_0_PFlash0_Cached_END" = ("_lc_ge_RegionBlock_0_PFlash0_Cached" == 0) ? 0 : "_lc_ge_RegionBlock_0_PFlash0_Cached" - 1;
  "_RegionBlock_0_PFlash0_Cached_LIMIT" = "_lc_ge_RegionBlock_0_PFlash0_Cached";

  /* RegionBlock_0_PFlash1_Cached (2 MiB) */
  group RegionBlock_0_PFlash1_Cached(ordered, run_addr = 0x80200000)
  {
  }
  "_RegionBlock_0_PFlash1_Cached_START" = "_lc_gb_RegionBlock_0_PFlash1_Cached";
  "_RegionBlock_0_PFlash1_Cached_END" = ("_lc_ge_RegionBlock_0_PFlash1_Cached" == 0) ? 0 : "_lc_ge_RegionBlock_0_PFlash1_Cached" - 1;
  "_RegionBlock_0_PFlash1_Cached_LIMIT" = "_lc_ge_RegionBlock_0_PFlash1_Cached";

  /* MemoryRegion_lmuram_Cahed (32 KiB) */
  group MemoryRegion_lmuram_Cahed(ordered, run_addr = 0x90000000)
  {
  }
  "_MemoryRegion_lmuram_Cahed_START" = "_lc_gb_MemoryRegion_lmuram_Cahed";
  "_MemoryRegion_lmuram_Cahed_END" = ("_lc_ge_MemoryRegion_lmuram_Cahed" == 0) ? 0 : "_lc_ge_MemoryRegion_lmuram_Cahed" - 1;
  "_MemoryRegion_lmuram_Cahed_LIMIT" = "_lc_ge_MemoryRegion_lmuram_Cahed";

  /* RegionBlock_BMHD0 (32 Byte) */
  group RegionBlock_BMHD0(ordered, run_addr = 0xA0000000)
  {
  }
  "_RegionBlock_BMHD0_START" = "_lc_gb_RegionBlock_BMHD0";
  "_RegionBlock_BMHD0_END" = ("_lc_ge_RegionBlock_BMHD0" == 0) ? 0 : "_lc_ge_RegionBlock_BMHD0" - 1;
  "_RegionBlock_BMHD0_LIMIT" = "_lc_ge_RegionBlock_BMHD0";

  /* RegionBlock_Startup (32 Byte) */
  group RegionBlock_Startup(ordered, run_addr = 0xA0000020)
  {
  }
  "_RegionBlock_Startup_START" = "_lc_gb_RegionBlock_Startup";
  "_RegionBlock_Startup_END" = ("_lc_ge_RegionBlock_Startup" == 0) ? 0 : "_lc_ge_RegionBlock_Startup" - 1;
  "_RegionBlock_Startup_LIMIT" = "_lc_ge_RegionBlock_Startup";

  /* RegionBlock_PFlash0_NonCached (2 MiB) */
  group RegionBlock_PFlash0_NonCached(ordered, run_addr = 0xA0006000)
  {
    group Code_Default(align=8)
    {
      select "[.]text.*";
select ".text.Shared*";
      select "[.]text.OS_ERRORHOOK_CODE";
    }
    "_Code_Default_START" = "_lc_gb_Code_Default";
    "_Code_Default_END" = ("_lc_ge_Code_Default" == 0) ? 0 : "_lc_ge_Code_Default" - 1;
    "_Code_Default_LIMIT" = "_lc_ge_Code_Default";

    group Const_Default(ordered, contiguous, fill, align=8)
    {
      select "[.]rodata.*";
select "[.]zrodata.*";

    }
    "_Const_Default_START" = "_lc_gb_Const_Default";
    "_Const_Default_END" = ("_lc_ge_Const_Default" == 0) ? 0 : "_lc_ge_Const_Default" - 1;
    "_Const_Default_LIMIT" = "_lc_ge_Const_Default";

    group OS_CODE(align=4)
    {
      select "[.]text.OS_CODE";
      select "[.]text.OS_OS_COREINITHOOK_CODE";
    }
    "_OS_CODE_START" = "_lc_gb_OS_CODE";
    "_OS_CODE_END" = ("_lc_ge_OS_CODE" == 0) ? 0 : "_lc_ge_OS_CODE" - 1;
    "_OS_CODE_LIMIT" = "_lc_ge_OS_CODE";

    group OS_CONST(ordered, contiguous, fill, align=4)
    {
      select "[.]rodata.OS_CONST";
      select "[.]zrodata.OS_CONST_FAST";
      select "[.]rodata.OS_CORE0_CONST";
      select "[.]zrodata.OS_CORE0_CONST_FAST";
      select "[.]rodata.OS_CORE1_CONST";
      select "[.]zrodata.OS_CORE1_CONST_FAST";
      select "[.]rodata.OS_CORE2_CONST";
      select "[.]zrodata.OS_CORE2_CONST_FAST";
      select "[.]rodata.OS_GLOBALSHARED_CONST";
      select "[.]zrodata.OS_GLOBALSHARED_CONST_FAST";
      select "[.]rodata.OS_INTVEC_CONST";
      select "[.]zrodata.OS_INTVEC_CONST_FAST";
      select "[.]rodata.OS_SystemApplication_OsCore0_CONST";
      select "[.]zrodata.OS_SystemApplication_OsCore0_CONST_FAST";
      select "[.]rodata.OS_SystemApplication_OsCore1_CONST";
      select "[.]zrodata.OS_SystemApplication_OsCore1_CONST_FAST";
      select "[.]rodata.OS_SystemApplication_OsCore2_CONST";
      select "[.]zrodata.OS_SystemApplication_OsCore2_CONST_FAST";
    }
    "_OS_CONST_START" = "_lc_gb_OS_CONST";
    "_OS_CONST_END" = ("_lc_ge_OS_CONST" == 0) ? 0 : "_lc_ge_OS_CONST" - 1;
    "_OS_CONST_LIMIT" = "_lc_ge_OS_CONST";

    group OS_EXCVEC_CORE0_CODE(align=32)
    {
      select "[.]text.OS_EXCVEC_CORE0_CODE";
    }
    "_OS_EXCVEC_CORE0_CODE_START" = "_lc_gb_OS_EXCVEC_CORE0_CODE";
    "_OS_EXCVEC_CORE0_CODE_END" = ("_lc_ge_OS_EXCVEC_CORE0_CODE" == 0) ? 0 : "_lc_ge_OS_EXCVEC_CORE0_CODE" - 1;
    "_OS_EXCVEC_CORE0_CODE_LIMIT" = "_lc_ge_OS_EXCVEC_CORE0_CODE";

    group OS_EXCVEC_CORE0_CONST(ordered, contiguous, fill, align=32)
    {
      select "[.]rodata.OS_EXCVEC_CORE0_CONST";
      select "[.]zrodata.OS_EXCVEC_CORE0_CONST_FAST";
    }
    "_OS_EXCVEC_CORE0_CONST_START" = "_lc_gb_OS_EXCVEC_CORE0_CONST";
    "_OS_EXCVEC_CORE0_CONST_END" = ("_lc_ge_OS_EXCVEC_CORE0_CONST" == 0) ? 0 : "_lc_ge_OS_EXCVEC_CORE0_CONST" - 1;
    "_OS_EXCVEC_CORE0_CONST_LIMIT" = "_lc_ge_OS_EXCVEC_CORE0_CONST";

    group OS_EXCVEC_CORE1_CODE(align=32)
    {
      select "[.]text.OS_EXCVEC_CORE1_CODE";
    }
    "_OS_EXCVEC_CORE1_CODE_START" = "_lc_gb_OS_EXCVEC_CORE1_CODE";
    "_OS_EXCVEC_CORE1_CODE_END" = ("_lc_ge_OS_EXCVEC_CORE1_CODE" == 0) ? 0 : "_lc_ge_OS_EXCVEC_CORE1_CODE" - 1;
    "_OS_EXCVEC_CORE1_CODE_LIMIT" = "_lc_ge_OS_EXCVEC_CORE1_CODE";

    group OS_EXCVEC_CORE1_CONST(ordered, contiguous, fill, align=32)
    {
      select "[.]rodata.OS_EXCVEC_CORE1_CONST";
      select "[.]zrodata.OS_EXCVEC_CORE1_CONST_FAST";
    }
    "_OS_EXCVEC_CORE1_CONST_START" = "_lc_gb_OS_EXCVEC_CORE1_CONST";
    "_OS_EXCVEC_CORE1_CONST_END" = ("_lc_ge_OS_EXCVEC_CORE1_CONST" == 0) ? 0 : "_lc_ge_OS_EXCVEC_CORE1_CONST" - 1;
    "_OS_EXCVEC_CORE1_CONST_LIMIT" = "_lc_ge_OS_EXCVEC_CORE1_CONST";

    group OS_EXCVEC_CORE2_CODE(align=32)
    {
      select "[.]text.OS_EXCVEC_CORE2_CODE";
    }
    "_OS_EXCVEC_CORE2_CODE_START" = "_lc_gb_OS_EXCVEC_CORE2_CODE";
    "_OS_EXCVEC_CORE2_CODE_END" = ("_lc_ge_OS_EXCVEC_CORE2_CODE" == 0) ? 0 : "_lc_ge_OS_EXCVEC_CORE2_CODE" - 1;
    "_OS_EXCVEC_CORE2_CODE_LIMIT" = "_lc_ge_OS_EXCVEC_CORE2_CODE";

    group OS_EXCVEC_CORE2_CONST(ordered, contiguous, fill, align=32)
    {
      select "[.]rodata.OS_EXCVEC_CORE2_CONST";
      select "[.]zrodata.OS_EXCVEC_CORE2_CONST_FAST";
    }
    "_OS_EXCVEC_CORE2_CONST_START" = "_lc_gb_OS_EXCVEC_CORE2_CONST";
    "_OS_EXCVEC_CORE2_CONST_END" = ("_lc_ge_OS_EXCVEC_CORE2_CONST" == 0) ? 0 : "_lc_ge_OS_EXCVEC_CORE2_CONST" - 1;
    "_OS_EXCVEC_CORE2_CONST_LIMIT" = "_lc_ge_OS_EXCVEC_CORE2_CONST";

    group OS_INTVEC_CODE(align=32)
    {
      select "[.]text.OS_INTVEC_CODE";
    }
    "_OS_INTVEC_CODE_START" = "_lc_gb_OS_INTVEC_CODE";
    "_OS_INTVEC_CODE_END" = ("_lc_ge_OS_INTVEC_CODE" == 0) ? 0 : "_lc_ge_OS_INTVEC_CODE" - 1;
    "_OS_INTVEC_CODE_LIMIT" = "_lc_ge_OS_INTVEC_CODE";

    group OS_INTVEC_CONST(align=8192)
    {
      reserved ".pad.OS_INTVEC_CONST" (size=0);
    }
    "_OS_INTVEC_CONST_START" = "_lc_gb_OS_INTVEC_CONST";
    "_OS_INTVEC_CONST_END" = ("_lc_ge_OS_INTVEC_CONST" == 0) ? 0 : "_lc_ge_OS_INTVEC_CONST" - 1;
    "_OS_INTVEC_CONST_LIMIT" = "_lc_ge_OS_INTVEC_CONST";

    group OS_INTVEC_CORE0_CODE(align=32)
    {
      select "[.]text.OS_INTVEC_CORE0_CODE";
    }
    "_OS_INTVEC_CORE0_CODE_START" = "_lc_gb_OS_INTVEC_CORE0_CODE";
    "_OS_INTVEC_CORE0_CODE_END" = ("_lc_ge_OS_INTVEC_CORE0_CODE" == 0) ? 0 : "_lc_ge_OS_INTVEC_CORE0_CODE" - 1;
    "_OS_INTVEC_CORE0_CODE_LIMIT" = "_lc_ge_OS_INTVEC_CORE0_CODE";

    group OS_INTVEC_CORE0_CONST(ordered, contiguous, fill, align=32)
    {
      select "[.]rodata.OS_INTVEC_CORE0_CONST";
      select "[.]zrodata.OS_INTVEC_CORE0_CONST_FAST";
    }
    "_OS_INTVEC_CORE0_CONST_START" = "_lc_gb_OS_INTVEC_CORE0_CONST";
    "_OS_INTVEC_CORE0_CONST_END" = ("_lc_ge_OS_INTVEC_CORE0_CONST" == 0) ? 0 : "_lc_ge_OS_INTVEC_CORE0_CONST" - 1;
    "_OS_INTVEC_CORE0_CONST_LIMIT" = "_lc_ge_OS_INTVEC_CORE0_CONST";

    group OS_INTVEC_CORE1_CODE(align=32)
    {
      select "[.]text.OS_INTVEC_CORE1_CODE";
    }
    "_OS_INTVEC_CORE1_CODE_START" = "_lc_gb_OS_INTVEC_CORE1_CODE";
    "_OS_INTVEC_CORE1_CODE_END" = ("_lc_ge_OS_INTVEC_CORE1_CODE" == 0) ? 0 : "_lc_ge_OS_INTVEC_CORE1_CODE" - 1;
    "_OS_INTVEC_CORE1_CODE_LIMIT" = "_lc_ge_OS_INTVEC_CORE1_CODE";

    group OS_INTVEC_CORE1_CONST(ordered, contiguous, fill, align=32)
    {
      select "[.]rodata.OS_INTVEC_CORE1_CONST";
      select "[.]zrodata.OS_INTVEC_CORE1_CONST_FAST";
    }
    "_OS_INTVEC_CORE1_CONST_START" = "_lc_gb_OS_INTVEC_CORE1_CONST";
    "_OS_INTVEC_CORE1_CONST_END" = ("_lc_ge_OS_INTVEC_CORE1_CONST" == 0) ? 0 : "_lc_ge_OS_INTVEC_CORE1_CONST" - 1;
    "_OS_INTVEC_CORE1_CONST_LIMIT" = "_lc_ge_OS_INTVEC_CORE1_CONST";

    group OS_INTVEC_CORE2_CODE(align=32)
    {
      select "[.]text.OS_INTVEC_CORE2_CODE";
    }
    "_OS_INTVEC_CORE2_CODE_START" = "_lc_gb_OS_INTVEC_CORE2_CODE";
    "_OS_INTVEC_CORE2_CODE_END" = ("_lc_ge_OS_INTVEC_CORE2_CODE" == 0) ? 0 : "_lc_ge_OS_INTVEC_CORE2_CODE" - 1;
    "_OS_INTVEC_CORE2_CODE_LIMIT" = "_lc_ge_OS_INTVEC_CORE2_CODE";

    group OS_INTVEC_CORE2_CONST(ordered, contiguous, fill, align=32)
    {
      select "[.]rodata.OS_INTVEC_CORE2_CONST";
      select "[.]zrodata.OS_INTVEC_CORE2_CONST_FAST";
    }
    "_OS_INTVEC_CORE2_CONST_START" = "_lc_gb_OS_INTVEC_CORE2_CONST";
    "_OS_INTVEC_CORE2_CONST_END" = ("_lc_ge_OS_INTVEC_CORE2_CONST" == 0) ? 0 : "_lc_ge_OS_INTVEC_CORE2_CONST" - 1;
    "_OS_INTVEC_CORE2_CONST_LIMIT" = "_lc_ge_OS_INTVEC_CORE2_CONST";

    group Startup_Code(ordered, contiguous, fill, align=8)
    {
      select ".text.brsStartup";


   "_RESET" = "brsStartupEntry";
   "_start" = "brsStartupEntry";
   "_start_tc0" = "brsStartupEntry";
   "_start_tc1" = "brsStartupEntry";
   "_start_tc2" = "brsStartupEntry";
   "_start_tc3" = "brsStartupEntry";
   "_start_tc4" = "brsStartupEntry";
   "_start_tc5" = "brsStartupEntry";
   "_brsStartupEntry" = "brsStartupEntry";
    }
    "_Startup_Code_START" = "_lc_gb_Startup_Code";
    "_Startup_Code_END" = ("_lc_ge_Startup_Code" == 0) ? 0 : "_lc_ge_Startup_Code" - 1;
    "_Startup_Code_LIMIT" = "_lc_ge_Startup_Code";

    group OS_DATA_SHARED_INIT_ROM(contiguous, load_addr, align=4)
    {
      select "OS_BARRIER_CORE0_VAR";
      select "OS_BARRIER_CORE0_VAR_NOCACHE";
      select "OS_BARRIER_CORE1_VAR";
      select "OS_BARRIER_CORE1_VAR_NOCACHE";
      select "OS_BARRIER_CORE2_VAR";
      select "OS_BARRIER_CORE2_VAR_NOCACHE";
      select "OS_CORESTATUS_CORE0_VAR";
      select "OS_CORESTATUS_CORE0_VAR_NOCACHE";
      select "OS_CORESTATUS_CORE1_VAR";
      select "OS_CORESTATUS_CORE1_VAR_NOCACHE";
      select "OS_CORESTATUS_CORE2_VAR";
      select "OS_CORESTATUS_CORE2_VAR_NOCACHE";
      select "OS_GLOBALSHARED_VAR";
      select "OS_GLOBALSHARED_VAR_NOCACHE";
      select "OS_PUBLIC_CORE0_VAR";
      select "OS_PUBLIC_CORE0_VAR_NOCACHE";
      select "OS_PUBLIC_CORE1_VAR";
      select "OS_PUBLIC_CORE1_VAR_NOCACHE";
      select "OS_PUBLIC_CORE2_VAR";
      select "OS_PUBLIC_CORE2_VAR_NOCACHE";
      select "OS_VAR";
      select "OS_VAR_NOCACHE";
    }
    "_OS_DATA_SHARED_INIT_ROM_START" = "_lc_gb_OS_DATA_SHARED_INIT_ROM";
    "_OS_DATA_SHARED_INIT_ROM_LIMIT" = "_lc_ge_OS_DATA_SHARED_INIT_ROM";

    group Data_Default_INIT_ROM(contiguous, load_addr, align=4)
    {
      select "[.]data.Can.canConfigInitFlag";
      select "[.]data.Mcu.Mcu_kConfigPtr";
      select "[.]data.Mcal_TcLib.Mcal_IntDisableCounterRedn";
      select"[.]data.Mcal_TcLib.Mcal_IntDisableCounter";          
      select"[.]data.Mcal_TcLib.Mcal_SavedIntStateRedn";            
      select"[.]data.Mcal_TcLib.Mcal_SavedIntState";                 
      select"[.]data.Mcal_WdgLib.Mcal_ResetEndInitCounterRedn";   
      select"[.]data.Mcal_WdgLib.Mcal_ResetEndInitCounter";         
      select"[.]data.Mcal_WdgLib.Mcal_SafetyResetEndInitCounterRedn";
      select"[.]data.Mcal_WdgLib.Mcal_SafetyResetEndInitCounter";  
      select"[.]data.Mcal_WdgLib.Mcal_WdgSafetyEndInitSemRedn";     
      select"[.]data.Mcal_WdgLib.Mcal_WdgSafetyEndInitSem";          
      select"[.]data.Mcu.Mcu_ResetStatusVal";                       
      select"[.]data.CanNm_Cfg.CanNm_ModuleInitialized";           
      select"[.]data.CanSM.CanSM_IsInitialized";                    
      select"[.]data.ComM.ComM_InitStatus";                      
      select"[.]data.Com_Lcfg.Com_Initialized";                     
      select"[.]data.Det.detModuleInit";                            
      select"[.]data.Nm.Nm_Initialized";    
      select"[.]data.PduR_Lcfg.PduR_Initialized";                         

    }
    "_Data_Default_INIT_ROM_START" = "_lc_gb_Data_Default_INIT_ROM";
    "_Data_Default_INIT_ROM_LIMIT" = "_lc_ge_Data_Default_INIT_ROM";

  }
  "_RegionBlock_PFlash0_NonCached_START" = "_lc_gb_RegionBlock_PFlash0_NonCached";
  "_RegionBlock_PFlash0_NonCached_END" = ("_lc_ge_RegionBlock_PFlash0_NonCached" == 0) ? 0 : "_lc_ge_RegionBlock_PFlash0_NonCached" - 1;
  "_RegionBlock_PFlash0_NonCached_LIMIT" = "_lc_ge_RegionBlock_PFlash0_NonCached";

  /* RegionBlock_BMHD2 (32 Byte) */
  group RegionBlock_BMHD2(ordered, run_addr = 0xA000FFE0)
  {
  }
  "_RegionBlock_BMHD2_START" = "_lc_gb_RegionBlock_BMHD2";
  "_RegionBlock_BMHD2_END" = ("_lc_ge_RegionBlock_BMHD2" == 0) ? 0 : "_lc_ge_RegionBlock_BMHD2" - 1;
  "_RegionBlock_BMHD2_LIMIT" = "_lc_ge_RegionBlock_BMHD2";

  /* RegionBlock_BMHD3 (32 Byte) */
  group RegionBlock_BMHD3(ordered, run_addr = 0xA001FFE0)
  {
  }
  "_RegionBlock_BMHD3_START" = "_lc_gb_RegionBlock_BMHD3";
  "_RegionBlock_BMHD3_END" = ("_lc_ge_RegionBlock_BMHD3" == 0) ? 0 : "_lc_ge_RegionBlock_BMHD3" - 1;
  "_RegionBlock_BMHD3_LIMIT" = "_lc_ge_RegionBlock_BMHD3";

  /* RegionBlock_BMHD1 (32 Byte) */
  group RegionBlock_BMHD1(ordered, run_addr = 0xA0020000)
  {
  }
  "_RegionBlock_BMHD1_START" = "_lc_gb_RegionBlock_BMHD1";
  "_RegionBlock_BMHD1_END" = ("_lc_ge_RegionBlock_BMHD1" == 0) ? 0 : "_lc_ge_RegionBlock_BMHD1" - 1;
  "_RegionBlock_BMHD1_LIMIT" = "_lc_ge_RegionBlock_BMHD1";

  /* RegionBlock_PFlash1_NonCached (2 MiB) */
  group RegionBlock_PFlash1_NonCached(ordered, run_addr = 0xA0200000)
  {
  }
  "_RegionBlock_PFlash1_NonCached_START" = "_lc_gb_RegionBlock_PFlash1_NonCached";
  "_RegionBlock_PFlash1_NonCached_END" = ("_lc_ge_RegionBlock_PFlash1_NonCached" == 0) ? 0 : "_lc_ge_RegionBlock_PFlash1_NonCached" - 1;
  "_RegionBlock_PFlash1_NonCached_LIMIT" = "_lc_ge_RegionBlock_PFlash1_NonCached";

  /* MemoryRegion_lmuram_NonCahed (32 KiB) */
  group MemoryRegion_lmuram_NonCahed(ordered, run_addr = 0xB0000000)
  {
  }
  "_MemoryRegion_lmuram_NonCahed_START" = "_lc_gb_MemoryRegion_lmuram_NonCahed";
  "_MemoryRegion_lmuram_NonCahed_END" = ("_lc_ge_MemoryRegion_lmuram_NonCahed" == 0) ? 0 : "_lc_ge_MemoryRegion_lmuram_NonCahed" - 1;
  "_MemoryRegion_lmuram_NonCahed_LIMIT" = "_lc_ge_MemoryRegion_lmuram_NonCahed";

}
