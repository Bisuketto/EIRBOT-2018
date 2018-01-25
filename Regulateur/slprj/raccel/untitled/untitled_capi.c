#include "__cf_untitled.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "untitled_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "untitled.h"
#include "untitled_capi.h"
#include "untitled_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"untitled/Reference" ) , TARGET_STRING ( "reference" ) , 0 , 0 , 0 , 0 , 0 }
, { 1 , 0 , TARGET_STRING ( "untitled/Sum" ) , TARGET_STRING ( "error" ) , 0
, 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"untitled/Controller/Saturation" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2
} , { 3 , 0 , TARGET_STRING ( "untitled/Plant/Transfer Fcn" ) , TARGET_STRING
( "plant_output" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters
[ ] = { { 4 , TARGET_STRING ( "untitled/Reference" ) , TARGET_STRING ( "Time"
) , 0 , 0 , 0 } , { 5 , TARGET_STRING ( "untitled/Reference" ) ,
TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 6 , TARGET_STRING (
"untitled/Reference" ) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 7 ,
TARGET_STRING ( "untitled/Controller/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 8 , TARGET_STRING (
"untitled/Controller/Saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 ,
0 } , { 9 , TARGET_STRING ( "untitled/Controller/Discrete Transfer Fcn" ) ,
TARGET_STRING ( "Numerator" ) , 0 , 1 , 0 } , { 10 , TARGET_STRING (
"untitled/Controller/Discrete Transfer Fcn" ) , TARGET_STRING ( "Denominator"
) , 0 , 1 , 0 } , { 11 , TARGET_STRING (
"untitled/Controller/Discrete Transfer Fcn" ) , TARGET_STRING (
"InitialStates" ) , 0 , 0 , 0 } , { 12 , TARGET_STRING (
"untitled/Plant/Transfer Fcn" ) , TARGET_STRING ( "A" ) , 0 , 2 , 0 } , { 13
, TARGET_STRING ( "untitled/Plant/Transfer Fcn" ) , TARGET_STRING ( "C" ) , 0
, 3 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . nhvtbrec3d , & rtB . fxzuucao4l ,
& rtB . orwxcl3fbq , & rtB . asgpaedjpu , & rtP . Reference_Time , & rtP .
Reference_Y0 , & rtP . Reference_YFinal , & rtP . Saturation_UpperSat , & rtP
. Saturation_LowerSat , & rtP . DiscreteTransferFcn_NumCoef [ 0 ] , & rtP .
DiscreteTransferFcn_DenCoef [ 0 ] , & rtP . DiscreteTransferFcn_InitialStates
, & rtP . TransferFcn_A [ 0 ] , & rtP . TransferFcn_C [ 0 ] , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 1 , 5 , 3 , 1 , 1 , 3 } ;
static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 , 1.0E-6 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 1 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 0 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 4 , ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockParameters , 10 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 1608993079U , 1720908219U , 1403314151U ,
3867020258U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
untitled_GetCAPIStaticMap ( ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void untitled_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void untitled_host_InitializeDataMapInfo ( untitled_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
