#ifndef __PLIB_BMX_TEMPLATE_BMX_REGISTERS_H__
#define __PLIB_BMX_TEMPLATE_BMX_REGISTERS_H__

typedef struct bmx_regs {
    __BMXCONbits_t BMXCON;
    uint32_t BMXCONCLR;
    uint32_t BMXCONSET;
    uint32_t BMXCONINV;
    uint32_t BMXDKPBA;
    uint32_t Reserved1[3];
    uint32_t BMXDUDBA;
    uint32_t Reserved2[3];
    uint32_t BMXDUPBA;
    uint32_t Reserved3[3];
    uint32_t BMXDRMSZ;
    uint32_t Reserved4[3];
    uint32_t BMXPUPBA;
    uint32_t BMXPUPBACLR;
    uint32_t BMXPUPBASET;
    uint32_t BMXPUPBAINV;
    uint32_t BMXPFMSZ;
    uint32_t Reserved5[3];
    uint32_t BMXBOOTSZ;
    uint32_t Reserved6[3];
} bmx_register_t;

#endif /* __PLIB_BMX_TEMPLATE_BMX_REGISTERS_H__ */
