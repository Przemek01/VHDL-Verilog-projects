/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/ISE/kontroler/kontroler_tb.v";
static const char *ng1 = "zbocze_data_irq.txt";
static const char *ng2 = "r";
static const char *ng3 = "poziom_data_irq.txt";
static const char *ng4 = "zbocze_data_irq_maskowanie.txt";
static const char *ng5 = "poziom_data_irq_maskowanie.txt";
static const char *ng6 = "nie udalo sie otworzyc plikow zbocze_data_irq.txt";
static const char *ng7 = "nie udalo sie otworzyc plikow poziom_data_irq.txt";
static const char *ng8 = "nie udalo sie otworzyc plikow zbocze_data_irq_maskowanie.txt";
static const char *ng9 = "nie udalo sie otworzyc pliku poziom_data_irq_maskowanie.txt";
static int ng10[] = {0, 0};
static int ng11[] = {1, 0};
static const char *ng12 = "wyniki.txt";
static const char *ng13 = "w";
static const char *ng14 = "nie udalo sie otworzyc pliku";
static const char *ng15 = "%h\n";
static unsigned int ng16[] = {1U, 0U};
static unsigned int ng17[] = {31U, 0U};
static unsigned int ng18[] = {2U, 0U};
static unsigned int ng19[] = {3U, 0U};
static unsigned int ng20[] = {0U, 0U};
static const char *ng21 = "data_out = %h | data_in = %h | adres = %b | nr_w = %b | irq_in = %h | irq_out = %b \n";



static void Initial_31_0(char *t0)
{
    char t1[8];
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;

LAB0:    xsi_set_current_line(31, ng0);

LAB2:    xsi_set_current_line(34, ng0);
    *((int *)t1) = xsi_vlogfile_file_open_of_cname_ctype(ng1, ng2);
    t2 = (t1 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t1, 0, 0, 32);
    xsi_set_current_line(35, ng0);
    *((int *)t1) = xsi_vlogfile_file_open_of_cname_ctype(ng3, ng2);
    t2 = (t1 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t1, 0, 0, 32);
    xsi_set_current_line(36, ng0);
    *((int *)t1) = xsi_vlogfile_file_open_of_cname_ctype(ng4, ng2);
    t2 = (t1 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t1, 0, 0, 32);
    xsi_set_current_line(37, ng0);
    *((int *)t1) = xsi_vlogfile_file_open_of_cname_ctype(ng5, ng2);
    t2 = (t1 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t1, 0, 0, 32);
    xsi_set_current_line(39, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t1, 0, 8);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 & 4294967295U);
    if (t10 != 0)
        goto LAB6;

LAB4:    if (*((unsigned int *)t5) == 0)
        goto LAB3;

LAB5:    t11 = (t1 + 4);
    *((unsigned int *)t1) = 1;
    *((unsigned int *)t11) = 1;

LAB6:    t12 = (t1 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t1);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB7;

LAB8:
LAB9:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t1, 0, 8);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 & 4294967295U);
    if (t10 != 0)
        goto LAB14;

LAB12:    if (*((unsigned int *)t5) == 0)
        goto LAB11;

LAB13:    t11 = (t1 + 4);
    *((unsigned int *)t1) = 1;
    *((unsigned int *)t11) = 1;

LAB14:    t12 = (t1 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t1);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB15;

LAB16:
LAB17:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t1, 0, 8);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 & 4294967295U);
    if (t10 != 0)
        goto LAB22;

LAB20:    if (*((unsigned int *)t5) == 0)
        goto LAB19;

LAB21:    t11 = (t1 + 4);
    *((unsigned int *)t1) = 1;
    *((unsigned int *)t11) = 1;

LAB22:    t12 = (t1 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t1);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB23;

LAB24:
LAB25:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t1, 0, 8);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 & 4294967295U);
    if (t10 != 0)
        goto LAB30;

LAB28:    if (*((unsigned int *)t5) == 0)
        goto LAB27;

LAB29:    t11 = (t1 + 4);
    *((unsigned int *)t1) = 1;
    *((unsigned int *)t11) = 1;

LAB30:    t12 = (t1 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t1);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB31;

LAB32:
LAB33:
LAB1:    return;
LAB3:    *((unsigned int *)t1) = 1;
    goto LAB6;

LAB7:    xsi_set_current_line(39, ng0);

LAB10:    xsi_set_current_line(40, ng0);
    xsi_vlogfile_write(1, 0, 0, ng6, 1, t0);
    xsi_set_current_line(41, ng0);
    xsi_vlog_finish(1);
    goto LAB9;

LAB11:    *((unsigned int *)t1) = 1;
    goto LAB14;

LAB15:    xsi_set_current_line(44, ng0);

LAB18:    xsi_set_current_line(45, ng0);
    xsi_vlogfile_write(1, 0, 0, ng7, 1, t0);
    xsi_set_current_line(46, ng0);
    xsi_vlog_finish(1);
    goto LAB17;

LAB19:    *((unsigned int *)t1) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(49, ng0);

LAB26:    xsi_set_current_line(50, ng0);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);
    xsi_set_current_line(51, ng0);
    xsi_vlog_finish(1);
    goto LAB25;

LAB27:    *((unsigned int *)t1) = 1;
    goto LAB30;

LAB31:    xsi_set_current_line(55, ng0);

LAB34:    xsi_set_current_line(56, ng0);
    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    xsi_set_current_line(57, ng0);
    xsi_vlog_finish(1);
    goto LAB33;

}

static void Initial_66_1(char *t0)
{
    char t5[8];
    char t19[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t20;
    char *t21;
    char *t22;
    char *t24;

LAB0:    t1 = (t0 + 4376U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(66, ng0);

LAB4:    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(68, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 1608);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(69, ng0);
    t3 = ((char*)((ng11)));
    t4 = (t0 + 1608);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(71, ng0);
    *((int *)t5) = xsi_vlogfile_file_open_of_cname_ctype(ng12, ng13);
    t2 = (t5 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t5, 0, 0, 32);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 4294967295U);
    if (t11 != 0)
        goto LAB10;

LAB8:    if (*((unsigned int *)t6) == 0)
        goto LAB7;

LAB9:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;

LAB10:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t5);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB11;

LAB12:
LAB13:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB7:    *((unsigned int *)t5) = 1;
    goto LAB10;

LAB11:    xsi_set_current_line(72, ng0);

LAB14:    xsi_set_current_line(73, ng0);
    xsi_vlogfile_write(1, 0, 0, ng14, 1, t0);
    xsi_set_current_line(74, ng0);
    xsi_vlog_finish(1);
    goto LAB13;

LAB15:    xsi_set_current_line(78, ng0);

LAB16:    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    *((int *)t19) = xsi_vlogfile_feof(*((unsigned int *)t4));
    t6 = (t19 + 4);
    *((int *)t6) = 0;
    memset(t5, 0, 8);
    t12 = (t19 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t19);
    t10 = (t9 & t8);
    t11 = (t10 & 4294967295U);
    if (t11 != 0)
        goto LAB20;

LAB18:    if (*((unsigned int *)t12) == 0)
        goto LAB17;

LAB19:    t13 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t13) = 1;

LAB20:    t20 = (t5 + 4);
    t14 = *((unsigned int *)t20);
    t15 = (~(t14));
    t16 = *((unsigned int *)t5);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(101, ng0);

LAB30:    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    *((int *)t19) = xsi_vlogfile_feof(*((unsigned int *)t4));
    t6 = (t19 + 4);
    *((int *)t6) = 0;
    memset(t5, 0, 8);
    t12 = (t19 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t19);
    t10 = (t9 & t8);
    t11 = (t10 & 4294967295U);
    if (t11 != 0)
        goto LAB34;

LAB32:    if (*((unsigned int *)t12) == 0)
        goto LAB31;

LAB33:    t13 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t13) = 1;

LAB34:    t20 = (t5 + 4);
    t14 = *((unsigned int *)t20);
    t15 = (~(t14));
    t16 = *((unsigned int *)t5);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB35;

LAB36:    xsi_set_current_line(121, ng0);

LAB44:    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    *((int *)t19) = xsi_vlogfile_feof(*((unsigned int *)t4));
    t6 = (t19 + 4);
    *((int *)t6) = 0;
    memset(t5, 0, 8);
    t12 = (t19 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t19);
    t10 = (t9 & t8);
    t11 = (t10 & 4294967295U);
    if (t11 != 0)
        goto LAB48;

LAB46:    if (*((unsigned int *)t12) == 0)
        goto LAB45;

LAB47:    t13 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t13) = 1;

LAB48:    t20 = (t5 + 4);
    t14 = *((unsigned int *)t20);
    t15 = (~(t14));
    t16 = *((unsigned int *)t5);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB49;

LAB50:    xsi_set_current_line(143, ng0);

LAB58:    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    *((int *)t19) = xsi_vlogfile_feof(*((unsigned int *)t4));
    t6 = (t19 + 4);
    *((int *)t6) = 0;
    memset(t5, 0, 8);
    t12 = (t19 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t19);
    t10 = (t9 & t8);
    t11 = (t10 & 4294967295U);
    if (t11 != 0)
        goto LAB62;

LAB60:    if (*((unsigned int *)t12) == 0)
        goto LAB59;

LAB61:    t13 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t13) = 1;

LAB62:    t20 = (t5 + 4);
    t14 = *((unsigned int *)t20);
    t15 = (~(t14));
    t16 = *((unsigned int *)t5);
    t17 = (t16 & t15);
    t18 = (t17 != 0);
    if (t18 > 0)
        goto LAB63;

LAB64:    xsi_set_current_line(163, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_fclose(*((unsigned int *)t4));
    xsi_set_current_line(164, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_fclose(*((unsigned int *)t4));
    xsi_set_current_line(165, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_fclose(*((unsigned int *)t4));
    xsi_set_current_line(166, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_fclose(*((unsigned int *)t4));
    xsi_set_current_line(168, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_fclose(*((unsigned int *)t4));
    xsi_set_current_line(169, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

LAB17:    *((unsigned int *)t5) = 1;
    goto LAB20;

LAB21:    xsi_set_current_line(78, ng0);

LAB23:    xsi_set_current_line(79, ng0);
    t21 = (t0 + 5192);
    *((int *)t21) = 1;
    t22 = (t0 + 4408);
    *((char **)t22) = t21;
    *((char **)t1) = &&LAB24;
    goto LAB1;

LAB24:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 2568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 2408);
    t12 = (t6 + 56U);
    t13 = *((char **)t12);
    memset(t19, 0, 8);
    t20 = (t19 + 4);
    t21 = (t13 + 4);
    t7 = *((unsigned int *)t13);
    t8 = (t7 >> 0);
    *((unsigned int *)t19) = t8;
    t9 = *((unsigned int *)t21);
    t10 = (t9 >> 0);
    *((unsigned int *)t20) = t10;
    t11 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t11 & 31U);
    t14 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t14 & 31U);
    xsi_vlog_bit_copy(t5, 0, t19, 0, 5);
    *((int *)t23) = xsi_vlogfile_fscanf(*((unsigned int *)t4), ng15, 2, t0, (char)118, t5, 5);
    t22 = (t23 + 4);
    *((int *)t22) = 0;
    t24 = (t0 + 2408);
    xsi_vlogvar_assign_value(t24, t5, 0, 0, 5);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB25;
    goto LAB1;

LAB25:    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB26;
    goto LAB1;

LAB26:    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB27:    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB28;
    goto LAB1;

LAB28:    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB29;
    goto LAB1;

LAB29:    goto LAB16;

LAB31:    *((unsigned int *)t5) = 1;
    goto LAB34;

LAB35:    xsi_set_current_line(101, ng0);

LAB37:    xsi_set_current_line(102, ng0);
    t21 = (t0 + 5208);
    *((int *)t21) = 1;
    t22 = (t0 + 4408);
    *((char **)t22) = t21;
    *((char **)t1) = &&LAB38;
    goto LAB1;

LAB38:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 2728);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 2408);
    t12 = (t6 + 56U);
    t13 = *((char **)t12);
    memset(t19, 0, 8);
    t20 = (t19 + 4);
    t21 = (t13 + 4);
    t7 = *((unsigned int *)t13);
    t8 = (t7 >> 0);
    *((unsigned int *)t19) = t8;
    t9 = *((unsigned int *)t21);
    t10 = (t9 >> 0);
    *((unsigned int *)t20) = t10;
    t11 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t11 & 31U);
    t14 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t14 & 31U);
    xsi_vlog_bit_copy(t5, 0, t19, 0, 5);
    *((int *)t23) = xsi_vlogfile_fscanf(*((unsigned int *)t4), ng15, 2, t0, (char)118, t5, 5);
    t22 = (t23 + 4);
    *((int *)t22) = 0;
    t24 = (t0 + 2408);
    xsi_vlogvar_assign_value(t24, t5, 0, 0, 5);
    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(106, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(108, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB39:    xsi_set_current_line(109, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB40;
    goto LAB1;

LAB40:    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(113, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB41;
    goto LAB1;

LAB41:    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB42;
    goto LAB1;

LAB42:    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB43:    goto LAB30;

LAB45:    *((unsigned int *)t5) = 1;
    goto LAB48;

LAB49:    xsi_set_current_line(121, ng0);

LAB51:    xsi_set_current_line(122, ng0);
    t21 = (t0 + 5224);
    *((int *)t21) = 1;
    t22 = (t0 + 4408);
    *((char **)t22) = t21;
    *((char **)t1) = &&LAB52;
    goto LAB1;

LAB52:    xsi_set_current_line(123, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 2408);
    t12 = (t6 + 56U);
    t13 = *((char **)t12);
    memset(t19, 0, 8);
    t20 = (t19 + 4);
    t21 = (t13 + 4);
    t7 = *((unsigned int *)t13);
    t8 = (t7 >> 0);
    *((unsigned int *)t19) = t8;
    t9 = *((unsigned int *)t21);
    t10 = (t9 >> 0);
    *((unsigned int *)t20) = t10;
    t11 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t11 & 31U);
    t14 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t14 & 31U);
    xsi_vlog_bit_copy(t5, 0, t19, 0, 5);
    *((int *)t23) = xsi_vlogfile_fscanf(*((unsigned int *)t4), ng15, 2, t0, (char)118, t5, 5);
    t22 = (t23 + 4);
    *((int *)t22) = 0;
    t24 = (t0 + 2408);
    xsi_vlogvar_assign_value(t24, t5, 0, 0, 5);
    xsi_set_current_line(125, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(126, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(127, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB53;
    goto LAB1;

LAB53:    xsi_set_current_line(129, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(130, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(131, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB54;
    goto LAB1;

LAB54:    xsi_set_current_line(132, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(133, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(134, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB55;
    goto LAB1;

LAB55:    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(138, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB56;
    goto LAB1;

LAB56:    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(140, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB57;
    goto LAB1;

LAB57:    goto LAB44;

LAB59:    *((unsigned int *)t5) = 1;
    goto LAB62;

LAB63:    xsi_set_current_line(143, ng0);

LAB65:    xsi_set_current_line(144, ng0);
    t21 = (t0 + 5240);
    *((int *)t21) = 1;
    t22 = (t0 + 4408);
    *((char **)t22) = t21;
    *((char **)t1) = &&LAB66;
    goto LAB1;

LAB66:    xsi_set_current_line(145, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 2408);
    t12 = (t6 + 56U);
    t13 = *((char **)t12);
    memset(t19, 0, 8);
    t20 = (t19 + 4);
    t21 = (t13 + 4);
    t7 = *((unsigned int *)t13);
    t8 = (t7 >> 0);
    *((unsigned int *)t19) = t8;
    t9 = *((unsigned int *)t21);
    t10 = (t9 >> 0);
    *((unsigned int *)t20) = t10;
    t11 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t11 & 31U);
    t14 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t14 & 31U);
    xsi_vlog_bit_copy(t5, 0, t19, 0, 5);
    *((int *)t23) = xsi_vlogfile_fscanf(*((unsigned int *)t4), ng15, 2, t0, (char)118, t5, 5);
    t22 = (t23 + 4);
    *((int *)t22) = 0;
    t24 = (t0 + 2408);
    xsi_vlogvar_assign_value(t24, t5, 0, 0, 5);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(148, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB67;
    goto LAB1;

LAB67:    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(152, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB68;
    goto LAB1;

LAB68:    xsi_set_current_line(154, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(155, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(156, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB69;
    goto LAB1;

LAB69:    xsi_set_current_line(157, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(158, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB70;
    goto LAB1;

LAB70:    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(160, ng0);
    t2 = (t0 + 4184);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB71:    goto LAB58;

}

static void Always_174_2(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 4624U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 4432);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(174, ng0);
    t4 = (t0 + 1768);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 1768);
    xsi_vlogvar_wait_assign_value(t24, t3, 0, 0, 1, 0LL);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Always_176_3(char *t0)
{
    char t5[8];
    char t17[8];
    char t27[8];
    char t42[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    char *t41;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t55;

LAB0:    t1 = (t0 + 4872U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 5256);
    *((int *)t2) = 1;
    t3 = (t0 + 4904);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(177, ng0);

LAB5:    xsi_set_current_line(178, ng0);
    t4 = (t0 + 4680);
    xsi_process_wait(t4, 1000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(179, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t6 = (t0 + 1928);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t5, 0, 8);
    t9 = (t5 + 4);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t5) = t12;
    t13 = *((unsigned int *)t10);
    t14 = (t13 >> 0);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t15 & 255U);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 & 255U);
    t18 = (t0 + 1048U);
    t19 = *((char **)t18);
    memset(t17, 0, 8);
    t18 = (t17 + 4);
    t20 = (t19 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (t21 >> 0);
    *((unsigned int *)t17) = t22;
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 0);
    *((unsigned int *)t18) = t24;
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 & 255U);
    t26 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t26 & 255U);
    t28 = (t0 + 2088);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    memset(t27, 0, 8);
    t31 = (t27 + 4);
    t32 = (t30 + 4);
    t33 = *((unsigned int *)t30);
    t34 = (t33 >> 0);
    *((unsigned int *)t27) = t34;
    t35 = *((unsigned int *)t32);
    t36 = (t35 >> 0);
    *((unsigned int *)t31) = t36;
    t37 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t37 & 3U);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t38 & 3U);
    t39 = (t0 + 2248);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    t43 = (t0 + 2408);
    t44 = (t43 + 56U);
    t45 = *((char **)t44);
    memset(t42, 0, 8);
    t46 = (t42 + 4);
    t47 = (t45 + 4);
    t48 = *((unsigned int *)t45);
    t49 = (t48 >> 0);
    *((unsigned int *)t42) = t49;
    t50 = *((unsigned int *)t47);
    t51 = (t50 >> 0);
    *((unsigned int *)t46) = t51;
    t52 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t52 & 31U);
    t53 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t53 & 31U);
    t54 = (t0 + 1208U);
    t55 = *((char **)t54);
    xsi_vlogfile_fwrite(*((unsigned int *)t4), 0, 0, 1, ng21, 7, t0, (char)118, t5, 8, (char)118, t17, 8, (char)118, t27, 2, (char)118, t41, 1, (char)118, t42, 5, (char)118, t55, 1);
    goto LAB2;

}


extern void work_m_00000000001331531395_0248603010_init()
{
	static char *pe[] = {(void *)Initial_31_0,(void *)Initial_66_1,(void *)Always_174_2,(void *)Always_176_3};
	xsi_register_didat("work_m_00000000001331531395_0248603010", "isim/kontroler_tb_isim_beh.exe.sim/work/m_00000000001331531395_0248603010.didat");
	xsi_register_executes(pe);
}
