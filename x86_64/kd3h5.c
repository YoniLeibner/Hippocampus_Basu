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
 
#define nrn_init _nrn_init__kd3
#define _nrn_initial _nrn_initial__kd3
#define nrn_cur _nrn_cur__kd3
#define _nrn_current _nrn_current__kd3
#define nrn_jacob _nrn_jacob__kd3
#define nrn_state _nrn_state__kd3
#define _net_receive _net_receive__kd3 
#define _f_trates _f_trates__kd3 
#define rates rates__kd3 
#define states states__kd3 
#define trates trates__kd3 
 
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
#define gbar _p[0]
#define gbar_columnindex 0
#define ek _p[1]
#define ek_columnindex 1
#define gk _p[2]
#define gk_columnindex 2
#define ninf _p[3]
#define ninf_columnindex 3
#define ntau _p[4]
#define ntau_columnindex 4
#define n _p[5]
#define n_columnindex 5
#define a _p[6]
#define a_columnindex 6
#define b _p[7]
#define b_columnindex 7
#define ik _p[8]
#define ik_columnindex 8
#define Dn _p[9]
#define Dn_columnindex 9
#define _g _p[10]
#define _g_columnindex 10
#define _ion_ik	*_ppvar[0]._pval
#define _ion_dikdv	*_ppvar[1]._pval
 
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
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates(void);
 static void _hoc_states(void);
 static void _hoc_trates(void);
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

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_kd3", _hoc_setdata,
 "rates_kd3", _hoc_rates,
 "states_kd3", _hoc_states,
 "trates_kd3", _hoc_trates,
 0, 0
};
 /* declare global and static user variables */
#define Rb Rb_kd3
 double Rb = 0.002;
#define Ra Ra_kd3
 double Ra = 0.02;
#define qa qa_kd3
 double qa = 9;
#define q10 q10_kd3
 double q10 = 2.3;
#define tha tha_kd3
 double tha = 20;
#define tadj tadj_kd3
 double tadj = 0;
#define temp temp_kd3
 double temp = 16;
#define usetable usetable_kd3
 double usetable = 1;
#define vmax vmax_kd3
 double vmax = 100;
#define vmin vmin_kd3
 double vmin = -120;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_kd3", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tha_kd3", "mV",
 "qa_kd3", "mV",
 "Ra_kd3", "/ms",
 "Rb_kd3", "/ms",
 "temp_kd3", "degC",
 "vmin_kd3", "mV",
 "vmax_kd3", "mV",
 "gbar_kd3", "pS/um2",
 "ek_kd3", "mV",
 "gk_kd3", "pS/um2",
 "ntau_kd3", "ms",
 0,0
};
 static double delta_t = 1;
 static double n0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "tha_kd3", &tha_kd3,
 "qa_kd3", &qa_kd3,
 "Ra_kd3", &Ra_kd3,
 "Rb_kd3", &Rb_kd3,
 "temp_kd3", &temp_kd3,
 "q10_kd3", &q10_kd3,
 "vmin_kd3", &vmin_kd3,
 "vmax_kd3", &vmax_kd3,
 "tadj_kd3", &tadj_kd3,
 "usetable_kd3", &usetable_kd3,
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
 
static int _ode_count(int);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"kd3",
 "gbar_kd3",
 "ek_kd3",
 0,
 "gk_kd3",
 "ninf_kd3",
 "ntau_kd3",
 0,
 "n_kd3",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 11, _prop);
 	/*initialize range parameters*/
 	gbar = 300;
 	ek = -85;
 	_prop->param = _p;
 	_prop->param_size = 11;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _kd3h5_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 11, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 kd3 /ems/elsc-labs/segev-i/yoni.leibner/PycharmProjects/Hippocampus_Basu/mods_2/kd3h5.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double _znexp ;
 static double *_t_ninf;
 static double *_t__znexp;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int _f_trates(double);
static int rates(double);
static int states();
static int trates(double);
 static void _n_trates(double);
 
static int  states (  ) {
   trates ( _threadargscomma_ v ) ;
   n = n + _znexp * ( ninf - n ) ;
   
/*VERBATIM*/
        return 0;
  return 0; }
 
static void _hoc_states(void) {
  double _r;
   _r = 1.;
 states (  );
 hoc_retpushx(_r);
}
 static double _mfac_trates, _tmin_trates;
 static void _check_trates();
 static void _check_trates() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_dt;
  static double _sav_celsius;
  static double _sav_temp;
  static double _sav_Ra;
  static double _sav_Rb;
  static double _sav_tha;
  static double _sav_qa;
  if (!usetable) {return;}
  if (_sav_dt != dt) { _maktable = 1;}
  if (_sav_celsius != celsius) { _maktable = 1;}
  if (_sav_temp != temp) { _maktable = 1;}
  if (_sav_Ra != Ra) { _maktable = 1;}
  if (_sav_Rb != Rb) { _maktable = 1;}
  if (_sav_tha != tha) { _maktable = 1;}
  if (_sav_qa != qa) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_trates =  vmin ;
   _tmax =  vmax ;
   _dx = (_tmax - _tmin_trates)/199.; _mfac_trates = 1./_dx;
   for (_i=0, _x=_tmin_trates; _i < 200; _x += _dx, _i++) {
    _f_trates(_x);
    _t_ninf[_i] = ninf;
    _t__znexp[_i] = _znexp;
   }
   _sav_dt = dt;
   _sav_celsius = celsius;
   _sav_temp = temp;
   _sav_Ra = Ra;
   _sav_Rb = Rb;
   _sav_tha = tha;
   _sav_qa = qa;
  }
 }

 static int trates(double _lv){ _check_trates();
 _n_trates(_lv);
 return 0;
 }

 static void _n_trates(double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_trates(_lv); return; 
}
 _xi = _mfac_trates * (_lv - _tmin_trates);
 if (isnan(_xi)) {
  ninf = _xi;
  _znexp = _xi;
  return;
 }
 if (_xi <= 0.) {
 ninf = _t_ninf[0];
 _znexp = _t__znexp[0];
 return; }
 if (_xi >= 199.) {
 ninf = _t_ninf[199];
 _znexp = _t__znexp[199];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 ninf = _t_ninf[_i] + _theta*(_t_ninf[_i+1] - _t_ninf[_i]);
 _znexp = _t__znexp[_i] + _theta*(_t__znexp[_i+1] - _t__znexp[_i]);
 }

 
static int  _f_trates (  double _lv ) {
   double _ltinc ;
 rates ( _threadargscomma_ _lv ) ;
   tadj = pow( 3.0 , ( ( celsius - temp ) / 10.0 ) ) ;
   _ltinc = - dt * tadj ;
   _znexp = 1.0 - exp ( _ltinc / ntau ) ;
    return 0; }
 
static void _hoc_trates(void) {
  double _r;
    _r = 1.;
 trates (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int  rates (  double _lv ) {
   a = Ra * ( _lv - tha ) / ( 1.0 - exp ( - ( _lv - tha ) / qa ) ) ;
   b = - Rb * ( _lv - tha ) / ( 1.0 - exp ( ( _lv - tha ) / qa ) ) ;
   ntau = 1.0 / ( a + b ) ;
   ninf = a * ntau ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ hoc_execerror("kd3", "cannot be used with CVODE"); return 0;}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  n = n0;
 {
   trates ( _threadargscomma_ v ) ;
   n = ninf ;
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
   gk = gbar * n ;
   ik = ( 1e-4 ) * gk * ( v - ek ) ;
   }
 _current += ik;

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
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
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
 { error =  states();
 if(error){fprintf(stderr,"at line 71 in file kd3h5.mod:\n        SOLVE states\n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
   _t_ninf = makevector(200*sizeof(double));
   _t__znexp = makevector(200*sizeof(double));
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/ems/elsc-labs/segev-i/yoni.leibner/PycharmProjects/Hippocampus_Basu/mods_2/kd3h5.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "\n"
  "Kd3h5.mod\n"
  "\n"
  "Potassium channel, Hodgkin-Huxley style kinetics\n"
  "Kinetic rates based roughly on Sah et al. and Hamill et al. (1991)\n"
  "\n"
  "Use with na3h5.mod\n"
  "\n"
  "Author: Zach Mainen, Salk Institute, 1994, zach@salk.edu\n"
  "	\n"
  "ENDCOMMENT\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX kd3\n"
  "	USEION k WRITE ik\n"
  "	RANGE n, gk, gbar\n"
  "	RANGE ninf, ntau, ek\n"
  "	GLOBAL Ra, Rb\n"
  "	GLOBAL q10, temp, tadj, vmin, vmax\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "	(pS) = (picosiemens)\n"
  "	(um) = (micron)\n"
  "} \n"
  "\n"
  "PARAMETER {\n"
  "	gbar = 300   	(pS/um2)	: 0.03 mho/cm2\n"
  "	v 		(mV)\n"
  "								\n"
  "	tha  = 20	(mV)		: v 1/2 for inf\n"
  "	qa   = 9	(mV)		: inf slope		\n"
  "	\n"
  "	Ra   = 0.02	(/ms)		: max act rate\n"
  "	Rb   = 0.002	(/ms)		: max deact rate	\n"
  "	ek = -85 (mV)\n"
  "	dt		(ms)\n"
  "	celsius		(degC)\n"
  "	temp = 16	(degC)		: original temp 	\n"
  "	q10  = 2.3			: temperature sensitivity\n"
  "\n"
  "	vmin = -120	(mV)\n"
  "	vmax = 100	(mV)\n"
  "} \n"
  "\n"
  "\n"
  "ASSIGNED {\n"
  "	a		(/ms)\n"
  "	b		(/ms)\n"
  "	ik 		(mA/cm2)\n"
  "	gk		(pS/um2)\n"
  "	ninf\n"
  "	ntau (ms)	\n"
  "	tadj\n"
  "}\n"
  " \n"
  "\n"
  "STATE { n }\n"
  "\n"
  "INITIAL { \n"
  "	trates(v)\n"
  "	n = ninf\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "        SOLVE states\n"
  "	gk = gbar*n\n"
  "	ik = (1e-4) * gk * (v - ek)\n"
  "} \n"
  "\n"
  "LOCAL nexp\n"
  "\n"
  "PROCEDURE states() {   :Computes state variable n \n"
  "        trates(v)      :             at the current v and dt.\n"
  "        n = n + nexp*(ninf-n)\n"
  "        VERBATIM\n"
  "        return 0;\n"
  "        ENDVERBATIM\n"
  "}\n"
  "\n"
  "PROCEDURE trates(v) {  :Computes rate and other constants at current v.\n"
  "                      :Call once from HOC to initialize inf at resting v.\n"
  "        LOCAL tinc\n"
  "        TABLE ninf, nexp\n"
  "	DEPEND dt, celsius, temp, Ra, Rb, tha, qa\n"
  "	\n"
  "	FROM vmin TO vmax WITH 199\n"
  "\n"
  "	rates(v): not consistently executed from here if usetable_hh == 1\n"
  "\n"
  "        tadj = 3^((celsius - temp)/10)\n"
  "\n"
  "        tinc = -dt * tadj\n"
  "        nexp = 1 - exp(tinc/ntau)\n"
  "}\n"
  "\n"
  "\n"
  "PROCEDURE rates(v) {  :Computes rate and other constants at current v.\n"
  "                      :Call once from HOC to initialize inf at resting v.\n"
  "\n"
  "        a = Ra * (v - tha) / (1 - exp(-(v - tha)/qa))\n"
  "        b = -Rb * (v - tha) / (1 - exp((v - tha)/qa))\n"
  "        ntau = 1/(a+b)\n"
  "	ninf = a*ntau\n"
  "}\n"
  ;
#endif
