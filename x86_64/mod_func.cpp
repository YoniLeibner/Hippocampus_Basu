#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _beforestep_py_reg(void);
extern void _CaDynamics_E2_reg(void);
extern void _Ca_HVA_reg(void);
extern void _Ca_LVAst_reg(void);
extern void _g_total_reg(void);
extern void _hh_guy_reg(void);
extern void _Ih_human_reg(void);
extern void _Ih_human_shifts2_reg(void);
extern void _Ih_human_shifts3_reg(void);
extern void _Ih_human_shifts_freeze_reg(void);
extern void _Ih_human_shifts_reg(void);
extern void _Ih_human_shifts_mul_add_reg(void);
extern void _Ih_human_shifts_mul_add_uni_reg(void);
extern void _Ih_reg(void);
extern void _Im_reg(void);
extern void _kd3h5_reg(void);
extern void _K_Pst_reg(void);
extern void _K_Tst_reg(void);
extern void _na3_reg(void);
extern void _Nap_Et2_reg(void);
extern void _NaTa_t_reg(void);
extern void _NaTs2_t_reg(void);
extern void _NMDA_reg(void);
extern void _ProbAMPA_reg(void);
extern void _ProbAMPANMDA2_ratio_reg(void);
extern void _ProbAMPANMDA_EMS_reg(void);
extern void _ProbAMPANMDA_reg(void);
extern void _ProbGABAAB_EMS_reg(void);
extern void _ProbGABAA_EMS_reg(void);
extern void _ProbGABAA_reg(void);
extern void _ProbNMDA_reg(void);
extern void _SK_E2_reg(void);
extern void _SKv3_1_reg(void);

void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"mods_2//beforestep_py.mod\"");
    fprintf(stderr, " \"mods_2//CaDynamics_E2.mod\"");
    fprintf(stderr, " \"mods_2//Ca_HVA.mod\"");
    fprintf(stderr, " \"mods_2//Ca_LVAst.mod\"");
    fprintf(stderr, " \"mods_2//g_total.mod\"");
    fprintf(stderr, " \"mods_2//hh_guy.mod\"");
    fprintf(stderr, " \"mods_2//Ih_human.mod\"");
    fprintf(stderr, " \"mods_2//Ih_human_shifts2.mod\"");
    fprintf(stderr, " \"mods_2//Ih_human_shifts3.mod\"");
    fprintf(stderr, " \"mods_2//Ih_human_shifts_freeze.mod\"");
    fprintf(stderr, " \"mods_2//Ih_human_shifts.mod\"");
    fprintf(stderr, " \"mods_2//Ih_human_shifts_mul_add.mod\"");
    fprintf(stderr, " \"mods_2//Ih_human_shifts_mul_add_uni.mod\"");
    fprintf(stderr, " \"mods_2//Ih.mod\"");
    fprintf(stderr, " \"mods_2//Im.mod\"");
    fprintf(stderr, " \"mods_2//kd3h5.mod\"");
    fprintf(stderr, " \"mods_2//K_Pst.mod\"");
    fprintf(stderr, " \"mods_2//K_Tst.mod\"");
    fprintf(stderr, " \"mods_2//na3.mod\"");
    fprintf(stderr, " \"mods_2//Nap_Et2.mod\"");
    fprintf(stderr, " \"mods_2//NaTa_t.mod\"");
    fprintf(stderr, " \"mods_2//NaTs2_t.mod\"");
    fprintf(stderr, " \"mods_2//NMDA.mod\"");
    fprintf(stderr, " \"mods_2//ProbAMPA.mod\"");
    fprintf(stderr, " \"mods_2//ProbAMPANMDA2_ratio.mod\"");
    fprintf(stderr, " \"mods_2//ProbAMPANMDA_EMS.mod\"");
    fprintf(stderr, " \"mods_2//ProbAMPANMDA.mod\"");
    fprintf(stderr, " \"mods_2//ProbGABAAB_EMS.mod\"");
    fprintf(stderr, " \"mods_2//ProbGABAA_EMS.mod\"");
    fprintf(stderr, " \"mods_2//ProbGABAA.mod\"");
    fprintf(stderr, " \"mods_2//ProbNMDA.mod\"");
    fprintf(stderr, " \"mods_2//SK_E2.mod\"");
    fprintf(stderr, " \"mods_2//SKv3_1.mod\"");
    fprintf(stderr, "\n");
  }
  _beforestep_py_reg();
  _CaDynamics_E2_reg();
  _Ca_HVA_reg();
  _Ca_LVAst_reg();
  _g_total_reg();
  _hh_guy_reg();
  _Ih_human_reg();
  _Ih_human_shifts2_reg();
  _Ih_human_shifts3_reg();
  _Ih_human_shifts_freeze_reg();
  _Ih_human_shifts_reg();
  _Ih_human_shifts_mul_add_reg();
  _Ih_human_shifts_mul_add_uni_reg();
  _Ih_reg();
  _Im_reg();
  _kd3h5_reg();
  _K_Pst_reg();
  _K_Tst_reg();
  _na3_reg();
  _Nap_Et2_reg();
  _NaTa_t_reg();
  _NaTs2_t_reg();
  _NMDA_reg();
  _ProbAMPA_reg();
  _ProbAMPANMDA2_ratio_reg();
  _ProbAMPANMDA_EMS_reg();
  _ProbAMPANMDA_reg();
  _ProbGABAAB_EMS_reg();
  _ProbGABAA_EMS_reg();
  _ProbGABAA_reg();
  _ProbNMDA_reg();
  _SK_E2_reg();
  _SKv3_1_reg();
}

#if defined(__cplusplus)
}
#endif
