/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__ProbAMPANMDA2_RATIO
#define _nrn_initial _nrn_initial__ProbAMPANMDA2_RATIO
#define nrn_cur _nrn_cur__ProbAMPANMDA2_RATIO
#define _nrn_current _nrn_current__ProbAMPANMDA2_RATIO
#define nrn_jacob _nrn_jacob__ProbAMPANMDA2_RATIO
#define nrn_state _nrn_state__ProbAMPANMDA2_RATIO
#define _net_receive _net_receive__ProbAMPANMDA2_RATIO 
#define setRNG setRNG__ProbAMPANMDA2_RATIO 
#define state state__ProbAMPANMDA2_RATIO 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define tau_r_AMPA _p[0]
#define tau_r_AMPA_columnindex 0
#define tau_d_AMPA _p[1]
#define tau_d_AMPA_columnindex 1
#define tau_r_NMDA _p[2]
#define tau_r_NMDA_columnindex 2
#define tau_d_NMDA _p[3]
#define tau_d_NMDA_columnindex 3
#define Use _p[4]
#define Use_columnindex 4
#define Dep _p[5]
#define Dep_columnindex 5
#define Fac _p[6]
#define Fac_columnindex 6
#define e _p[7]
#define e_columnindex 7
#define mgVoltageCoeff _p[8]
#define mgVoltageCoeff_columnindex 8
#define gmax _p[9]
#define gmax_columnindex 9
#define u0 _p[10]
#define u0_columnindex 10
#define i _p[11]
#define i_columnindex 11
#define i_AMPA _p[12]
#define i_AMPA_columnindex 12
#define i_NMDA _p[13]
#define i_NMDA_columnindex 13
#define g_AMPA _p[14]
#define g_AMPA_columnindex 14
#define g_NMDA _p[15]
#define g_NMDA_columnindex 15
#define weight_NMDA _p[16]
#define weight_NMDA_columnindex 16
#define A_AMPA _p[17]
#define A_AMPA_columnindex 17
#define B_AMPA _p[18]
#define B_AMPA_columnindex 18
#define A_NMDA _p[19]
#define A_NMDA_columnindex 19
#define B_NMDA _p[20]
#define B_NMDA_columnindex 20
#define factor_AMPA _p[21]
#define factor_AMPA_columnindex 21
#define factor_NMDA _p[22]
#define factor_NMDA_columnindex 22
#define a _p[23]
#define a_columnindex 23
#define DA_AMPA _p[24]
#define DA_AMPA_columnindex 24
#define DB_AMPA _p[25]
#define DB_AMPA_columnindex 25
#define DA_NMDA _p[26]
#define DA_NMDA_columnindex 26
#define DB_NMDA _p[27]
#define DB_NMDA_columnindex 27
#define _g _p[28]
#define _g_columnindex 28
#define _tsav _p[29]
#define _tsav_columnindex 29
#define _nd_area  *_ppvar[0]._pval
#define rng	*_ppvar[2]._pval
#define _p_rng	_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  2;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_erand(void*);
 static double _hoc_setRNG(void*);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(Object* _ho) { void* create_point_process(int, Object*);
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt(void*);
 static double _hoc_loc_pnt(void* _vptr) {double loc_point_process(int, void*);
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(void* _vptr) {double has_loc_point(void*);
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(void* _vptr) {
 double get_loc_point_process(void*); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "erand", _hoc_erand,
 "setRNG", _hoc_setRNG,
 0, 0
};
#define erand erand_ProbAMPANMDA2_RATIO
 extern double erand( );
 /* declare global and static user variables */
#define mggate mggate_ProbAMPANMDA2_RATIO
 double mggate = 0;
#define mg mg_ProbAMPANMDA2_RATIO
 double mg = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "mg_ProbAMPANMDA2_RATIO", "mM",
 "tau_r_AMPA", "ms",
 "tau_d_AMPA", "ms",
 "tau_r_NMDA", "ms",
 "tau_d_NMDA", "ms",
 "Use", "1",
 "Dep", "ms",
 "Fac", "ms",
 "e", "mV",
 "mgVoltageCoeff", "mV",
 "gmax", "uS",
 "i", "nA",
 "i_AMPA", "nA",
 "i_NMDA", "nA",
 "g_AMPA", "uS",
 "g_NMDA", "uS",
 0,0
};
 static double A_NMDA0 = 0;
 static double A_AMPA0 = 0;
 static double B_NMDA0 = 0;
 static double B_AMPA0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "mg_ProbAMPANMDA2_RATIO", &mg_ProbAMPANMDA2_RATIO,
 "mggate_ProbAMPANMDA2_RATIO", &mggate_ProbAMPANMDA2_RATIO,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(void* _vptr) {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"ProbAMPANMDA2_RATIO",
 "tau_r_AMPA",
 "tau_d_AMPA",
 "tau_r_NMDA",
 "tau_d_NMDA",
 "Use",
 "Dep",
 "Fac",
 "e",
 "mgVoltageCoeff",
 "gmax",
 "u0",
 0,
 "i",
 "i_AMPA",
 "i_NMDA",
 "g_AMPA",
 "g_NMDA",
 "weight_NMDA",
 0,
 "A_AMPA",
 "B_AMPA",
 "A_NMDA",
 "B_NMDA",
 0,
 "rng",
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 30, _prop);
 	/*initialize range parameters*/
 	tau_r_AMPA = 0.2;
 	tau_d_AMPA = 1.7;
 	tau_r_NMDA = 2.04;
 	tau_d_NMDA = 75.2;
 	Use = 1;
 	Dep = 100;
 	Fac = 10;
 	e = 0;
 	mgVoltageCoeff = 0.08;
 	gmax = 0.001;
 	u0 = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 30;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _net_receive(Point_process*, double*, double);
 static void _net_init(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _ProbAMPANMDA2_ratio_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 30, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "pointer");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_init[_mechtype] = _net_init;
 pnt_receive_size[_mechtype] = 7;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ProbAMPANMDA2_RATIO /ems/elsc-labs/segev-i/yoni.leibner/PycharmProjects/Hippocampus_Basu/mods_2/ProbAMPANMDA2_ratio.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "AMPA and NMDA receptor with presynaptic short-term plasticity ";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int setRNG();
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[4], _dlist1[4];
 static int state(_threadargsproto_);
 
/*VERBATIM*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double nrn_random_pick(void* r);
void* nrn_random_arg(int argpos);

 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   DA_AMPA = - A_AMPA / tau_r_AMPA ;
   DB_AMPA = - B_AMPA / tau_d_AMPA ;
   DA_NMDA = - A_NMDA / tau_r_NMDA ;
   DB_NMDA = - B_NMDA / tau_d_NMDA ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 DA_AMPA = DA_AMPA  / (1. - dt*( ( - 1.0 ) / tau_r_AMPA )) ;
 DB_AMPA = DB_AMPA  / (1. - dt*( ( - 1.0 ) / tau_d_AMPA )) ;
 DA_NMDA = DA_NMDA  / (1. - dt*( ( - 1.0 ) / tau_r_NMDA )) ;
 DB_NMDA = DB_NMDA  / (1. - dt*( ( - 1.0 ) / tau_d_NMDA )) ;
  return 0;
}
 /*END CVODE*/
 static int state () {_reset=0;
 {
    A_AMPA = A_AMPA + (1. - exp(dt*(( - 1.0 ) / tau_r_AMPA)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau_r_AMPA ) - A_AMPA) ;
    B_AMPA = B_AMPA + (1. - exp(dt*(( - 1.0 ) / tau_d_AMPA)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau_d_AMPA ) - B_AMPA) ;
    A_NMDA = A_NMDA + (1. - exp(dt*(( - 1.0 ) / tau_r_NMDA)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau_r_NMDA ) - A_NMDA) ;
    B_NMDA = B_NMDA + (1. - exp(dt*(( - 1.0 ) / tau_d_NMDA)))*(- ( 0.0 ) / ( ( - 1.0 ) / tau_d_NMDA ) - B_NMDA) ;
   }
  return 0;
}
 
static void _net_receive (Point_process* _pnt, double* _args, double _lflag) 
{    _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t; {
   _args[1] = _args[0] ;
   _args[2] = _args[0] ;
   if ( Fac > 0.0 ) {
     _args[5] = _args[5] * exp ( - ( t - _args[6] ) / Fac ) ;
     }
   else {
     _args[5] = Use ;
     }
   if ( Fac > 0.0 ) {
     _args[5] = _args[5] + Use * ( 1.0 - _args[5] ) ;
     }
   _args[3] = 1.0 - ( 1.0 - _args[3] ) * exp ( - ( t - _args[6] ) / Dep ) ;
   _args[4] = _args[5] * _args[3] ;
   _args[3] = _args[3] - _args[5] * _args[3] ;
   _args[6] = t ;
     if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = A_AMPA;
    double __primary = (A_AMPA + _args[1] * factor_AMPA) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau_r_AMPA ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau_r_AMPA ) - __primary );
    A_AMPA += __primary;
  } else {
 A_AMPA = A_AMPA + _args[1] * factor_AMPA ;
     }
   if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = B_AMPA;
    double __primary = (B_AMPA + _args[1] * factor_AMPA) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau_d_AMPA ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau_d_AMPA ) - __primary );
    B_AMPA += __primary;
  } else {
 B_AMPA = B_AMPA + _args[1] * factor_AMPA ;
     }
   if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = A_NMDA;
    double __primary = (A_NMDA + _args[2] * factor_NMDA) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau_r_NMDA ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau_r_NMDA ) - __primary );
    A_NMDA += __primary;
  } else {
 A_NMDA = A_NMDA + _args[2] * factor_NMDA ;
     }
   if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = B_NMDA;
    double __primary = (B_NMDA + _args[2] * factor_NMDA) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tau_d_NMDA ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tau_d_NMDA ) - __primary );
    B_NMDA += __primary;
  } else {
 B_NMDA = B_NMDA + _args[2] * factor_NMDA ;
     }
 } }
 
static void _net_init(Point_process* _pnt, double* _args, double _lflag) {
       _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
 _args[3] = 1.0 ;
   _args[5] = u0 ;
   _args[6] = t ;
   }
 
static int  setRNG (  ) {
   
/*VERBATIM*/
    {
        /**
         * This function takes a NEURON Random object declared in hoc and makes it usable by this mod file.
         * Note that this method is taken from Brett paper as used by netstim.hoc and netstim.mod
         * which points out that the Random must be in negexp(1) mode
         */
        void** pv = (void**)(&_p_rng);
        if( ifarg(1)) {
            *pv = nrn_random_arg(1);
        } else {
            *pv = (void*)0;
        }
    }
  return 0; }
 
static double _hoc_setRNG(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 setRNG (  );
 return(_r);
}
 
double erand (  ) {
   double _lerand;
 
/*VERBATIM*/
	    //FILE *fi;
        double value;
        if (_p_rng) {
                /*
                :Supports separate independent but reproducible streams for
                : each instance. However, the corresponding hoc Random
                : distribution MUST be set to Random.negexp(1)
                */
                value = nrn_random_pick(_p_rng);
		        //fi = fopen("RandomStreamMCellRan4.txt", "w");
                //fprintf(fi,"random stream for this simulation = %lf\n",value);
                //printf("random stream for this simulation = %lf\n",value);
                return value;
        }else{
 _lerand = exprand ( 1.0 ) ;
   
/*VERBATIM*/
        }
 _lerand = value ;
   
return _lerand;
 }
 
static double _hoc_erand(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  erand (  );
 return(_r);
}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 ();
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  A_NMDA = A_NMDA0;
  A_AMPA = A_AMPA0;
  B_NMDA = B_NMDA0;
  B_AMPA = B_AMPA0;
 {
   double _ltp_AMPA , _ltp_NMDA ;
 A_AMPA = 0.0 ;
   B_AMPA = 0.0 ;
   A_NMDA = 0.0 ;
   B_NMDA = 0.0 ;
   _ltp_AMPA = ( tau_r_AMPA * tau_d_AMPA ) / ( tau_d_AMPA - tau_r_AMPA ) * log ( tau_d_AMPA / tau_r_AMPA ) ;
   _ltp_NMDA = ( tau_r_NMDA * tau_d_NMDA ) / ( tau_d_NMDA - tau_r_NMDA ) * log ( tau_d_NMDA / tau_r_NMDA ) ;
   factor_AMPA = - exp ( - _ltp_AMPA / tau_r_AMPA ) + exp ( - _ltp_AMPA / tau_d_AMPA ) ;
   factor_AMPA = 1.0 / factor_AMPA ;
   factor_NMDA = - exp ( - _ltp_NMDA / tau_r_NMDA ) + exp ( - _ltp_NMDA / tau_d_NMDA ) ;
   factor_NMDA = 1.0 / factor_NMDA ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _tsav = -1e20;
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   mggate = 1.0 / ( 1.0 + exp ( mgVoltageCoeff * - ( v ) ) * ( mg / 3.57 ) ) ;
   g_AMPA = ( 1.0 ) * gmax * ( B_AMPA - A_AMPA ) ;
   g_NMDA = gmax * ( B_NMDA - A_NMDA ) * mggate ;
   i_AMPA = g_AMPA * ( v - e ) ;
   i_NMDA = g_NMDA * ( v - e ) ;
   i = i_AMPA + i_NMDA ;
   }
 _current += i;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_v + .001);
 	{ _rhs = _nrn_current(_v);
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
 { error =  state();
 if(error){fprintf(stderr,"at line 103 in file ProbAMPANMDA2_ratio.mod:\n        SOLVE state METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 }}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = A_AMPA_columnindex;  _dlist1[0] = DA_AMPA_columnindex;
 _slist1[1] = B_AMPA_columnindex;  _dlist1[1] = DB_AMPA_columnindex;
 _slist1[2] = A_NMDA_columnindex;  _dlist1[2] = DA_NMDA_columnindex;
 _slist1[3] = B_NMDA_columnindex;  _dlist1[3] = DB_NMDA_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/ems/elsc-labs/segev-i/yoni.leibner/PycharmProjects/Hippocampus_Basu/mods_2/ProbAMPANMDA2_ratio.mod";
static const char* nmodl_file_text = 
  "TITLE AMPA and NMDA receptor with presynaptic short-term plasticity \n"
  "\n"
  "\n"
  "COMMENT\n"
  "AMPA and NMDA receptor conductance using a dual-exponential profile\n"
  "presynaptic short-term plasticity based on Fuhrmann et al. 2002\n"
  "Implemented by Srikanth Ramaswamy, Blue Brain Project, July 2009\n"
  "Etay: changed weight to be equal for NMDA and AMPA, gmax accessible in Neuron\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "NEURON {\n"
  "\n"
  "        POINT_PROCESS ProbAMPANMDA2_RATIO\n"
  "        RANGE tau_r_AMPA, tau_d_AMPA, tau_r_NMDA, tau_d_NMDA\n"
  "        RANGE Use, u, Dep, Fac, u0, weight_NMDA\n"
  "        RANGE i, i_AMPA, i_NMDA, g_AMPA, g_NMDA, e, gmax, mgVoltageCoeff\n"
  "        NONSPECIFIC_CURRENT i\n"
  "	POINTER rng\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "\n"
  "        tau_r_AMPA = 0.2   (ms)  : dual-exponential conductance profile\n"
  "        tau_d_AMPA = 1.7    (ms)  : IMPORTANT: tau_r < tau_d\n"
  "	tau_r_NMDA = 2.04   (ms) : dual-exponential conductance profile\n"
  "        tau_d_NMDA = 75.2     (ms) : IMPORTANT: tau_r < tau_d\n"
  "        Use = 1.0   (1)   : Utilization of synaptic efficacy (just initial values! Use, Dep and Fac are overwritten by BlueBuilder assigned values) \n"
  "        Dep = 100   (ms)  : relaxation time constant from depression\n"
  "        Fac = 10   (ms)  :  relaxation time constant from facilitation\n"
  "        e = 0     (mV)  : AMPA and NMDA reversal potential\n"
  "	mg = 1   (mM)  : initial concentration of mg2+\n"
  "	mgVoltageCoeff = 0.08 (mV) : the coefficient for the voltage dependance of the equation\n"
  "        mggate\n"
  "    	gmax = .001 (uS) : weight conversion factor (from nS to uS)\n"
  "    	u0 = 0 :initial value of u, which is the running value of Use\n"
  "}\n"
  "\n"
  "COMMENT\n"
  "The Verbatim block is needed to generate random nos. from a uniform distribution between 0 and 1 \n"
  "for comparison with Pr to decide whether to activate the synapse or not\n"
  "ENDCOMMENT\n"
  "   \n"
  "VERBATIM\n"
  "\n"
  "#include<stdlib.h>\n"
  "#include<stdio.h>\n"
  "#include<math.h>\n"
  "\n"
  "double nrn_random_pick(void* r);\n"
  "void* nrn_random_arg(int argpos);\n"
  "\n"
  "ENDVERBATIM\n"
  "  \n"
  "\n"
  "ASSIGNED {\n"
  "\n"
  "        v (mV)\n"
  "        i (nA)\n"
  "	i_AMPA (nA)\n"
  "	i_NMDA (nA)\n"
  "        g_AMPA (uS)\n"
  "	g_NMDA (uS)\n"
  "        factor_AMPA\n"
  "	factor_NMDA\n"
  "	rng\n"
  "	weight_NMDA\n"
  "    a\n"
  "}\n"
  "\n"
  "STATE {\n"
  "\n"
  "        A_AMPA       : AMPA state variable to construct the dual-exponential profile - decays with conductance tau_r_AMPA\n"
  "        B_AMPA       : AMPA state variable to construct the dual-exponential profile - decays with conductance tau_d_AMPA\n"
  "	A_NMDA       : NMDA state variable to construct the dual-exponential profile - decays with conductance tau_r_NMDA\n"
  "        B_NMDA       : NMDA state variable to construct the dual-exponential profile - decays with conductance tau_d_NMDA\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "\n"
  "        LOCAL tp_AMPA, tp_NMDA\n"
  "        \n"
  "	A_AMPA = 0\n"
  "        B_AMPA = 0\n"
  "	\n"
  "	A_NMDA = 0\n"
  "	B_NMDA = 0\n"
  "        \n"
  "	tp_AMPA = (tau_r_AMPA*tau_d_AMPA)/(tau_d_AMPA-tau_r_AMPA)*log(tau_d_AMPA/tau_r_AMPA) :time to peak of the conductance\n"
  "	tp_NMDA = (tau_r_NMDA*tau_d_NMDA)/(tau_d_NMDA-tau_r_NMDA)*log(tau_d_NMDA/tau_r_NMDA) :time to peak of the conductance\n"
  "        \n"
  "	factor_AMPA = -exp(-tp_AMPA/tau_r_AMPA)+exp(-tp_AMPA/tau_d_AMPA) :AMPA Normalization factor - so that when t = tp_AMPA, gsyn = gpeak\n"
  "        factor_AMPA = 1/factor_AMPA\n"
  "	\n"
  "	factor_NMDA = -exp(-tp_NMDA/tau_r_NMDA)+exp(-tp_NMDA/tau_d_NMDA) :NMDA Normalization factor - so that when t = tp_NMDA, gsyn = gpeak\n"
  "        factor_NMDA = 1/factor_NMDA\n"
  "   \n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "\n"
  "        SOLVE state METHOD cnexp\n"
  "	mggate = 1 / (1 + exp(mgVoltageCoeff * -(v)) * (mg / 3.57 (mM))) :mggate kinetics - Jahr & Stevens 1990\n"
  "        g_AMPA = (1) * gmax * (B_AMPA-A_AMPA) :compute time varying conductance as the difference of state variables B_AMPA and A_AMPA\n"
  "	g_NMDA = gmax*(B_NMDA-A_NMDA) * mggate :compute time varying conductance as the difference of state variables B_NMDA and A_NMDA and mggate kinetics\n"
  "        i_AMPA = g_AMPA*(v-e) :compute the AMPA driving force based on the time varying conductance, membrane potential, and AMPA reversal\n"
  "	i_NMDA = g_NMDA*(v-e) :compute the NMDA driving force based on the time varying conductance, membrane potential, and NMDA reversal\n"
  "	i = i_AMPA + i_NMDA\n"
  "}\n"
  "\n"
  "DERIVATIVE state{\n"
  "\n"
  "        A_AMPA' = -A_AMPA/tau_r_AMPA\n"
  "        B_AMPA' = -B_AMPA/tau_d_AMPA\n"
  "	A_NMDA' = -A_NMDA/tau_r_NMDA\n"
  "        B_NMDA' = -B_NMDA/tau_d_NMDA\n"
  "}\n"
  "\n"
  "\n"
  "NET_RECEIVE (weight,weight_AMPA, weight_NMDA, Pv, Pr, u, tsyn (ms)){\n"
  "	\n"
  "	weight_AMPA = weight\n"
  "	weight_NMDA = weight\n"
  "	:printf(\"NMDA weight = %g\\n\", weight_NMDA)\n"
  "\n"
  "        INITIAL{\n"
  "                Pv=1\n"
  "                u=u0\n"
  "                tsyn=t\n"
  "            }\n"
  "\n"
  "        : calc u at event-\n"
  "        if (Fac > 0) {\n"
  "                u = u*exp(-(t - tsyn)/Fac) :update facilitation variable if Fac>0 Eq. 2 in Fuhrmann et al.\n"
  "           } else {\n"
  "                  u = Use  \n"
  "           } \n"
  "           if(Fac > 0){\n"
  "                  u = u + Use*(1-u) :update facilitation variable if Fac>0 Eq. 2 in Fuhrmann et al.\n"
  "           }    \n"
  "\n"
  "        \n"
  "            Pv  = 1 - (1-Pv) * exp(-(t-tsyn)/Dep) :Probability Pv for a vesicle to be available for release, analogous to the pool of synaptic\n"
  "                                                 :resources available for release in the deterministic model. Eq. 3 in Fuhrmann et al.\n"
  "            Pr  = u * Pv                         :Pr is calculated as Pv * u (running value of Use)\n"
  "            Pv  = Pv - u * Pv                    :update Pv as per Eq. 3 in Fuhrmann et al.\n"
  "            :printf(\"Pv = %g\\n\", Pv)\n"
  "            :printf(\"Pr = %g\\n\", Pr)\n"
  "            tsyn = t\n"
  "            \n"
  "                    A_AMPA = A_AMPA + weight_AMPA*factor_AMPA\n"
  "                    B_AMPA = B_AMPA + weight_AMPA*factor_AMPA\n"
  "		    A_NMDA = A_NMDA + weight_NMDA*factor_NMDA\n"
  "                    B_NMDA = B_NMDA + weight_NMDA*factor_NMDA\n"
  "\n"
  "}\n"
  "\n"
  "PROCEDURE setRNG() {\n"
  "VERBATIM\n"
  "    {\n"
  "        /**\n"
  "         * This function takes a NEURON Random object declared in hoc and makes it usable by this mod file.\n"
  "         * Note that this method is taken from Brett paper as used by netstim.hoc and netstim.mod\n"
  "         * which points out that the Random must be in negexp(1) mode\n"
  "         */\n"
  "        void** pv = (void**)(&_p_rng);\n"
  "        if( ifarg(1)) {\n"
  "            *pv = nrn_random_arg(1);\n"
  "        } else {\n"
  "            *pv = (void*)0;\n"
  "        }\n"
  "    }\n"
  "ENDVERBATIM\n"
  "}\n"
  "\n"
  "FUNCTION erand() {\n"
  "VERBATIM\n"
  "	    //FILE *fi;\n"
  "        double value;\n"
  "        if (_p_rng) {\n"
  "                /*\n"
  "                :Supports separate independent but reproducible streams for\n"
  "                : each instance. However, the corresponding hoc Random\n"
  "                : distribution MUST be set to Random.negexp(1)\n"
  "                */\n"
  "                value = nrn_random_pick(_p_rng);\n"
  "		        //fi = fopen(\"RandomStreamMCellRan4.txt\", \"w\");\n"
  "                //fprintf(fi,\"random stream for this simulation = %lf\\n\",value);\n"
  "                //printf(\"random stream for this simulation = %lf\\n\",value);\n"
  "                return value;\n"
  "        }else{\n"
  "ENDVERBATIM\n"
  "                : the old standby. Cannot use if reproducible parallel sim\n"
  "                : independent of nhost or which host this instance is on\n"
  "                : is desired, since each instance on this cpu draws from\n"
  "                : the same stream\n"
  "                erand = exprand(1)\n"
  "VERBATIM\n"
  "        }\n"
  "ENDVERBATIM\n"
  "        erand = value\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
#endif
