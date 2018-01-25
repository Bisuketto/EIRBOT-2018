#include "__cf_untitled.h"
#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "untitled_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME untitled
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (4) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T orwxcl3fbq ; real_T asgpaedjpu ; real_T nhvtbrec3d ;
real_T fxzuucao4l ; } B ; typedef struct { real_T mdhre0xjct [ 4 ] ; struct {
void * AQHandles ; } gvyelfai1g ; struct { void * AQHandles ; } nkyn11imst ;
struct { void * AQHandles ; } l2d0qhjoya ; int_T avbu4pf4vu ; } DW ; typedef
struct { real_T hhwnc3k50x [ 3 ] ; } X ; typedef struct { real_T hhwnc3k50x [
3 ] ; } XDot ; typedef struct { boolean_T hhwnc3k50x [ 3 ] ; } XDis ; typedef
struct { real_T hhwnc3k50x [ 3 ] ; } CStateAbsTol ; typedef struct { real_T
eey5q2c1p3 ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T DiscreteTransferFcn_NumCoef [ 5 ] ; real_T
DiscreteTransferFcn_DenCoef [ 5 ] ; real_T DiscreteTransferFcn_InitialStates
; real_T Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T
TransferFcn_A [ 3 ] ; real_T TransferFcn_C [ 3 ] ; real_T Reference_Time ;
real_T Reference_Y0 ; real_T Reference_YFinal ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
untitled_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern const int_T
gblParameterTuningTid ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
